#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 100001

//parrent
int parrent[MAX][20]; // log10만 -> 20 이하
vector<int> children[MAX]; // 자식 노드들
int level[MAX]; //root 로부터 거리
queue<int> q;
//공통조상 찾기
int getComNode(int a, int b) {
    //level 맞추기
    if (level[a] > level[b]) swap(a, b); //a가 레벨이 더 작다고 생각(상위 레벨)
    
    for (int i = 19; i >= 0; i--) {
        if (level[b] - level[a] >= (1 << i)) {
            b = parrent[b][i];
           // *cnt += 1 << i;
        }
    }
    //공통조상 찾기
    if (a==b) return a;
    if (parrent[a][0] == parrent[b][0]) return parrent[a][0];

    for (int i = 19; i >= 0; i--) {
        if (parrent[a][i] != parrent[b][i]) {
            a = parrent[a][i];
            b = parrent[b][i];
        }
    }
    return parrent[a][0];
}
//distance 구하기
int getDistance(int a, int b) {
    int par = getComNode(a, b);
    int dit = (level[a] - level[par]) + (level[b] - level[par]);
    return dit;
}
//bfs
long long bfs_function() {
    long long ans = 0;
    int pre = 1;
    for (int i = 0; i < children[pre].size(); i++) {
        q.push(children[pre][i]);
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans += getDistance(pre, now);
        pre = now;
        for (int i = 0; i < children[now].size(); i++) {
            int child = children[now][i];
            q.push(child);
        }
    }
    return ans;
}
int T, N;
void init() {
    memset(parrent, 0, sizeof(parrent));
    for (int i = 0; i < MAX; i++) {
        children[i].clear();
        level[i] = 0;
    }
    while (!q.empty()) q.pop();
}
void input() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a;
        cin >> a;
        int id = i + 2;
        parrent[id][0] = a;
        children[a].push_back(id);
        level[id] = level[a] + 1;
    }
    for (int i = 1; i <= N;i++) {
        sort(children[i].begin(), children[i].end(), less<int>());
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= N; j++) {
            parrent[j][i] = parrent[parrent[j][i - 1]][i - 1];
        }
    }
}
int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        input();
        cout << '#' << t << ' ' << bfs_function() << '\n';
    }

    return 0;
}