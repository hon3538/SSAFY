#include <iostream>
#include <queue>
using namespace std;

int N,M,K;
struct dungeon{
    int num;
    int val;
};
vector<dungeon>v[11];
int DAT[11]; //index 던전 , value : 가중치 

int main(){
    cin>>N>>M>>K;
    queue<dungeon> q;
    for(int i=0;i<M;i++){
        int from,to,value;
        cin>>from>>to>>value;
        v[from].push_back({to,value});
        //mat[from][to] = cost; 인접행렬로 바로 받을 수도 있음..
    }

    q.push({0,0});
    while(!q.empty()){
        dungeon d=q.front();
        q.pop();
        for(int to=0;to<v[d.num].size();to++){
            int n=v[d.num][to].num;
            if(DAT[n]>0)
                continue;
            DAT[n]=d.val+v[d.num][to].val;
            if(DAT[n]>K)
                continue;
            q.push(v[d.num][to]);
        }
    }
    for(int i=0;i<=N;i++){
        if(DAT[i]>0&&DAT[i]<=K){ cout<<i<<" ";}
    }
    return 0;
}