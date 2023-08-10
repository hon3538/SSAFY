#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_SIZE 605
#define INT_MAX 0x7fffffff
struct Node {
    int city; //도착 city
    int cost;
    bool operator < (Node a) const {
        return cost > a.cost;
    }
};
vector<Node> to_graph[MAX_SIZE]; // 정상 방향
vector<Node> from_graph[MAX_SIZE]; // 반대로 저장
unordered_map<int, int> um; //<실제 city num , 치환 id>
int current_index;

int dist[MAX_SIZE];

int to_dijkstra(int hub) {
    for (int i = 0; i < MAX_SIZE; i++) {
        dist[i] = INT_MAX;
    }
    priority_queue<Node> pq;
    pq.push({ hub,0 });
    dist[hub] = 0; //dist 를 1부터 시작했으니 나중에 -1 해준다
    int cost = 0;
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        //이미 방문한적 있으면 넘어가 (같으면 아직 방문 x 체크만 해둔거, 더 작으면 이미 방문한거)
        if (dist[now.city] < now.cost) continue;
        cost += dist[now.city];
       // cout << "to:" << now.city << " cost:" << dist[now.city]<<'\n';
        for (int i = 0; i < to_graph[now.city].size(); i++) {
            Node next = to_graph[now.city][i];
            //이미 방문했었지만, 기존에 더 최단거리로 방문한적 있으면 넘어가
            int nextCost = dist[now.city] + next.cost;
            if (dist[next.city] <= nextCost) continue;
            //현재가 최단거리면 방문해
            dist[next.city] = nextCost;
            pq.push({ next.city,nextCost });
        }
    }
    return cost;
}
int from_dijkstra(int hub) {
    for (int i = 0; i < MAX_SIZE; i++) {
        dist[i] = INT_MAX;
    }
    priority_queue<Node> pq;
    pq.push({ hub,0 });
    dist[hub] = 0; //dist 를 1부터 시작했으니 나중에 -1 해준다
    int cost = 0;
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        //이미 방문한적 있으면 넘어가 (같으면 아직 방문 x 체크만 해둔거, 더 작으면 이미 방문한거)
        if (dist[now.city] < now.cost) continue;
        cost += dist[now.city];
       //cout << "to:" << now.city << " cost:" << dist[now.city] << '\n';
        for (int i = 0; i < from_graph[now.city].size(); i++) {
            Node next = from_graph[now.city][i];
            //이미 방문했었지만, 기존에 더 최단거리로 방문한적 있으면 넘어가
            int nextCost = dist[now.city] + next.cost;
            if (dist[next.city] <= nextCost) continue;
            //현재가 최단거리면 방문해
            dist[next.city] = nextCost;
            pq.push({ next.city,nextCost });
        }
    }
    return cost;
}
int init(int N, int sCity[], int eCity[], int mCost[]) {
    current_index = 0;
    um.clear();
    for (int i = 0; i < MAX_SIZE; i++) {
        to_graph[i].clear();
        from_graph[i].clear();
    }
    for (int i = 0; i < N; i++) {
        if (um.find(sCity[i]) == um.end()) {
            um.insert({ sCity[i],current_index++ });
        }
        if (um.find(eCity[i]) == um.end()) {
            um.insert({ eCity[i],current_index++ });
        }
        //graph 저장
        int sCity_id = um[sCity[i]];
        int eCity_id = um[eCity[i]];

        to_graph[sCity_id].push_back({ eCity_id,mCost[i] });
        from_graph[eCity_id].push_back({ sCity_id,mCost[i] });
    }
    return current_index;
}
void add(int sCity, int eCity, int mCost) {
    if (um.find(sCity) == um.end()) {
        um.insert({ sCity,current_index++ });
    }
    if (um.find(eCity) == um.end()) {
        um.insert({ eCity,current_index++ });
    }
    int sCity_id = um[sCity];
    int eCity_id = um[eCity];
    to_graph[sCity_id].push_back({ eCity_id,mCost });
    from_graph[eCity_id].push_back({ sCity_id,mCost });
}
int cost(int mHub) {
    int hub_id = um[mHub];
    int ans = 0;
    ans = to_dijkstra(hub_id) + from_dijkstra(hub_id);
    return ans;
}