//각 노드의 자식중에서 입력받은 두 노드를 포함하고 있으면 true를 출력한다 
//dfs 로 하기엔 노드수가 10000개임, BU DP로 자식 -> 부모 방향으로 가면서 DAT index: 부모, value 입력 노드로 저장한다
//두 번째 노드에서 마찬가지로 진행할때 visited 된 첫 부모가 가장 가까운 공통 조상이다.
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N;
int input1,input2;
vector<int>v[10001];
int ans;
int parent[10001];
int Find(int now){
    if(now==parent[now])
        return now;
    return parent[now]=Find(parent[now]);
}
void Union(int A,int B){
    int pa=Find(A);
    int pb=Find(B);
    if(pa==pb)
        return;
    parent[pb]=pa;
}
int func(int now){
    int count=0;
    int flag=false;
    if(now==input1||now==input2){
        count++;
        flag=true;
    }
    
    for(int i=0;i<v[now].size();i++){
        int next=v[now][i];

        int ret=func(next);
        if(ret==1) {count++; flag=true;}
    }
    if(count==2) ans=now;
    if(flag) return 1;

    return 0;
}
int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N;
        ans=0;
        for(int i=1;i<=N;i++){
            parent[i]=i;
        }
        for(int i=0;i<N-1;i++){
            int a,b;
            cin>>a>>b; //a가 b의 부모
            v[a].push_back(b);
            if(Find(a)!=Find(b)){
                Union(a,b);
            }
        }
        cin>>input1>>input2;
        func(Find(1));
        cout<<ans<<'\n';
        for(int i=0;i<=N;i++){
            v[i].clear();
        }
    }
    return 0;
}