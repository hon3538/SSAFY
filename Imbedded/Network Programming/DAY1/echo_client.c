#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

const char *IP = "127.0.0.1"; // 접속할 서버의 IP 주소
const char *PORT = "12345"; // 접속할 서버의 포트 번호

int sock; // 소켓 디스크립터

// Ctrl + C 인터럽트 핸들러
void interrupt(int arg)
{
    printf("\nYou typped Ctrl + C\n"); // 사용자가 Ctrl + C를 입력했을 때 출력될 메시지
    printf("Bye\n"); // 프로그램 종료 메시지

    close(sock); // 소켓 연결 종료
    exit(1); // 프로그램 종료
}

int main()
{
    // Ctrl + C 인터럽트 핸들러 설정
    signal(SIGINT, interrupt);

    // 소켓 생성
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("ERROR :: 1_Socket Create Error\n"); // 소켓 생성 오류 메시지 출력
        exit(1); // 프로그램 종료
    }

    // 서버 정보 설정
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET; // IPv4 주소 체계 사용
    //inet_addr() 도 빅엔디안으로 만들어주는 함수인데 htonl() 과 다른점은 string으로 입력을 받는 다는 것이다
    //IP가 현재 string 이기 때문에 string -> 빅엔디안 int, 
    addr.sin_addr.s_addr = inet_addr(IP); // 접속할 서버의 IP 주소 설정
    addr.sin_port = htons(atoi(PORT)); // 접속할 서버의 포트 번호 설정

    // 서버에 연결
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        printf("ERROR :: 2_Connect Error\n"); // 서버 연결 오류 메시지 출력
        exit(1); // 프로그램 종료
    }

    char buf[100];
    while (1)
    {
        memset(buf, 0, 100); // 버퍼 초기화
        scanf("%s", buf); // 키보드 입력 받기
        if (!strcmp(buf, "exit")) // 사용자가 'exit'를 입력했을 경우
        {
            write(sock, buf, strlen(buf)); // 서버에 'exit' 메시지 전송
            break; // 무한 루프 탈출
        }
        write(sock, buf, strlen(buf)); // 서버에 입력한 메시지 전송
        memset(buf, 0, 100); // 버퍼 초기화
        int len = read(sock, buf, 99); // 서버에서 받은 응답 읽기
        if (len == 0) // 서버와의 연결이 끊어졌을 경우
        {
            printf("INFO :: Server Disconnected\n"); // 서버 연결 끊김 메시지 출력
            break; // 무한 루프 탈출
        }
        printf("%s\n", buf); // 서버에서 받은 응답 출력
    }

    close(sock); // 소켓 연결 종료
    return 0