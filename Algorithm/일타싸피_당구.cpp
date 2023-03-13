#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winSock2.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#pragma warning(disable : 4996)
#pragma comment(lib, "ws2_32.lib")

// 닉네임을 사용자에 맞게 변경해 주세요.
#define NICKNAME "SEOUL21_HONGEUISEON"

// 일타싸피 프로그램을 로컬에서 실행할 경우 변경하지 않습니다.
#define HOST "127.0.0.1"

// 일타싸피 프로그램과 통신할 때 사용하는 코드값으로 변경하지 않습니다.
#define PORT 1447
#define CODE_SEND 9901
#define CODE_REQUEST 9902
#define SIGNAL_ORDER 9908
#define SIGNAL_CLOSE 9909

struct HOLE {
	int y, x;
	double dit;
	bool operator < (HOLE o) const {
		return dit > o.dit;
	}
};
void ErrorHandling(const char *message);
float getAngle(float start_y, float start_x, float target_y, float target_x);
double getDit(float start_y, float start_x, float target_y, float target_x);
void setPosition(float ball_y, float ball_x, float hole_y, float hole_x);
int isValid(int w_y, int w_x, int t_y, int t_x, int h_y, int h_x);
float Y = 0;
float X = 0;
int main()
{
	// 게임 환경에 대한 상수입니다.
	int TABLE_WIDTH = 254;
	int TABLE_HEIGHT = 127;
	int NUMBER_OF_BALLS = 6;
	int HOLES[6][2] = { {0, 0}, {127, 0}, {254, 0}, {0, 127}, {127, 127}, {254, 127} };

	float balls[6][2] = {
		0.0f,
	};
	int order = 0;

	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN sockAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup failure.");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	if (hSocket == INVALID_SOCKET)
		ErrorHandling("Socket Creating Failure.");

	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = inet_addr(HOST);
	sockAddr.sin_port = htons(PORT);

	printf("Trying Connect: %s:%d\n", HOST, PORT);
	if (connect(hSocket, (SOCKADDR *)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
		ErrorHandling("Connection Failure.");
	else
		printf("Connected: %s:%d\n", HOST, PORT);

	char sendData[1024];

	sprintf(sendData, "%d/%s/", CODE_SEND, NICKNAME);
	send(hSocket, (char *)&sendData, sizeof(sendData), 0);
	printf("Ready to play!\n--------------------");

	while (1)
	{
		// Receive Data
		char message[1024];
		int strLen;
		int recvCount = 0;
		strLen = recv(hSocket, message, sizeof(message) - 1, 0);
		// printf("Data Received: %s\n", message);

		// Read Game Data
		char *recvData;
		recvData = strtok(message, "/");
		float pos = atof(recvData);

		recvCount++;

		for (int i = 0; i < NUMBER_OF_BALLS; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				balls[i][j] = pos;
				recvData = strtok(NULL, "/");

				if (recvData != NULL)
				{
					pos = atof(recvData);

					recvCount++;
				}
			}
		}

		// Check Signal for Player Order or Close Connection
		if (balls[0][0] == SIGNAL_ORDER)
		{
			order = (int)balls[0][1];
			printf("\n\n* You will be the %s player. *\n\n", order == 1 ? "first" : "second");
			continue;
		}
		else if (balls[0][0] == SIGNAL_CLOSE)
		{
			break;
		}

		// Show Balls' Position
		for (int i = 0; i < NUMBER_OF_BALLS; i++)
		{
			printf("ball %d: %f, %f\n", i, balls[i][0], balls[i][1]);
		}

		float angle = 0.0f;
		float power = 0.0f;

		//////////////////////////////
		// 이 위는 일타싸피와 통신하여 데이터를 주고 받기 위해 작성된 부분이므로 수정하면 안됩니다.
		//
		// 모든 수신값은 변수, 배열에서 확인할 수 있습니다.
		//   - order: 1인 경우 선공, 2인 경우 후공을 의미, 선공 1,3,8 / 후공 2,4,8
		//   - balls[][]: 일타싸피 정보를 수신해서 각 공의 좌표를 배열로 저장
		//     예) balls[0][0]: 흰 공의 X좌표
		//         balls[0][1]: 흰 공의 Y좌표
		//         balls[1][0]: 1번 공의 X좌표
		//         balls[4][0]: 4번 공의 X좌표
		//         balls[5][0]: 마지막 번호(8번) 공의 X좌표

		// 여기서부터 코드를 작성하세요.
		// 아래에 있는 것은 샘플로 작성된 코드이므로 자유롭게 변경할 수 있습니다.

		//설계 
		//현재 흰공에서 칠 수 있는 모든 공을 확인
		//만약 target이 홀 좌표에 있다면 넘어가
		//흰공과 목적구 사이 거리
		int orderTarget[2][3] = { {1,3,5},{2,4,5} };
		HOLE now;
		int YY = -1, XX = -1;
		for (int i = 0; i < 3; i++) { // 공 3개
			int targetNum = orderTarget[order - 1][i];
			float target_y = balls[targetNum][1];
			float target_x = balls[targetNum][0];
			if (target_y == -1 && target_x == -1) continue; //이미 홀에 들어갔으면
			// distance: 두 점(좌표) 사이의 거리를 계산
			double distance = getDit(balls[0][1], balls[0][0], target_y, target_x);
			//시작볼과 끝볼의 angle 계산
			angle = getAngle(balls[0][1], balls[0][0], target_y, target_x);
			//printf("ball %d: %f, %f\n", i, balls[i][0], balls[i][1]);
			printf("angle: %f\n", angle);


			//해당 목적구에 가장 가까운 hole부터 찾고
			//목적구와 hole 각도 계산 후, 내 볼을 보낼 위치 찾음
			//현재 내볼과 보낼 위치 각도를 구하고 치면됨
			//단 목적구가 홀로 가는 경로와 내볼을 보낼 위치까지 경로에 다른게 있으면 x
			//또한 내가 보낼 위치가 불가능하면(테이블과 겹치거나 벗어나면) x
			priority_queue<HOLE>pq;
			for (int j = 0; j < 6; j++) {
				pq.push({ HOLES[j][1],HOLES[j][0],getDit(target_y,target_x,(float)HOLES[j][1],(float)HOLES[j][0]) });
				//printf("Y: %d X: %d\n", HOLES[j][1], HOLES[j][0]);
				//printf("HOLES Y:%d X:%d dit: %f \n", HOLES[j][1], HOLES[j][0], pq.top().dit);
			}
			//목적구와 hole 각도 계산 후, 내 볼을 보낼 위치 찾음
			while (!pq.empty()) {
				now = pq.top();
				pq.pop();
				//printf("Y: %d X: %d\n", now.y, now.x);
				//int angToHole = getAngle(target_y, target_x, now.y, now.x);
				setPosition(target_y, target_x, now.y, now.x);
				//Y,X 가 세팅됨
				//printf("Y: %f X: %f\n", Y, X);

				if (isValid(balls[0][1], balls[0][0], Y, X, now.y, now.x) == 0) {
					continue;
				}
				YY = Y;
				XX = X;
				printf("targetNum:%d Hole_Y,X:(%d,%d) target_Y,X:(%f,%f) Position_Y,X:(%f,%f)\n", targetNum, now.y, now.x, target_y, target_x, Y, X);

			}
			break;
		}
		if (YY != -1 && XX != -1) {
			angle = getAngle(balls[0][1], balls[0][0], YY, XX);
		}
		else {
			angle = getAngle(balls[0][1], balls[0][0], Y, X);
		}
		double retDit1 = getDit(balls[0][1], balls[0][0], Y, X);
		double retDit2 = getDit(Y, X, now.y, now.x);
		// power: 거리 distance에 따른 힘의 세기를 계산
		power = (float)(retDit1 + retDit2) * 0.5f;


		// 주어진 데이터(공의 좌표)를 활용하여 두 개의 값을 최종 결정하고 나면,
		// 나머지 코드에서 일타싸피로 값을 보내 자동으로 플레이를 진행하게 합니다.
		//   - angle: 흰 공을 때려서 보낼 방향(각도)
		//   - power: 흰 공을 때릴 힘의 세기
		// 
		// 이 때 주의할 점은 power는 100을 초과할 수 없으며,
		// power = 0인 경우 힘이 제로(0)이므로 아무런 반응이 나타나지 않습니다.
		//
		// 아래는 일타싸피와 통신하는 나머지 부분이므로 수정하면 안됩니다.
		//////////////////////////////

		char mergedData[1024];
		sprintf(mergedData, "%f/%f/", angle, power);
		send(hSocket, (char *)&mergedData, sizeof(mergedData), 0);
		printf("Data Sent: %s\n", mergedData);
	}

	closesocket(hSocket);
	WSACleanup();

	return 0;
}

void ErrorHandling(const char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
float getAngle(float start_y, float start_x, float target_y, float target_x) {
	float ang;
	// whiteBall_x, whiteBall_y: 흰 공의 X, Y좌표를 나타내기 위해 사용한 변수
	float whiteBall_x = start_x;
	float whiteBall_y = start_y;

	// targetBall_x, targetBall_y: 목적구의 X, Y좌표를 나타내기 위해 사용한 변수
	float targetBall_x = target_x;
	float targetBall_y = target_y;

	// width, height: 목적구와 흰 공의 X좌표 간의 거리, Y좌표 간의 거리
	float width = fabsf(targetBall_x - whiteBall_x);
	float height = fabsf(targetBall_y - whiteBall_y);

	// radian: width와 height를 두 변으로 하는 직각삼각형의 각도를 구한 결과
	//   - 1radian = 180 / PI (도)
	//   - 1도 = PI / 180 (radian)
	// angle : 아크탄젠트로 얻은 각도 radian을 degree로 환산한 결과
	double radian = height > 0 ? atan(width / height) : 0;
	ang = (float)((180 / M_PI) * radian);

	// 목적구가 상하좌우로 일직선상에 위치했을 때 각도 입력
	if (whiteBall_x == targetBall_x)
	{
		if (whiteBall_y < targetBall_y)
		{
			ang = 0; //target이 위에 있을때 0도, 시계방향으로 증가
		}
		else
		{
			ang = 180;
		}
	}
	else if (whiteBall_y == targetBall_y)
	{
		if (whiteBall_x < targetBall_x)
		{
			ang = 90; //target이 오른쪽에 있을경우
		}
		else
		{
			ang = 270; // target이 왼쪽에 있을경우
		}
	}

	// 목적구가 흰 공을 중심으로 3사분면에 위치했을 때 각도를 재계산
	if (whiteBall_x > targetBall_x && whiteBall_y > targetBall_y)
	{
		radian = atan(width / height);
		ang = (float)(((180 / M_PI) * radian) + 180);
	}
	// 목적구가 흰 공을 중심으로 4사분면에 위치했을 때 각도를 재계산
	else if (whiteBall_x < targetBall_x && whiteBall_y > targetBall_y)
	{
		radian = atan(height / width);
		ang = (float)(((180 / M_PI) * radian) + 90);
	}
	return ang;
}
double getDit(float start_y, float start_x, float target_y, float target_x) {
	float width = fabsf(target_x - start_x);
	float height = fabsf(target_y - start_y);
	double distance = (double)sqrt((width * width) + (height * height));
	return distance;
}
void setPosition(float ball_y, float ball_x, float hole_y, float hole_x) {
	//동서남북
	float ang = getAngle(ball_y, ball_x, hole_y, hole_x);
	//printf("ang: %f\n", ang);
	float temp = ang;
	while (temp > 90) { temp -= 90; }

	//printf("temp: %f\n", temp);
	float cosValue = 5.73 * cos((float)temp*(M_PI) / 180);
	float sinValue = 5.73 * sin((float)temp*(M_PI) / 180);
	//printf("COS: %f SIN: %f\n", cosValue, sinValue);
	if (ang == 0) { //홀이 북쪽
		Y = ball_y - 5.73;
		X = ball_x;
	}
	else if (ang == 180) { // 홀이 남쪽
		Y = ball_y + 5.73;
		X = ball_x;
	}
	else if (ang == 90) { // 홀이 동쪽
		Y = ball_y;
		X = ball_x - 5.73;
	}
	else if (ang == 270) { //홀이 서쪽
		Y = ball_y;
		X = ball_x + 5.73;
	}
	else if (ang > 0 && ang < 90) { //1사분면
		Y = ball_y - cosValue;
		X = ball_x - sinValue;
	}
	else if (ang > 90 && ang < 180) { //4
		Y = ball_y + sinValue;
		X = ball_x - cosValue;
	}
	else if (ang > 180 && ang < 270) {
		Y = ball_y + cosValue;
		X = ball_x + sinValue;
	}
	else if (ang > 270 && ang < 360) {
		Y = ball_y - sinValue;
		X = ball_x + cosValue;
	}
}
int isValid(int w_y, int w_x, int t_y, int t_x, int h_y, int h_x) { //예각일때 불가능
	//#1 target과 홀 각도
	int ang1 = getAngle(t_y, t_x, h_y, h_x);
	//#2 target과 흰공 각도
	int ang2 = getAngle(t_y, t_x, w_y, w_x);
	int gap = abs(ang1 - ang2);
	if (gap < 95) {
		return 0;
	}
	return 1;
}