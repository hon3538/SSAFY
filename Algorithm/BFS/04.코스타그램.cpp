#include <iostream>
#include <queue>

using namespace std;

vector<int>map[100001];
int visited[100001];
int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int from,to;
        cin>>from>>to;
        map[from].push_back(to);
        map[to].push_back(from);
    }
    int start;
    cin>>start;

    int cnt=0;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();

        for(int to=0;to<map[now].size();to++){
            int next=map[now][to];
            if(visited[next]>0)
                continue;
            visited[next]=visited[now]+1;
            if(visited[next]-1<=2){
                cnt++;
            }else break;
            q.push(next);
        }
    }
    cout<<cnt;
    return 0;
}