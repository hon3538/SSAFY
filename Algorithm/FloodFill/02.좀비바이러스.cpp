#include <iostream>
#include <queue>
#include <string>
using namespace std;

int h, w;
struct NODE {
    int y;
    int x;
};
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
string map[100];
int visited[101][101];
int isRange(int y, int x) {
    if (y < 1 || x < 1 || y > h || x > w)
        return 0;
    return 1;
}
int main() {

    cin >> w >> h;
    for (int y = 0; y < h; y++) {
        cin >> map[y];
        for (int x = 0; x < w; x++) {
            visited[y+1][x+1] = map[y][x] - '0';
        }
    }
    int y, x;
    cin >> x >> y;
    //bfs
    queue<NODE>q;
    q.push({ y,x });
    visited[y][x] = 3;
    int ans = 0;
    while (!q.empty()) {
        NODE now = q.front();
        q.pop();
        ans = visited[now.y][now.x];
        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (!isRange(dy, dx) || visited[dy][dx] != 1)
                continue;
            visited[dy][dx] = visited[now.y][now.x] + 1;
            q.push({ dy,dx });
        }
    }
    int cnt = 0;
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            if (visited[y][x] == 1)
                cnt++;
        }
    }
    cout << ans << '\n' << cnt;
    return 0;
}