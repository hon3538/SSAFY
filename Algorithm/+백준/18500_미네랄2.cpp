//한번 막대 던질때마다 미네랄이 떨어지는지 확인
//floodfill 로 확인
//떨어지면 새맵으로 update
//현재 맵을 clone하고
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int R, C;
int N;
char map[100][100];
int visited[100][100];
struct Node {
    int y, x;
};
Node h; //y범위
Node w; //x범위

void remove(int isLeft, int height) {
    if (isLeft % 2 == 0) {
        int x = 0;
        while (x < C) {
            if (map[height][x] == 'x') {
                map[height][x] = '.';
                break;
            }
            x++;
        }
    }
    else {
        int x = C - 1;
        while (x >= 0) {
            if (map[height][x] == 'x') {
                map[height][x] = '.';
                break;
            }
            x--;
        }
    }
}
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int floodfill(int y, int x,int n) { //떨어질 게 있는지 확인
    queue<Node>q;
    q.push({ y,x });
    visited[y][x] = n;
    int floor = -1;
    int Left = 21e8;
    int Right = -21e8;
    int check[100] = { 0 };
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (floor < now.y) floor = now.y;
        if (Left > now.x) Left = now.x;
        if (Right < now.x) Right = now.x;
        
        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
            if (map[dy][dx] == '.') continue;
            if (visited[dy][dx] == n) continue;
            visited[dy][dx] = n;

            q.push({ dy,dx });
        }
    }
    if (floor == R - 1) return floor;
    h = { y,floor };
    w = { Left,Right };
    return floor;
}
void update(int n) { //맵 업데이트
    for (int y = h.x + n; y >= h.y+n; y--) {
        for (int x = w.y; x <= w.x; x++) {
            if (y>h.x&&map[y][x] == 'x') continue;
            map[y][x] = map[y - n][x];
        }
    }
    for (int y = h.y; y < h.y + n; y++) {
        for (int x = w.y; x <= w.x; x++) {
            map[y][x] = '.';
        }
    }
}
void deb() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cout << map[y][x];
        }
        cout << '\n';
    }
}
int main() {
    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> map[y][x];
        }
    }
    cin >> N;
    deb();

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        remove(i, (R - 1) - (n - 1));
        deb();
        int cnt = 1;
        memset(visited, 0, sizeof(visited));
        int flag = 0;
        for (int y = 0; y < R; y++) { //맵 업데이트
            for (int x = 0; x < C; x++) {
                if (map[y][x] == '.') continue;
                if (visited[y][x] == 1) continue;
                int ret=floodfill(y, x,cnt++);
                if (ret!= R - 1) { flag=1; break; }
            }
            if (flag) break;
        }

        if (!flag) continue; //떨어질게 없음
        int ret = check();

        update(ret);
        deb();
    }
    deb();
    return 0;
}