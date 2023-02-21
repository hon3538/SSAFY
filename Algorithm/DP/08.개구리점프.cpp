#include <iostream>
using namespace std;
//각 좌표마다 가능한 dir으로 끝까지 가보면서
//DP 업데이트
//DP는 min으로 초기화해주고 비교하여 큰 경우만 업데이트
//기존 map값은 유지해두고 그걸로 계산해 나가야됨
//0은 못가는곳
//DP를 안 써버림..
//각 좌표가 될때마다 방향하나씩만 확인해가면 되잖아
int H, W;
int DP[1000][1000];
int map[1000][1000];
int dir[3][2] = { 1,-1,1,0,1,1 };
int main() {
    cin >> H >> W;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cin >> map[y][x];
            DP[y][x] = -21e8;
        }
    }
    DP[0][0] = map[0][0];
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (map[y][x] == 0)
                continue;
            for (int i = 0; i < 3; i++) {
                int dy = y;
                int dx = x;
                int score = DP[y][x]; //DP를 쓰는순간 이좌표의 고정값(최댓값)이다.
                while (1) {
                    dy += dir[i][0];
                    dx += dir[i][1];
                    if (dy < 0 || dx < 0 || dy >= H || dx >= W)
                        break;
                    if (map[dy][dx] == 0)
                        break;
                    if (DP[dy][dx] > score + map[dy][dx]) { //가려는 방향의 점수가 이미 더 크면
                        break;
                    }
                    DP[dy][dx] = score + map[dy][dx];
                    score += map[dy][dx];
                }
            }
        }
    }
    int max = 0;
    for (int x = 0; x < W; x++) {
        if (map[H - 1][x] == 0)
            continue;
        if (max < DP[H - 1][x])
            max = DP[H - 1][x];
    }
    cout << max;
    return 0;
}
/* TD
#include<iostream>
using namespace std;

int h, w;
int map[100][100];
int memo[100][100];

int getMaxPoint(int dy, int dx)
{
    if (dx < 0 || dx >= w) return -21e8;
    if (dy == h) return 0;
    if (memo[dy][dx] != 0) return memo[dy][dx];
    if (map[dy][dx] == 0) return -21e8;

    int a = getMaxPoint(dy + 1, dx - 1);
    int b = getMaxPoint(dy + 1, dx);
    int c = getMaxPoint(dy + 1, dx + 1);

    int ret = a;
    if (ret < b) ret = b;
    if (ret < c) ret = c;

    memo[dy][dx] = ret + map[dy][dx];
    return memo[dy][dx];
}

int main()
{
    //freopen("text.txt", "r", stdin);

    cin >> h >> w;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> map[y][x];
        }
    }

    int ret = getMaxPoint(0, 0);
    cout << ret;

    return 0;
}
*/
/* BU
#include <iostream>
using namespace std;

int MAP[1000][1000];
int dp[1000][1000];
int height, width;
int MIN = -21e8;

int main() {
    cin >> height >> width;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> MAP[i][j];
            dp[i][j] = MIN;
        }
    }
    dp[0][0] = MAP[0][0];
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (MAP[i][j] == 0)
                continue;
            if(j-1 < 0)
                dp[i][j] = max(dp[i - 1][j] + MAP[i][j], dp[i - 1][j + 1] + MAP[i][j]);
            else if (j + 1 >= width)
                dp[i][j] = max(dp[i - 1][j] + MAP[i][j], dp[i - 1][j - 1] + MAP[i][j]);
            else
                dp[i][j] = max(max(dp[i - 1][j] + MAP[i][j], dp[i - 1][j - 1] + MAP[i][j]), dp[i - 1][j + 1] + MAP[i][j]);
        }
    }

    int ans = -21e8;
    for (int i = 0; i < width; i++) {
        ans = max(ans, dp[height - 1][i]);
    }
    cout << ans;
}
*/