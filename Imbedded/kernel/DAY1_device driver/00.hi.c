// Device Driver 특징
// main 함수가 없다
// 라이센스 설정

#include <linux/module.h>

MODULE_LICENSE("GPL")

// 권장사항
// 커널 내부 모듈끼리 함수 중복을 피하기 위해 함수명을 모듈 이름_역할 형태로 사용
// 모든 함수에 static을 붙이기
static int hi_init(void){
    printk( KERN_INFO "OK HELLO KFC\n");
    return 0;
}
static void hi_exit(void){
    printk( KERN_INFO "BYE BYE\n\n");
}
//device driver(.ko) 적재시에 동작
module_init(hi_init);

//device driver(.ko) 해제시에 동작
module_exit(hi_exit);

//kernel log로 동작상태 파악
//dmesg : 최근 커널로그 출력
//dmesg -w : 커널로그 모니터링
//module_init, module_exit 시 실행되는 내용이 커널 로그에 출력된다