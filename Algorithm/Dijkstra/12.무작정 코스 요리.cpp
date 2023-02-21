//문제좀 제대로 파악해라..
//이해 ! 주의! 제한사항! 입력방식! 출력방식!
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
int N, M; // 요리개수(노드), 요리순서(간선)
struct Edge {
    int to;
    int cost;
    bool operator < (Edge o) const {
        return cost > o.cost;
    }
};
vector<Edge> v[1001];
int dist[1001];
int path[1001];
int price[1001];
void dijkstra(int start) {
    priority_queue<Edge>pq;
    pq.push({ start,0 });
    path[start] = start;
    price[start] = 0;
    dist[start] =0;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (dist[now.to] < now.cost) // dist가 다른 더 짧은 경로로 업뎃 됐다면 continue;
            continue;
        //이걸 안해주면 dist =짧은 경로 -> 나중에 -> dist =더 짧은 경로
        // 일때 더짧은 경로를 먼저 들어오긴하지만 pq에는 그냥 짧은 경로도 들어가있기때문
        //dist[now.to] = now.cost;
        for (int i = 0; i < v[now.to].size(); i++) {
            Edge next = v[now.to][i];
            int nextCost = next.cost + now.cost;
            if (dist[next.to] <= nextCost) {
                continue;
            }
            dist[next.to] = nextCost; //기존 경로보다 더 짧으면 업데이트
            path[next.to] = now.to;
            price[next.to] = next.cost;
            pq.push({ next.to,nextCost });
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        dist[i] = INT_MAX;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
    dijkstra(1);
    int from = N;
    vector<int>node;
    node.push_back(N);
    int max = 0;
    while (path[from] != from) { //from ==start일때 
        node.push_back(path[from]);
        if (max < price[from]) {
            max = price[from];
        }
        from = path[from];
    }
    int back = node.size() - 1;
    //cout<<"size"<<node.size()<<'\n';
    for (int i = 0; i < node.size(); i++) {
        cout << node[back] << ' ';
        back--;
    }
    cout << '\n' << max;
    return 0;
}