#include <iostream>
#include <queue>

using namespace std;
int N,M;
int map[101][101];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
struct Node{
    int y,x;
};

int main(){
    cin>>N>>M;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            cin>>map[y][x];
        }
    }
    int ans=0;    
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            if(map[y][x]==0)
                continue;
            ans++;
            queue<Node>q;
            q.push({y,x});
            while(!q.empty()){
                Node now =q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int dy=now.y+dir[i][0];
                    int dx=now.x+dir[i][1];
                    if(dy<0||dx<0||dy>=N||dx>=M)
                        continue;
                    if(map[dy][dx]==0)
                        continue;
                    map[dy][dx]=0;
                    q.push({dy,dx});
                }
            }
        }
    }
    cout<<ans;
    return 0;
}