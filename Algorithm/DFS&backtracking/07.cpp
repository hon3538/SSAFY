#include <iostream>

using namespace std;

int map[6][6]={
    0,0,1,1,0,1,
    0,0,0,1,1,1,
    0,0,0,0,1,1,
    0,0,0,0,0,0,
    1,0,0,0,0,1,
    0,0,0,0,0,0
};
int visited[6];
void dfs(int now){
    if(visited[now]==1)
        return;
    visited[now]=1;
    cout<<now<<" ";
    for(int to=0;to<6;to++){
        if(map[now][to]==0||visited[to]==1)
            continue;
        dfs(now);
    }
}
int main(){
    int start;
    cin>>start;

    dfs(start);
    return 0;
}