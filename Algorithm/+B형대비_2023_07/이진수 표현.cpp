#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;
        int flag = (1 << N) - 1;
        cout << '#' << t << ' ';
        if ((M & flag) == flag) cout << "ON\n";
        else cout << "OFF\n";
    }

    return 0;
}