#include <iostream>
#include <string>


using namespace std;
int N;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int isRange(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= N)
        return 0;
    return 1;
}
int main() {
    int DAT[1001][1001] = {0}; // index ÁÂÇ¥ / value ÆøÅº¹øÈ£
    int Y[1000001] = { 0 };
    int X[1000001] = { 0 };

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> DAT[y][x];
            Y[DAT[y][x]] = y;
            X[DAT[y][x]] = x;
        }
    }
    int ans = 0;
    for (int t = 1; t <= N * N; t++) {
        if (DAT[Y[t]][X[t]] == 0)
            continue;
        ans = DAT[Y[t]][X[t]];
        DAT[Y[t]][X[t]] = 0;
        for (int i = 0; i < 4; i++) {
            int dy = Y[t] + dir[i][0];
            int dx = X[t] + dir[i][1];
            if (!isRange(dy, dx))
                continue;
            DAT[dy][dx] = 0;
        }
        
    }
    cout << ans<<"ÃÊ";
}

