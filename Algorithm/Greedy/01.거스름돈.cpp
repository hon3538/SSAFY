#include <iostream>
#include <algorithm>
using namespace std;

// 거스름돈 예시
/*
1500 4
100 50 10 500
*/

bool cmp(int left, int right) {
    if (left > right)
        return true;
    if (left < right)
        return false;
    return false; 
}

int target; // 거스름돈
int N; // 동전의 수
int coins[5]; 

int main() {
    cin >> target;
    cin >> N; 
    // 동전 입력 
    for (int i = 0; i < N; i++)
        cin >> coins[i]; 

    // S : 탐욕적으로 가장 큰 단위의 동전부터 돌려준다! 
    sort(coins, coins + N, cmp); 

    int ans = 0; 
    for (int i = 0; i < N; i++) {
        int now = coins[i]; 
        ans += target / now; 
        target %= now; 
    }
    cout << ans; 
}