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
#define RECV_RETRIES 50
#define RECV_POLL_MS 100

static char *server_ip = "127.0.0.1";
module_param(server_ip, charp, 0444);
MODULE_PARM_DESC(server_ip, "IP address of the UDP server to send to");

static struct task_struct *client_thread;

static void wait_for_reply(struct socket *sock, char *buffer)
{
    struct sockaddr_in from_addr;
    struct msghdr msg;
    struct kvec vec;
    int ret, i;

    for (i = 0; i < RECV_RETRIES && !kthread_should_stop(); i++) {
        memset(&msg, 0, sizeof(msg));
        memset(&from_addr, 0, sizeof(from_addr));

        msg.msg_name = &from_addr;
        msg.msg_namelen = sizeof(from_addr);

        vec.iov_base = buffer;
        vec.iov_len = BUFFER_SIZE - 1;

        ret = kernel_recvmsg(sock, &msg, &vec, 1, vec.iov_len, MSG_DONTWAIT);

        if (ret > 0) {
            buffer[ret] = '\0';
            pr_info("UDP client: received: %s\n", buffer);
            return;
        } else if (ret == -EAGAIN) {
            msleep(RECV_POLL_MS);
        } else {
            pr_err("UDP client: receive failed: %d\n", ret);
            return;
        }
    }
}

static int udp_client_thread(void *arg)
{
    struct socket *sock = NULL;
    struct sockaddr_in server_addr = { .sin_family = AF_INET, .sin_port = htons(SERVER_PORT) };
    struct msghdr msg = { .msg_name = &server_addr, .msg_namelen = sizeof(server_addr) };
    struct kvec vec;
    char *buffer;
    char send_msg[] = "Hello from kernel UDP client";
    int ret;

    buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);
    if (!buffer)
        return -ENOMEM;

    if (in4_pton(server_ip, -1, (u8 *)&server_addr.sin_addr.s_addr, -1, NULL) != 1) {
        pr_err("UDP client: invalid server IP: %s\n", server_ip);
        ret = -EINVAL;
        goto out_free;
    }

    ret = sock_create_kern(&init_net, AF_INET, SOCK_DGRAM, IPPROTO_UDP, &sock);
    if (ret < 0) {
        pr_err("UDP client: socket creation failed: %d\n", ret);
        goto out_free;
    }

    vec.iov_base = send_msg;
    vec.iov_len = strlen(send_msg);
    ret = kernel_sendmsg(sock, &msg, &vec, 1, vec.iov_len);
    if (ret < 0) {
        pr_err("UDP client: send failed: %d\n", ret);
        goto out_release;
    }
    pr_info("UDP client: sent to %s:%d: %s\n", server_ip, SERVER_PORT, send_msg);

    wait_for_reply(sock, buffer);
    ret = 0;

out_release:
    sock_release(sock);
out_free:
    kfree(buffer);
    pr_info("UDP client: done\n");
    return ret;
}

static int __init udp_client_init(void)
{
    client_thread = kthread_run(udp_client_thread, NULL, "udp_client");
    if (IS_ERR(client_thread)) {
        pr_err("UDP client: failed to create thread\n");
        return PTR_ERR(client_thread);
    }
    return 0;
}

static void __exit udp_client_exit(void)
{
    if (client_thread) {
        kthread_stop(client_thread);
        client_thread = NULL;
    }
    pr_info("UDP client: module unloaded\n");
}

module_init(udp_client_init);
module_exit(udp_client_exit);

MODULE_LICENSE("GPL");
