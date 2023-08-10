
//값을 받을 때 해당 위치까지 합을 저장 (그냥 배열도 당연히 저장)
//longlong
// 구간합이면 뒷숫자까지 - 앞숫자까지
//교환이면 따로 그순번을 기준으로 뒤에있는 모든 순번에 값의 변화를 적용해야한다
//

#include <iostream>
using namespace std;
int N,M,K; // 수의 개수, 변경횟수, 구간 합 횟수
int arr[1000000];

int main(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<M+K;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){ //b번째수를 c값으로 change

        }else{ //구간합

        }
    }
    return 0;
}