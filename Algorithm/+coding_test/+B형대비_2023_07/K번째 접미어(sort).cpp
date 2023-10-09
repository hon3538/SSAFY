#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

bool cmp(string a, string b) {
    return a < b;
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        v.clear();

        int K;
        cin >> K;
        string s;
        cin >> s;
        int len = s.length();

        string ss = "";
        for (int i = len - 1; i >= 0; i--) {
            ss = s[i] + ss;
            v.push_back(ss);
        }
        sort(v.begin(), v.end(), cmp);
        cout << '#' << t << ' ' << v[K - 1] << '\n';
    }

    return 0;
}