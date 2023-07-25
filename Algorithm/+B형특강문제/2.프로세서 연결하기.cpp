/*
코어수 12개
맵 크기 12x12

dfs level : 코어, branch : 방향
4^12 -> 800만
800만 x 각 전선 그리는 시간 12(각 level당 전선그리는 횟수는 최대 24회임) = 9600


backtracking
이미 연결코어최대가 될 수 없는 경우를 판독
max > 현재까지 연결된 코어수 + 확인해야할 코어수 -> return

바로 연결된 코어들 제외
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAP_SIZE 12
#define CORE_MAX 12

int map[MAP_SIZE][MAP_SIZE];

struct Core {
    int y, x;
};
vector<Core> coreList;
int connectedCore;
int line_length;
int max_core;
int min_line;
int N;
void input() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int input;
            cin >> input;
            map[y][x] = input;
            if (input == 1) {
                if (y == 0 || x == 0 || y == N - 1 || x == N - 1) {
                    connectedCore++;
                    continue;
                }
                coreList.push_back({ y,x });
            }
        }
    }
}
void init() {
    memset(map, 0, sizeof(map));
    coreList.clear();
    connectedCore = 0;
    line_length = 0;
    max_core=0;
    min_line=21e8;
}
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
bool mark(int d, bool isMark, int level) {
    Core now = coreList[level];
    int line_cnt = 0;
    int op, value;
    if (isMark) { op = 1; value = 2; } //그릴떄
    else { op = -1; value = 0; } //지울떄
    int dy = now.y;
    int dx = now.x;
    while (1) {
        dy += dir[d][0];
        dx += dir[d][1];
        if (dy >= N || dx >= N || dy < 0 || dx < 0) {
            connectedCore += op;
            return true; //그리기 성공
        }
        if (isMark && map[dy][dx] != 0) break;
        map[dy][dx] = value;
        line_cnt++;
        line_length += op;
        
    }
    //원상 복구
    dy = now.y;
    dx = now.x;
    for (int i = 0; i < line_cnt; i++) {
        dy += dir[d][0];
        dx += dir[d][1];
        map[dy][dx] = 0;
    }
    line_length -= line_cnt;
    return false; //그리기 실패
}
void dfs(int level) {
    if (level == coreList.size()) {
        if (max_core < connectedCore) {
            max_core = connectedCore;
            min_line = line_length;
        }
        else if(max_core==connectedCore){
            min_line = min_line > line_length ? line_length : min_line;
        }
        return;
    }
    //backtracking 현재 최대값 > 연결된 개수 + 남은 개수
    if (max_core > connectedCore + (coreList.size() - level)) return;
    for (int d = 0; d < 4; d++) {
        bool ret = mark(d, true, level); //방향, mark/unmark, level
        dfs(level + 1);
        if (ret) mark(d, false, level);
    }
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        input();
        dfs(0);
        cout << '#' << t << ' ' << min_line << '\n';
    }

    return 0;
}