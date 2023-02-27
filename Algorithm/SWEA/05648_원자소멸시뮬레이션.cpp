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