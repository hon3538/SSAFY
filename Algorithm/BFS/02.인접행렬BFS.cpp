#include <iostream>
#include <queue>
using namespace std;

int N;
int map[11][11];
int main(){
    cin>>N;
    queue<int> q; 
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            cin>>map[y][x];
        }
    }
    int visited[100]={0};
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int now =q.front();
        q.pop();

        cout<<now<<" ";
        for(int to=0;to<N;to++){
            if(map[now][to]==0||visited[to]>0)
                continue;
            visited[to]=visited[now]+1;
            q.push(to);
        }
    }

}