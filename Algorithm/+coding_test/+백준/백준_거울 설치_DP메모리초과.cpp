//50 * 50
//* 불가
//# 입구 2개 반대편으로 가야함
//! 거울이 설치될 수 있는자리
//visited로 각 방향에서 들어오는 것을 체크
//같은 방향으로 들어오면 중복이므로 return
//다른 입구에 도착했을 때 거울 count
// DP

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
char map[50][50];
int visited[50][50][4]; // 해당 좌표와 들어오는 방향에 count를 최솟값으로 저장
struct Node {
    int y, x;
    int d;
};
vector<Node>point;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int func(Node now) {
    if (now.y < 0 || now.x < 0 || now.y >= N || now.x >= N) return 21e8;
    if (map[now.y][now.x] == '*') return 21e8;
    if (now.y == point[1].y && now.x == point[1].x) return 0;
    if (visited[now.y][now.x][now.d] != 0) return visited[now.y][now.x][now.d];
    
    int dy, dx;
   
    int ret = 21e8; //최소 거울개수
    if (map[now.y][now.x] == '!') {

        dy = now.y + dir[(now.d + 1) % 4][0];
        dx = now.x + dir[(now.d + 1) % 4][1];
        int ret1 = func({ dy,dx,(now.d + 1) % 4 }) + 1;

        dy = now.y + dir[(now.d + 3) % 4][0];
        dx = now.x + dir[(now.d + 3) % 4][1];
        int ret2 = func({ dy,dx,(now.d + 3) % 4 }) + 1;

        ret = min(ret1, ret2);
    }
 
    dy = now.y + dir[now.d][0];
    dx = now.x + dir[now.d][1];
    ret = min(ret, func({ dy,dx,now.d }));
    return visited[now.y][now.x][now.d] = ret;
}
int main() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            if (map[y][x] == '#')
                point.push_back({ y,x,0}); //시작과 끝
        }
    }
    int ans = 21e8;
    for (int i = 0; i < 4; i++) {
        int ret = func({ point[0].y,point[0].x,i });
        if (ret < ans)
            ans = ret;
    }
    cout << ans;
    return 0;
}