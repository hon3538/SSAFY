//소끼리 만날 수 없는 경우
//맵에 길 표시,
//각 소의 위치에서 모든 소로 갈 수 있는지 floodfill,
//visited하고 만나는 쌍 count
//각 floodfill마다 소 개수 x (계산 안 된 안 만나는 소) 를 ans에 더해나간다.
//다음 floodfill 에서는 이미 쌍 계산을 한 소들은 계산 제외
//계산 안 된 안 만나는 소 = K마리 - cnt(이번에 만난애들)- checked(이미 계산 된애들)

//길을 건너야만 만날 수 있는 소 쌍 구하는 거였음..
//같은 플루드필에 있는 대신 인접하지 않은.
//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, K, R; // NxN 맵 크기, K 소 마리수, R 길 개수
int map[100][100];
struct Node {
	int y, x;
};
int ans;
int checked; //이미 계산된 애들
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int floodfill(int y, int x) {
	queue<Node>q;
	int res = 0;
	q.push({ y,x });
	if (map[y][x] > 0) {
		res++;
		map[y][x] = 0;
	}
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
			if (map[dy][dx] == 0) continue;
			if (map[dy][dx] > 0) {
				res++;
			}
			map[dy][dx] = 0;
			q.push({ dy,dx });
		}
	}
	return res; // 만나는 소들 cnt
}
int main() {
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2; //1부터 시작하므로 -1 해준다
		int by = max(y1 - 1, y2 - 1);
		int sy = min(y1 - 1, y2 - 1);
		int bx = max(x1 - 1, x2 - 1);
		int sx = min(x1 - 1, x2 - 1);
		for (int y = sy; y <= by; y++) {
			for (int x = sx; x <= sx; x++) {
				map[y][x] = -1; //-1은 길이라는 뜻
			}
		}
	}
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a-1][b-1] = i + 1;
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] <= 0) continue;
			int ret = floodfill(y, x);
			checked += ret;
			int remain = K - checked; //만나는 쌍을 안 본 친구들 개수
			//안 만나는 쌍 개수 계산
			ans += remain * ret;
		}
	}
	cout << ans;
	return 0;
}