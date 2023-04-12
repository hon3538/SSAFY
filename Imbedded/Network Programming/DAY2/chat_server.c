#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

//접속한 클라이언트 수
#define MAX_CLIENT_CNT 500

const char *PORT = "12345";
int server_sock; //안내원 1명

//창구 직원 500명

int client_sock[MAX_CLIENT_CNT];
struct sockaddr_in client_addr[MAX_CLIENT_CNT];

pthread_t tid[MAX_CLIENT_CNT];
int exitFlag[MAX_CLIENT_CNT];

// mutex 선언
pthread_mutex_t mutx;

//서버 종료 -> 창구 직원 500명 퇴근 -> 창구 직원 1명 1명당 쓰레드
void interrupt(int arg)
{
	printf("\nYou typed Ctrl + C\n");
	printf("Bye\n");

	//작동 중인 모든 Thread 종료 및 소켓 종료
	for (int i = 0; i < MAX_CLIENT_CNT; i++)
	{
		if (client_sock[i] != 0) //아직 퇴근 안 한 창구직원들 퇴근하자
		{
			pthread_cancel(tid[i]);
			pthread_join(tid[i], 0);
			close(client_sock[i]);
		}
	}
	//서버 소켓 종료
	close(server_sock);
	exit(1);
}

//똑같다.
void removeEnterChar(char *buf)
{
	int len = strlen(buf);
	for (int i = len - 1; i >= 0; i--)
	{
		if (buf[i] == '\n') {
			buf[i] = '\0';
			break;
		}
	}
}

int getClientID()
{
	for (int i = 0; i < MAX_CLIENT_CNT; i++)
	{
		if (client_sock[i] == 0)
			return i;
	}
	return -1;// 500명 다 참
}

void *client_handler(void *arg) //id 쓰레드 별 아이디 -> 쓰레드를 종료시키는 용도
{
	int id = *(int *)arg;

	char name[100];
	// inet_ntoa 는,빅 엔디안  long int ip 를 문자열로 바꿈
	strcpy(name, inet_ntoa(client_addr[id].sin_addr));
	printf("INFO :: Connect new Client (ID : %d, IP : %s)\n", id, name);

	// wait & write
	char buf[100];
	while (1)	{

		//초기화
		memset(buf, 0, 100);
		//메시지 읽어

		//종료 옵션 똑같다.
		int len = read(client_sock[id], buf, 99);
		if (len == 0)		{
			printf("INFO :: Disconnect with client.. BYE\n");
			exitFlag[id] = 1;
			break;
		}

		//종료 옵션 똑같다.
		if (!strcmp("exit", buf))		{
			printf("INFO :: Client want close.. BYE\n");
			exitFlag[id] = 1;
			break;
		}

		// remove '\n'
		removeEnterChar(buf);

		// send new message
		// mutex
		pthread_mutex_lock(&mutx);

		//
		//접속한 클라이언트 전부에게 메시지 전송 ,,브로드 캐스팅 ->  접속한 클라이언트 전부에게 메시지를 쏜다.
		for (int i = 0; i < MAX_CLIENT_CNT; i++)
		{
			if (client_sock[i] != 0)
			{
				write(client_sock[i], buf, strlen(buf));
			}
		}
		pthread_mutex_unlock(&mutx);
	}
	//exit or ctrl + C 와 같은 클라이언트 소켓이 종료되면, 서버 내 클라이언트 소켓을 종료시킨다.
	close(client_sock[id]);
}

int main()
{
	// Ctrl + C 누를 경우 안전종료
	signal(SIGINT, interrupt);

	// mutex init
	pthread_mutex_init(&mutx, NULL);

	// socket create 똑같다. -> 은행 문 열었다.
	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (server_sock == -1)
	{
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}

	// option setting 똑같다.
	// 종료 시 3분 정도 동일한 포트 배정 불가 에러 해결
	int optval = 1;
	setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (void *)&optval, sizeof(optval));

	// 주소 설정 똑같다.
	struct sockaddr_in server_addr = {0};
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(PORT));

	// bind 똑같다.
	if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("ERROR :: 2_bind Error\n");
		exit(1);
	}

	// listen 똑같다.
	if (listen(server_sock, 5) == -1)
	{
		printf("ERROR :: 3_listen Error");
		exit(1);
	}

	socklen_t client_addr_len = sizeof(struct sockaddr_in);

	// pthread argument bug fix
	int id_table[MAX_CLIENT_CNT]; //창구직원 별 ( thread 별로 ) id 부여
	printf("Wait for next client...\n");

	//기다리죠. 문열었다.
	while (1)
	{
		// get Client ID
		int id = getClientID();
		id_table[id] = id;

		if (id == -1)
		{
			printf("WARNING :: Client FULL\n");
			sleep(1);
		}

		// 새로운 클라이언트를 위해 초기화 똑같다.
		memset(&client_addr[id], 0, sizeof(struct sockaddr_in));

		// accpet 똑같다.
		client_sock[id] = accept(server_sock, (struct sockaddr *)&client_addr[id], &client_addr_len);
		if (client_sock[id] == -1)
		{
			printf("ERROR :: 4_accept Error\n");
			break;
		}

		// Create Thread
		pthread_create(&tid[id], NULL, client_handler, (void *)&id_table[id]);

		// check ExitFlag
		for (int i = 0; i < MAX_CLIENT_CNT; i++)
		{
			if (exitFlag[i] == 1)
			{
				exitFlag[i] = 0;
				pthread_join(tid[i], 0);
				client_sock[i] = 0;
			}
		}
	}
	// 서버 소켓 close 똑같다.
	close(server_sock);
	return 0;
}
