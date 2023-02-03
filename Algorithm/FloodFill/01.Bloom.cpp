#include <iostream>
#include <queue>
using namespace std;
int h, w;
struct NODE {
    int y;
    int x;
};
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int visited[101][101];
int isRange(int y, int x) {
    if (y < 0 || x < 0 || y >= h || x >= w)
        return 0;
    return 1;
}
int main() {

    cin >> h >> w;
    int fy, fx;
    int sy, sx;
    cin >> fy >> fx >> sy >> sx;

    queue<NODE>q;
    
    q.push({ fy,fx });
    q.push({ sy,sx });
    int days=0;
    visited[fy][fx] = 1;
    visited[sy][sx] = 1;
    while (!q.empty()) {
            NODE f = q.front();
            days = visited[f.y][f.x];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dy = f.y + dir[i][0];
                int dx = f.x + dir[i][1];
                if (!isRange(dy, dx) || visited[dy][dx] > 0)
                    continue;
                visited[dy][dx] = visited[f.y][f.x] + 1;
               q.push({ dy,dx });
            }
    }
    cout << days;
    return 0;
}