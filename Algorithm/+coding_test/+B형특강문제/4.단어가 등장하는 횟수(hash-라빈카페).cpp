/*
설계
완전 탐색 O(NM)

문자열 탐색 알고리즘
1. KMP
장점 : O(N+M)이 보장된다, 단점 : 구현이 복잡하다

2. 보이어 무어
장점 : 일반적인 패턴의 경우 O(N+M) + 구현 쉬움, 단점 : 최악 O(NM)

3. 라빈카페
장점 : O(N+M)보장+구현 쉬움, 단점 : 예외를 조심해야함

아래는 라빈카페로 푼다
문자열 B안에 문자열 S가 몇번 들어가는지 확인하려면
B의 길이 * S의 길이 만큼이 소요된다.
만약 S를 Hash로 계산하면 비교할 때는 B의 길이만큼만 시간이 든다
하지만 B에서 S의 길이만큼 계속 Hash를 계산해줘야하는 것도 오래걸린다
-> Rolling Hash 로 구현 (Sliding window와 비슷한 개념)

그럼 Hash 함수를 어떻게 구현할 것인가?
a->1
b->2
c->3
.. 로 숫자로 치환하고
"abc" 의 문자열은 power=아무 숫자
hash1=a*power^2+b*power^1+c*power^0
"abcd"
hash2=(hash1+d의 숫자)*power
"bcd"
hash3=hash2/power - a의 숫자*power^2

collision 은 vector로 관리..하자 그냥
같은 hash 나오면 vector에 넣고 완전탐색해그냥~

vector쓰기 싫으면 최대한 안 겹치도록 hashing 을 power값 다르게해서
반복하면됨
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int EXPONENT1 = 31;
const int EXPONENT2 = 37;
const int EXPONENT3 = 41;

int getCount(const string& str, const string& pattern) {
    int count = 0;

    int stringLength = str.length();
    int patternLength = pattern.length();

    int stringHash1 = 0;
    int patternHash1 = 0;

    int stringHash2 = 0;
    int patternHash2 = 0;

    int stringHash3 = 0;
    int patternHash3 = 0;

    int power1 = 1;
    int power2 = 1;
    int power3 = 1;

    for (int i = 0; i <= stringLength - patternLength; i++) { // Window's starting position
        // Check if string[i ... i + patternLength - 1] is equal to pattern
        if (i == 0) {
            for (int j = 0; j < patternLength; j++) {
                stringHash1 += str[patternLength - 1 - j] * power1;
                patternHash1 += pattern[patternLength - 1 - j] * power1;

                stringHash2 += str[patternLength - 1 - j] * power2;
                patternHash2 += pattern[patternLength - 1 - j] * power2;

                stringHash3 += str[patternLength - 1 - j] * power3;
                patternHash3 += pattern[patternLength - 1 - j] * power3;

                if (j < patternLength - 1) {
                    power1 *= EXPONENT1;
                    power2 *= EXPONENT2;
                    power3 *= EXPONENT3;
                }
            }
        } else {
            stringHash1 = EXPONENT1 * (stringHash1 - str[i - 1] * power1) + str[patternLength - 1 + i];
            stringHash2 = EXPONENT2 * (stringHash2 - str[i - 1] * power2) + str[patternLength - 1 + i];
            stringHash3 = EXPONENT3 * (stringHash3 - str[i - 1] * power3) + str[patternLength - 1 + i];
        }

        if (stringHash1 == patternHash1 && stringHash2 == patternHash2 && stringHash3 == patternHash3) {
            count++;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int testCase = 1; testCase <= T; testCase++) {
        string B, S;
        getline(cin, B);
        getline(cin, S);

        int result = getCount(B, S);

        cout << "#" << testCase << " " << result << "\n";
    }

    return 0;
}

/*
독서광 동철이는 책을 정말 꼼꼼히 읽는다. 그 증거로, 책에서 어떤 단어가 몇 번 등장하는지 물어보면 정확하게 그 답을 맞춰내는 신기한 능력이 있다.
그런데, 특출난 능력이 있으면 누군가는 시샘을 하게 마련이다.
동철이의 친구 영수는 동철이의 이런 능력을 의심하고 있었지만, 도저히 그 답이 맞는지 세어볼 수가 없어 당신에게 도움을 요청하였다.
영수의 궁금증을 해소해주기 위하여, 책의 내용 B가 주어질 때 특정 단어 S가 등장하는 횟수를 알아내어라.
책의 내용에서 특정 단어가 등장하는 부분이 중첩될 수도 있음에 유의하여라.
예를 들어, B="ABABA"이고 S="ABA"이면 2번 등장하는 것으로 간주한다.

[입력]
첫 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 20)
각 테스트 케이스의 첫 번째 줄에 책의 내용 B가 주어진다.
책의 내용은 알파벳 소문자와 대문자, 그리고 숫자로만 이루어지고, 길이는 1 이상 500,000 이하이다.
각 테스트 케이스의 두 번째 줄에 찾고자 하는 단어 S가 주어진다.
찾고자 하는 단어는 알파벳 소문자와 대문자, 그리고 숫자로만 이루어지고, 길이는 1 이상 100,000 이하이다.
[출력]
각 테스트케이스마다 한 줄에 걸쳐, 테스트케이스 수 “#(TC) “를 출력하고, 단어가 등장하는 횟수를 출력한다.
*/