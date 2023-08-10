//각 칸 총 또는 플레이어
//플레이어의 숫자는 초기 능력치
//총의 숫자는 공격력

//이동할때 총이 있을 때, 가지고있는 것과 비교하여 높은 공격력 총 챙김
//나머지 총은 거기에 두고감

//이동할때 사람이 있으면 싸움, 능력치+총 공격력 큰 사람이 승리하며
//같으면 능력치가 더 높은 사람이 승리
//이긴 사람은 자신의 능력치+공격력에서 상대방의 것을 뺀것만큼 포인트 획득

//진 사람은 총을 해당 격자에 내려놓고 이동
//이동하려는 곳에 다른 사람이 있거나 바깥이면
//오른쪽방향으로 회전, 
//빈칸이 보이는 순간 이동, 해당 칸에 총있으면 높은 총 주워

//이긴 사람은 해당칸에 공격력 높은 총 줍
//같은 칸에 총 여러개 가능..
//사람 싸우면 진사람 총과 자신이 가진 총만 비교하면 됨

//n 격자 20x20
//m 플레이어 30
//k 라운드 수 500

//사람은 자신의 위치+방향 + 능력치 + 가진 총 능력치를 가지고 돌아댕김

//pq 2차원 배열 만들기 -> 총
//라운드 수 반복문 만들고
//각 라운드 별로 사람을 한번씩 움직여서 논리 실행


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;// 격자, 플레이서, 라운드
int map[20][20];
struct cmp {
    bool operator()(int i1, int i2) {
        return i1 < i2;
     }
};
priority_queue<int, vector<int>, cmp>guns[20][20];
struct Player {
    int y, x;
    int d;
    int power;
    int gun;
    int point;
};
vector<Player>v;
//갈 수 있는 칸 찾기
int winner, loser;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int fight(int a, int b) {
    int a_sum = v[a].power + v[a].gun;
    int b_sum = v[b].power + v[b].gun;
    int point;
    if (a_sum > b_sum) {
        winner = a;
        loser = b;
        point = a_sum - b_sum;
    }
    else if (a_sum < b_sum) {
        winner = b;
        loser = a;
        point = b_sum - a_sum;
    }
    else {
        if (v[a].power > v[b].power) {
            winner = a;
            loser = b;
            point = a_sum - b_sum;
        }
        else {
            winner = b;
            loser = a;
            point = b_sum - a_sum;
        }
    }
    return point; //포인트 출력
}
void winnerMove(int y, int x, int w, int l) {
    int ret = max(v[w].gun, v[l].gun);
    if (v[w].gun != ret) {
        guns[y][x].push(v[w].gun);
        v[w].gun = ret;
    }
    else {
        guns[y][x].push(v[l].gun);
    }
    map[y][x] = w + 1;
    v[w].y = y;
    v[w].x = x;
}
void loserMove(int l) {
    int dy, dx, nd;
    for (int i = 0; i < 4; i++) {
        nd = (v[l].d + i) % 4;
        dy = v[l].y + dir[nd][0];
        dx = v[l].x + dir[nd][1];
        if (dy < 0 || dx < 0 || dy >= n || dx >= n) continue;
        if (map[dy][dx] != 0) continue;
        break;
    }
    //총버리고 사람 없는 곳으로 이동하고
    v[l].d = nd;
    v[l].y = dy;
    v[l].x = dx;
    v[l].gun = 0;
    map[dy][dx] = l + 1;
    if (!guns[dy][dx].empty()) {
        v[l].gun = guns[dy][dx].top();
        guns[dy][dx].pop();
    }
}
void debug() {
    cout << "==============\n";
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int n;
            if (guns[y][x].empty()) n = 0;
            else n = guns[y][x].top();
            cout << map[y][x]<<'('<<n<<')'<< ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    for (int i = 0; i < m; i++) {
        cout << i + 1 << "의 정보\n";
        cout << "방향 power gun point : "<< v[i].d << ' ' << v[i].power << ' ' <<v[i].gun<<' '<< v[i].point << '\n';
    }
    cout << "==============\n";
}
int main() {
    cin >> n >> m >> k;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int a;
            cin >> a;
            guns[y][x].push(a);
        }
    }
    for (int i = 0; i < m; i++) {
        int y, x, d, s;
        cin >> y >> x >> d >> s;
        v.push_back({ y - 1,x - 1,d,s,0,0 });
        map[y - 1][x - 1] = i + 1; //i+1 번째 사람
    }
   // debug();
    for (int r = 0; r < k; r++) {//라운드 시작
        //cout << "라운드 :" << r << '\n';
        for (int i = 0; i < m; i++) { //사람별로
            int dy = v[i].y + dir[v[i].d][0];
            int dx = v[i].x + dir[v[i].d][1];
            if (dy < 0 || dx < 0 || dy >= n || dx >= n) { //방향 바꿔서 이동
                v[i].d = (v[i].d + 2) % 4;
                dy = v[i].y + dir[v[i].d][0];
                dx = v[i].x + dir[v[i].d][1];
            }
            map[v[i].y][v[i].x] = 0; // 현재 있던 자리 초기화
            v[i].y = dy;
            v[i].x = dx;
            //int winner, loser;
            if (map[dy][dx] != 0) { //다른 사람 있다면 
                int ret = fight(i, map[dy][dx] - 1);
                v[winner].point += ret;
                //이긴 사람은 총바꾸고 이동
                winnerMove(dy, dx, winner, loser);
                //진 사람은 총버리고 이동시켜
                loserMove(loser);
            }
            else { //없다면
                map[dy][dx] = i + 1;
                if (guns[dy][dx].empty() || guns[dy][dx].top() == 0) continue;
              
                if (guns[dy][dx].top() > v[i].gun) {
                    guns[dy][dx].push(v[i].gun);
                    v[i].gun = guns[dy][dx].top();
                    guns[dy][dx].pop();
                }
                
            }
            //debug();
        }
    }
    for (int i = 0; i < m; i++) {
        cout << v[i].point << ' ';
    }

    return 0;
}