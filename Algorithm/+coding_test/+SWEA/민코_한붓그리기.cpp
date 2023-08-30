#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[100][100];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

queue<int>q;

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

int getEdge(int y, int x) {
    int cnt = 0;
    int now=y*N+x;
    for (int i = 0; i < 4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        int next=dy*N+dx;
        if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
        if (map[dy][dx] == 1) continue;
        if(Find(now)==Find(next)) continue;
        if(connected[dy][dx]==2) continue;
        cnt++;
    }
    return cnt;
}

void kruskal() {
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int y = now / N;
        int x = now % N;
        
        int possible=getEdge(y,x);
        if(connected[y][x]==2) continue;
        if(connected[y][x]+possible>2){
            q.push(now);
            continue;
        }
        
        for(int i=0;i<4;i++){
            int dy = y + dir[i][0];
            int dx = x + dir[i][1];
            int next=dy*N+dx;
            if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
            if (map[dy][dx] == 1) continue;
            if(Find(now)==Find(next)) continue;
            if(connected[dy][dx]==2) continue;
            connected[y][x]++;
            connected[dy][dx]++;
            Union(now,next);
        }
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
            int now=y*N+x;
            q.push(now);
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