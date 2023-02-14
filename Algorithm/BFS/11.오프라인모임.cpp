#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
//시작->P 까지 최단 거리
//p->시작 까지 최단거리 
//두 거리 합 최대값..출력
int N,M,P; // 마을 개수, 도로 개수, 도착 마을
int Max;
struct Edge{
    int to;
    int cost;
    bool operator < (Edge o) const{
        return cost>o.cost;
    }
};
vector<Edge>v[1001];

int dijkstra(int start, int end){
    int dist[1001];
    priority_queue<Edge>pq;
    for(int i=0;i<=1000;i++){
        dist[i]=INT_MAX;
    }
    pq.push({start,0});
    dist[start]=0;
    while(!pq.empty()){
        Edge now=pq.top();
        pq.pop();
        if(now.cost>dist[now.to])
            continue;
        for(int to=0;to<v[now.to].size();to++){
            Edge next=v[now.to][to];
            int nextCost=now.cost+next.cost;
            if(nextCost>dist[next.to])
                continue;
            dist[next.to]=nextCost;
            pq.push({next.to,nextCost});
        }
    }
    return dist[end];
}
int main(){
    cin>>N>>M>>P;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    for(int i=1;i<=N;i++){
        int sum=dijkstra(i,P)+dijkstra(P,i);
        if(sum>Max){
            Max=sum;
        }
    }
    cout<<Max;
    return 0;
}