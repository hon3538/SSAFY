//사람이름임 최단 거리를 구하는 알고리즘
//BFS는 최단 경로(가중치x), Dijkstra는 최단 거리(가중치o)

// 준비단계
// 1. dist DAT 필요 -> dist[출발지]=0;
// 2. visited 필요 (지금 이 노드의 최단 거리가 확정이 되었는가?-방문하는순간 확정된거임)

// 구현단계
// 1. 모든 노드의 최단거리가 확정될 때까지
// 2. 지금 dist에 기록되어있는 [후보 거리]중 가장 작은 간선을 가진 노드를 찾는다.
// -> PQ
// 3. now 노드로부터 갈 수 있는 모든 간선들을 확인하면서 dist에 후보지를 갱신
// -> 만약 이미 가진 후보지보다 작거나 같은 경로가 나타나면 갱신할 필요 없음
#include <iostream>
#include <vector>
using namespace std;

/*
10 13
0 1 1
0 3 4
0 2 5
1 4 3
1 5 6
2 5 8
2 7 10
2 6 9
7 6 11
6 9 2
6 8 13
7 8 12
5 6 7
*/

struct Edge {
    int to; // 어디로 향하는 간선이고?
    int cost; // 가중치
};

int N, M; // N : 노드의 개수, M : 간선의 개수
vector<Edge>al[100]; 


// 시간복잡도 : O(V^2)
void dijkstra(int start) {
    // dist 준비
    int dist[100] = { 0, };
    // 모두 아주 큰 값이 들어가도록 세팅
    int MAX = 21e8; 
    for (int i = 0; i < N; i++)
        dist[i] = MAX; 
    // 출발지까지는 가중치 = 0
    dist[start] = 0; 

    // visited 준비
    // index: 노드, value: 지금 이 노드의 최단 거리가 확정이 되었는가? 
    int visited[100] = { 0, }; 

    // dijkstra 동작을 구현 
    // 노드의 개수만큼 반복 -> 한번 돌때마다 하나의 노드의 최단 거리가 확정
    // 즉, 모든 노드의 최단거리가 확정될때까지 
    for (int i = 0; i < N; i++) {

        int mincost = 21e8; // 지금 가장 작은 가중치를 가진 간선의 값
        int now = -1; // 내가 지금 가려고 하는 노드 

        // 지금 가장 가중치가 작은 간선을 찾을것 
        for (int j = 0; j < N; j++) {
            // j번째 노드에 기록된 후보지가 최소값보다 작으면 -> 갱신 
            if (dist[j] >= mincost)
                continue; 
            // 이미 확정된 노드라면 -> 다시 갈 필요 X
            if (visited[j] == 1)
                continue; 
            // 새로운 최소값을 찾았다! 
            mincost = dist[j];
            now = j; 
        }

        // now까지의 최단 거리 = 확정
        visited[now] = 1; 

        for (int j = 0; j < al[now].size(); j++) {
            Edge next = al[now][j]; 
            // 다음 노드까지의 비용 = 지금 확정된 노드까지의 비용(거리) + next까지 가는 비용
            int ncost = dist[now] + next.cost; 
            // 새로운 경로를 찾았다
            // 하지만, 이미 기록된 후보지보다 더 오래걸리는 경로면 쓸모 없다 
            if (dist[next.to] <= ncost)
                continue; // 새로운 후보지로 등록하지 않는다. 
            dist[next.to] = ncost; 
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