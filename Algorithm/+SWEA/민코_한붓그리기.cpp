#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[100][100];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
struct Edge {
    int from;
    int to;
    int dir;
    int cnt;
    bool operator < (Edge o) const {
        return cnt > o.cnt;
    }
};
int getEdge(int y, int x) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
        if (map[dy][dx] == 1) continue;
        cnt++;
    }
    return cnt;
}
priority_queue<Edge>pq;
int check[100][100][4];
int visited[100][100][4];
int connected[100][100]; //2일떄 연결 다 됨
int parent[10000];
int Find(int now) {
    if (now == parent[now])
        return now;
    return parent[now] = Find(parent[now]);
}
void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);

    if (pa == pb) return;
    parent[pb] = pa;
}
void kruskal() {

    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        int y = now.from / N;
        int x = now.from % N;

        int ny = now.to / N;
        int nx = now.to % N;
        if (Find(now.from) == Find(now.to)) continue;
        if (visited[y][x][now.dir] == 1) continue;
        visited[y][x][now.dir] = 1;
        visited[ny][nx][(now.dir + 2) % 4] = 1;

        if (connected[y][x] == 2) continue;
        if (connected[ny][nx] == 2) continue;
        connected[y][x]++;
        connected[ny][nx]++;

        Union(now.from, now.to);
    }
}
int main() {
    for (int i = 0; i < 10000; i++) {
        parent[i] = i;
    }
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int y, x;
        cin >> y >> x;
        map[y][x] = 1;
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == 1) continue;
            for (int i = 0; i < 4; i++) {
                int dy = y + dir[i][0];
                int dx = x + dir[i][1];
                if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
                if (map[dy][dx] == 1) continue;

                if (check[y][x][i] == 1) continue;
                check[y][x][i] = 1;

                int now = y * N + x % N;
                int next = dy * N + dx % N;
                int edges = getEdge(dy, dx);
                pq.push({ now,next,i,edges});

            }
        }
    }
    kruskal();
    int ans = 0;
    for (int i = 0; i < N*N; i++) {
        int y = i / N;
        int x = i % N;

        if (map[y][x] == 1) continue;
        if (parent[i] == i) ans++;
    }
    cout << ans;
    return 0;
}