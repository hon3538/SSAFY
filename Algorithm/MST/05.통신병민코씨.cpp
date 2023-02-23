#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
//unionfind
//kruskal
//각 간선의 최솟값 연결
//간선의 최솟값은 Node A, Node B가 주어졌을 때 BFS로 찾기
//그다음 같은 소속 아니면 union 해주고 둘 사이 거리 더해가면됨
int X, Y;
int map[50][50];
int visited[50][50];
int Size;
struct Node {
    int y, x;
};
struct Edge {
    int a;
    int b;
    int cost;
    bool operator <(Edge o)const {
        return cost > o.cost;
    }
};
vector<Node>v;
priority_queue<Edge>pq;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int getDit(Node start) {
 //node 이름은 1부터 시작, v[node-1] vector index는 0부터 시작.
    queue<Node>q;

    q.push(start);
    int dit = -1;
    memset(visited, 0, sizeof(visited));
    visited[start.y][start.x] = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= Y || dx >= X)
                continue;
            if (map[dy][dx] == -1 || visited[dy][dx] >= 1)
                continue;
            if (map[dy][dx] != 0) {
                pq.push({ map[start.y][start.x],map[dy][dx],visited[now.y][now.x]});
            }
            visited[dy][dx] = visited[now.y][now.x] + 1;
            q.push({ dy,dx });
        }
    }
    return dit;
}
int parent[101];
int Find(int now) {
    if (parent[now] == now)
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
int kruskal() {
    int sum = 0;
    int cnt = 0;

    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (Find(now.a) == Find(now.b))
            continue;
        sum += now.cost;

        cnt++;
        Union(now.a, now.b);
    }
    if (cnt == Size - 1) {
        return sum;
    }
    else return -1;
}
void print() {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (map[y][x] >= 0)
                cout << ' ';
            cout << map[y][x];
        }
        cout << '\n';
    }
}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> X >> Y;
        Size = 0;
        v.clear();
        v.push_back({ -1,-1 }); //node 0번은 없으므로 예외처리
        for (int y = 0; y < Y; y++) {
            string s;
            cin >> s;
            for (int x = 0; x < X; x++) {
                if (s[x] == '#') {
                    map[y][x] = -1;
                }
                else if (s[x] == '_') {
                    map[y][x] = 0;
                }
                else {
                    Size++;
                    v.push_back({ y,x });
                    map[y][x] = Size;
                }
            }
        }
       // print();
        for (int i = 1; i <= Size; i++) {
            parent[i] = i;
            getDit(v[i]);
            //cout << pq.size() << '\n';
            map[v[i].y][v[i].x] = -1; //이미 연결한 노드는 벽으로 만들어줌
            //print();
        }
        cout << kruskal() << '\n';
    }

    return 0;
}