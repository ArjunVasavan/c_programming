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

static char *server_ip = "127.0.0.1";
module_param(server_ip, charp, 0444);
MODULE_PARM_DESC(server_ip, "IP address of the TCP server to connect to");

static struct task_struct *client_thread;

static int tcp_client_thread(void *arg)
{
    struct socket *sock = NULL;
    struct sockaddr_in server_addr;
    char *buffer;
    char send_msg[] = "Hello from kernel TCP client";
    int ret;

    buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);
    if (!buffer) {
        pr_err("TCP client: buffer allocation failed\n");
        return -ENOMEM;
    }

    ret = sock_create_kern(&init_net,
                           AF_INET,
                           SOCK_STREAM,
                           IPPROTO_TCP,
                           &sock);

    if (ret < 0) {
        pr_err("TCP client: socket creation failed: %d\n", ret);
        kfree(buffer);
        return ret;
    }

    pr_info("TCP client: socket created\n");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    ret = in4_pton(server_ip, -1, (u8 *)&server_addr.sin_addr.s_addr, -1, NULL);
    if (ret != 1) {
        pr_err("TCP client: invalid server IP: %s\n", server_ip);
        sock_release(sock);
        kfree(buffer);
        return -EINVAL;
    }

    ret = kernel_connect(sock,
                         (struct sockaddr *)&server_addr,
                         sizeof(server_addr),
                         0);

    if (ret < 0) {
        pr_err("TCP client: connect failed: %d\n", ret);
        sock_release(sock);
        kfree(buffer);
        return ret;
    }

    pr_info("TCP client: connected to %s:%d\n", server_ip, SERVER_PORT);

    {
        struct msghdr msg;
        struct kvec vec;

        memset(&msg, 0, sizeof(msg));

        vec.iov_base = send_msg;
        vec.iov_len = strlen(send_msg);

        ret = kernel_sendmsg(sock, &msg, &vec, 1, strlen(send_msg));

        if (ret < 0) {
            pr_err("TCP client: send failed: %d\n", ret);
            sock_release(sock);
            kfree(buffer);
            return ret;
        }

        pr_info("TCP client: sent: %s\n", send_msg);
    }

    memset(buffer, 0, BUFFER_SIZE);

    {
        struct msghdr msg;
        struct kvec vec;

        memset(&msg, 0, sizeof(msg));

        vec.iov_base = buffer;
        vec.iov_len = BUFFER_SIZE - 1;

        ret = kernel_recvmsg(sock, &msg, &vec, 1, BUFFER_SIZE - 1, 0);

        if (ret > 0) {
            buffer[ret] = '\0';
            pr_info("TCP client: received: %s\n", buffer);
        } else if (ret == 0) {
            pr_info("TCP client: server closed connection\n");
        } else {
            pr_err("TCP client: receive failed: %d\n", ret);
        }
    }

    sock_release(sock);
    kfree(buffer);

    pr_info("TCP client: done\n");

    return 0;
}


static int __init tcp_client_init(void)
{
    pr_info("TCP client: module loaded\n");

    client_thread = kthread_run(tcp_client_thread,
                                NULL,
                                "tcp_client");

    if (IS_ERR(client_thread)) {
        pr_err("TCP client: failed to create thread\n");
        client_thread = NULL;
        return PTR_ERR(client_thread);
    }

    return 0;
}


static void __exit tcp_client_exit(void)
{
    pr_info("TCP client: stopping\n");

    if (client_thread) {
        kthread_stop(client_thread);
        client_thread = NULL;
    }

    pr_info("TCP client: module unloaded\n");
}


module_init(tcp_client_init);
module_exit(tcp_client_exit);

MODULE_LICENSE("GPL");
