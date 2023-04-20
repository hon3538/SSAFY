#include <linux/module.h>
#include <linux/fs.h>
// file system 헤더를 가지고 온 이유
// device file을 사용하기 위함 (open write read close)

// /dev/ 에 만든 nobrand 장치 파일의 정보
#define NOD_MAJOR 100
#define NOD_NAME "nobrand"

MODULE_LICENSE("GPL");

//int fd = open("/dev/nobrand", O_RDWR);
static int nobrand_open(struct inode *inode, struct file *filp){
    printk( KERN_INFO "welcome\n");
    return 0;
}
// close(fd) 하면 실행 ㅋ
static int nobrand_release(struct inode *inode, struct file *filp){
    printk( KERN_INFO "release\n\n");
    return 0;
}
static struct file_operations fops={
    //open
    .open = nobrand_open,
    .release = nobrand_release,
};
static int nobrand_init(void){
    //
    if(register_chrdev(NOD_MAJOR, NOD_NAME, &fops)<0){
        printk( KERN_INFO "INIT FAIL\n");
    }
    printk( KERN_INFO "hi\n");
    return 0;
}

static void nobrand_exit(void){
    unregister_chrdev(NOD_MAJOR, NOD_NAME);
    printk( KERN_INFO "bye\n\n");
}

module_init(nobrand_init);
module_exit(nobrand_exit);
//module_open(nobrand_open);
//module_release(nobrand_release);
