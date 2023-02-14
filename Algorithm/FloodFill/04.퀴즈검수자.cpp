#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int H, W; //장기판 높이, 너비
int R, C; // 붉은색 좌표
int Y, X; // 파란색 좌표
int N; //붉은색 쫄의 개수

struct Node {
    int y, x;
};
int map[101][101]; //-1쫄병, 0 갈수있음, visited -> 거리
int dir[8][2] = { -3,-2,-3,2,-2,3,2,3,3,2,3,-2,2,-3,-2,-3 };
void print() {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cout << map[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int main() {
    cin >> H >> W >> R >> C >> Y >> X >> N;
    for (int i = 0; i < N; i++) {
        int y, x;
        cin >> y >> x;
        map[y][x] = -1; // 쫄;
    }

    queue<Node>q;
    q.push({ R,C });
    map[R][C] = 1;
    int ans = -1;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        //print();
        if (now.y == Y && now.x == X) {
            ans = map[now.y][now.x]-1;
            break;
        }
        for (int i = 0; i < 8; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= H || dx >= W)
                continue;
            if (map[dy][dx] != 0)
                continue;
            map[dy][dx] += map[now.y][now.x] + 1;
            q.push({ dy,dx });
        }
    }


    cout << ans;
    return 0;
}