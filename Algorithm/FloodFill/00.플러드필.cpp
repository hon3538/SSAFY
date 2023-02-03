#include <iostream>
#include <queue>

using namespace std;

int map[5][5];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int isRange(int y,int x){
    if(y<0||x<0||y>=5||x>=5)
        return 0;
    return 1;
}
struct NODE{
    int y;
    int x;
};
int visited[5][5];
int main(){
    int y,x;
    cin>>y>>x;
    queue<NODE>q;
    q.push({y,x});
    visited[y][x]=1;

    while(!q.empty()){
    NODE now=q.front();
    q.pop();


    for(int i=0;i<4;i++){
        int dy=now.y+dir[i][0];
        int dx=now.x+dir[i][1];
        if(!isRange(dy,dx)||visited[dy][dx]>0)
            continue;
        visited[dy][dx]=visited[now.y][now.x]+1;
        q.push({dy,dx});
    }

    }

    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
            cout<<visited[y][x]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}