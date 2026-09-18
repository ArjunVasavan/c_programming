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
#define RETRY_DELAY_MS 3000

static char *server_ip = "127.0.0.1";
module_param(server_ip, charp, 0444);
MODULE_PARM_DESC(server_ip, "IP address of the TCP server to connect to");

static struct task_struct *client_thread;

/* One connect/send/receive cycle. Returns 0 on success, <0 on error. */
static int tcp_client_exchange(char *buffer)
{
    struct socket *sock = NULL;
    struct sockaddr_in server_addr = { .sin_family = AF_INET, .sin_port = htons(SERVER_PORT) };
    char send_msg[] = "Hello from kernel TCP client";
    struct msghdr msg = { 0 };
    struct kvec vec;
    int ret;

    if (in4_pton(server_ip, -1, (u8 *)&server_addr.sin_addr.s_addr, -1, NULL) != 1) {
        pr_err("TCP client: invalid server IP: %s\n", server_ip);
        return -EINVAL;
    }

    ret = sock_create_kern(&init_net, AF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
    if (ret < 0) {
        pr_err("TCP client: socket creation failed: %d\n", ret);
        return ret;
    }

    ret = kernel_connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr), 0);
    if (ret < 0) {
        pr_err("TCP client: connect failed: %d\n", ret);
        goto out;
    }
    pr_info("TCP client: connected to %s:%d\n", server_ip, SERVER_PORT);

    vec.iov_base = send_msg;
    vec.iov_len = strlen(send_msg);
    ret = kernel_sendmsg(sock, &msg, &vec, 1, vec.iov_len);
    if (ret < 0) {
        pr_err("TCP client: send failed: %d\n", ret);
        goto out;
    }
    pr_info("TCP client: sent: %s\n", send_msg);

    memset(buffer, 0, BUFFER_SIZE);
    vec.iov_base = buffer;
    vec.iov_len = BUFFER_SIZE - 1;
    ret = kernel_recvmsg(sock, &msg, &vec, 1, vec.iov_len, 0);

    if (ret > 0) {
        buffer[ret] = '\0';
        pr_info("TCP client: received: %s\n", buffer);
    } else if (ret == 0) {
        pr_info("TCP client: server closed connection\n");
    } else {
        pr_err("TCP client: receive failed: %d\n", ret);
    }

out:
    sock_release(sock);
    return (ret < 0) ? ret : 0;
}

static int tcp_client_thread(void *arg)
{
    char *buffer;
    int ret;

    buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);
    if (!buffer)
        return -ENOMEM;

    /* Retry until the module is unloaded. kthread_should_stop() is
     * checked before and after each attempt so kthread_stop() wakes
     * the thread promptly instead of waiting out the full delay. */
    while (!kthread_should_stop()) {
        ret = tcp_client_exchange(buffer);
        if (ret < 0)
            pr_err("TCP client: exchange failed: %d, retrying\n", ret);

        if (!kthread_should_stop())
            msleep_interruptible(RETRY_DELAY_MS);
    }

    kfree(buffer);
    pr_info("TCP client: thread exiting\n");
    return 0;
}

static int __init tcp_client_init(void)
{
    client_thread = kthread_run(tcp_client_thread, NULL, "tcp_client");
    if (IS_ERR(client_thread)) {
        pr_err("TCP client: failed to create thread\n");
        return PTR_ERR(client_thread);
    }
    return 0;
}

static void __exit tcp_client_exit(void)
{
    if (client_thread) {
        kthread_stop(client_thread);
        client_thread = NULL;
    }
    pr_info("TCP client: module unloaded\n");
}

module_init(tcp_client_init);
module_exit(tcp_client_exit);

MODULE_LICENSE("GPL");
