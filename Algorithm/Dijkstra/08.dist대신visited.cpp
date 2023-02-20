#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <cstring>
using namespace std;
int C,P,K,A,B; // 양방향 길의 개수, 건물 개수, 코코위치, 부착위치 A,B

struct Edge{
    int to;
    int cost;
    bool operator < (Edge o) const{
        return cost>o.cost;
    }
};
vector<Edge>v[100001];
int visited[100001];
int bfs(int node,int search){
    priority_queue<Edge>pq;
    memset(visited,0,sizeof(visited));
    pq.push({node,0});
    while(!pq.empty()){
        Edge now=pq.top();
        pq.pop();
        
        if(visited[now.to]==1)
            continue;
        visited[now.to]=1;
        if(visited[search]==1){
            return now.cost;
        }
        for(int i=0;i<v[now.to].size();i++){
            Edge next=v[now.to][i];
            if(visited[next.to]==1)
                continue;
            next.cost+=now.cost;
            pq.push(next);
        }
    }
}
int main(){
    cin>>C>>P>>K>>A>>B;
    for(int i=0;i<C;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int ans1;
    int ans2;
    ans1=bfs(K,A)+bfs(A,B);
    ans2=bfs(K,B)+bfs(B,A);
    if(ans1>ans2){
        cout<<ans2;
    }else cout<<ans1;

    return 0;
}