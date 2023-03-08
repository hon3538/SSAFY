//무게(~100000)와 가치(~1000)가 다른 물건 100개 
//10만 무게까지 버틸 수 있음
//최대 가치는?
//완전탐색? 100개라 dfs 불가능
//DP? 무게가 0일땐 가치 0, 
// TD
// weight 으로 받고
// 각 물건 무게를 빼면서 return 은 가치 출력
// DP : index -> weight , value 가치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int weight[101];
int value[101];
int DP[101][100001]; //물건번호, 무게
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> weight[i] >> value[i];
    }
   //처음은 0이여야함
    for (int limit = 1; limit <= K; limit++) { //해당 무게 limit에서
        for (int i = 1; i <= N; i++) { //여기 까지 봤을 때 최대값을 DP에 담기

            if (limit >= weight[i]) //넣을 수 있으면
                DP[i][limit] = max(DP[i - 1][limit - weight[i]] + value[i], DP[i - 1][limit]);
            else { //못넣으면
                DP[i][limit] = DP[i - 1][limit];
            }
        }
   }
    cout << DP[N][K];
    return 0;
}