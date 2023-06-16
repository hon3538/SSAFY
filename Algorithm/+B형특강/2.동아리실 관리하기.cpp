//전날 가능한 경우와 다음날 가능한 경우를 같이 본다
//불가능한 경우는 master를 미포함하거나, 열쇠를 가진사람을 미포함 하는 경우
//열쇠를 가진 사람이 있다는 의미는 전날과 다음날 연속하여
//참여한 사람이 최소 한 명이상 있단는 것이다.
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAX 10001
#define MOD 1000000007;
// i일에 j의 케이스가 몇 개 있는지?
// j -> 0000, 0001,0010, 0011 ... ABCD 순서
int cases[MAX][16];
string input;
void setCases(int day) {
    int master = 1 << (input[day] - 'A');
    if (day == 0) {
        for (int i = 1; i < 16; i++) {
            if ((i & master) == 0) continue; // 책임자가 없는 경우
            if ((i & 1) == 0) continue; //key를 가진 'A'가 없는경우
            cases[day][i] = 1;
        }
        return;
    }

    for (int i = 1; i < 16; i++) { //전날 
        if (cases[day - 1][i] == 0) continue; //전날 가능한 case가 없는 경우
        for (int j = 1; j < 16; j++) { // 다음날
            if ((j & master) == 0) continue;
            if ((j & i) == 0) continue; //전날과 연속된 사람이 없는 경우
            cases[day][j] = (cases[day][j] + cases[day - 1][i]) % MOD;
        }

    }
}
int getCaseCount(string s) {
    //init
    memset(cases, 0, sizeof(cases));
    int len = s.length();
    for (int i = 0; i < len; i++) {
        setCases(i);
    }
    int ans = 0;
    for (int i = 1; i < 16; i++) {
        ans = (ans + cases[len - 1][i]) % MOD;
    }
    return ans;
}
int T;
int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> input;
        cout << '#' << t << ' ' << getCaseCount(input) << '\n';
    }
    return 0;
}