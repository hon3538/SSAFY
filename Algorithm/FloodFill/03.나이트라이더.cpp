#include <iostream>
#include <queue>
using namespace std;

int h,w;
int dir[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};

int isRange(int y,int x){
    if(y<=0||x<=0||y>h||x>w)
        return 0;
    return 1;
}
struct NODE{
    int y;
    int x;
};
int main(){
    cin>>h>>w;
    int knight[2];
    int target[2];
    cin>>knight[0]>>knight[1]>>target[0]>>target[1];
    int visited[101][101]={0};

    queue<NODE>q;
    q.push({knight[0],knight[1]});
    visited[knight[0]][knight[1]]=1;
    int ans=0;
    while(!q.empty()){
        NODE now = q.front();
        q.pop();

        if(target[0]==now.y&&target[1]==now.x){
            ans=visited[now.y][now.x];
            break;
        }
        
        for(int i=0;i<8;i++){
            int dy=now.y+dir[i][0];
            int dx=now.x+dir[i][1];
            if(!isRange(dy,dx)||visited[dy][dx]>0)
                continue;
            visited[dy][dx]=visited[now.y][now.x]+1;
            q.push({dy,dx});
        }

    }
    cout<<ans-1;
    return 0;
}
