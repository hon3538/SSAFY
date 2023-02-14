#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
int N, T;
struct Edge
{
    int to;
    int cost;
    bool operator<(Edge right) const
    {
        return cost>right.cost;
    }
};

vector<Edge> v[20001];
int dist[20001];
int main() 
{
    cin >> N >> T;

    for (int i = 0; i < T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }
    priority_queue<Edge> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        if(dist[now.to]<now.cost){
            continue;
        }
        for (int i = 0; i < v[now.to].size(); i++)
        {
            Edge next = v[now.to][i];
            int nextCost = next.cost + dist[now.to];
            if (nextCost > dist[next.to])
                continue;
            dist[next.to] = nextCost;
            pq.push({next.to, nextCost});
        }
    }
    if(dist[N-1]==INT_MAX)
        cout<<"impossible";
    else cout<<dist[N-1];
    return 0;
}