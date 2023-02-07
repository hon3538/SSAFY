#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// highest 찾기 -> dfs 시작점
// 최대 K까지 -가능 한번 ㅋ
// 최대 등산로 길이 찾기

// level -> NODE
// branch -> dir
int N, K;
int map[9][9];
int highest;
int lenMax;

void dfs(int level){
    //끝날 조건 -> 더이상 갈 수 있는 곳이 없을 때
    //inRange and visited or 모든 높이 차이가 K이상 일때  
}
void input();
int main()
{
    int T;
    cin >> T;
    vector<int> ans;
    for (int t = 0; t < T; t++)
    {
        // 전역변수 초기화
        highest = INT_MIN;
        lenMax = INT_MIN;
        input();

        // start
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (highest != map[y][x])
                    continue;
            }
        }
    }
}

void input()
{
    cin >> N >> K;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> map[y][x];
            if (highest < map[y][x])
                highest = map[y][x];
        }
    }
}