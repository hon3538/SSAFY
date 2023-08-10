//브루투 포스
//각 위치와 4방향의 경우를 모두 봐야한다.
//원래 위치 또는 블랙홀(-1)을 만났을 때 게임종료
//벽을 부딪힐때마다 점수 cnt
//어느 위치와 어떤 방향으로 출발해야 최대 점수를 얻는지?
//웜홀은 쌍을 이루고 있음
//웜홀 최대 5쌍, 블랙홀 최대 5개

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N;
int map[100][100];
int block[100][100][4];
int visited[4][100][100];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 }; //위 오 아래 왼

struct Node {
    int y, x;
    int d;
};
vector<int>ans;
Node WH[11][2];
int changeDir(int d, int block) {  //y,x 는 현재 위치고 아직 블록 가기전
    //블록 종류에 따라서 현재 진행 방향에 따른 다음 방향을 return
    if (block == 5) return (d + 2) % 4; // 5번블록은 무조건 반대

    int next;
    int relative = (block - d);// 방향과 블록은 상대적이다
    if (relative <= 0) relative += 4; //0번 블럭은 없음
    if (1 == relative) //반대방향
    {
        next = (d + 2) % 4;
        return next;
    }
    else if (2 == relative)
    {
        next = (d + 1) % 4; //시계방향

        return next;
    }
    else if (3 == relative) //반시계
    {
        next = d - 1;
        if (next < 0) next += 4;
        return next;
    }
    else if (4 == relative) //반대방향
    {
        next = (d + 2) % 4;
        return next;
    }
    return -1;
    //1번으로 위로 올때랑 2번으로 왼쪽에서 올때 메커니즘이 같음
    //즉 0번(위) 방향은 1번블럭이랑 부딪힐때와 1번방향(오른쪽)의 2번이랑 같음
    //즉, block 번호는 상대적이다.
}
int func(Node start) { // bruteforce
    Node now = { start.y,start.x,start.d };
    int cnt = 0;
    while (1) {
        int dy = now.y + dir[now.d][0];
        int dx = now.x + dir[now.d][1];

        if (dy < 0 || dx < 0 || dy >= N || dx >= N) { //벽이랑 부딪히면 방향 바꿔
            return cnt * 2 + 1;
        }
        visited[now.d][dy][dx] = 1;
        //처음위치랑 같으면 나가
        if (dy == start.y && dx == start.x) {
            return cnt;
        }
        //암것도 없으면 직진해
        if (map[dy][dx] == 0) {
            now.y = dy;
            now.x = dx;
            continue;
        }
        //블랙홀 만나면 나가
        if (map[dy][dx] == -1) {
            return cnt;
        }
        //웜홀 만나면 다른 웜홀로 가
        if (map[dy][dx] >= 6) {
            if (WH[map[dy][dx]][0].y == dy && WH[map[dy][dx]][0].x == dx) {
                now.y = WH[map[dy][dx]][1].y;
                now.x = WH[map[dy][dx]][1].x;
            }
            else {
                now.y = WH[map[dy][dx]][0].y;
                now.x = WH[map[dy][dx]][0].x;
            }
            continue;
        }
        if(map[dy][dx]==5)
            return cnt * 2 + 1;
        //블럭 부딪히면 방향 바꿔
        cnt++;
       // if (block[dy][dx][now.d] > cnt)  //이게 있을 떄 왜 오류,,? 각 블럭에서 모든 방향에서 오는 경우의 cnt 최대값을 계속 갱신하면서 카운트
          //  return -1;
     //   block[dy][dx][now.d] = cnt;
        now.d = changeDir(now.d, map[dy][dx]);
        now.y = dy;
        now.x = dx;
    }
}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        memset(block, 0, sizeof(block));
        memset(visited, 0, sizeof(visited));
        memset(WH, 0, sizeof(WH));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> map[y][x];
                if (map[y][x] >= 6) {
                    if (WH[map[y][x]][0].d==0) {
                        WH[map[y][x]][0] = { y,x,1 };
                    }else {
                        WH[map[y][x]][1] = { y,x,1 };
                    }
                }
            }
        }
        int res = 0;
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (map[y][x] != 0) { //빈 공간이 아니면 넘어가
                        continue;
                    }
                    for (int d = 0; d < 4; d++) {
                        //if (visited[d][y][x] == 1)
                          //  continue;
                        int ret = func({ y,x,d }); //y,x 위치와 dir 을 가지고 출발
                        if (ret > res)
                            res = ret;
                    }
                }
            }
        ans.push_back(res);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << "#"  << i + 1 << " " << ans[i] << "\n";
    }
    return 0;
}
