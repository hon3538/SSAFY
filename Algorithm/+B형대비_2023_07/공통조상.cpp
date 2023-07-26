/*
1. 임의의 두 정점의 가장 가까운 조상 찾기
- 재귀로 구성
2. 그 정점이 가지는 서브 트리 크기 구하기
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define SIZE 10001

vector<int> children[SIZE]; // index: parrent , value : child
struct Node {
    int cnt;
    int target;
};
int ans_node;
int ans_size;
Node dfs(int node, int t1, int t2) {
    Node ret = { 1,0 };
    if (node == t1 || node == t2) ret.target = 1;
    
    for (int i = 0; i < children[node].size(); i++) {
        Node res = dfs(children[node][i], t1, t2);
        ret.cnt += res.cnt;
        ret.target += res.target;
    }
    if (ans_node == 0 && ret.target == 2) {
        ans_node = node;
        ans_size = ret.cnt;
    }
    return ret;
}
void init() {
    for (int i = 0; i < SIZE; i++) children[i].clear();
    ans_size = 0;
    ans_node = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        int V, E, A, B; // 정점개수, 간선개수, 찾고자하는 두 개의 정점 번호
        cin >> V >> E >> A >> B;
        for (int i = 0; i < E; i++) {
            //부모-자식 순서로 간선 정보
            int p, child;
            cin >> p >> child;
            children[p].push_back(child);
        }
        dfs(1, A, B);
        cout << '#' << t <<' ' << ans_node << ' ' << ans_size << '\n';
    }

}


