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

static void handle_client(struct socket *client_socket, char *buffer)
{
    struct msghdr msg = { 0 };
    struct kvec vec;
    char response[] = "Hello from kernel server";
    int ret;

    vec.iov_base = buffer;
    vec.iov_len = BUFFER_SIZE - 1;
    ret = kernel_recvmsg(client_socket, &msg, &vec, 1, vec.iov_len, 0);

    if (ret > 0) {
        buffer[ret] = '\0';
        pr_info("TCP server: received: %s\n", buffer);

        vec.iov_base = response;
        vec.iov_len = strlen(response);
        ret = kernel_sendmsg(client_socket, &msg, &vec, 1, vec.iov_len);
        if (ret < 0)
            pr_err("TCP server: send failed: %d\n", ret);
        else
            pr_info("TCP server: response sent\n");
    } else if (ret == 0) {
        pr_info("TCP server: client closed connection\n");
    } else {
        pr_err("TCP server: receive failed: %d\n", ret);
    }
}

static int tcp_server_thread(void *arg)
{
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(SERVER_PORT),
    };
    char *buffer;
    int ret;

    buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);
    if (!buffer)
        return -ENOMEM;

    ret = sock_create_kern(&init_net, AF_INET, SOCK_STREAM, IPPROTO_TCP, &server_socket);
    if (ret < 0) {
        pr_err("TCP server: socket creation failed: %d\n", ret);
        goto out_free;
    }

    ret = kernel_bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        pr_err("TCP server: bind failed: %d\n", ret);
        goto out_release;
    }

    ret = kernel_listen(server_socket, 5);
    if (ret < 0) {
        pr_err("TCP server: listen failed: %d\n", ret);
        goto out_release;
    }

    pr_info("TCP server: listening on port %d\n", SERVER_PORT);

    while (!kthread_should_stop()) {
        struct socket *client_socket = NULL;
        struct sockaddr_in client_addr;

        ret = kernel_accept(server_socket, &client_socket, O_NONBLOCK);
        if (ret < 0) {
            if (ret == -EAGAIN || ret == -ERESTARTSYS) {
                msleep(100);
                continue;
            }
            if (!kthread_should_stop())
                pr_err("TCP server: accept failed: %d\n", ret);
            continue;
        }

        if (kernel_getpeername(client_socket, (struct sockaddr *)&client_addr) >= 0)
            pr_info("TCP server: client connected from %pI4:%u\n",
                    &client_addr.sin_addr.s_addr, ntohs(client_addr.sin_port));

        memset(buffer, 0, BUFFER_SIZE);
        handle_client(client_socket, buffer);

        sock_release(client_socket);
        pr_info("TCP server: client disconnected\n");
    }

    ret = 0;

out_release:
    sock_release(server_socket);
    server_socket = NULL;
out_free:
    kfree(buffer);
    return ret;
}

static int __init tcp_server_init(void)
{
    server_thread = kthread_run(tcp_server_thread, NULL, "tcp_server");
    if (IS_ERR(server_thread)) {
        pr_err("TCP server: failed to create thread\n");
        return PTR_ERR(server_thread);
    }
    return 0;
}

static void __exit tcp_server_exit(void)
{
    if (server_thread) {
        kthread_stop(server_thread);
        server_thread = NULL;
    }
    if (server_socket) {
        sock_release(server_socket);
        server_socket = NULL;
    }
    pr_info("TCP server: module unloaded\n");
}

module_init(tcp_server_init);
module_exit(tcp_server_exit);

MODULE_LICENSE("GPL");
