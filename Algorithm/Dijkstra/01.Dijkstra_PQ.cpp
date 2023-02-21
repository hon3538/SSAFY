// 준비 단계
// #1 priority queue 준비
// -> 시작 Edge를 일단 삽입 (시작노드,0)
// #2 dist 준비
// -> 모두 max로 초기화
// -> 시작노드까지의 최단거리를 0으로 설정
// -> dist는 시작노드에서 각 노드들의 최단 거리만을 저장하는 DAT 배열
// -> 모든 노드 거리를 저장해놓고 필요한 노드의 거리를 dist에서 바로 뽑아쓸 수 있다.
// #3 visited 준비

// 구현 단계 
// #1 더이상 갈 후보지가 없을 때까지 반복
// #2 가장 가중치가 작은 간선 채택 -> (top)=now
// -> 이 노드를 확정
// #3 now로부터 갈 수 있는 간선들 확인하면서 
// -> dist 기록갱신
// -> pq에 후보지 삽입

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct Edge{
    int node;
    int cost;
};
vector<Edge>v[100];
int N,E;
int dist[100];
int visited[100];
int main(){
    cin>>N>>E;
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    for(int i=1;i<N;i++){
        dist[i]=INT_MAX; // 21e8
    }
    priority_queue<Edge>pq;
    pq.push({0,0});
    dist[0]=0;
    
    while(!pq.empty()){
        Edge now=pq.top();
        pq.pop();

        for(int i=0;i<v[now.node].size();i++){
            Edge next=v[now.node][i];
            if(visited[now.node]==1)
                continue;
            int nextCost=next.cost+dist[now.node];
            if(dist[next.node]<nextCost)
                continue;
            dist[next.node]=nextCost;
            pq.push(next);
        }
    }
    return 0;
}
/*
void dijkstra(int start) {
    // priority queue
    priority_queue<Edge>pq;
    // 시작 노드를 삽입 
    pq.push({ start, 0 });

    // dist
    int dist[100] = { 0, };
    int MAX = 21e8;
    for (int i = 0; i < N; i++)
        dist[i] = MAX;
    dist[start] = 0; 

    // visited
    //int visited[100] = { 0, }; 

    // 구현 단계
    // 더이상 갈 후보지가 없을떄 까지 반복 
    while (!pq.empty()) {
        // 후보지 중 가장 가중치가 낮은 간선을 뽑아옵니다. 
        // priority queue -> cost를 기준으로 MINHEAP
        Edge now = pq.top();
        pq.pop(); 

        // 이미 확정된 노드라면 이 노드에 대해서는 아무것도 안해도 된다!
        //if (visited[now.to] == 1)
            //continue; 
        // now까지의 최단거리 확정된다! 
        //visited[now.to] = 1; 

        //dist[now.to]가 INT_MAX가 아니라는 것은 이미 방문했다는것이고
        //동시에 최소값이라는 것이다.
        //왜냐면 pq.push하기전에 각 경로에서 dist보다 작을 경우에만
        //dist를 업데이트 해줬고 경로에 있는 cost들을 더해서 다음 edge의 cost에 업데이트해주므로
        //queue에 들어갔다고 해도 cost로 priority_queue 정렬을 해주므로
        //같은 노드로 오는, 나중에 나오는 edge 값은 곧 cost가 더 높은 것이므로
        //backtracking 해주면 visited 변수 없이도 visited 처리 할 수 있다.  
        if (dist[now.to] < now.cost)  // 같은 경우는 진행, 이전에 더 작은길잉 없었다는 뜻
            continue;
//이걸 안해주면 dist =짧은 경로 -> 나중에 -> dist =더 짧은 경로
        // 일때 더짧은 경로를 먼저 들어오긴하지만 pq에는 그냥 짧은 경로도 들어가있기때문
        그냥 여기서 dist를 업데이트를 해줄 수도 있지만
        dist 말고 다른 조건등이 있을 때, 또 이전 node와 next node 사이
        정보를 이용해야 할 때는 next를 받아오는 for문안에서 진행한다
        따라서 for문 안에서 next도 가기전에 dist를 업뎃해준다.

        여기도 하고 for문도 하면 어떻게 될까?
        결론은 의미없다..어차피 dist는 업데이트 돼서 들어오기때문에
        
        //이해를 쉽게하기 위해서 dist[node] 는 해당 노드에 어떤 경로로
        //몇 번의 경로를 거치든 상관없이 시작점에서 부터 가장 작은 cost값을
        //저장한다 다음에 갈 노드의 dist[node]가 더 작으면 q에 안 넣으므로..
        //cost가 작은 경로 위주로 가므로, 가야할 길이 이미 cost가 정해졌다면
        //다른 더 빠른 길에서 이미 그길을 향해서 지나간 것이다.

        // now로부터 갈수 있는 간선들을 확인
        for (int i = 0; i < al[now.to].size(); i++) {
            Edge next = al[now.to][i];
            // ncost = next번까지의 최종 비용
            int ncost = dist[now.to] + next.cost; 
            // 만약 지금 최종 비용이 이미 기록되어있는 후보 경로의 비용보다 크거나 같으면
            if (dist[next.to] <= ncost)
                continue; // 쓸모없는 경로 
            // next까지 가기 위한 새로운 최단 거리  찾음!~
            dist[next.to] = ncost; -> 현재 dist보다 더 적은 길로 갈 수 있으면 q에 업뎃해줌 , 그리고 q에서 뺄때 확인
            // 새로운 후보지로 등록 
            //가능한 후보들을 다 넣어놓고 pq에서 나오는 순간 그노드는 확정임 
            pq.push({ next.to, ncost });
        }
    }
    for (int i = 0; i < N; i++) {
        cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
    }
}

int main() {
    cin >> N >> M;
    // 간선 정보 입력
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost; 
        al[from].push_back({ to, cost });
        al[to].push_back({ from, cost });
    }
    dijkstra(0); 
}
*/