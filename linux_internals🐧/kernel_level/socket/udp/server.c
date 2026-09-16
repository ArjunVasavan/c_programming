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

static int udp_server_thread(void *arg)
{
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    char *buffer;
    char response[] = "Hello from kernel UDP server";
    int ret;

    buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);
    if (!buffer) {
        pr_err("UDP server: buffer allocation failed\n");
        return -ENOMEM;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    ret = sock_create_kern(&init_net,
                           AF_INET,
                           SOCK_DGRAM,
                           IPPROTO_UDP,
                           &server_socket);

    if (ret < 0) {
        pr_err("UDP server: socket creation failed: %d\n", ret);
        kfree(buffer);
        return ret;
    }

    pr_info("UDP server: socket created\n");

    ret = kernel_bind(server_socket,
                      (struct sockaddr *)&server_addr,
                      sizeof(server_addr));

    if (ret < 0) {
        pr_err("UDP server: bind failed: %d\n", ret);
        sock_release(server_socket);
        server_socket = NULL;
        kfree(buffer);
        return ret;
    }

    pr_info("UDP server: bound to port %d\n", SERVER_PORT);

    while (!kthread_should_stop()) {

        struct msghdr msg;
        struct kvec vec;

        memset(&client_addr, 0, sizeof(client_addr));
        memset(&msg, 0, sizeof(msg));
        memset(buffer, 0, BUFFER_SIZE);

        msg.msg_name = &client_addr;
        msg.msg_namelen = sizeof(client_addr);

        vec.iov_base = buffer;
        vec.iov_len = BUFFER_SIZE - 1;

        ret = kernel_recvmsg(server_socket,
                             &msg,
                             &vec,
                             1,
                             BUFFER_SIZE - 1,
                             MSG_DONTWAIT);

        if (ret < 0) {

            if (ret == -EAGAIN || ret == -ERESTARTSYS) {
                msleep(100);
                continue;
            }

            if (kthread_should_stop())
                break;

            pr_err("UDP server: receive failed: %d\n", ret);
            continue;
        }

        buffer[ret] = '\0';

        pr_info("UDP server: received from %pI4:%u: %s\n",
                &client_addr.sin_addr.s_addr,
                ntohs(client_addr.sin_port),
                buffer);

        {
            struct msghdr reply_msg;
            struct kvec reply_vec;

            memset(&reply_msg, 0, sizeof(reply_msg));

            reply_msg.msg_name = &client_addr;
            reply_msg.msg_namelen = sizeof(client_addr);

            reply_vec.iov_base = response;
            reply_vec.iov_len = strlen(response);

            ret = kernel_sendmsg(server_socket,
                                 &reply_msg,
                                 &reply_vec,
                                 1,
                                 strlen(response));

            if (ret < 0)
                pr_err("UDP server: send failed: %d\n", ret);
            else
                pr_info("UDP server: response sent\n");
        }
    }

    kfree(buffer);

    return 0;
}


static int __init udp_server_init(void)
{
    pr_info("UDP server: module loaded\n");

    server_thread = kthread_run(udp_server_thread,
                                NULL,
                                "udp_server");

    if (IS_ERR(server_thread)) {
        pr_err("UDP server: failed to create thread\n");
        server_thread = NULL;
        return PTR_ERR(server_thread);
    }

    return 0;
}


static void __exit udp_server_exit(void)
{
    pr_info("UDP server: stopping\n");

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
