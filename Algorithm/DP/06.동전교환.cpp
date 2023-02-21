#include <iostream>
#include <limits.h>
using namespace std;
// 각 동전의 배수가 되는 price들의 동전 수는 알 수 있음
// 0원은 동전 0개이다. -> 이로부터 각 동전의 배수될때마다 +1씩해줌으로써
// 각 price의 동전 개수를 알 수 있다.
// 10 1개, 20 2개, 30 3개,,,
// 50 1개 100 2개 150 3개,,,
// 항상 최솟값으로 업데이트
// 초기값은 max로

// 만들 수 없는 값은 초기값으로 유지되어 있다.
int target, n;
int coins[11];
int DP[3001];
int main()
{
    cin >> target >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    for (int i = 0; i <= 3000; i++)
    {
        DP[i] = 21e8; // MAX로 해버리면 +1해줄때 값이 overflow발생..
    }
    DP[0] = 0; // 0원은 동전 0개
    for (int i = 0; i < n; i++)
    {
        int coin = coins[i];
        for (int j = coin; j <= target; j++)
        {
            if (DP[j - coin] + 1 < DP[j])
            {
                DP[j] = DP[j - coin] + 1;
            }
        }
    }
    if (DP[target] == 21e8)
        cout << "impossible";
    else
        cout << DP[target];
    return 0;
}