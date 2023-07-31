/*
비교 50만번
문자열 -> hash 치환

weight1 = 37
weight2 = 47
power1 =1
power2 =1
hash = s[0]*power^i + s[1]*power^i-1 ...+s[i]*power
-> hash += s[i], hash*=power;

sliding window로 hash 비교
nextHash = power*(prevhash - string[head]*power) + new char
power*=weight;
head++;

hash를 하나만 만들기엔 중복 위험이 있으므로 여러개 만들어서 모든 hash값이
같을때 진정 같은 문자열으로 판단
*/
#include <iostream>
#include <string>
using namespace std;

#define HASH_KEY_ONE 37
#define HASH_KEY_TWO 47
int power1 = 1;
int power2 = 1;
int len;
string book, target;
int searchTarget( int t_hash1, int t_hash2) {
    //초기 hash 찾기
    int size = book.length();
    int cnt = 0;
    int hash1 = 0;
    int hash2 = 0;
    power1 = 1;
    power2 = 1;
    for (int i = len - 1; i >= 0; i--) {
        hash1 += book[i] * power1;
        hash2 += book[i] * power2;
        if (i == 0) break; //최대 power를 그대로 냅두고 사용하기 위해
        power1 *= HASH_KEY_ONE;
        power2 *= HASH_KEY_TWO;
    }
    if (hash1 == t_hash1 && hash2 == t_hash2) cnt++;

    for (int i = 0; i < size - len; i++) {
        hash1 = HASH_KEY_ONE * (hash1 - book[i] * power1) + book[i + len];
        hash2 = HASH_KEY_TWO * (hash2 - book[i] * power2) + book[i + len];

        if (hash1 == t_hash1 && hash2 == t_hash2) cnt++;
    }
    return cnt;
}
int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int t = 1; t <= T; t++) {
        getline(cin, book);
        getline(cin, target);
        len = target.length();
        power1 = 1;
        power2 = 1;
        int hash1 = 0;
        int hash2 = 0;
        //target hash 정의
        for (int i = len - 1; i >= 0; i--) {
            hash1 += target[i] * power1;
            hash2 += target[i] * power2;
            power1 *= HASH_KEY_ONE;
            power2 *= HASH_KEY_TWO;
        }
        int ans = searchTarget( hash1, hash2);
        cout << '#' << t << ' ' << ans << '\n';

    }
    return 0;
}