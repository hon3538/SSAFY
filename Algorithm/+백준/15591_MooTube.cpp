// N : 동영상 번호 (1~5000), Q : 농부의 질문 횟수 (1~5000)
// 임의의 두 동영상 사이 cost(USADO) 1~1000000000
// a -> b, b -> a 양방향 그래프
// a -> b 유사도는 모든 경로의 cost 중 최소 cost 로 결정된다.
// K , V : V부터 K 이상인 USADO를 가지는 동영상 개수

// 양방향 그래프 문제
// DP? 5000x5000 1억 byte 10^8 -> 100mb
// 왜냐면 그래프가 경로 탐색이 반복됨; 에바
// DP[출발노드][도착노드] = 최소 cost

// 근데 쿼리가 5000개라 어차피 최악의 경우가 250000000, 2천 오백만임
// 따라서 DP 할 필요 없다 ^^

// 그럼 쿼리가 있을 때마다 모든 쿼리를 탐색해서 각 노드, Dijkstra
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,Q;
struct Edge{
    int to;
    int cost;
    int Min;
};
vector<Edge>v[5001];
//int visited[]
int dijkstra(int start){
    priority_queue<Edge>pq;
    pq.push({start,10000,10000});

    while(!pq.empty()){
        Edge now=pq.top();
        pq.pop();

        for(int i=0;i<v[now.to].size();i++){

        }
    }
}
int main(){
    cin>>N>>Q;
    //graph 정보 입력
    for(int i=0;i<N-1;i++){ 
        int a,b,c; 
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    // 출발 노드에서 k 값보다 큰 USADO를 구하라
    // k보다 USADO가 작아지는 순간 out
    for(int i=0;i<Q;i++){
        int k,start;
        cin>>k>>start;
        int ret=dijkstra(start); // 가능한 동영상 개수출력
    }
    return 0;
}