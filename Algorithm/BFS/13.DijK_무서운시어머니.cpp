#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int Y, X;
int N;
int map[1000][1000];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int Max = INT_MIN;
int mX, mY;
struct Node {
    int y, x;
    int cost;
    bool operator < (Node o) const {
        return cost > o.cost;
    }
};
int main() {
    cin >> Y >> X;
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            if (map[y][x] > Max) {
                Max = map[y][x];
                mY = y;
                mX = x;
            }
        }
    }
    priority_queue<Node>pq;
    pq.push({ Y,X,map[Y][X] });
    map[Y][X] = -1;
    int ans;
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if (now.y == mY && now.x == mX) { // 도착지
            ans = now.cost;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= N)
                continue;
            if (map[dy][dx] == -1)
                continue;

            int nextCost = now.cost + map[dy][dx];
            map[dy][dx] = -1;
            pq.push({ dy,dx,nextCost });
        }
    }
    cout << ans;
    return 0;
}