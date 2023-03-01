#include<iostream>
#include <queue>
using namespace std;
int map[4][4];
int DP[4][4];
int visited[4][4];
int dir[4][2] = { 0,1,1,0};
struct Node {
    int y, x;
};
int func(int y, int x) {
    if (y == 3 && x == 3) {
        return 0;
    }
    if (DP[y][x] != 0)
        return DP[y][x];

    int Min = 21e8;
    for (int i = 0; i < 2; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4)
            continue;
        
        int ret = func(dy, dx);

        if (ret < Min) {
            Min = ret;
            if (ret == 0)
                break;
        }
    }
    return DP[y][x] = Min + map[y][x];
}
int main() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cin >> map[y][x];
        }
    }

    int ret = func(0, 0);
   
    queue<Node>q;
    q.push({ 0,0 });
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        cout << now.y << ',' << now.x << '\n';
        if (now.y == 3 && now.x == 3)
            break;
        int minY;
        int minX;
        int min = 21e8;
        for (int i = 0; i < 2; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4)
                continue;
            if (min > DP[dy][dx]) {
                minY = dy;
                minX = dx;
                min = DP[dy][dx];
            }
        }
        q.push({ minY,minX });
    }
    return 0;
}