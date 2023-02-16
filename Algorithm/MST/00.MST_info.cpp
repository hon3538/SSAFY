// MST -> Minimum Spanning Tree
//*Spanning : 늘어나는, 퍼진다, 걸치다..
// 모든 노드를 거치는 Tree 를 Spanning Tree 라고 함
//  그럼 MST란? 비용이 가장 낮게 모든 노드를 거치는 트리

// *MST의 특징
// 1.모든 노드를 최소한의 비용으로 거쳐야한다? 즉, 간선 개수가 최소한으로 모든 노드를 연결해야 한다.
// -> 간선 개수 = 노드 개수 -1 이 최소 간선 개수이다.
// 2.이 말은 싸이클(순환회로)가 없으므로, 모든 노드는 단 하나의 경로만 생성한다.
// 3.*양 방향 연결에서만 유효하다.

// MST :
// 모든 노드에서 -> 모든 노드로 갈 수 있는 최소 비용을 가진 하나의 경로

// MST 를 찾는 과정
// 가장 짧은 간선부터 순서대로 연결하다가 cycle 생기면 연결 안 하고 다음 간선 ㄱㄱ
// -> 간선은 priority_queue 로 찾고 cycle은 union find로 찾는다.
// 간선 위주를 kruskal 이라 한다.


// MST가 모든 노드를 거치고 있는지도 확인해야한다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M; // 노드, 간선
struct Edge
{
    int a;
    int b; // 양방향인거 알아서 from to로 안 하고 두 노드를 저장
    int cost;
};
bool cmp(Edge left, Edge right)
{
    // vector이므로, 원하는 방향을 true로
    if (left.cost < right.cost)
        return true;
    if (left.cost < right.cost)
        return false;
    return false;
}
vector<Edge> v; // 간선을 저장할 벡터
int parent[100];
int Find(int now)
{
    if (now == parent[now])
        return now;

    return parent[now] = Find(parent[now]);
}
void Union(int A, int B)
{
    int pa = Find(A);
    int pb = Find(B);
    if (pa == pb)
        return;
    parent[pb] = pa;
}
int kruskal() //O(logN)
{
    // 짧은 간선부터 우선적으로 확인한기 위해 간선정보를 정렬
    sort(v.begin(), v.end(), cmp);
    // 앞에서부터 순차적으로 간선을 확인
    // 확인 -> 이 간선ㅇ르 MST의 일원으로 채택할 수 있는가 ?
    // 이게 판단되면 -> 연결한다. (즉, 비용을 누적한다)
    // 연결할 수 없으면 -> 다음간선 확인
    int sum = 0; // MST의 최종 비용
    int cnt;
    for (int i = 0; i < v.size(); i++)
    {
        Edge now = v[i]; // 연결해볼까? 하는 간선
        // if(now.cost<10)  //비용 조건이 있다면 조건 추가
        //  continue;

        // A-B + 비용
        // now번 간선을 연결할 수 있는지를 확인
        // cycle이 발생하는가?-> 만약 A와 B가 같은 소속이라면
        if (Find(now.a) == Find(now.b))
            continue;
        // 이제 이 간선은 연결을 시킬것이다.
        sum += now.cost;
        // 이제 now의 A와 now B는 하나의 소속이 된다.
        Union(now.a, now.b); //O(A(N))~=O(1)
        cnt++;
    }
    // MST가 완성되었는지 확인
    // 최종적으로 연결된 간선의 개수 = N-1이라면 Ok
    if (cnt == N - 1)
        return sum;
    else
        return -1;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        v.push_back({a, b, cost});
    }
    int check=kruskal();

    if (check ==- 1)
        cout << "tree 불가능";
    else
        cout << check;
    return 0;
}