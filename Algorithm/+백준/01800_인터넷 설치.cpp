//dijkstra + ps
//ps(logP) * dij(N+E)
//최소 비용

//최소 비용을 찾는데 조건이 있다?
//-> ps

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, P, K;
struct Edge {
	int to;
	int cost;
	int cnt;
	bool operator <(Edge o) const {
		return cnt < o.cnt;
	}
};

vector<Edge>v[1001];
int dist[1001];
int dijkstra(int limit) {
	priority_queue<Edge>pq;
	pq.push({ 1,0,K+1 }); //1이 곧 0 (visited)
	memset(dist, 0, sizeof(dist));
	dist[1] = K+1;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (dist[now.to] > now.cnt) continue;
		if (now.to == N) {
			return 1;
		}
		for (int i = 0; i < v[now.to].size(); i++) {
			Edge next = v[now.to][i];
			if (next.cost > limit) {
				if (now.cnt > 1)
					next.cnt = now.cnt - 1;
				else continue; //이미 무료 다썼으면 나가리
			}
			else next.cnt = now.cnt;
			//이미 해당노드에 같거나 더 높은 cnt로 들렸으면 들릴 필요없음
			if (dist[next.to] >= next.cnt) continue;
			dist[next.to] = next.cnt;
			pq.push(next);
		}
	}
	return 0;
}
int ps() {
	int left = 0;
	int right = 1000000;
	int ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (dijkstra(mid)) {
			ans = mid;
			right = mid - 1; //가능하다는 것은 최소비용이 더 낮을 수도 있다 ㅎㅎ
		}
		else { //불가능 하면 최소비용이 더 높다.
			left = mid + 1;
		}
	}
	return ans;
}
int main() {
	cin >> N >> P >> K;
	for (int i = 0; i < P; i++) { //그래프 입력
		int a, b, p;
		cin >> a >> b >> p;
		v[a].push_back({ b,p });
		v[b].push_back({ a,p });
	}
	cout << ps();
	return 0;
}
