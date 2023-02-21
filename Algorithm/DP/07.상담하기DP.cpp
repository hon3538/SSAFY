#include <iostream>
#include <vector>
using namespace std;
//DFS로 구현가능할 듯 한데..쨋든
//최대 수익
//DP -> index:날짜, value : 얻을 수 있는 최대 수익
//각 날짜의 돈의로 초기화
//DP[0]=0 일을 안 하면 수익 0..
//1일에 번 수익은 다음 가능한 날짜의 수익(DP말고 origin 수익)을 DP에 업데이트해준다.
//단 기존 DP값과 비교해서 큰 것을 넣어준다.
//2일도 역시 반복..
int N;
struct date {
    int days;
    int income;
};
vector<date>v;
int DP[101];
int main() {
    cin >> N;
    v.push_back({ 0,0 }); //0일 초기화
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
        DP[i + 1] = b;
    }
    DP[0] = 0; // 0일 0원
    //1일 일하고 다음 가능한 날짜들에 수익을 더해준다
    //2일 일하고 다음 가능한 날짜들의 수익과 기존 수익과 비교한다
    //더 높으면 넣어주고 아니면 만다.
    //반복한다.
    for (int i = 1; i <= N; i++) {
        int days = v[i].days;
        //앞 날짜부터 보기때문에 DP[i]는 고정된 숫자이다.
        //i날짜에서 번돈을 j날짜의 소득에 더해준다. 
        //단 더해주기 전에, 이전에 j날짜에 업데이트된 소득이 더큰지 확인해야한다
        //DP의 value가 최대 소득을 계속 업데이트 하기 때문이다.
        for (int j = i + days; j <= N; j++) { 
            if (v[j].income + DP[i] > DP[j]) { 
                DP[j] = DP[i] + v[j].income;
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (max < DP[i])
            max = DP[i];
    }
    cout << max;
    return 0;
}