//일단 중복 안 되는 모든 될 수 있는 간선들을 다 때려박고
//가중치 작은 순서로 한번 sort 하고 진행
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V, E;
struct Edge {
    int a, b;
    int cost;
    bool operator < (Edge o)const {
        return cost > o.cost;
    }
};
priority_queue<Edge>pq;
//****sort는 마지막에 한번만 하면 되므로 pq 보단 vector가 유리하다.
vector<int>parent;
int Find(int now) {
    if (now == parent[now])
        return now;

    return parent[now] = Find(parent[now]);
}
void Union(int A, int B) {
    int pa = Find(A);
    int pb = Find(B);
    if (pa == pb)
        return;
    parent[pb] = pa;
}
int kruskal() {

    int sum = 0;
    int cnt = 0;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (Find(now.a) == Find(now.b))
            continue;
        sum += now.cost;
        cnt++;
        Union(now.a, now.b);
    }
    if (cnt != V - 1) {
        return -1;
    }
    else return sum;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i <= V; i++) {
        parent.push_back(i);
    }
    for (int i = 0; i < E; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        pq.push({ a,b,cost });
    }
    cout << kruskal();

    return 0;
}