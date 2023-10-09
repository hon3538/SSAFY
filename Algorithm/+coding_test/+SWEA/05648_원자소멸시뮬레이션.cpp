#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;
struct Node {
    int y, x;
    int d; // 상하좌우
    int k;
};
vector<Node>v;
int map[4001][4001];
int sum;
int dead[1001];
int cnt;
int dir[4][2] = { 1,0,-1,0,0,-1,0,1 }; // 상하 좌우
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        v.clear();
        memset(dead, 0, sizeof(dead));
        memset(map, 0, sizeof(map));
        cnt = 0;
        sum = 0;
        for (int i = 0; i < N; i++) {
            //x,y -> -1000~1000, but 이동 단위 0.5 -> map 4000
            int x, y, d, k;
            cin >> x >> y >> d >> k;
            v.push_back({ 2*(y+1000),2*(x+1000),d,k });
        }
        //시간 최대 2000, 시간에 따라 한번씩 이동시키고 겹치는 것들끼리 죽임
        for (int i = 0; i <= 4000; i++) { //0.5시간 단위임
             
            for (int j = 0; j < v.size(); j++) {
                if (dead[j] == 1)
                    continue;
                int dy = v[j].y + dir[v[j].d][0];
                int dx = v[j].x + dir[v[j].d][1];
                if (dy < 0 || dx < 0 || dy>4000 || dx>4000) {
                    //얘넨 영원히 산다
                    dead[j] = 1; //masking 처리용
                    cnt++;
                    continue;
                }
                v[j].y = dy;
                v[j].x = dx;
                if (map[dy][dx] >= 1) {
                    dead[j]=1;
                    cnt++;
                    sum += v[j].k;
                }
                map[dy][dx]++;
            }
            for (int j = 0; j < v.size(); j++) {
                if (dead[j] == 1)
                    continue;
                if (map[v[j].y][v[j].x] > 1) {
                    dead[j] = 1;
                    cnt++;
                    sum += v[j].k;
                }
                map[v[j].y][v[j].x] = 0;
            }
            if (cnt == N)
                break;
        }
        cout << '#' << t + 1 << ' ' << sum << '\n';
    }
    return 0;
}
/*
#include <iostream>
#include <vector>
#include <cstring> 
#include <algorithm>
using namespace std;

struct Atom {
    int x;
    int y;
    int dir;
    int energy;
    int dist;
};

struct Explode {
    int A; // 터질 원소 A
    int B; // 터질 원소 B
    int dist; // 이 거리를 이동하고 터짐
};

bool cmp(Explode A, Explode B) {
    // 먼저 만난게 먼저 터질 것
    if (A.dist < B.dist)
        return true;
    if (A.dist > B.dist)
        return false;
    return false;
}

int N; //원소들의 수 

Explode getDist(Atom A, Atom B, int anum, int bnum){

    // A가 상하로 이동하고 있다면 -> 위에서 내려오는것, 왼쪽에서 오는것, 오른쪽에서 오는것과 만날 가능성 있음 
    if (A.dir == 0 || A.dir == 1) {

        // A = 위, B = 아래로 이동중이라면 x좌표는 동일하고, A가 더 아래에 있어야 함
        if (A.dir == 0 && B.dir == 1 && (A.x == B.x && A.y < B.y))
                return { anum, bnum, abs(B.y - A.y) }; 

        // A = 아래, B = 위로 이동중이라면 x는 동일하고,  A가 더 위에 있어야 함.
        if (A.dir == 1 && B.dir == 0 && (A.x == B.x && A.y > B.y))
                return { anum, bnum, abs(B.y - A.y) };

        // 왼쪽으로 (오른쪽에서) 오는것
        if (B.dir == 2) {
            // 왼쪽으로 오는것과 만나려면, A가 B 보다 왼쪽에 있어야 함
            // 그리고 대각선 거리 (A.x - B.x 와 A.y - B.y) 가 동일해야 함
            if (A.x > B.x || (A.dir == 1 && A.y < B.y) || (A.dir == 0 && A.y > B.y))
                return { -1, -1, -1 };
            if (abs(A.x - B.x) == abs(A.y - B.y))
                return { anum, bnum, abs(A.x - B.x) + abs(A.y - B.y) };
        }

        //  오른쪽으로 (왼쪽)에서 오는것 
        if (B.dir == 3) {
            // 오른쪽으로 오는것과 만나려면, A가 B보다 오른쪽에 있어야 함.
            // 그리고 대각선 거리가 동일해야 함. 
            if (A.x < B.x || (A.dir == 1 && A.y < B.y) || (A.dir == 0 && A.y > B.y))
                return { -1, -1, -1 };
            if (abs(A.x - B.x) == abs(A.y - B.y))
                return { anum, bnum, abs(A.x - B.x) + abs(A.y - B.y) };
        }
    }

    // A가 좌우로 가고 있다면
    else if (A.dir == 2 || A.dir == 3) {

        // A는 왼쪽으로, B는 오른쪽으로 이동중이라면 y는 동일하고, A가 B보다 오른쪽에 있어야 함
        if (A.dir == 2 && B.dir == 3 && (A.y == B.y && A.x > B.x))
                return {anum, bnum, abs(A.x - B.x) };

        // A는 오른쪽으로, B는 왼쪽으로 이동중이라면 y는 동일하고, A가 B보다 왼쪽에 있어야 함 
        if (A.dir == 3 && B.dir == 2 && (A.y == B.y && A.x < B.x))
                return {anum, bnum, abs(A.x - B.x) };

        // 위로 (아래에서 오는 것) 
        if (B.dir == 0) {
            // 위로 오는 것과 만나려면 A가 B보다 위에 있어야 함
            // 그리고 대각선 거리 (A.x - B.x 와 A.y - B.y) 가 동일해야 함
            if (A.y < B.y || (A.dir == 2 && A.x < B.x) || (A.dir == 3 && A.x > B.x))
                return { -1, -1, -1 }; 
            if (abs(A.x - B.x) == abs(A.y - B.y))
                return {anum, bnum, abs(A.x - B.x) + abs(A.y - B.y) }; 
        }

        //  아래로 (위에서 오는 것)
        if (B.dir == 1) {
            // 아래로 오는 것과 만나려면 A가 B보다 아래 있어야 함
            // 그리고 대각선 거리가 동일해야 함. 
            if (A.y > B.y || (A.dir == 2 && A.x < B.x) || (A.dir == 3 && A.x > B.x))
                return { -1, -1, -1 };
            if (abs(A.x - B.x) == abs(A.y - B.y))
                return { anum, bnum, abs(A.x - B.x) + abs(A.y - B.y) };
        }
    }
    return { -1, -1, -1 };
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // reset
        vector<Atom>v;
        vector<Explode>temp;

        // input
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x, y, dir, energy;
            cin >> x >> y >> dir >> energy;
            v.push_back({ x, y, dir, energy, 0 });
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                Atom A = v[i];
                Atom B = v[j];

                // 둘이 같은 방향으로 이동하면 만날일 없으니 pass
                if (A.dir == B.dir)
                    continue;

                Explode e = getDist(A, B, i, j); 

                if(e.dist != -1)
                    temp.push_back(e); 
            }
        }

        // solve 
        // 거리순 (시간순)으로 정렬 
        sort(temp.begin(), temp.end(), cmp);

        // 터지는 원소들을 확인
        for (int i = 0; i < temp.size(); i++) {
            Explode now = temp[i];
            Atom A = v[now.A];
            Atom B = v[now.B];

            // now.dist의 거리에서 만나는 조합이라면 -> 이 시간대에 만나서 터질 아이들 
            // 이후에 다시 터질일이 없도록 "이 때 터진다!" 를 기록
            if ((A.dist == 0 || A.dist == now.dist) && (B.dist == 0 || B.dist == now.dist)) {
                v[now.A].dist = now.dist;
                v[now.B].dist = now.dist;
            }
        }

        int res = 0;
        for (int i = 0; i < v.size(); i++)
            if (v[i].dist != 0)
                res += v[i].energy;

        cout << "#" << tc << " " << res << '\n';
    }
}
*/