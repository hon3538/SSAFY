#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define NOD_MAJOR 100
#define NOD_NAME "nobrand"

MODULE_LICENSE("GPL");

static int nobrand_open(struct inode *inode, struct file *filp){
    printk( KERN_INFO "welcome\n");
    return 0;
}

static int nobrand_release(struct inode *inode, struct file *filp){
    printk( KERN_INFO "release\n");
    return 0;
}
static ssize_t nobrand_read(struct file *filp, char *buf, size_t count, loff_t *ppros){
    buf[0]='H';
    buf[1]='I';
    buf[2]='\0';
    return count;
}
static ssize_t nobrand_write(struct file *flip, const char *buf, size_t count, loff_t *ppos){
    printk( KERN_INFO "app msg : %s\n", buf);
    return count;
}
static long nobrand_ioctl(struct file *filp, unsigned int cmd, unsigned long arg){
    printk(KERN_ALERT "command number : %d\n",cmd);

    struct Node t;
    char buf[30];
    int ret;
    void *p=(void*)(arg);
    switch (cmd){
        case _IO(0,3):
            printk(KERN_INFO "Copy from user struct!");
            ret= copy_from_user(&(t.n), (void*)arg,1);
            ret=copy_from_user(t.buf, (void*)(arg+1),100);
            printk(KERN_ALERT "struct n : %d",t.n);
            printk(KERN_ALERT "struct buf : %s",t.buf);
            break;
    }   
    return 0;
}

static struct file_operations fops={
    .open = nobrand_open,
    .release = nobrand_release,
    .read =nobrand_read,
    .write=nobrand_write,
    .unlocked_ioctl = nobrand_ioctl,
};

static int nobrand_init(void){
    if(register_chrdev(NOD_MAJOR, NOD_NAME, &fops)<0){
        printk( KERN_INFO "INIT FAIL\n");
    }   
    printk( KERN_INFO "hi\n");
    return 0;
}

static void nobrand_exit(void){
    unregister_chrdev(NOD_MAJOR,NOD_NAME);
    printk( KERN_INFO "bye\n");
}
module_init(nobrand_init);
module_exit(nobrand_exit);
~                             