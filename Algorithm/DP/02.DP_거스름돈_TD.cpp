#include <iostream>
using namespace std;
//거스름돈
/*
1200 5
10 50 100 400 500
*/
//#1 Top-Down
// 각 동전을 branch로 두고 재귀적으로 내려감
// 현재값에서 선택한 동전을 빼보면서 0원이 나오면 정답이 될 수 있다!
// - 값이 나오면 정답이 될 수 없다!

//그럼 정답과 오답을 찾았을 때 어떤 값을 상위로 return을 해줘야 될까?
//해당 가격에서 최소한의 가격이 되게하는 동전의 개수를 저장해줘야하므로
//하위에서 올라온 모든 branch의 값들의 최솟값을 저장한다.

//index:특정 거슬름돈 액수
//value:그 거스름돈을 돌려주기 위한 최소 동전 갯수
int dp[10001]; 
int target; //만들어야하는 거스름돈
int N;
int coins[100];
//# Top-Down
int func(int now){
    //기저 조건
    if(now ==0) {//답을 찾았다
        //정답에 영향을 주지 않는 값 return
        return 0;
    }
    if(now <0){ // 오답이다 
        //now까지의 기록에 최소값이 저장될 수 있도록
        //영향을 미칠 값 즉, 아~주 큰 값을 return
        return 21e8;
    }
    if(dp[now]!=0){
        return dp[now];
    }
    //재귀 구성
    //now에서부터 각 동전종류별로 하나씩 빼가면서 내려간다
    int Min=21e8;
    for(int i=0;i<N;i++){
        //now로 다시 올라오면
        //coin개수를 하나 카운트
        int count=func(now-coins[i])+1;
        if(Min>count){
            Min=count;
        }
    }
    return dp[now]=Min;
}
int main(){
    cin>>target>>N;
    for(int i=0;i<N;i++){
        cin>>coins[i];
    }
    cout<<func(target);
    return 0;
}