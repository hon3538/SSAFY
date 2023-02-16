//교수님 코드
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
2
6 5
#####_
#A#A##
#_#_A#
#S__##
#####_
7 7
#####__
#AAA###
#____A#
#_S_###
#_____#
#AAA###
#####__
*/

struct Node {
    int y, x; 
};

struct Edge {
    int a, b, cost; 
};

int Y; // 세로 크기
int X; // 가로 크기
int MAP[50][50]; // 변환된 맵
vector<Edge>v; 
int check[50][50]; 

// (y,x)로부터 다른 모든 노드까지의 거리를 찾고, 우리의 간선을 만들어줄 함수 
void bfs(int y, int x) {
    queue<Node>q; 
    q.push({ y, x });

    int visited[50][50] = { 0, };
    visited[y][x] = 1;

    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 }; 

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        // 어느 순간 특정 위치에 도달했을떄 -> 만약 이 위치가 "다른" 노드라면
        // 지금 (y,x) -> (now.y, now.x) cost 저장 
        if (MAP[now.y][now.x] > 0 && !(y == now.y && x == now.x) && check[now.y][now.x] == 0)
            v.push_back({ MAP[y][x], MAP[now.y][now.x], visited[now.y][now.x] - 1 });

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= Y || nx >= X)
                continue;
            if (visited[ny][nx] > 0)
                continue;
            // 추가 : 벽 처리
            if (MAP[ny][nx] == -1)
                continue; 

            visited[ny][nx] = visited[now.y][now.x] + 1; 
            q.push({ ny, nx });
        }
    }
}

int main() {    
    int T; // test case 개수
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // reset
        int num = 1; // 찾는 노드의 번호

        // input
        cin >> X >> Y; 
        for (int i = 0; i < Y; i++) {
            // 문자로 구성된 한줄 입력
            string row; 
            cin >> row; 
            for (int j = 0; j < X; j++) {
                // 벽이면
                if (row[j] == '#')
                    MAP[i][j] = -1;
                else if (row[j] == 'A' || row[j] == 'S') {
                    MAP[i][j] = num;
                    num++; // 다음 넘버
                }
                else {
                    MAP[i][j] = 0; 
                }
            }
        }
        // solve
        // 모든 노드 -> 모든 노드까지의 거리 = cost간선 저장
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                // 만약 노드가 있는 위치라면 -> 탐색 시작
                if (MAP[i][j] > 0) {
                    bfs(i, j);
                    check[i][j] = 1; // (i,j)위치에서의 탐색은 종료되었따
                    // 즉, 다른 노드에서 이 노드로 오는 경로는 다시 안넣어도 된다 
                }
            }
        }

        // output
        // 이 간선 (vector)를 활용해서 MST를 만들고, 해당 비용을 출력 
        cout << kruskal(); 
    }
}