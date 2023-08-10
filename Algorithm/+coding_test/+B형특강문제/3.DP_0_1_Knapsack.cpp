//DP[i][j]=k;
//i부피에서 j번까지 물건이 있을때 최대 가치 k
//DP[0~1000][0] = 0 -> 물건이 없으면 가치는 0
//반대로 DP[0][1~1000] -> 가방 부피가 0이면 가치도 0
//DP[i][j]=max(DP[i-j물건의 부피][j-1]+j물건의 가치, DP[i][j-1]);
//만약 j물건의 부피가 가방 부피보다 크다면 DP[i][j]=DP[i][j-1];

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define BAG_SIZE 1001
#define ITEMS 101

int DP[BAG_SIZE][ITEMS];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;

        for (int i = 1; i <= N; i++) {
            int V, C; //물건 정보, 가치
            cin >> V >> C;
            for (int j = 1; j <= K; j++) {
                if (V > j) DP[j][i] = DP[j][i - 1];
                else DP[j][i] = max(DP[j - V][i - 1] + C, DP[j][i - 1]);
            }
        }
        cout << '#' << t << ' ' << DP[K][N] << '\n';
    }
    return 0;
}
