#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

int N, M;
int dir[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };

struct Node
{
    int y, x;
    int cost;
    bool operator <(Node o) const {
        return cost > o.cost;
    }
};

int map[101][101];
int dist[101][101];

int main()
{
    cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> map[y][x];
            dist[y][x] = INT_MAX;
        }
    }
    priority_queue<Node> pq;
    pq.push({ 0, 0, map[0][0]});
    dist[0][0] = map[0][0];
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();

        if (now.cost > dist[now.y][now.x])
            continue;
        for (int i = 0; i < 4; i++)
        {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= M)
                continue;
            int nextCost = now.cost + map[dy][dx];
            if (nextCost > dist[dy][dx])
                continue;
            dist[dy][dx] = nextCost;
            pq.push({ dy, dx, nextCost });
        }
    }
    cout << dist[N - 1][M - 1];
    return 0;
}