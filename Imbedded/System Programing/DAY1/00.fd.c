#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    //vim 에서 open에 숫자 2+shift+K 하면 정보 나옴..필요한 라이브러리 등
    //숫자 1 : Linux Shell Command, 2 : System Call, 3 : Linux Library
    int fd=open("./test.txt",O_RDONLY,0);
    // File Decriptor : 한 프로그램이 파일에 접근하려고 할 때, 부여되는 정수를 뜻함
    //한 감옥에서 죄수들의 번호를 부여하는 것처럼 한 프로그램에 사용되는 파일에게
    //번호를 부여하는 것이다.
    
    //open는 error가 잦다, fd는 항상 정수인데 음수값일 대는 Error을 뜻한다
    if(fd<0){
        //매크로
        //__FILE__ : 에러 file 이름
        //__LINE__ : dpfj line 번호
        printf("[%s :: %d] FILE OPEN ERROR\n",__FILE__,__LINE__);
        exit(1);
        //exit(0) : return 값 0, 정상 종류
        //exit(1) : return 값 1, 오류로 인한 종료
    }

    // int open(path,flag,mode);
    // flag 필수 옵션
    // O_RDONLY : 읽기만
    // O_WRONLY : 쓰기만
    // O_RDWR -> 이걸로 사용해서 read만 수행해도 됨, 읽기+쓰기
    // flag 추가옵션 ex) open(path, O_WRONLY | O_TRUNC, 0644);
    // O_CREAT : 없으면 새로 생성
    // O_APPEND : 덧붙이기
    // O_TRUNC : 파일 내용 제거 후 사용

    // mode -> 사실상 읽고 쓸때는 의미없음.. Create 할때만 해당 권한으로 만든다는 것임
    // Create 할 때 파일 권한, 0xxx 값을 넣으면 된다(8진수)
    // 0777 : rwxrwxrwx, 0644 : rw-r--r--
    // Open할 때 파일 권한은 없어도 됨.


    char buf[1000]={0};
    //널문자를 고려하여 999칸을 읽는다.
    read(fd,buf,1000-1);
    printf("%s\n",buf);
    close(fd);
    return 0;
}
