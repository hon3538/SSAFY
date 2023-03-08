//무게(~100000)와 가치(~1000)가 다른 물건 100개 
//10만 무게까지 버틸 수 있음
//최대 가치는?
//완전탐색? 100개라 dfs 불가능
//DP? 무게가 0일땐 가치 0, 
// TD
// weight 으로 받고
// 각 물건 무게를 빼면서 return 은 가치 출력
// DP : index -> weight , value 가치
#include <iostream>

using namespace std;
int N,K;
int weight;
int thing[100][2]; // 0: 무게, 1:가치
int used[100];
int DP[100001];
int func(int now){
    if(weight<=0)
        return 0;
    if(DP[now]!=0)
        return DP[now];
    int max=-21e8;
    int idx=-1;
    for(int i=0;i<N;i++){
        if(used[i]==1)
            continue;
        used[i]=1;
        now-=thing[i][0];
        int ret=func(now);
        now+=thing[i][0];
        used[i]=0;
        if(max<ret){ max=ret; idx=i;}
    }
    return DP[now]=max+thing[idx][1];
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        thing[i][0]=a;
        thing[i][1]=b;
    }
    cout<<func(K);
}