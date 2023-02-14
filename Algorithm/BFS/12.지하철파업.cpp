#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
int V,E,P; //역의 개수, 도로 개수, 민철대리 위치
struct Edge{
    int to;
    int cost;
    
    bool operator < (Edge o) const{
        return cost>o.cost;
    }
};
vector<Edge>v[5001];
int dijkstra(int start,int end){
    int dist[5001];
    for(int i=0;i<=5000;i++){
        dist[i]=INT_MAX;
    }
    priority_queue<Edge>pq;
    pq.push({start,0});
    dist[start]=0;
    while(!pq.empty()){
        Edge now =pq.top();
        pq.pop();

        if(now.cost>dist[now.to])
            continue;
        for(int to=0;to<v[now.to].size();to++){
            Edge next =v[now.to][to];
            int nextCost = now.cost+next.cost;
            if(nextCost>dist[next.to])
                continue;
            dist[next.to]=nextCost;
            pq.push({next.to,nextCost});
        }
    }
    return dist[end];
}
int main(){
    cin>>V>>E>>P;
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    if(dijkstra(1,V)==dijkstra(1,P)+dijkstra(P,V))
        cout<<"OKAY";
    else 
        cout<<"SORRY";

    return 0;
}