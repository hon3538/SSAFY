#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//문제 이해 제대로 하고가기
//각 사람단위로 bfs를 돌료 베이스캠프를 맵에 표시하기
//각 사람단위로 bfs 돌려 베이스캠프에서 편의점도착 시간을 visited에 넣기
//마지막 사람이 도착했을때 시간이 곧 정답
int N, M; //격자수, 사람 수
int map[15][15];//-1 베이스 캠프(초기), 여길 사람번호로 업데이트 해줄거
struct Node {
    int y, x;
    int time;
};
vector<Node>store;
vector<Node>base;
int dir[4][2] = { -1,0,0,-1,0,1,1,0 };
int visited[15][15];
void setBase(int n) {//bfs
    //n번 사람의 base 찾기
    queue<Node>q;
    q.push(store[n]);
    memset(visited, 0, sizeof(visited));
    visited[store[n].y][store[n].x] = 1;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (map[now.y][now.x] == -1) {
            base.push_back({ now.y,now.x,n + 1 });
            map[now.y][now.x] = n;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
            if (map[dy][dx] > 0) continue;
            if (visited[dy][dx] == 1) continue;
            visited[dy][dx] = 1;
            q.push({ dy,dx });
        }
    }
}
int Fixed[15][15]; //해당 자리에 고정된 시간
int ans;
void bfs(int n) { //base에서 시작시간, 유치원 도착시간 visited에 남기기
    queue<Node>q;
    q.push({ base[n] });
    memset(visited, 0, sizeof(visited));
    visited[base[n].y][base[n].x] = 1;
    Fixed[base[n].y][base[n].x] = n + 1;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (store[n].y == now.y && store[n].x == now.x) {
            Fixed[now.y][now.x] = now.time;
            if (ans < now.time) ans = now.time;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
            if (Fixed[dy][dx]!=0 && Fixed[dy][dx] <= now.time) continue;
            if (visited[dy][dx] == 1) continue;
            visited[dy][dx] = 1;
            q.push({ dy,dx,now.time + 1 });
        }
    }
}
int main() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            if (map[y][x] == 1)
                map[y][x] = -1;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        store.push_back({ a - 1,b - 1 });
    }
    for (int i = 0; i < M; i++) {
        setBase(i);
        bfs(i);
    }
    cout << ans;
    return 0;
}