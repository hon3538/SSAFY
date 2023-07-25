#include <iostream>
#include <cstring>
using namespace std;

int check;
int res = (1 << 10) - 1;
void init() {
    check = 0;
}

int getRes(int n) {
    int cnt = 0;
    while (res!=check) {
        cnt++;
        int num = n * cnt;
        while (num > 0) {
            int flag = 1 << num % 10;
            check |= flag;
            num /= 10;
        }
    }
    return cnt * n;
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        int N;
        cin >> N;
        cout << '#' << t << ' ';
        cout << getRes(N);
        cout << '\n';
    }
}