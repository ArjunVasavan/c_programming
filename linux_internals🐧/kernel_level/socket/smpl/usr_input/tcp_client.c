#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/net.h>
#include <linux/in.h>
#include <linux/socket.h>
#include <net/net_namespace.h>

#define SERVER_PORT 2325
#define BUFFER_SIZE 1024
#define DEVICE_NAME "tcp_msg"

static char *server_ip = "127.0.0.1";
module_param(server_ip, charp, 0444);
MODULE_PARM_DESC(server_ip, "IP address of the TCP server to send to");

static int tcp_send_message(char *buf, size_t len)
{
    struct socket *sock;
    struct sockaddr_in addr = { .sin_family = AF_INET, .sin_port = htons(SERVER_PORT) };
    struct msghdr mh = { 0 };
    struct kvec vec;
    int ret;

    if (in4_pton(server_ip, -1, (u8 *)&addr.sin_addr.s_addr, -1, NULL) != 1) {
        pr_err("tcp_msg: invalid server IP: %s\n", server_ip);
        return -EINVAL;
    }

    ret = sock_create_kern(&init_net, AF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
    if (ret < 0) {
        pr_err("tcp_msg: socket creation failed: %d\n", ret);
        return ret;
    }

    ret = kernel_connect(sock, (struct sockaddr *)&addr, sizeof(addr), 0);
    if (ret < 0) {
        pr_err("tcp_msg: connect to %s:%d failed: %d\n", server_ip, SERVER_PORT, ret);
        goto out;
    }

    vec.iov_base = buf;
    vec.iov_len = len;
    ret = kernel_sendmsg(sock, &mh, &vec, 1, len);
    if (ret < 0) {
        pr_err("tcp_msg: send failed: %d\n", ret);
        goto out;
    }
    pr_info("tcp_msg: sent to %s:%d: %s\n", server_ip, SERVER_PORT, buf);

    vec.iov_base = buf;
    vec.iov_len = BUFFER_SIZE - 1;
    ret = kernel_recvmsg(sock, &mh, &vec, 1, vec.iov_len, 0);
    if (ret > 0) {
        buf[ret] = '\0';
        pr_info("tcp_msg: received: %s\n", buf);
    } else if (ret == 0) {
        pr_info("tcp_msg: server closed connection\n");
    } else {
        pr_err("tcp_msg: receive failed: %d\n", ret);
    }
    ret = 0;

out:
    sock_release(sock);
    return ret;
}

static ssize_t tcp_msg_write(struct file *file, const char __user *ubuf,
                              size_t count, loff_t *ppos)
{
    size_t len = min(count, (size_t)(BUFFER_SIZE - 1));
    char *buf;
    int ret;

    buf = kmalloc(BUFFER_SIZE, GFP_KERNEL);
    if (!buf)
        return -ENOMEM;

    if (copy_from_user(buf, ubuf, len)) {
        kfree(buf);
        return -EFAULT;
    }
    buf[len] = '\0';

    if (len > 0 && buf[len - 1] == '\n')
        buf[len - 1] = '\0';

    ret = tcp_send_message(buf, strlen(buf));
    kfree(buf);

    return (ret < 0) ? ret : count;
}

static const struct file_operations tcp_msg_fops = {
    .owner = THIS_MODULE,
    .write = tcp_msg_write,
};

static struct miscdevice tcp_msg_dev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name  = DEVICE_NAME,
    .fops  = &tcp_msg_fops,
    .mode  = 0666,
};

static int __init tcp_msg_init(void)
{
    int ret = misc_register(&tcp_msg_dev);

    if (ret) {
        pr_err("tcp_msg: failed to register misc device: %d\n", ret);
        return ret;
    }

    pr_info("tcp_msg: loaded, write to /dev/%s to send a message\n", DEVICE_NAME);
    return 0;
}

static void __exit tcp_msg_exit(void)
{
    misc_deregister(&tcp_msg_dev);
    pr_info("tcp_msg: unloaded\n");
}

module_init(tcp_msg_init);
module_exit(tcp_msg_exit);

MODULE_LICENSE("GPL");
