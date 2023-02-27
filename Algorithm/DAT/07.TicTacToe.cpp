#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char map[3][3];

int DAT[26];
int team[26][26];
int p[26];
int main() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            char c;
            cin >> c;
            map[y][x] = c;
        }
    }

    for (int y = 0; y < 3; y++) {
        vector<int>v;
 
        memset(DAT, 0, sizeof(DAT));
        int cnt = 0;
        for (int x = 0; x < 3; x++) {
            int num = (int)(map[y][x] - 'A');
            DAT[num]++;
            if (v.size() == 0) {
                v.push_back(num);
            }if (v[0] != num && v.size() == 1)
                v.push_back(num);
            if (DAT[num] > 1) {
                cnt++;
            }
        }
        sort(v.begin(), v.end());
        if (cnt == 1) { // 두 사람
            team[v[0]][v[1]] = 1;
        }
        else if (cnt == 2) { // 한 사람 
            p[v[0]] = 1;
        }
    }
    for (int x = 0; x < 3; x++) {
        vector<int>v;
        
        memset(DAT, 0, sizeof(DAT));
        int cnt = 0;
        for (int y = 0; y < 3; y++) {
            
            int num = (int)(map[y][x] - 'A');
            DAT[num]++;
            if (v.size()==0) {
                v.push_back(num);
            }if (v[0] != num && v.size() == 1)
                v.push_back(num);
            if (DAT[num] > 1) {
                cnt++;
            }
        }
        sort(v.begin(), v.end());
        if (cnt == 1) { // 두 사람
            team[v[0]][v[1]] = 1;
        }
        else if (cnt == 2) { // 한 사람 
            p[v[0]] = 1;
        }
    }

    vector<int>v1;
    vector<int>v2;
    int cnt1 = 0;
    int cnt2 = 0;
    int DAT1[26] = { 0 };
    int DAT2[26] = { 0 };
    for (int i = 0; i < 3; i++) {

        int num1 = map[i][i] - 'A';
        int num2 = map[i][2 - i] - 'A';
        DAT1[num1]++;
        DAT2[num2]++;
        if (v1.size() == 0) {
            v1.push_back(num1);
        }
        else if (v1[0] != num1 && v1.size() == 1) {
            v1.push_back(num1);
        }
        if (v2.size() == 0) {
            v2.push_back(num2);
        }
        else if (v1[0] != num2 && v2.size() == 1) {
            v2.push_back(num2);
        }
        if (DAT1[num1] > 1) {
            cnt1++;
        }
        if (DAT2[num1] > 1) {
            cnt2++;
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (cnt1 == 1) { // 두 사람
        team[v1[0]][v1[1]] = 1;
    }
    else if (cnt1 == 2) { // 한 사람 
        p[v1[0]] = 1;
    }
    if (cnt2 == 1) { // 두 사람
        team[v2[0]][v2[1]] = 1;
    }
    else if (cnt2 == 2) { // 한 사람 
        p[v2[0]] = 1;
    }
    int teamCnt = 0;
    int pCnt = 0;
    for (int y = 0; y < 26; y++) {
        for (int x = 0; x < 26; x++) {
            if (team[y][x] == 1) {
                teamCnt++;
            }
        }
        if (p[y] == 1) {
            pCnt++;
        }
    }
    cout << pCnt << '\n' << teamCnt;
    return 0;
}