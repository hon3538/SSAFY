//kruskal 은 간선 위주 선택이고
//Prim은 노드 우선 선택이다
//#1 아무 노드부터 시작, PQ 시작 삽입
//#2 해당 노드에서 갈 수 있는 다음 간선정보 삽입
//#3 가장가까운 노드로 이동, 거기서 또 삽입
//삽입할 때마다 connected 여부 확인해서 연결되어있으면 PQ에 안 넣어주면 됨

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge{
    int to;
    int cost;
    bool operator <(Edge o) const{
        return cost>o.cost;
    }
};
int N,M;

vector<Edge>al[101];
int prim(int start){
    //#1 priority_queue 준비
    priority_queue<Edge>pq;
    pq.push({start,0});

    //#2 connected DAT를 준비
    //지금 내가 start 부터 시작한 MST의 일원으로 연결이 되어있는가?
    int connected[101]={0};
    int sum=0; // 비용
    int cnt=0;
    while(!pq.empty()){
        Edge now =pq.top();
        pq.pop();

        //이미 now가 MST의 일원이라면
        if(connected[now.to]==1)
            continue;
            //지금 이 노드까지 오는 길=MST의 일원

        //MST의 일원으로 새로 확보가 되는 노드
        connected[now.to]=1;
        sum+=now.cost;// 이 길의 비용을 누적
        cnt++;
        // now 에서 갈 수 있는 노드를 priority_queue에 삽입
        for(int i=0;i<al[now.to].size();i++){
            Edge next=al[now.to][i];
            //만약 이미 다음 갈려고 하는 노드 = MST의 일원 = 다시 안 봐도 된다
            if(connected[next.to]==1)
                continue;
            pq.push(next);
        }
    }
    if(cnt==N)
        return sum;
    return -1;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        al[from].push_back({to,cost});
        al[to].push_back({from,cost});
    }
    //prim-MST;
    cout<<prim(2);
}