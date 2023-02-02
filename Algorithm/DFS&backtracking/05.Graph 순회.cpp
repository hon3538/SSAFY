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
    //�������� ����(ù ������ ó��������� ���)
    visited[now] = 1;
    pre.push_back(now);
    for (int to = 100; to >= 0; to--) {
        int flag = map[now][to];
        if (flag == 0)
            continue;
        //�������� ����
        //���� ��ȸ
        dfs(to);
        //���´��� ����
        //���� ��ȸ


        //visited[to]=0;
    }
    //������ ���� ����
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