#include <iostream>
#include <vector>
using namespace std;
int N;


int depth[100001]; // index: 자식, value: 부모노드
vector<int>v[100001];
int DP[100001][30]; //첫번쨰 : 노드번호, 두번쨰 j승의 -> i노드의 j승 부모
void getParent(int now, int level) {
    depth[now] = level;
    for (int i = 0; i<v[now].size(); i++) {
        int next = v[now][i];
        if (next==1||DP[next][0] != 0)
            continue;
        DP[next][0] = now;
        getParent(next, level + 1);
    }
}
void Find() {
    for (int j = 1; j < 25; j++) { // j승의 부모 path
        for (int i = 1; i <= N; i++) { // 노드번호
            DP[i][j] = DP[DP[i][j - 1]][j - 1];
            //DP[j-1승 부모부터][j-1승 만큼 거리에 있는] = j승 부모
            // j-1승 부모 = DP[i][j-1]
            //j-1승 거리는 = j-1
        }
    }
}
/*int getNode(int now, int target) { // 같은 뎁스의 노드를 구한다
    //now가 시작지점
    //target은 target depth
    int j = 1;
    while (depth[DP[now][0]] != target) {
        if (depth[DP[now][j]] <= target) {
            now = DP[now][j-1];
            j = 0;
        }
        j++;
    }
    return DP[now][0]; //depth 가 같은 node;
}*/
int getNode(int now, int target) { // 같은 뎁스의 노드를 구한다
    //now가 시작지점
    //target은 target depth
    int j = 0;
    while (depth[now] != target) {
        if (depth[DP[now][j]] < target) {
            now = DP[now][j - 1];
            j = -1;
        }
        j++;
    }
    return now; //depth 가 같은 node;
}
int ps(int a, int b) {
    //#1 depth 차이
    //뭐가 더 뎁스큰지알아야지
    //무조건 a를 크게
    if (depth[a] < depth[b]) { // b가 더 크면, a랑 b 바뀜
        swap(a, b);
    } 
    //#2 
    if(depth[a]!=depth[b])
        a = getNode(a, depth[b]); //b와 depth가 같은 노드를 찾음

    if (a == b) //같은 레벨로 바꿨는데 같으면
        return a;
    int j = 1;
    while (DP[a][0] != DP[b][0]) { //a,b 의 바로위 부모가 같으면 이게 정답
        
        if (j>22||DP[a][j] == DP[b][j]) { //공통 조상을 찾았으면 공통조상이 아닌 최근 조상부터 다시 탐색
            a = DP[a][j - 1];
            b = DP[b][j - 1];
            j = 0;
        }
        j++;
    }
    return DP[a][0];
}
void de() {
    for (int i = 0; i < 15; i++) {
        cout << i << "번 노드 ";
        for (int j = 0; j < 30; j++) {
            cout << DP[i][j];
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //DP[1][0] = 1; ->에러생김 1번노드의 부모는 0이여야됨.
    getParent(1, 0); 
    Find();
    //de();
    //공통부모를 찾을 노드쌍 입력
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << ps(a, b)<<'\n';
    }
    return 0;
}