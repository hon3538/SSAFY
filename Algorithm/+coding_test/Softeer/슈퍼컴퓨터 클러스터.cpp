/*
컴퓨터 10만개
비용 10^18
성능 10^9  = 10억
PS 로 가장 낮은 성능이 가능한지 확인
*/
#include <iostream>
#include <math.h>
using namespace std;

#define MAX 100000
int N, B; //컴퓨터 개수, 예산
int computer[MAX]; // 각 컴퓨터의 성능
int minVal=0x7fffffff;
bool isValid(int target){
    long long price = B;
    for(int i=0; i<N; i++){
        if(target <= computer[i]) continue;
        price -= pow(target - computer[i], 2);
        if(price<0) return false;
    }
    return true;
}
int ps(int left, int right){ // 성능
    int ans = minVal;  

    while(left<=right){
        int mid = (left+right)/2;
        if(isValid(mid)){ //모든 컴퓨터를 최소 성능을 mid로 맞출 수 있는지?
            left = mid +1;
            ans = mid;
        }else{
            right = mid - 1;
        }
    }
    return ans;
}
int main(){
    cin>>N>>B;
    for(int i=0; i<N; i++){
        cin>>computer[i];
        if(minVal>computer[i]) minVal = computer[i];
    }
    cout<<ps(minVal,B);
    return 0;
}