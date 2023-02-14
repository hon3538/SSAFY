#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
int N, M, K; // 도시 수, 고속도로 수, 햇수
int A, B; // A 시작 도시, B 도착 도시
struct Road {
    int to;
    int cost;
    bool operator < (Road o)const {
        return cost > o.cost;
    }
};
vector<Road>v[1001];
int taxRate[11];
void dijkstra(int tax) {
    priority_queue<Road>pq;
    int dist[1001];
    for (int i = 0; i <= N; i++) {
        dist[i] = INT_MAX;
    }
    pq.push({ A,0 });
    dist[A] = 0;
    while (!pq.empty()) {
        Road now = pq.top();
        pq.pop();

        if (dist[now.to] < now.cost)
            continue;
        for (int to = 0; to < v[now.to].size(); to++) {
            Road next = v[now.to][to];
            int nextExp = now.cost + next.cost + tax;
            if (nextExp > dist[next.to])
                continue;
            dist[next.to] = nextExp;
            pq.push({ next.to,nextExp });
        }
    }
    cout << dist[B]<<'\n';
}
int main() {
    cin >> N >> M >> K;
    cin >> A >> B;
    for (int i = 0; i < M; i++) {
        int f, t, c;
        cin >> f >> t >> c;
        v[f].push_back({ t,c });
        v[t].push_back({ f,c });
    }
    for (int i = 1; i <= K; i++) {
        int p;
        cin >> p;
        taxRate[i] =taxRate[i-1]+ p;
    }
    for (int i = 0; i <= K; i++) {
        dijkstra(taxRate[i]);
    }
    
    return 0;
}