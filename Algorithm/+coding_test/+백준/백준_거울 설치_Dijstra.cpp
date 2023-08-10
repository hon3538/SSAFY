#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
char map[51][51];
int visited[51][51][4]; // 해당 좌표와 들어오는 방향에 count를 최솟값으로 저장
struct Node {
    int y, x;
    int d;
    int count;
    
    bool operator < (Node o) const {
        return count > o.count;
    }
};
vector<Node>point;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int dijkstra(int y,int x) {
    priority_queue<Node>pq;
    for (int i = 0; i < 4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        pq.push({ dy,dx,i,1 });
        visited[y][x][i] = 1;
    }

    while (!pq.empty()) {
        Node now=pq.top();
        pq.pop();
        if (now.y < 0 || now.x < 0 || now.y >= N || now.x >= N) continue;
        if (map[now.y][now.x] == '*') continue;
        if (now.y == point[1].y && now.x == point[1].x) return now.count-1;
        if (visited[now.y][now.x][now.d] != 0 && visited[now.y][now.x][now.d] <= now.count)
            continue;
        visited[now.y][now.x][now.d] = now.count;
        int nextDir;
        int dy, dx;
        if (map[now.y][now.x] == '!') {
            for (int i = 1; i < 4; i += 2) {
                nextDir = (now.d + i) % 4;
                dy = now.y + dir[nextDir][0];
                dx = now.x + dir[nextDir][1];
                pq.push({ dy,dx,nextDir,now.count + 1 });
            }
        }
        dy = now.y + dir[now.d][0];
        dx = now.x + dir[now.d][1];
        pq.push({ dy,dx,now.d,now.count });
    }
}
int main() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            if (map[y][x] == '#')
                point.push_back({ y,x,0,0 }); //시작과 끝
        }
    }
    int ans = dijkstra(point[0].y, point[0].x);
    cout << ans;
    return 0;
}