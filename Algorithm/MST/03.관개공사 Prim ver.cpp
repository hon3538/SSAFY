#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
int N, K;
struct Node {
	int y, x;
};
vector<Node>nodeList;
struct Edge {
	int to;
	int cost;
	bool operator < (Edge o) const {
		return cost > o.cost;
	}
};
vector<Edge>v[2000];
int getExpense(int now, int next) {
	Node a = nodeList[now];
	Node b = nodeList[next];
	return pow((a.y - b.y), 2) + pow((a.x - b.x), 2);
}
int connected[2000];
int prim(int start) {
	priority_queue<Edge>pq;
	pq.push({start, 0});

	int sum = 0;
	int cnt = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (connected[now.to] == 1)
			continue;
		connected[now.to] = 1;
		sum += now.cost;
		cnt++;
		for (int i = 0; i < N; i++) { //모든 간선에 대해 탐색
			if (connected[i] == 1)
				continue;
			int expense = getExpense(now.to, i);
			if (expense < K)
				continue;
			pq.push({ i,expense });
		}
	}
	if (cnt == N) {
		return sum;
	}
	else return -1;
}
int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		nodeList.push_back({ y,x });
	}
	cout << prim(0);

	return 0;
}