//씨앗심음
//하루뒤에 꽃핌
//땅 숫자만큼 삼
//땅 숫자만큼 DAT[k]~DAT[k+땅숫자] 모두 +1씩 ㅋ
//DAT[day] 하나씩 보면서 가장 큰값 출력
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int N, M; // 밭의 크기
int Y, X; // 시작 위치
struct Node {
    int y, x;
    int days;
};
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int map[501][501];
int DAT[1000001];
int main() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }
    cin >> Y >> X;

    queue<Node>q;
    q.push({ Y,X,0 });
    for (int i = 1; i <= map[Y][X]; i++) {
        DAT[i]++;
    }
    map[Y][X] = 0;
    
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= M)
                continue;
            if (map[dy][dx] == 0)
                continue;
            int nextDay = now.days + 1;
            for (int i = 1; i <= map[dy][dx]; i++) {
                DAT[nextDay + i]++;
            }
            map[dy][dx] = 0;
            q.push({ dy,dx,nextDay});
        }
    }
    int Max = INT_MIN;
    int maxIdx;
    for (int i = 0; i <= 1000000; i++) {
        if (DAT[i] > Max) {
            Max = DAT[i];
            maxIdx = i;
        }
    }
    cout << maxIdx << "일\n" << Max << "개";
    return 0;
}
