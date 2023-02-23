#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
// 시작점에서 특정 경로를 통해서 목적지로 최소한의 거리로 가야함
// 만약 갈 수 있는 길 중 특정 경로를 확인한다면
//특정경로 없이 가는 최단경로와 특정경로를 끼고 가는 최단경로가 같으면 그노드 출력
// -> 그냥 dijkstra 돌리고 특정경로를 지났는지 안 지났는지 확인하면 됨
int n,m,o; // 지점(노드)개수(2000), 도로(간선)개수(50000), 목적지 후보 개수(100)
int s,g,h; // 출발지, 지나간 지점 두개
struct Edge{
    int to;
    int cost;
    int flag=false; //특정경로를 지난 flag 이냐?
    bool operator < (Edge o) const {
        // if(cost==o.cost){
        //     if(o.to==h||o.to==g)
        //         return true;
        // }
        return cost>o.cost;
    }
};
int flag; // 특정경로를 지났는지 확인, 지난 후부터 각 노드들의 최소거리 업데이트하기 위함, default:false
int dist[2001]; 
int passed[2001];
vector<Edge>v[2001];
vector<int>goal;
void dijkstra(int start){
    priority_queue<Edge>pq;
    pq.push({start,0});
    dist[start]=0; 
    while(!pq.empty()){
        Edge now=pq.top();
        pq.pop();
        if(dist[now.to]<now.cost)
            continue;

        if(now.flag==true) // 해당 경로가 특정경로 이후 경로라면
            passed[now.to]=1;
        for(int i=0;i<v[now.to].size();i++){
            Edge next=v[now.to][i];
            int nextCost=now.cost+next.cost;
            next.flag=now.flag;
            if(dist[next.to]<nextCost) //같은 경우는 다시 봐준다. 특정 경로로 갈 수도 있기때문에
                continue;
            dist[next.to]=nextCost;
            if((next.to==g||next.to==h)&&(now.to==g||now.to==h)){ 
                //now.to가 h or g && next.to 도 h or g면 이것은 특정경로
                next.flag=true;
            }
            pq.push({next.to,nextCost,next.flag});
        }
    }
}
int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n>>m>>o;
        cin>>s>>g>>h;
        
        goal.clear();
        flag=false;
        memset(v,0,sizeof(v));
        memset(dist,0,sizeof(dist)); 
        memset(passed,0,sizeof(passed));
        for(int i=0;i<=n;i++){
            dist[i]=21e8;
        }
        for(int i=0;i<m;i++){
            int a,b,d; // a와 b사이 양방향 도로, d거리
            cin>>a>>b>>d;
            v[a].push_back({b,d});
            v[b].push_back({a,d});
        }
       for(int i=0;i<o;i++){ //목적지 후보
            int g;
            cin>>g;
            goal.push_back(g);
       }
       dijkstra(s);
       sort(goal.begin(),goal.end());
        for(int i=0;i<o;i++){
            if(passed[goal[i]]==1){
                cout<<goal[i]<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}