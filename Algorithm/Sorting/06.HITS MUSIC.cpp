#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>v;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1;j< v.size(); j++) {
            string s = v[i] + v[j];
            if (s == "HITSMUSIC")
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}