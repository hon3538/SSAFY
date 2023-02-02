//순서대로 키와 번호를 입력받고
//키가 큰 순서대로 작은번호인지 확인
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <cstring>
using namespace std;
int DAT[1000001] = { 0 }; // index : 키값, value : height 
int h[1000001] = { 0 };
int num[1000001] = { 0 };
int main() {
    int T;
    cin >> T;
    vector<string>res;
    //순서대로 키를 입력받고
    //키를 큰 순서대로 0부터 배분, 같을경우 우선순위가 낮은 키
    //입력 받은 순서대로 키가 배분됐는지 확인
    for (int t = 0; t < T; t++) {
        memset(DAT, 0, sizeof(DAT));
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
        for (int i = 0; i < N; i++) {
            DAT[num[i]] = h[i];
        }
        int before = INT_MAX;
        int flag = true;
        for (int i = 1; i <= N; i++) {
            if (DAT[i] > before) {
                flag = false;
                break;
            }
            before = DAT[i];
        }
            if(!flag)
                 res.push_back("NO");
             else res.push_back("YES");

    }

     for(int i=0;i<T;i++){
         cout<<res[i]<<'\n';
     }
    return 0;
}
