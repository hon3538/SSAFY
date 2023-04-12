#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

//나중엔 main argument로 받아서 사용하기
const char *PORT = "12345"; //어떤 포트(주소)로 열지

//file descriptor
int server_sock;
int client_sock;

void interrupt(int arg)
{
	printf("\nYou typed Ctrl + C\n");
	printf("Bye\n");

	close(client_sock);
	close(server_sock);
	exit(1);
}

void removeEnterChar(char *buf)
{
	int len = strlen(buf);
	for (int i = len - 1; i >= 0; i--)
	{
		if (buf[i] == '\n')
			buf[i] = '\0';
		break;
	}
}

int main(int argc,char *argv) //port를 입력받는다
{
	//signal -> ctrl+c 인터럽트
	//SIGINT 는 키보드에서 오는 interrupt를 의미한다
	signal(SIGINT, interrupt);

    //int socket(int domain, int type, int protocol);  //생성 실패하면 -1 리턴, 성공시 fd 리턴
    //*fd란? file descriptor의 약자로 시스템(OS)이 특정 파일에 할당해준 정수값을 의미한다.
    //파일뿐아니라, 소켓과 같은 자원도 가지고 있는 값이다.
    //이 숫자를 해당 자원에 대한 접근 지정자처럼 사용되므로 보다 편하게 원하는 파일에 접근이 가능하다

    //domain : Protocol Family를 지정, PF_INET은 인터넷 IP 포로토콜 체계이다
    //사용하는 프로토콜 체계는 여러가지가 있지만 IP를 사용할 것이기 때문에 PF_INET만 사용한다
    //type : 소켓의 타입, 보편적으로 Stream과 Datagram을 사용, SOCK_STREAM은 연결형(TCP), SOCK_DGRAM은 비연결형(UDP)이라고 생각하면 된다
    //protocol : 프로토콜로, 일반적으로 0을 넣어주면 시스템이 자동으로 설정해준다
	server_sock = socket(PF_INET, SOCK_STREAM, 0); // IPv4 TCP/IP 소켓
	if (server_sock == -1)
	{
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}
    //int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
    //소켓 세부 사항을 확인하는 함수
    //int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
    //소켓 세부 사항을 설정하는 함수

    //1.sockfd : 옵션을 설정할 소켓의 fd
    //2.level : 확인(get)또는 변경/설정(set)할 옵션의 프로토콜 레벨 전달
    //-SOL_SOCKET : optname 이 socket level 에서 설정하는 option명임을 지정함
    //-IPPROTO_IP : optname 이 IP protocol level에서 설정하는 option 명임을 지정함
    //-IPPROTO_TCP : optname 이 TCP protocol level에서 설정하는 option명임을 지정함

    //3.optname : 확인 또는 변경할 옵션의 이름 전달
    //-SO_REUSEADDR : 이미 사용중인 주소나 포트에 대해서도 바인드 허용
    //4.optval : 확인결과 저장 버퍼 or optname에 따른 설정할 값
    //5.optlen : 버퍼 크기
	int optval = 1;
	setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (void *)&optval, sizeof(optval));


    //int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    /*struct sockaddr {
        sa_family_t sa_family;
        char sa_data[14];
    }*/
    //socket을 생성해서 얻은 fd를 이용하여 소켓에 주소를 부여해야한다. bind가 소켓에 주소를 부여하는 기능을 수행한다.
    //그러면 이후에 connet()와 accept() 함수는 연결을 설정하는 과정에서 바인드된 주소를 사용한다
    //socket: 전화기, sockaddr : 전화번호

    //주소 정보 초기화
    //sin_family : IP용 Address Family인 AF_INET을 지정
    //sin_port : a사용할 포트 지정
    //sin_addr.s_addr : 주소를 지정, 0이면 현재 컴퓨터의 주소를 자동으로 채운다
    
	struct sockaddr_in server_addr = {0};
	server_addr.sin_family = AF_INET;
	//INADDR_ANY 는 서버의 IP주소를 자동으로 찾아서 대입해주는 함수(long 형)
	//IP주소를 INADDR_ANY, PORT가 9000일 경우 -> 현재 서버 컴퓨터의 9000번 포트를 목적지로 하는 모든
	//연결 요청에 대해 해당 서버 응용 프로그램에서 처리하겠다는 의미이다.
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(PORT));
    //*htons? host-to-network short 
    //16비트 정수를 호스트 바이트 순서에서 네트워크 바이트 순서로 변환하는 함수이다. (리틀엔디언->빅엔디언)
    //AF_INET(IP 주소체계) 소켓 주소 구조체에서 사용되는 포트 번호와 IP주소는 빅엔디언을 따른다.
    //x86에서 사용되는 리틀 엔디언과는 반대의 표기법이다. 따라서 변함없이 그래돌 사용하게되면
    //바이트 순서가 달라지게 되어 제대로 동작하지 않는다
    
    //두번째 인자에서 sockaddr_in에서 (struct sockaddr*)으로 형변환 하는 이유?
    //bind는 TCP/IP 뿐만 아니라 다양한 프로토콜이 존재하기 때문에, 인자로 받아야할 구조체 형이 
    //sockarr_in 뿐만이 아니다. 따라서 여러 프로토콜에서 들어오는 정보를 다 받을 수 있도록
    //일반화된 구조체가 sockaddr 이다. sockaddr_in은 sockaddr와 크기가 같기 때문에 형변환 할 수 있다
    
    //sockaddr = AF(2바이트) + sa_data(14바이트)
    //sockaddr_in = AF(2바이트) + port(2바이트) + IP addr(4바이트) + optional(8바이트)
    //->sockaddr의 sa_data에 port, IP 등을 바로 집어넣기 불편하므로 일단 sockaddr_in에 넣고 형변환해주는 방식을 사용한다

	if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("ERROR :: 2_bind Error\n");
		exit(1);
	}


    //int listen(int sockfd, int backlog );
    //backlog : 연결 요청 대기 큐(Queue)의 크기정보 전달
    //5가 전달되면 큐의 크기가 5가 되어서 클라이언트의 연결요청을 5개까지 대기시킬 수 있다.
    //비연결형 서비스는 이 함수를 사용하지 않고, 연결형 서비스에서만 사용한다.
	if (listen(server_sock, 5) == -1)
	{
		printf("ERROR :: 3_listen Error");
		exit(1);
	}

    //클라이언트 소켓을 받을 버퍼를 초기화한다.
	client_sock = 0;
	struct sockaddr_in client_addr = {0};
	socklen_t client_addr_len = sizeof(client_addr);

	//server socket안에 클라이언트 socket을 만들기 때문에 2중 반복문 사용

	while (1)
	{
		memset(&client_addr, 0, sizeof(client_addr));

        //int accept(int sockfd,struct sockaddr *addr, socklen_t *addrlen);
        //addr : 클라이언트 주소정보를 저장할 버퍼
        //addrlen: addr에 전달된 주소의 변수 크기를 바이트 단위로 전달

        //listen으로 받은 "연결 요청 대기 큐"에 대기중인 클라이언트 연결요청(connect)을 수락하는 기능의 함수
        //호출 성공시 내부적으로 데이터 입출력에 사용할 소켓을 생성하고 그 소켓의 fd를 반환한다.
        //자동으로 소켓이 생성되고, 연결 요청을 한 클라이언트 소켓에 연결까지 이뤄진다는 것이다.
        //클라이언트 요청 ->서버 listen->서버 대기큐 ->서버 accept ->서버에서 소켓생성 -> 클라이언트 소켓과 연걸
		client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
		if (client_sock == -1)
		{
			printf("ERROR :: 4_accept Error\n");
			break;
		}

		char buf[100];
		while (1)
		{

            //ssize_t read(int fd,void *buf,size_t count);
            //buf : 읽어들인 데이터가 저장될 버퍼 변수
            //count : 읽어들일 데이터의 count 크기

			memset(buf, 0, 100);
			//read 했는데 0일때 = client가 종료됐을 때
			int len = read(client_sock, buf, 99);

            //엔터 없애는 함수... 해당하는 요청에 따른 result를 buf에 담아서 나중에 write로 쓰면
            //클라이언트에서 내용을 받는다
			removeEnterChar(buf);

			if (len == 0) //len은 안전한 종료를 위해 받아준것이다
			{
				printf("INFO :: Disconnect with client... BYE\n");
				break;
			}

			if (!strcmp("exit", buf))
			{
				printf("INFO :: Client want close... BYE\n");
				break;
			}
			write(client_sock, buf, strlen(buf));
		}
		close(client_sock);
	}
	close(server_sock);
	return 0;
}
