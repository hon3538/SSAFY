//DP[i][j]=k
//첫 번쨰 string의 i번째 문자까지와
//두 번째 string의 j번째 문자까지 봤을 때
//LCS 길이 k
//맨마지막 단어가 같으면 맨 마지막 단어를 추가하기 전길이와 추가했을때(+1)
//길이를 비교하여 큰 것으로 넣는다.
//왜냐하면 이전에 저장된 길이해 해당 단어가 이미 포함되었을 수도 있다.

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

#define MAX 1001
int DP[MAX][MAX];

int T;
int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string a, b;
        cin >> a >> b;
        memset(DP, 0, sizeof(DP));
        //function
        for (int i = 1; i <= a.length(); i++) {
            for (int j = 1; j <= b.length(); j++) {
                if (a[i - 1] == b[j - 1]) {
                    // 끝이 같으면
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                }
                else {
                    //다르면
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                }
            }
        }
        cout << '#' << t << ' ' << DP[a.length()][b.length()]<<'\n';
    }

    return 0;
}