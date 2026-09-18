#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/net.h>
#include <linux/in.h>
#include <linux/socket.h>
#include <linux/delay.h>
#include <net/net_namespace.h>

#define SERVER_PORT 2325
#define BUFFER_SIZE 1024

static struct socket *server_socket;
static struct task_struct *server_thread;

static int handle_datagram(char *buffer, char *response)
{
    struct sockaddr_in client_addr = { 0 };
    struct msghdr msg = {
        .msg_name = &client_addr,
        .msg_namelen = sizeof(client_addr),
    };
    struct kvec vec = { .iov_base = buffer, .iov_len = BUFFER_SIZE - 1 };
    int recv_ret, send_ret;

    memset(buffer, 0, BUFFER_SIZE);
    recv_ret = kernel_recvmsg(server_socket, &msg, &vec, 1, vec.iov_len, MSG_DONTWAIT);
    if (recv_ret <= 0)
        return recv_ret;

    buffer[recv_ret] = '\0';
    pr_info("UDP server: received from %pI4:%u: %s\n",
            &client_addr.sin_addr.s_addr, ntohs(client_addr.sin_port), buffer);

    vec.iov_base = response;
    vec.iov_len = strlen(response);
    send_ret = kernel_sendmsg(server_socket, &msg, &vec, 1, vec.iov_len);
    if (send_ret < 0)
        pr_err("UDP server: send failed: %d\n", send_ret);
    else
        pr_info("UDP server: response sent\n");

    return recv_ret;
}

static int udp_server_thread(void *arg)
{
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(SERVER_PORT),
    };
    char *buffer;
    char response[] = "Hello from kernel UDP server";
    int ret;

    buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);
    if (!buffer)
        return -ENOMEM;

    ret = sock_create_kern(&init_net, AF_INET, SOCK_DGRAM, IPPROTO_UDP, &server_socket);
    if (ret < 0) {
        pr_err("UDP server: socket creation failed: %d\n", ret);
        goto out_free;
    }

    ret = kernel_bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        pr_err("UDP server: bind failed: %d\n", ret);
        goto out_release;
    }

    pr_info("UDP server: bound to port %d\n", SERVER_PORT);

    while (!kthread_should_stop()) {
        ret = handle_datagram(buffer, response);
        if (ret < 0) {
            if (ret == -EAGAIN || ret == -ERESTARTSYS) {
                msleep(100);
                continue;
            }
            if (!kthread_should_stop())
                pr_err("UDP server: receive failed: %d\n", ret);
        }
    }

    ret = 0;

out_release:
    sock_release(server_socket);
    server_socket = NULL;
out_free:
    kfree(buffer);
    return ret;
}

static int __init udp_server_init(void)
{
    server_thread = kthread_run(udp_server_thread, NULL, "udp_server");
    if (IS_ERR(server_thread)) {
        pr_err("UDP server: failed to create thread\n");
        return PTR_ERR(server_thread);
    }
    return 0;
}

static void __exit udp_server_exit(void)
{
    if (server_thread) {
        kthread_stop(server_thread);
        server_thread = NULL;
    }
    if (server_socket) {
        sock_release(server_socket);
        server_socket = NULL;
    }
    pr_info("UDP server: module unloaded\n");
}

module_init(udp_server_init);
module_exit(udp_server_exit);

MODULE_LICENSE("GPL");
