#include <iostream>
#include <vector>
using namespace std;

int N, K, S;
int map[101][101];
int visited[101];
vector<int>pre;
vector<int>post;
void dfs(int now) {

    if (visited[now] == 1)
        return;
    //들어오고나서 동작(첫 노드부터 처리해줘야할 경우)
    visited[now] = 1;
    pre.push_back(now);
    for (int to = 100; to >= 0; to--) {
        int flag = map[now][to];
        if (flag == 0)
            continue;
        //들어가기전에 동작
        //전위 순회
        dfs(to);
        //나온다음 동작
        //후위 순회


        //visited[to]=0;
    }
    //나가기 전에 동작
    post.push_back(now);

}
int main() {
    cin >> N >> K >> S;

    for (int i = 0; i < K; i++) {
        int from, to;
        cin >> from >> to;
        map[from][to] = 1;
    }
    dfs(S);
    for (int i = 0; i < pre.size(); i++)
        cout << pre[i] << " ";
    cout << '\n';
    for (int i = 0; i < post.size(); i++)
        cout << post[i]<<" ";
}