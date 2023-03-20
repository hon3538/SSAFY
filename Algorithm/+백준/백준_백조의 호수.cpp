
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int R, C;
char map[1500][1500];
int visited[1500][1500];
int Max;
struct NODE {
	int y, x;
	int c; //c-1 = 해당 위치를 며칠뒤에 갈 수 있는지?
	bool operator < (NODE o) const {
		return c > o.c;
	}
};
vector<NODE>point;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
void print_debug(int dy,int dx) {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (y == dy && x == dx) {
				cout << 'C';
				continue;
			}
			cout << map[y][x];
		}
		cout << '\n';
	}
}
int dijkstra(int y, int x) {
	priority_queue<NODE>pq;
	visited[y][x] = 1;
	pq.push({ y,x,1 });
	int Max = -21e8;
	while (!pq.empty()) {
		NODE now = pq.top();
		pq.pop();
		//print_debug(now.y, now.x);
		if (Max < now.c)
			Max = now.c;
		if (now.y == point[1].y&&now.x == point[1].x) {
			return (Max - 1) / 2 + (Max - 1) % 2;
		}
		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			

			int next = now.c;
			if (map[dy][dx] == 'X') next++;
			if (map[dy][dx] == '.') next = 1;
			if (dy == point[1].y&&dx == point[1].x) {
				return (Max - 1) / 2 + (Max - 1) % 2;
			}
			if (visited[dy][dx]!=0&&visited[dy][dx] <=next) continue;
			visited[dy][dx] = next;
			pq.push({ dy,dx,next });
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'L') {
				point.push_back({ y,x,1 }); //거위 위치
			}
		}
	}
	int ans = dijkstra(point[0].y, point[0].x);

	cout << ans;
	return 0;
}
