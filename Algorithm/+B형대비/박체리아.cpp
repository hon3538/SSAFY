/*** user.cpp ***/
 
#define MAX_N 100

#include <iostream>
#include <queue>
using namespace std;
int Energy[MAX_N][MAX_N];
int type[MAX_N][MAX_N]; // 타입이 무엇인지 0 nothing, 1빨간 , 2파란
int ans;
void init(int N, int Dish[MAX_N][MAX_N])
{
    for(int y=0;y<MAX_N;y++){
        for(int x=0;x<MAX_N;x++){
            Energy[y][x]=Dish[y][x];
        }
    }
    

}

int dir[4][2]={-1,0,0,1,1,0,0,-1};
struct Node{
    int y,x;
};
void sex(int y,int x,int e){ //type, y,x, energy
    priority_queue<Node>pq; // 비어있는 곳 우선순위대로 정렬
    queue<Node>q; // floodfill 용
    int t=type[y][x];
    int visited[100][100];
    q.push({y,x});
    visited[y][x]=1;
    while(!q.empty()){
        Node now=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int dy=now.y+dir[i][0];
            int dx=now.x+dir[i][1];
            if(dy<0||dx<0||dy>=MAX_N||dx>=MAX_N) continue;
            if(type[dy][dx]!=0&&type[dy][dx]!=t) continue;
            if(visited[dy][dx]==1) continue;
            visited[dy][dx]=1;
            if(type[dy][dx]==0){
                pq.push({dy,dx});
                continue;
            }
            q.push({dy,dx});
        }
    }    
    while(e>0&&!pq.empty()){
        Node now=pq.top();
        pq.pop();
        type[now.y][now.x]=t;
        ans++;
        e-=Energy[now.y][now.x];
        for(int i=0;i<4;i++){
            int dy=now.y+dir[i][0];
            int dx=now.x+dir[i][1];
            if(dy<0||dx<0||dy>=MAX_N||dx>=MAX_N) continue;
            if(type[dy][dx]!=0) continue;
            if(visited[dy][dx]==1) continue;
            visited[dy][dx]=1;
            pq.push({dy,dx});
        }
    }
}
int dropMedicine(int totalTarget, int R, int C, int totalEnergy)
{
    //다르면 나가
    if(type[R-1][C-1]!=0&&type[R-1][C-1]!=totalTarget) return ans;
    //같으면 바로 번식 floodfill
    if(type[R-1][C-1]==totalTarget) {
        sex(R-1,C-1,totalEnergy);
        return ans;
    }
    //비었으면 에너지깎고 바로 번식
    totalEnergy-=Energy[R-1][C-1];
    type[R-1][C-1]=totalTarget;
    ans++;
    sex(R-1,C-1,totalEnergy);
    return ans;
}
 
int cleanBacteria(int R, int C)
{
    int y=R-1;
    int x=C-1;
    int t=type[y][x];
    queue<Node>q;
    q.push({y,x});
    type[y][x]=0;
    ans--;
    while(!q.empty()){
        Node now=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int dy=now.y+dir[i][0];
            int dx=now.x+dir[i][1];
            if(dy<0||dx<0||dy>=MAX_N||dx>=MAX_N) continue;
            if(type[dy][dx]!=t) continue;
            type[dy][dx]=0;
            ans--;
            q.push({dy,dx});
        }
    }   
    
    return ans;
}