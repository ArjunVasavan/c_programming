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
MODULE_PARM_DESC(server_ip, "IP address of the UDP server to send to");

static struct task_struct *client_thread;

static int udp_client_thread(void *arg)
{
    struct socket *sock = NULL;
    struct sockaddr_in server_addr;
    char *buffer;
    char send_msg[] = "Hello from kernel UDP client";
    int ret;

    buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);
    if (!buffer) {
        pr_err("UDP client: buffer allocation failed\n");
        return -ENOMEM;
    }

    ret = sock_create_kern(&init_net,
                           AF_INET,
                           SOCK_DGRAM,
                           IPPROTO_UDP,
                           &sock);

    if (ret < 0) {
        pr_err("UDP client: socket creation failed: %d\n", ret);
        kfree(buffer);
        return ret;
    }

    pr_info("UDP client: socket created\n");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    ret = in4_pton(server_ip, -1, (u8 *)&server_addr.sin_addr.s_addr, -1, NULL);
    if (ret != 1) {
        pr_err("UDP client: invalid server IP: %s\n", server_ip);
        sock_release(sock);
        kfree(buffer);
        return -EINVAL;
    }

    {
        struct msghdr msg;
        struct kvec vec;

        memset(&msg, 0, sizeof(msg));

        msg.msg_name = &server_addr;
        msg.msg_namelen = sizeof(server_addr);

        vec.iov_base = send_msg;
        vec.iov_len = strlen(send_msg);

        ret = kernel_sendmsg(sock, &msg, &vec, 1, strlen(send_msg));

        if (ret < 0) {
            pr_err("UDP client: send failed: %d\n", ret);
            sock_release(sock);
            kfree(buffer);
            return ret;
        }

        pr_info("UDP client: sent to %s:%d: %s\n", server_ip, SERVER_PORT, send_msg);
    }

    memset(buffer, 0, BUFFER_SIZE);

    {
        struct msghdr msg;
        struct kvec vec;
        struct sockaddr_in from_addr;
        int i;

        for (i = 0; i < 50 && !kthread_should_stop(); i++) {

            memset(&msg, 0, sizeof(msg));
            memset(&from_addr, 0, sizeof(from_addr));

            msg.msg_name = &from_addr;
            msg.msg_namelen = sizeof(from_addr);

            vec.iov_base = buffer;
            vec.iov_len = BUFFER_SIZE - 1;

            ret = kernel_recvmsg(sock, &msg, &vec, 1, BUFFER_SIZE - 1, MSG_DONTWAIT);

            if (ret > 0) {
                buffer[ret] = '\0';
                pr_info("UDP client: received: %s\n", buffer);
                break;
            } else if (ret == -EAGAIN) {
                msleep(100);
                continue;
            } else {
                pr_err("UDP client: receive failed: %d\n", ret);
                break;
            }
        }
    }

    sock_release(sock);
    kfree(buffer);

    pr_info("UDP client: done\n");

    return 0;
}


static int __init udp_client_init(void)
{
    pr_info("UDP client: module loaded\n");

    client_thread = kthread_run(udp_client_thread,
                                NULL,
                                "udp_client");

    if (IS_ERR(client_thread)) {
        pr_err("UDP client: failed to create thread\n");
        client_thread = NULL;
        return PTR_ERR(client_thread);
    }

    return 0;
}


static void __exit udp_client_exit(void)
{
    pr_info("UDP client: stopping\n");

    if (client_thread) {
        kthread_stop(client_thread);
        client_thread = NULL;
    }

    pr_info("UDP client: module unloaded\n");
}


module_init(udp_client_init);
module_exit(udp_client_exit);

MODULE_LICENSE("GPL");
