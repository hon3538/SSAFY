#include <iostream>
#include <vector>
using namespace std;
int N; // <=30
int visited[31];
int cnt;
vector<int>v[31];
int DFS(int now) {
    //기저조건 -> 자식없으면 
    if (v[now].size() == 0) //양방향이기 때문에 0이 될 수 없음! 필요없음 ㅋ
        return 0;
    visited[now] = 1;
    int flag = 0; // 직계 자식 모두가 얼리어탑터임? 0 -> ㅇㅇ 1-> ㄴㄴ
    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if (visited[next] == 1)
            continue;
        int ret = DFS(next); //ret 1 -> 어뎁터, 0 -> 어뎁터 X
        if (ret == 0) {
            flag = 1; //얼리어답터 아닌 자식이 있으므로 본인이 어답터가돼야함
        }
    }
    if (flag)
        cnt++;
    return flag;
}
int main() {
    cin >> N;
    int start;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int n = DFS(1);
    cout << cnt;
    return 0;
}

//사회망 서비스
//각 사람은 얼리어답터이거나 아니거나 -> DFS로 구현해보자
//조건을 만족하는 얼리어답터 수

//DP, Top-down -> index : 노드 , value : 얼리어답터 개수
//무조건 부모는 한명이고 자식은 한명 이상이니까..
//끝자식들은 얼리어답터 X 