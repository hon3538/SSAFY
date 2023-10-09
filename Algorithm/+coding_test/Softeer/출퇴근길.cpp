/*
정점 10만개
간선 20만개

queue 로 목적지

Dijkstra 2번, 성공 여부에 따라서 해당 경로 node 들 set
S->T, T->S 에 둘다 포함된 동네 return

경로 저장 어떻게?
자신에게 들어오는 애들 저장하면서 ㄱㄱ
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cstring>
using namespace std;

#define NODE_MAX 100001

int n, m;
int S, T;
vector<int> graph[NODE_MAX];
unordered_set<int> from[NODE_MAX]; // index : node, value : from node
unordered_set<int> s2t; // s->t 로 가면서 들릴 수 있는 모든 노드 
unordered_set<int> t2s;
int visited[NODE_MAX];

vector<int> ans;
void S2T(int s, int t) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == t) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            from[next].insert(now);
            if (visited[next] == 1) continue;
            visited[next] = 1;
            q.push(next);
        }
    }
    // 목적지까지 오면서 들린 node들 set에 저장
    while (!q.empty()) q.pop();
    q.push(t);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        s2t.insert(now);
        for (auto it : from[now]) {
            if (s2t.find(it) != s2t.end()) continue;
            q.push(it);
        }
    }
}
void T2S(int s, int t) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(t);
    visited[t] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == s) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            from[next].insert(now);
            if (visited[next] == 1) continue;
            visited[next] = 1;
            q.push(next);
        }
    }
    // 목적지까지 오면서 들린 node들 set에 저장
    while (!q.empty()) q.pop();
    q.push(s);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        t2s.insert(now);
        for (auto it : from[now]) {
            if (t2s.find(it) != t2s.end()) continue;
            q.push(it);
        }
    }
}
void check() {
    for (auto it : t2s) {
        if (s2t.find(it) != s2t.end()) {
            ans.push_back(it);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    cin >> S >> T;
    S2T(S, T);

    for (int i = 0; i <= n; i++) from[i].clear();
    T2S(S, T);
    check();
    cout << ans.size() - 2;

    return 0;
}
