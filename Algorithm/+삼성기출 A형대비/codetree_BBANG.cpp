//사람 m명
//1분때 1번 사람이 베이스 캠프로감

//시뮬레이션 (맵 15x15)
//n분에 n번째사람 (~30)
//사람마다 bfs로 찾아야함
//15x15 * 30 * 225(사람마다 최대 이동시간)  => 충분
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m; //격자크기, 사람 수
int map[15][15]; //1베이스 캠프, 
//사람 들어가면 사람 번호(편의점,베이스)적고 안 들어감
int visited[30][15][15];
struct Node{
    int y,x;
    int person;
    int time;
};
vector<Node>store;
Node bases[30];// 각 사람의 베이스 캠프위치
int dir[4][2]={-1,0,0,-1,1,0,0,1}; //위 왼 밑 오
int done[30]; // 안 봐도 되는 사람

//다익스트라로 하면 되잖아..
void dijk(){ // store 저장
    priority_queue<Node>pq;
    for(int i=0;i<m;i++){
        pq.push(store[i]);
    }
    int cnt=0; //사람들이 모두 베이스 캠프를 찾았는지

    while(!pq.empty()){
        Node now = pq.top();
        pq.pop();
        if(done[now.person]==1) continue; //이미 베캠 찾음?
        if(map[now.y][now.x]==1){ //베이스 캠프면
            done[now.person]=1;
            map[now.y][now.x]=-1;
        }
        visited[now.person][now.y][now.x]==1;

        for(int i=0;i<4;i++){
            int dy=now.y+dir[i][0];
            int dx=now.x+dir[i][1];
            if(dy<0||dx<0||dy>=n||dx>=0) continue;
            if(visited[now.person][dy][dx]==1)
        }
        
    }
}
int main(){
    cin>>n>>m;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x];
        }
    }

    for(int i=0;i<m;i++){ //0번이 첫번째 사람이 가야하는 편의점
        int a,b;
        cin>>a>>b;
        store.push_back({a-1,b-1,i,i+1});
    }
    //그냥 편의점에서 시작한다면? ㄴㄴ
    //베이스 캠프 찾아야함
    //편의점에서부터 bfs 한번씩
    


    return 0;
}
