//맵을 숫자로 다 변환
//0또는 0이랑 닿은 지점은 플루드필로 visited 처리하고 하나의 그룹을 count
//마지막에 맵크기 - 별개수 - 그룹 멤버개수 + 그룹개수 = 클릭 횟수가됨

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

#define MAX 300

char map[MAX][MAX];
int visited[MAX][MAX];
int map_size;
int bomb_cnt;
int member_cnt;
int group_cnt;

//y,x
int dir[8][2] = { 1,0,1,1,0,1,-1,1,-1,0,-1,-1,0,-1,1,-1 };
struct Node {
    int y, x;
};
void bombAround(int y, int x) {
    //주변에 지뢰 있는지 확인
    for (int i = 0; i < 8; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (dy < 0 || dx < 0 || dy >= map_size || dx >= map_size) continue;
        visited[dy][dx] = 2; // 폭탄 근처에 있다는 의미
    }
}
void input() {
    memset(visited, 0, sizeof(visited));
    member_cnt = 0;
    group_cnt = 0;
    bomb_cnt = 0;
    for (int y = 0; y < map_size; y++) {
        string s;
        cin >> s;
        for (int x = 0; x < map_size; x++) {
            map[y][x] = s[x];
            if (s[x] == '*') {
                bomb_cnt++;
                bombAround(y, x); //폭탄 주변위치 전처리로 체크
            }
        }
    }
}

void bfs(int y, int x) {
    queue<Node> q;
    q.push({ y,x });
    visited[y][x] = 1;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        member_cnt++;
        for (int i = 0; i < 8; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= map_size || dx >= map_size) continue;
            if (visited[dy][dx] == 1) continue;
            if (visited[dy][dx] == 2) { //주변에 폭탄이 있으면
                visited[dy][dx] = 1;
                member_cnt++;
                continue;
            }
            visited[dy][dx] = 1;
            q.push({ dy,dx });
        }
    }

}
void floodfill() {
    for (int y = 0; y < map_size; y++) {
        for (int x = 0; x < map_size; x++) {
            if (map[y][x] == '*') continue;
            if (visited[y][x] > 0) continue;
            bfs(y, x);
            group_cnt++;
        }
    }
}
int T;
int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> map_size;
        input();
        floodfill();
        int alone = pow(map_size, 2) - bomb_cnt - member_cnt;
        int click_cnt = alone + group_cnt;
        cout << '#' << t << ' ' << click_cnt << '\n';
    }

    return 0;
}