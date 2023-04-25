#include <linux/module.h>
#include <linux/fs.h>
#include <asm/io.h>
#include <linux/moduleparam.h>
#define NOD_MAJOR 100
#define NOD_NAME "nobrand"

MODULE_LICENSE("GPL");
static int val=100;
module_param(val,int, S_IRUGO);
//sudo insmod nobrand.ko val=199 
//이렇게 insmod 시에 값을 넣어줄 수 있음
//모듈 파라미터는 사용자가 커널 모듈의 동작을 변경가능! -> 보안취약
//따라서 모듈 파라미터는 권한이 있는 사용자에게만 변경할 수 있도록
//제한하는게 권장됨

static volatile uint32_t *BASE;
static volatile uint32_t *GPFSEL1;
static volatile uint32_t *GPSET0;
static volatile uint32_t *GPCLR0;

static volatile uint32_t *GPFSEL0;
static volatile uint32_t *GPIO_PUP_REG0;
static volatile uint32_t *GPLEV0;

static int nobrand_open(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "welcome\n");
    return 0;
}

static int nobrand_release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "release\n");
    return 0;
}

static long nobrand_ioctl(struct file *filp, unsigned int cmd, unsigned long arg){
	
	return 0;
}

static struct file_operations fops = {
    .open = nobrand_open,
    .release = nobrand_release,
	.unlocked_ioctl = nobrand_ioctl,
};

static int nobrand_init(void)
{
	
    if (register_chrdev(NOD_MAJOR, NOD_NAME, &fops) < 0)
    {
        printk("INIT FALE\n");
    }

    printk(KERN_INFO "hi sum=%d\n",val);
    return 0;
}

static void nobrand_exit(void)
{
	
  	iounmap(BASE);

	unregister_chrdev(NOD_MAJOR, NOD_NAME);
    printk(KERN_INFO "bye\n");
}

module_init(nobrand_init);
module_exit(nobrand_exit);
