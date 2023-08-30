#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100001
int parrent[MAX_SIZE][20];
vector<int> children[MAX_SIZE]; // 자식들
int depth[MAX_SIZE]; // root (1번 node) 의 깊이는 1 !!!!!!!!!! -> default 깊이 (0) 과 다르게 해야 같은 높이를 맞출 수 있다.

int getCom(int a, int b) {
    //a와 b는 같은 깊이이다.
    if (a == b) return a;
    if (parrent[a][0] == parrent[b][0]) return parrent[a][0];
    for (int i = 19; i >= 0; i--) {
        if (parrent[a][i] != parrent[b][i]) {
            a = parrent[a][i];
            b = parrent[b][i];
        }
    }
    return parrent[a][0];
}
int lca(int a, int b) { // a와 b 사이 거리 구하기
    //두개의 노드 depth 맞춰주기 -> lca 가 아니라 공통 조상 찾는 함수에서 깊이 맞춰주기..
    if (depth[a] > depth[b]) swap(a, b); // a가 작고 b가 depth 깊은 것으로 고정
    int temp = b;
    for (int i = 19; i >= 0; i--) {
        if (depth[temp] - depth[a] >= (1 << i)) { // i << 1 이 아니라 1 << i 임!
            temp = parrent[temp][i]; // 2진법으로 거리를 좁혀나감 
        }
    }
    int gap = depth[b] - depth[temp];
    //공통 조상 구하기
    int common = getCom(a, temp);
    gap = gap + (depth[a] - depth[common]) * 2;
    //공통 조상과 거리 구해서 return 
    return gap;
}

void init() {
    memset(parrent, 0, sizeof(parrent));
    for (int i = 0; i < MAX_SIZE; i++) {
        children[i].clear();
        depth[i] = 0;
    }
    depth[1] = 1;
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        init();
        for (int i = 2; i <= N; i++) {
            int p;
            cin >> p;
            parrent[i][0] = p;
            parrent[i][1] = parrent[p][0];

            children[p].push_back(i);
            depth[i] = depth[p] + 1;
        }
        //parrent 채우기
        for (int i = 2; i < 20; i++) { // i <= 20 으로 해서 index error...
            for (int j = 1; j <= N; j++) {
                //j의 2^i번째 부모는 j의 2^(i-1) 부모의 2^(i-1) 부모와 같다
                parrent[j][i] = parrent[parrent[j][i - 1]][i - 1];
            }
        }
        // lca
        while (1) {
            cout << "두 노드를 입력하세요 : ";
            int a, b;
            cin >> a >> b;

            int ret = lca(a, b);
            cout << "거리 : " << ret << '\n';
        }
    }

    return 0;
}