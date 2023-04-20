KERNEL_HEADER=/lib/modules/$(shell uname -r)/build
CC = gcc

TARGET := app
obj-m := nobrand.o

all : driver app

driver:
    make -C $(KERNEL_HEADER) M=$(PWD) modules

app:
    make -o $@ ./app/$@.c

clean:
    make -C $(KERNEL_HEADER) M=$(PWD) clean
    rm -f *.o $(TARGET)
	
static int nobrand_open(struct inode *inode, struct file *filp){
    printk( KERN_INFO "welcome\n");
    return 0;
}

static int nobrand_release(struct inode *inode, struct file *filp){
    printk( KERN_INFO "release\n\n");
    return 0;
}
