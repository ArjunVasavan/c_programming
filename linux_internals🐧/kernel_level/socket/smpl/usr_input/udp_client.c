#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/net.h>
#include <linux/in.h>
#include <linux/socket.h>
#include <net/net_namespace.h>

#define SERVER_PORT 2325
#define BUFFER_SIZE 1024
#define DEVICE_NAME "udp_msg"
#define RECV_RETRIES 50
#define RECV_POLL_MS 100

static char *server_ip = "127.0.0.1";
module_param(server_ip, charp, 0444);
MODULE_PARM_DESC(server_ip, "IP address of the UDP server to send to");

static int udp_send_message(char *buf, size_t len)
{
    struct socket *sock;
    struct sockaddr_in addr = { .sin_family = AF_INET, .sin_port = htons(SERVER_PORT) };
    struct msghdr mh = { .msg_name = &addr, .msg_namelen = sizeof(addr) };
    struct kvec vec;
    int ret, i;

    if (in4_pton(server_ip, -1, (u8 *)&addr.sin_addr.s_addr, -1, NULL) != 1) {
        pr_err("udp_msg: invalid server IP: %s\n", server_ip);
        return -EINVAL;
    }

    ret = sock_create_kern(&init_net, AF_INET, SOCK_DGRAM, IPPROTO_UDP, &sock);
    if (ret < 0) {
        pr_err("udp_msg: socket creation failed: %d\n", ret);
        return ret;
    }

    vec.iov_base = buf;
    vec.iov_len = len;
    ret = kernel_sendmsg(sock, &mh, &vec, 1, len);
    if (ret < 0) {
        pr_err("udp_msg: send failed: %d\n", ret);
        goto out;
    }
    pr_info("udp_msg: sent to %s:%d: %s\n", server_ip, SERVER_PORT, buf);

    for (i = 0; i < RECV_RETRIES; i++) {
        vec.iov_base = buf;
        vec.iov_len = BUFFER_SIZE - 1;
        ret = kernel_recvmsg(sock, &mh, &vec, 1, vec.iov_len, MSG_DONTWAIT);

        if (ret > 0) {
            buf[ret] = '\0';
            pr_info("udp_msg: received: %s\n", buf);
            break;
        } else if (ret == -EAGAIN) {
            msleep(RECV_POLL_MS);
        } else {
            pr_err("udp_msg: receive failed: %d\n", ret);
            break;
        }
    }
    ret = 0;

out:
    sock_release(sock);
    return ret;
}

static ssize_t udp_msg_write(struct file *file, const char __user *ubuf,
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

    ret = udp_send_message(buf, strlen(buf));
    kfree(buf);

    return (ret < 0) ? ret : count;
}

static const struct file_operations udp_msg_fops = {
    .owner = THIS_MODULE,
    .write = udp_msg_write,
};

static struct miscdevice udp_msg_dev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name  = DEVICE_NAME,
    .fops  = &udp_msg_fops,
    .mode  = 0666,
};

static int __init udp_msg_init(void)
{
    int ret = misc_register(&udp_msg_dev);

    if (ret) {
        pr_err("udp_msg: failed to register misc device: %d\n", ret);
        return ret;
    }

    pr_info("udp_msg: loaded, write to /dev/%s to send a message\n", DEVICE_NAME);
    return 0;
}

static void __exit udp_msg_exit(void)
{
    misc_deregister(&udp_msg_dev);
    pr_info("udp_msg: unloaded\n");
}

module_init(udp_msg_init);
module_exit(udp_msg_exit);

MODULE_LICENSE("GPL");
