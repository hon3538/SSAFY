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