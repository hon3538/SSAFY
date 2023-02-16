#include <iostream>
#include <vector>
using namespace std;
//union 점 하나씩 단방향만 보면서 유니온 해가고
//이미 같은 부모가 나오면 false임
//같은 부모라는 의미는 이미 해당 점이 같은 그룹 소속이라는 것이고
//같은 그룹 소속의 다른 점과 또 이어버리면 순환회로가 발생함(삼각형)
//즉 Edge 를 연결할 때, 이미 두 노드가 같은 그룹(소속,parent)라면 
//순환회로인것임
int map[1000][1000];
int parent[1000];
int cnt = 0;
int Find(int now) {
    if (now == parent[now])
        return now;
    return parent[now] = Find(parent[now]);
}
int flag = true;
void Union(int A, int B) {
    int pa = Find(A);
    int pb = Find(B);
    if (pa == pb) {
        flag = false;
        return;
    }
    parent[pb] = pa;
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }
    for (int y = 0; y < N; y++) {
        flag = true;
        for (int x = y+1; x < N; x++) {
            if (map[y][x] != 0) {
                Union(y, x);
                if (!flag)
                    break;
            }
        }
        if (!flag)
            break;
    }
    if (flag) {
        cout << "STABLE";
    }
    else cout << "WARNING";

    return 0;
}