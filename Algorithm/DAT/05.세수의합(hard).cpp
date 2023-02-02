#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K;
int DAT[100001];
int index[5001];
int main() {
    cin >> N >> K;
    int t = 1;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        DAT[n] = t++; //index : 정수 , value : 들어온 순서
        index[i] = n;
    }
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int num = K - (index[i] + index[j]);
            if (num < 0||num>100000)
                continue;
            int order = DAT[num];
            if (order>0&&order>DAT[index[j]]) {
                cnt++;           
            }
        }
    }
    cout << cnt;
    return 0;
}

