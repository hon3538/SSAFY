#include <iostream>

using namespace std;

int parent[1001];
int Find(int now){
    if(now==parent[now])
        return now;
    return parent[now]=Find(parent[now]);
}
void Union(int a,int b){
    int pa=Find(a);
    int pb=Find(b);
    if(pa==pb)
        return;
    parent[pb]=pa;
}
int main(){
    int N,Q;
    cin>>N>>Q;
    for(int i=1;i<=N;i++){
        parent[i]=i;
    }
    for(int i=0;i<Q;i++){
        int k,a,b;
        cin>>k>>a>>b;
        if(k==0){
            if(Find(a)==Find(b))
                cout<<"YES\n";
                else cout<<"NO\n";
        }else if(k==1){
            Union(a,b);
        }
    }
    return 0;
}