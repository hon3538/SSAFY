#include <iostream>
#include <string>
#include <limits.h>
#include <queue>
using namespace std;
int N;
int map[50][50];
struct Node{
    int y,x;
    int cost;
    bool operator < (Node o) const{
        return cost>o.cost;
    }
};
int dist[50][50];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
void dijkstra(Node start){
    priority_queue<Node>pq;
    pq.push(start);

    while(!pq.empty()){
        Node now = pq.top();
        pq.pop();

        if(dist[now.y][now.x]<=now.cost){ //이미 해당지역을 들렸다면
            continue;
        }
        dist[now.y][now.x]=now.cost;
        for(int i=0;i<4;i++){
            int dy=now.y+dir[i][0];
            int dx=now.x+dir[i][1];
            if(dy<0||dx<0||dy>=N||dx>=N)
                continue;
            int nextCost=now.cost+map[dy][dx];
            if(dist[dy][dx]<=nextCost)
                continue;
            pq.push({dy,dx,nextCost});
        }
    }
}
int main(){
    cin>>N;
    
    for(int y=0;y<N;y++){
        string s;
        cin>>s;
        for(int x=0;x<N;x++){
            map[y][x]=((s[x]-'0')+1)%2;

            dist[y][x]=INT_MAX;
        }
    }
    dijkstra({0,0,0});
    cout<<dist[N-1][N-1];

    return 0;
}