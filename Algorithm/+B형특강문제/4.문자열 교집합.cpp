#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> us;
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        us.clear();
        int cnt = 0;
        int a, b;
        cin >> a >> b;

        string s;
        for (int i = 0; i < a; i++) {
            cin >> s;
            us.insert(s);
        }
        for (int i = 0; i < b; i++) {
            cin >> s;
            if (us.find(s) != us.end()) cnt++;
        }
        cout << '#' << t << ' ' << cnt << '\n';
    }
    return 0;
}


/*
문자열 집합은 알파멧 소문자로 이루어진 문자열들로 구성된 집합을 의미한다.
예를 들어 {"aba", "cdefasad", "wefawef"}은 문자열 3개로 구성된 한 개의 문자열 집합이다.
입력으로 2개의 문자열 집합이 주어졌을 때에, 두 집합에 모두 속하는 문자열 원소의 개수를 출력하는 프로그램을 작성하시오.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스마다 첫 번째 줄에 두 집합의 원소의 갯수를 나타내는 두 자연수 N M(1≤N, M≤105)이 주어진다.
둘째 줄에는 첫 번째 집합의 원소 문자열들이 공백을 사이에 두고 주어진다.
셋째 줄에는 두 번째 집합의 원소 문자열들이 공백을 사이에 두고 주어진다.
각 문자열은 소문자 알파벳으로만 구성되며, 길이가 1 이상 50 이하임이 보장된다.
한 집합에 같은 문자열이 두 번 이상 등장하지 않음이 보장된다.
*/