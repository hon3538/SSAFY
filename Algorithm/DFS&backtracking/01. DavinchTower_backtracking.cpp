#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

int h, w;
int** v;
//level -> 행
//branch -> 몇번 턴할지
void move(int* arr, int unit) {
	if (unit == 0)
		return;
	int* Clone = new int[w];
	for (int i = 0; i < w; i++) {
		Clone[i] = arr[i];
	}
	for (int i = w - 1; i >= 0; i--) {
		int nextIndex = i - unit;
		if (nextIndex < 0) {
			nextIndex += w;
		}
		arr[i] = Clone[nextIndex];
	}
}
int isPossible() {
	for (int x = 0; x < w; x++) {
		int DAT[201] = { 0 };
		for (int y = 0; y < h; y++) {
			if (DAT[v[y][x] + 100] > 0) {
				return 0;
			}
			DAT[v[y][x] + 100]++;
		}
	}
	return 1;
}
long long getDavinch() {
	long long Davinch = 1;
	for (int x = 0; x < w; x++) {
		long long sum = 0;
		for (int y = 0; y < h; y++) {
			sum += v[y][x];
		}
		Davinch *= sum;
	}
	return Davinch;
}
long long Max = INT_MIN;
int cnt = 0;
void func(int level) {

	//cout << "level : " << level << endl;
	if (level > 1 && !isPossible())
		return;
	if (level == h) {
		long long davinch = getDavinch();
		if (Max < davinch) {
			Max = davinch;
			//cout <<cnt++<<"번째 Max : "<< Max << endl;
		}
		return;
	}

	for (int i = 0; i < w; i++) {
		move(v[level], i);
		func(level + 1);
		move(v[level], (w - i) % w); //원상복귀
	}
}

void output() {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cout << v[y][x] << " ";
		}
		cout << endl;
	}
}
int main() {
	cin >> h >> w;
	v = new int* [h];
	for (int i = 0; i < h; i++) {
		v[i] = new int[w];
	}
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> v[y][x];
		}
	}
	func(0);

	cout << Max;
	return 0;
}
//강사님 코드
/*
* #include <iostream>
using namespace std;

int N; // 세로 길이
int M; // 가로 길이 
int tower[5][5]; 
long long MAX = -21e8; 
// index : 층
// value : 해당 층에서 몇번을 회전시켜봤는가?
int path[5]; 

// 지금 층까지의 회전값을 적용했을 때, 세로 방향에 동일한 값이 있는지 확인할 함수
bool isValid(int level) {
	// 세로방향으로 확인
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < level; j++) {
			// 현재 층 vs 현재 기준으로 위 층들과 각 값들을 확인
			// 각 층에는 path에 기록된 해당 층에 대한 회전값을 적용
			// 만약 동일한 값이 존재한다면, false 
			if (tower[level][(i+path[level]) % M] == tower[j][(i + path[j]) % M])
				return false; 
		}
	}
	// 모두 통과하면 true
	return true;
}

long long calculate() {
	long long res = 1; 
	for (int i = 0; i < M; i++) {
		int sum = 0; 
		for (int j = 0; j < N; j++) {
			// 각 층들에 대해 회전값을 적용한 값들의 합을 구한다
			sum += tower[j][(i + path[j]) % M];
		}
		res *= sum;
	}
	return res; 
}

void func(int level) {
	// 기저 조건 -> N층까지 모두 회전시켜봤고, 동일한 세로 값이 없다면
	if (level == N) {
		// 다빈치 점수 계산
		long long temp = calculate();
		if (temp > MAX)
			MAX = temp;
		return; 
	}

	// 수행
	// 재귀 구성 -> 한 층에서 돌려볼 수 있는 경우의 수는 0번~M-1번의 회전
	for (int i = 0; i < M; i++) {
		path[level] = i; // 이번 층에서 i번 만큼을 회전시킨다.
		
		//가지치기 -> 만약 이번 층까지의 회전값이 "유효하다면" 다음 층으로 간다 
		if (isValid(level))
			func(level + 1); 

		path[level] = 0; // 기록 초기화
	}
}

int main() {
	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> tower[i][j];

	// solve
	func(0); // 0층부터 조합 시작
	cout << MAX;
}
*/