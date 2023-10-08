#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;
        int mask = (1 << n) - 1;
        cout << '#' << t;
        if ((m & mask) == mask) cout << " ON\n";
        else cout << " OFF\n";
    }
}