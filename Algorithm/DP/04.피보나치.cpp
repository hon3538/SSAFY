#include <iostream>

using namespace std;
// 피보나치 수열 -> DP, Bottom-Up
// DP[1]=1,DP[2]=1 활용
// 0,1,1,2,3,5..
int DP[36];
int n;
int main(){
    cin>>n;
    DP[0]=0;
    DP[1]=1;
    

    for(int i=2;i<=n;i++){
        DP[i]=DP[i-2]+DP[i-1];
    }
    cout<<DP[n-1]; // n번째니까 index -> n-1
    return 0;
}