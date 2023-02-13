#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


vector<int>Line[5];
int main() {
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0;j< s.length(); j++)
            Line[i].push_back(s[j] - '0');
    }
    int a, b;
    cin >> a >> b;

    sort(Line[a].begin(), Line[a].end());
    sort(Line[b].begin(), Line[b].end());
    for (int i = 0; i < 5; i++) {
        cout << Line[i][0] << ' ';
    }
    return 0;
}