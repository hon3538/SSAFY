#include <iostream>
using namespace std;

#define MAX 2000

int N, X; // 총생활관 수(~2000), 분배 기준(~100000)
int room[MAX];

int main(){
    cin>>N>>X;
    for(int i=0; i<N; i++){
        cin>>room[i];
    }

    int spare=0; // 나머지
    for(int i=0; i<N; i++){
        spare += room[i]%X;
    }
    if(spare%X==0) cout<<1;
    else cout<<0;

    return 0;
}