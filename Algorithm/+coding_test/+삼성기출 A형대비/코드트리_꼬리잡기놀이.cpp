#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M,K; //격자크기 20, 팀 개수 5, 라운드 1000
int map[20][20];
struct Node {
    int y, x;
};
//init
//team map 하나 만들기 +팀원 저장
int team[20][20];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
void setTeam(int y, int x, int t_num) {
    queue<Node>q;
    q.push({ y,x });
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        team[now.y][now.x] = t_num;
        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
            if (map[dy][dx] == 0) continue;
            if (team[dy][dx] != 0) continue;
            q.push({ dy,dx });
        }
    }
}
vector<Node>t[6];
void setMem(int y, int x) {
    queue<Node>q;
    int m_num = 1;
    int visited[20][20] = { 0 };

    visited[y][x] = 1;
    t[team[y][x]].push_back({ y,x });

    //head용
    for (int i = 0; i < 4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
        if (map[dy][dx] != 2) continue;
        q.push({ dy,dx });
        break;
    }
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        t[team[y][x]].push_back({ now.y,now.x });
        visited[now.y][now.x] = 1;
        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
            if (map[dy][dx] <= 0) continue;
            if (visited[dy][dx] == 1) continue;
            q.push({ dy,dx });
            break;
        }
    }
}
void init() {
    int t_num = 1;
    //team set
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == 0) continue;
            if (team[y][x] != 0) continue;
            setTeam(y, x, t_num++);
        }
    }
    //member set
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] != 1) continue;
            setMem(y, x);
        }
    }
}
//move
void move() {
    //모든 팀 이동
    int visited[20][20] = { 0 };
    for (int i = 1; i <= M; i++) {
        //head 이동
        visited[t[i][0].y][t[i][0].x] = 1;
        int hy = t[i][0].y;
        int hx = t[i][0].x;
        for (int d = 0; d < 4; d++) {
            int dy = t[i][0].y + dir[d][0];
            int dx = t[i][0].x + dir[d][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
            if (map[dy][dx] == 0) continue;
            if (map[dy][dx] == 2) continue;
            map[t[i][0].y][t[i][0].x] = -1;
            t[i][0].y = dy;
            t[i][0].x = dx;
            break;
        }
        //나머지 이동
        for (int n = 1; n < t[i].size(); n++) {
            visited[t[i][n].y][t[i][n].x] = 1;
            for (int d = 0; d < 4; d++) {
                int dy = t[i][n].y + dir[d][0];
                int dx = t[i][n].x + dir[d][1];
                if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
                if (visited[dy][dx] != 1) continue;
                if (hy == dy && hx == dx && n != 1) continue;
                map[t[i][n].y][t[i][n].x] = -1;
                t[i][n].y = dy;
                t[i][n].x = dx;
                break;
            }
        }
        for (int n = 0; n < t[i].size(); n++) {
            map[t[i][n].y][t[i][n].x] = n + 1;
        }
    }
}
//ball
int ans;
void ball(int round) {
    int how = (round / N) % 4;
    int y, x;
    int flag = 0; //맞았는지 확인
    if (how == 0) {
        y = round & N;
        for (x = 0; x < N; x++) {
            if (map[y][x] >= 1) {
                flag = 1;
                break;
            }
        }
    }
    else if (how == 1) {
        x = round % N;
        for (y = N - 1; y >= 0; y--) {
            if (map[y][x] >= 1) {
                flag = 1;
                break;
            }
        }
    }
    else if (how == 2) {
        y = N-1-round % N;
        for (x = N - 1; x >= 0; x--) {
            if (map[y][x] >= 1) {
                flag = 1;
                break;
            }
        }
    }
    else if (how == 3) {
        x = N - 1 - round % N;
        for (y = 0; y < N; y++) {
            if (map[y][x] >= 1) {
                flag = 1;
                break;
            }
        }
    }
    if (flag) { 
        //맞았으면 점수 합산하고, 그팀 거꾸로
        ans += map[y][x] * map[y][x];
        vector<Node>temp;
        for (int i = t[team[y][x]].size()-1; i >=0; i--) {
            temp.push_back(t[team[y][x]][i]);
        }
        t[team[y][x]].clear();
        for (int i = 0; i < temp.size(); i++) {
            t[team[y][x]].push_back(temp[i]);
            map[temp[i].y][temp[i].x] = i + 1;
        }
        
    }
}
void debug(int r) {
    cout << r << " 번째 debug\n";
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] >= 0) cout << ' ' << map[y][x] << ' ';
            else cout << map[y][x] << ' ';
        }
        cout << '\n';
    }
        //cout << "point :"<<ans<<'\n';
        cout << '\n';
}
int main() {
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            if (map[y][x] == 4) map[y][x] = -1; //길
        }
    }
    init();
    debug(-1);
    for (int r = 0; r < K; r++) {
        move();
        debug(r);
        ball(r);
        debug(r);
        cout << "point :" << ans << '\n';
    }
    cout << ans;
    return 0;
}
/*
7 3 973
3 2 1 0 0 0 0
4 0 4 0 2 1 4
4 4 4 0 2 0 4
0 0 0 0 3 4 4
2 1 3 2 0 0 0
2 0 0 2 0 0 0
2 2 2 2 0 0 0
*/