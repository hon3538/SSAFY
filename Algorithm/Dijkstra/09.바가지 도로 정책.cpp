#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
int N, M;
struct Road {
    int to;
    int cost;
    int cnt;
    bool operator < (Road o) const {
        if (cost == o.cost) {
            return cnt > o.cnt;
        }
        return cost > cost;
    }
};
vector<Road>v[101];
struct Info {
    int cost;
    int cnt;
};
Info dist[101];
void dijkstra(int start) {
    priority_queue<Road>pq;
    pq.push({ start,0,1 });

    while (!pq.empty()) {
        Road now = pq.top();
        pq.pop();
        if (dist[now.to].cost < now.cost)
            continue;
        if (dist[now.to].cost==now.cost&&dist[now.to].cnt < now.cnt)
            continue;
        dist[now.to].cost = now.cost;
        dist[now.to].cnt = now.cnt;
        for (int i = 0; i < v[now.to].size(); i++) {
            Road next = v[now.to][i];
            int nextCost = next.cost + now.cost;
            if (dist[next.to].cost <= nextCost)
                continue;
            //dist[next.to].cost=dist[now.to].cost+next.cost;
            next.cnt = now.cnt + 1;
            pq.push({ next.to,nextCost,next.cnt });
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        dist[i].cost = INT_MAX;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (e > 10) {
            c += (e-10) * d;
        }
        v[a].push_back({ b,c,0 });
    }
    dijkstra(1);
    if (dist[N].cnt == 0)
        cout << -1;
    else cout << dist[N].cost << ' ' << dist[N].cnt;
    return 0;
}