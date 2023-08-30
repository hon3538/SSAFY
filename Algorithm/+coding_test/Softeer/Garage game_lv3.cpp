/*
dfs
branch : 각 map 위치 (275)
level : 3
-> 275^3 = 약 2300만
한번당 각 칸들이 밑으로 내려올 떄 15번..
2300만 * 15 -> 3억.. 3초.. 
backtracking 해당 위치에 암것도 없으먄 return 0

최대 map 크기 15x15
색상 1~10억
*/

#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

#define MAP_SIZE 15

int map[MAP_SIZE][MAP_SIZE];
queue<int> q[MAP_SIZE]; //각 열의 위에서 떨어질 차
int Max;
int N;

int dir[4][2]={-1,0,0,1,1,0,0,-1};
int cnt[MAP_SIZE];
struct Node{
    int y,x;
};
unordered_set<int> visited; // hash -> y*100 + x
int getScore(int y, int x){
    // 상하좌우로 같은 것들 탐색
    queue<Node> qq;
    qq.push({y,x});
    visited.clear();
    while(!qq.empty()){
        Node now = qq.front();
        qq.pop();

        for(int i=0;i<4;i++){
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            int hash = dy*100 + dx;
            if(dy<0||dx<0||dy>=N||dx>=N) continue;
            if(visited.find(hash)!= visited.end()) continue;
            visited.insert(hash);

        }
    }
}
void dfs(int level, int score){
    if(level==3){
        if( Max < score) Max = score;
        return;
    }

    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            if(map[y][x] == 0) continue;
            int ret = getScore(y,x);
            dfs(level+1, y, x, )
        }
    }
}
int main(){
    cin>>N;
    for(int i=0; i<2*N; i++){
        for(int j=0;j<N; j++){
            int n;
            cin>>n;
            q[j].push(n);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }

    return 0;
}
/*
2N은 q로 저장
각 열이 깨진 개수마다 map을 옮김
*/