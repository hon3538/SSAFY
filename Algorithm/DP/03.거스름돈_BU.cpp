//Bottom-UP
#include <iostream>
using namespace std;
int DP[10001];
int N;
int coins[100];
int target;

int main(){
    cin>>target>>N;
    for(int i=0;i<N;i++){
        cin>>coins[i];
    }
    //우리가 알 수 있는 가장 작은 단위
    //0원 -> 0개의 coin을 준다고 생각
    //점화식을 만들어 내야됨..
    //500원은 500원동전이 있으므로 1개로 만들 수 있음
    //500원의 배수는 개수를 알 수 있음
    //나머지 코인의 배수도 마찬가지
    //겹치는 부분은 최소값이 들어가야하므로
    //이미 값이 들어가있다는 것은 최소값이라는 의미..
    //이런식으로 모든 table(DP)를 채워나감
    
    //배수가 아닌 애들은 해당 값에서 500원, 400원 100원 ..값을 빼본
    //DP 값들중 최솟값으로 채워 넣는다
    // ex) 900원은 -100원은 DP[800]+1=3개, 900-400 -> DP[500]+1=2개,
    // 따라서 900원은 2개로 구성 가능
    
    //초기값은 맥스로 초기화
    for(int i=0;i<=target;i++){
        DP[i]=21e8;
    }
    DP[0]=0;
    //모든 코인에 대해서 테이블을 채운다
    for(int i=0;i<N;i++){
        int now=coins[i];
        for(int j=now;j<=target;j++){
            //지금 위치에서 내 동전의 값만큼을 뺀 공간에서
            //동전을 하나 더 추가했을 때 -> 지금 now를 만들 수 있는 값이 나온다
            //이미 dp에 기록된 값보다 많은 개수로 만들게 된다면 갱신 x
            if(DP[j-now]+1<DP[j]){
                DP[j]=DP[j-now]+1;
            }
        }
    }
    for(int i=0;i<=target;i++){
        cout<<DP[i]
    }
    return 0;
}