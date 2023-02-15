// Union(인수합병)- 결합하기
// UnionFind 응용
// #1 소속관리
// #2 데이터 관리
//  -> 소속관리
//  -> 데이터가 있을 때, 결합 전의 정보는 무의미
//  -> B의 소속의 정보가 전부 A소속의로 넘어간다
// #3 *그래프 내에서의 순환 정보
//  -> cycle이 존재하는 그래프인가? -> 최소 스패닝 트리
// #4 역순 유형
#include <iostream>

using namespace std;
/* 9개 노드, 7개의 결합 정보
    9 7

    0 3
    3 6
    6 8
    3 7
    1 4
    2 5
    0 1

    4 6 은 같은 그룹인데 다른 그룹이라 뜸 왜?
    1 4 에서 1의 소속은 1임 따라서 4의 소속도 4임 따라서 4의 소속은 1이됨
    1의 소속은 그 후에 0으로 됨.. 순서차이?
    6의 소속은 0이기때문에 1의 소속인 4와는 소속이 다르다고 출력

    *따라서 소속 비교는 parent만으로 하면 안 됨...
    parent끼리만 소속 정보를 update하므로 그 아래 애들은 소속 update가 안 됨
    -> 한번더 소속 정보 update 필요 Find(a)==Find(b) 이런식으로 비교하면 됨
*/
int N, M;
int parent[20];
int Find(int now)
{
    if (now == parent[now])
        return now;

    return parent[now] = Find(parent[now]);
}
void Union(int A, int B)
{
    // #1 각 A와 B의 소속을 확인
    int pa = Find(A);
    int pb = Find(B);
    // 이미 같은 소속인지 여부 확인
    if (pa == pb)
        return;

    // #2 B의 소속을 A의 산하로 넣는다.
    parent[pb] = pa;
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
        int A, B;
        cin >> A >> B;
        Union(A, B);
    }
    int a, b;
    cin >> a >> b;
    // a와 b가 같은 그룹인가?

    // if (parent[a] == parent[b]) -> XXXX
    //-> parent끼리만 소속 정보를 update하므로 그 아래 애들은 소속 update가 안 됨
    //-> 한번더 소속 정보 update 필요 Find(a)==Find(b) 이런식으로 비교하면 됨
    if (Find(a) == Find(b))
        // 이미 path compression 돼있기 때문에 부모의 소속찾으므로 빠르다.
        cout << "same\n";
    else
        cout << "different\n";
}