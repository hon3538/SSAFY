// Dynamic Programming : 답을 기억하는 프로그래밍 기법
// 대표적인 예시 : 피보나치 수열
#include <iostream>

using namespace std;
int dp[101]; //DAT;
int fibo(int now){
    
    if(now<=2) //  기저 조건
        return 1;
    //내가 이것을 기억을 했었다면
    if(dp[now]!=0)
        return dp[now];
        
    //다시 여기까지 돌아오는 순간
    // = now까지의 정답을 찾았다
    // now번째의 정답을 아니까 -> 잊지 않도록 기억(기록)
    return dp[now]=fibo(now-1)+fibo(now-2);
}
int main(){ 


    return 0;
}