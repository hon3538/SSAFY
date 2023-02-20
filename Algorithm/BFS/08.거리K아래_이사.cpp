#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N,M; //  지역수 , 버스 관계
int R,K; // 직장위치, 탐승횟수 제한

vector<int>v[11];
int dist[11];
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin>>R>>K;
    queue<int>q;
    q.push(R);
    dist[R]=1;
    int cnt=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(dist[now]>K+1) // 조건 불만족
            continue;
        if(dist[now]<=K+1){ // 조건 만족
            cnt++;
        }
        for(int i=0;i<v[now].size();i++){
            int next=v[now][i];
            if(dist[next]>=1){ //visited
                continue;
            }
            dist[next]=dist[now]+1;
            q.push(next);
        }
    }

    cout<<cnt;
    return 0;
}