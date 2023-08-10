//Node 2000개

//각 Node를 최소비용으로 연결
#include <iostream>
#include <queue>
using namespace std;
int N, C;
int costs[2000][2000];
int connected[2000];
struct Node {
	int y, x;
};
Node pipes[2000];
struct Edge {
	int to;
	int cost;

	bool operator < (Edge o) const {
		return cost > o.cost;
	}
};
int prim() {
	priority_queue<Edge>pq;
	int ans = 0; // 총 cost
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		if (costs[0][i] < C) continue;
		pq.push({ i,costs[0][i] });
	}
	connected[0] = 1;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (connected[now.to] == 1) continue;
		connected[now.to] = 1;
		ans += now.cost;
		cnt++;
        if(cnt==N-1) break;
		for (int i = 0; i < N; i++) {
			if (connected[i] == 1) continue;
			if (costs[now.to][i] < C) continue;
			pq.push({ i,costs[now.to][i] });
		}
	}
	if (cnt != N - 1) {
		return -1;
	}
	return ans;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pipes[i].y = b;
		pipes[i].x = a;
	}
	for (int i = 0; i < 2000; i++) {
		for (int j = i + 1; j < 2000; j++) {
			int dy = pipes[i].y - pipes[j].y;
			int dx = pipes[i].x - pipes[j].x;
			costs[i][j] = dy * dy + dx * dx;
			costs[j][i] = costs[i][j];
		}
	}
	cout << prim();
}