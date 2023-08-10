//한번 막대 던질때마다 미네랄이 떨어지는지 확인
//floodfill 로 확인
//떨어지면 새맵으로 update
//현재 맵을 clone하고
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int R, C;
int N;
char map[100][100];
int visited[100][100];
struct Node {
	int y, x;
};
Node h; //y범위
Node w; //x범위

int remove(int isLeft, int height) { //x값 리턴
	int x;
	if (isLeft % 2 == 0) {
		x = 0;
		while (x < C) {
			if (map[height][x] == 'x') {
				map[height][x] = '.';
				return x;
			}
			x++;
		}
	}
	else {
		x = C - 1;
		while (x >= 0) {
			if (map[height][x] == 'x') {
				map[height][x] = '.';
				return x;
			}
			x--;
		}
		x++;
	}
	return -1;
}
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int floodfill(int y, int x, int n) { //떨어질 게 있는지 확인
	queue<Node>q;
	q.push({ y,x });
	visited[y][x] = n;
	int top = 21e8;
	int bottom=-21e8;

	int Left = 21e8;
	int Right = -21e8;
	int check[100] = { 0 };
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (bottom < now.y) bottom = now.y;
		if (top > now.y) top = now.y;
		if (Left > now.x) Left = now.x;
		if (Right < now.x) Right = now.x;

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			if (map[dy][dx] == '.') continue;
			if (visited[dy][dx]!=0) continue;
			visited[dy][dx] = n;

			q.push({ dy,dx });
		}
	}
	if (bottom == R - 1) return bottom;
	h = { top,bottom };
	w = { Left,Right };
	return bottom;
}
int xList[100];
int used[100][100];
int getGap(int sy,int sx,int order) {
	queue<Node>q;
	q.push({ sy,sx });
	memset(used, 0, sizeof(used));
	used[sy][sx] = order;
	memset(xList, 0, sizeof(xList));
	int max = 21e8;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		int n = 1;
		if (xList[now.x] != 1) {
			while (now.y+n<R) {
				if (visited[now.y + n][now.x] == order) {
					n = 21e8;
					break;
				}
				if (map[now.y + n][now.x] != '.') {
					break;
				}
				n++;
			}
			if (max > n - 1) max = n - 1;
			if(n!=21e8)
				xList[now.x] = 1;
		}

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			if (visited[dy][dx] != order) continue;
			if (used[dy][dx] == order) continue;
			used[dy][dx] = order;
			q.push({ dy,dx });
		}
	}
	return max;
}
void update(int n,int order) { //맵 업데이트
	for (int y = h.x + n; y >= h.y + n; y--) {
		for (int x = w.y; x <= w.x; x++) {
			if (y > h.x&&map[y][x] == 'x') continue;
			if (visited[y - n][x] != order) continue;
			map[y][x] = map[y - n][x];
			visited[y][x] = order;
			visited[y - n][x] = 0;
			map[y - n][x] = '.';
		}
	}
}
void deb() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << map[y][x];
		}
		cout << '\n';
	}
}
int main() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
		}
	}
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		int y = (R - 1) - (n - 1);
		int x = remove(i, y);
		if (x == -1) continue;
		int cnt = 1;
		int ret = R - 1;
		memset(visited, 0, sizeof(visited));
		int dy;
		int dx;
		for (int i = 0; i < 4; i++) {
			dy = y + dir[i][0];
			dx = x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			if (map[dy][dx] == '.') continue;
			if (visited[dy][dx] != 0) continue;
			ret = floodfill(dy, dx, cnt++);
			if (ret != R - 1) {
				ret = getGap(dy, dx, cnt - 1);
				update(ret,cnt-1);
		}
	}
	deb();
	return 0;
}
