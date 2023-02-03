#include <iostream>
#include <string>
#include <queue>

using namespace std;

//다리 두개 위아래
//항상 첫번쨰다리 1번칸에서 시작(항상 안전)
//위험 0, 안전 1

//앞으로 이동
//뒤로이동
//점프 + K칸

//이동횟수만큼 1번칸부터 파괴됨 
int N, K;
int dir[4][2] = { 0,1,0,-1,-1,0,1,0 }; // 앞 뒤 위 아래
int isRange(int y, int x) {
    if (y < 0 || x < 0 || y >= 2)
        return 0;
    return 1;
}
struct NODE {
    int y;
    int x;
};
vector<int>bridge[2];
int main() {
    cin >> N >> K;
    dir[2][1] = K;
    dir[3][1] = K;
    for (int r = 0; r < 2; r++) {
        string s;
        cin >> s;
        for (int i = 0; i < N; i++) {
            bridge[r].push_back(s[i] - '0' - 1);
            //0이 안전 -1위험
        }
    }
    queue<NODE>q;
    q.push({ 0,0 });
    bridge[0][0] = 1;
    int ans = 1;
    int flag = false;
    while (!q.empty()) {
        NODE now = q.front();
        q.pop();
        if (flag) {
            flag = true;
            break;
        }
        if (ans != bridge[now.y][now.x]) {
            bridge[0][ans - 1] = -1;
            bridge[1][ans - 1] = -1;
            ans = bridge[now.y][now.x];
        }
        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (!isRange(dy, dx))
                continue;
            if (dx >= N) {
                flag = true;
                break;
            }
            if (bridge[dy][dx] != 0)
                continue;
            bridge[dy][dx] = bridge[now.y][now.x] + 1;
            q.push({ dy,dx });
        }
    }
    if (flag)
        cout << 1;
    else
        cout << 0;
    return 0;
}