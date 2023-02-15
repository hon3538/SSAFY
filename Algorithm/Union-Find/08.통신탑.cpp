#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//통신탑이 범위 내에 있으면 union 으로 엮는다
struct Node {
    int y, x;
    int r;
};
vector<Node>v;
int parent[3000];
int Find(int now) {
    if (now == parent[now])
        return now;
    return parent[now] = Find(parent[now]);
}
void Union(int A, int B) {
    int pa = Find(A);
    int pb = Find(B);
    if (pa == pb)
        return;
    parent[pb] = pa;
}
int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) { //입력 받을때마다 이전 좌표들하고 겹치는 것이 있는 지 확인
            int y, x, r;
            cin >> y >> x >> r;
            parent[i] = i;
            v.push_back({ y,x,r });
            for (int j = 0; j < i; j++) {
                double R = sqrt(pow(v[j].y - y, 2) + pow(v[j].x - x, 2));
                if (r + v[j].r >= R) {
                    Union(j, i);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (parent[i] == i) {
                cnt++;
            }
        }
        cout << cnt<<'\n';
    }
    return 0;
}