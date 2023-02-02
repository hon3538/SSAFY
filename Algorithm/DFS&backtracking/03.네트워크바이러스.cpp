#include <iostream>
#include <vector>
using namespace std;

vector<int>net[101];
int visited[101]; // index :컴퓨터 번호, value : 방문여부
int cnt;
void dfs(int now){
    visited[now]=1;
   
    for(int i=0;i<net[now].size();i++){
        int com=net[now][i];
        if(visited[com]==1)
            continue;
        cnt++; 
        dfs(com);
        //visited[i]=0;
    }
}
int main(){
    int N,E; // 노드, 간선
    cin>>N>>E;
    for(int i=0;i<E;i++){
        int from, to;
        cin>>from>>to;
        net[from].push_back(to);
        net[to].push_back(from);
    }
    dfs(1);
    cout<<cnt;

    return 0;
}