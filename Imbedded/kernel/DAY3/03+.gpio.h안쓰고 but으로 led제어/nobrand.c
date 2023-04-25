#include <linux/module.h>
#define NOD_MAJOR 100
#define NOD_NAME "nobrand"

MODULE_LICENSE("GPL");

static volatile uint32_t *BASE;
static volatile uint32_t *GPFSEL0;
static volatile uint32_t *GPFSEL1;
static volatile uint32_t *GPSET0;
static volatile uint32_t *GPSET1;
static volatile uint32_t *GPCLR0;
static volatile uint32_t *GPCLR1;
static volatile uint32_t *GPLEV0;
static volatile uint32_t *GPIO_PUP_PDN_CNTRL_REG0;
statuc v
//led 18, 23
//btn 2, 17


static nobrand_init(void){
	if(register_chrdev(NOD_MAJOR, NOD_NAME, &fops)<0){
		printk("INIT FAIL\n");

	}else
		printk( KERN_INFO,"init!!\n");
}

static nobrand_exit(void){
	
	unregister_chrdev(NOD_MAJOR, NOD_NAME);
	printk( KERN_INFO,"bye!!\n");
}

module_init(nobrand_init);
module_exit(nobrand_exit);
