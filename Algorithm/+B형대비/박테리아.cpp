/*** user.cpp ***/

#define MAX_N 100

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int Energy[MAX_N][MAX_N];
int type[MAX_N][MAX_N]; // 타입이 무엇인지 0 nothing, 1빨간 , 2파란
int cnt[2];
int Size;
int visited[MAX_N][MAX_N];
void init(int N, int Dish[MAX_N][MAX_N])
{
	Size = N;
	memset(type, 0, sizeof(type));
	memset(cnt, 0, sizeof(cnt));
	memset(visited, 0, sizeof(visited));
	for (int y = 0; y < MAX_N; y++) {
		for (int x = 0; x < MAX_N; x++) {
			Energy[y][x] = Dish[y][x];
		}
	}


}
void debug() {
	cout << "==debug==\n";
	for (int y = 0; y < Size; y++) {
		for (int x = 0; x < Size; x++) {
			cout << type[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
struct Node {
	int y, x;
	bool operator <(Node o)const {
		if (Energy[y][x] == Energy[o.y][o.x]) {
			if (y == o.y) return x > o.x;
			return y > o.y;
		}
		return Energy[y][x] < Energy[o.y][o.x];
	}
};

//activate
priority_queue<Node>pq; // 다음 생성될 위치
queue<Node>q; // 갈 위치

void activate(int y, int x) {
	while (!q.empty()) q.pop();
	int t = type[y][x];
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= Size || dx >= Size) continue;
			if (type[dy][dx] != 0 && type[dy][dx] != t) continue;
			if (visited[dy][dx] == 1) continue;
			visited[dy][dx] = 1;

			if (type[dy][dx] == 0) { //빈 곳이면 생성될 위치 list 에 삽입
				pq.push({ dy,dx });
				continue;
			}
			q.push({ dy,dx });
		}
	}
}
int dropMedicine(int totalTarget, int R, int C, int totalEnergy)
{
	int t = totalTarget;
	//반대 타입이면 바로 나가
	if (type[R - 1][C - 1] != 0 && type[R - 1][C - 1] != t) return cnt[t-1];

	pq = priority_queue<Node>();
	memset(visited, 0, sizeof(visited));
	if (type[R - 1][C - 1] == 0) {
		type[R - 1][C - 1] = t;
		cnt[t - 1]++;
		totalEnergy -= Energy[R - 1][C - 1];
	}
	activate(R - 1, C - 1);
	while (totalEnergy > 0 && !pq.empty()) {
		Node now = pq.top();
		pq.pop();
		cnt[t - 1]++;
		type[now.y][now.x] = t;
		activate(now.y, now.x);
		totalEnergy -= Energy[now.y][now.x];
		//debug();
	}

	return cnt[t-1];
}

int cleanBacteria(int R, int C)
{
	queue<Node>q;
	memset(visited, 0, sizeof(visited));
	int t = type[R - 1][C - 1];
	if (t == 0) return -1;
	q.push({ R - 1,C - 1 });
	visited[R - 1][C - 1] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		type[now.y][now.x] = 0;
		cnt[t - 1]--;
		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= Size || dx >= Size) continue;
			if (type[dy][dx] != t) continue;
			if (visited[dy][dx] == 1) continue;
			visited[dy][dx] = 1;
			q.push({ dy,dx });
		}
	}


	return cnt[t-1];
}