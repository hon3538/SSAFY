#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
// flood fill -> 모든 좌표
// 운용비용 = K*K+(K-1)(K-1)
// 운용비용 / M +a(1 or 0) -> 최소 필요 집 개수,
// if(최소 필요집 개수 - 현재집개수 >0)
// 최소 필요 집 개수 - 현재집 개수 = 추가필요한 집 개수 > 총 집 개수 - 현재 집 개수
// 최소필요집 개수 > 총 집 개수 => 불가능 조건(가지치기)

int N, M; // 도시크기, 지불 비용

int map[20][20];
int total;
struct Node
{
    int y, x;
};
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int floodfill(Node start)
{
    queue<Node> q;
    q.push(start);
    int K[20][20] = {0};
    K[start.y][start.x] = 1; // K ==> visited and 거리
    int now_K = 1;
    int expense = 1;
    int needed = 1;

    int home = 0;
    if (map[start.y][start.x] == 1)
        home = 1;
    int ans = home;
    while (q.empty())
    {
        Node now = q.front();
        q.pop();
        
        if (needed > home && needed > total)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= N)
                continue;
            if (K[dy][dx] >= 1)
                continue;
            if (map[dy][dx] == 1)
            {
                home++;
            }
            K[dy][dx] = now_K + 1;
            q.push({dy, dx});
        }
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                cin >> map[y][x];
                if (map[y][x] == 1)
                    total++;
            }
        }
        int max = -21e8;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                int ret = floodfill({y, x});
                if (ret > max)
                    max = ret;
            }
        }
        cout<<max;
    }
    return 0;
}