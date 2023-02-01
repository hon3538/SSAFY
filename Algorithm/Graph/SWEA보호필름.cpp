#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/*
2
6 8 3
0 0 1 0 1 0 0 1
0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0
1 1 1 1 0 0 0 1
0 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1
6 8 3
1 1 1 1 0 0 1 0
0 0 1 1 0 1 0 1
1 1 1 1 0 0 1 0
1 1 1 0 0 1 1 0
1 1 0 1 1 1 1 0
1 1 1 0 0 1 1 0
*/

// 2
int D; // 두께
int W; // 가로 크기
int K; // 합격 기준 (K개만큼 연속으로 연결된 구간이 있어야 한다)
int film[20][20]; // 보호필름
int COPY[20][20]; // 복사본
int injectioncnt = 0; // 약품을 주입한 횟수
int ans = 21e8; // 약 21억

bool test() {
    // 세로 방향으로 K개 이상 연결된 A 또는 B가 모든 열에 있는가? 
    for (int i = 0; i < W; i++) {
        // 지금 보는 열의 맨 위에 있는 값 -> 기준 
        int base = COPY[0][i]; // 무조건 맨 위에 있는거
        int cnt = 0;
        // 이 열이 유효한가? 
        int flag = 0; // 0 -> 유효하지 않다 1-> 유효하다
        for (int j = 0; j < D; j++) {
            // 지금 내가 보고 있는 열의 칸이 base와 동일하다면
            // 연속된 동일한 약품을 하나 더 찾았다!
            if (base == COPY[j][i]) {
                cnt++;
                // cnt를 늘리는 순간-> 만약 K이상의 연속되는 구간이 생긴다면 
                if (cnt >= K) {
                    // 지금 이 열은 유효하다!
                    flag = 1;
                    break; // 이 열은 유효하니, 다음 열로 넘어가세요!
                }
            }
            else {
                // base를 교체 -> 여기서부터 그 다른 약품이 연속되는 구간이 있을 수 있다!
                base = COPY[j][i];
                // base가 바뀌었으니 -> 새로운 연속되는 약품을 한개 찾았다!
                cnt = 1;
            }
        }
        // 지금 보는 열을 다 체크했는데, 유효하지 않다?
        // 지금 이 조합은 FAIL -> 불량품
        if (flag == 0)
            return false;
    }
    // test 통과!
    return true;
}

void func(int level) {
    // 기저 조건 -> D번 행까지 도달하면
    if (level == D) {
        // 성능테스트 
        if (test() == true) {
            // 최소 약품 주입 횟수
            if (injectioncnt < ans)
                ans = injectioncnt;
        }
        return;
    }

    // backtracking -> 만약 지금 주입한 약품의 수가 이미 ans보다 많으면
    // 이 길은 가망성이 없으니 -> 돌아가라! 
    if (injectioncnt > ans)
        return;

    // 재귀 구성 -> 3가지 갈래로 내려갈 수 있다.
    // #1. 아무것도 안한다
    func(level + 1);

    // #2. A로 바꾼다 -> level층 행의 값을 모두 0으로 바꾼다
    for (int i = 0; i < W; i++)
        COPY[level][i] = 0;
    injectioncnt++;
    func(level + 1);
    // 나올때 원상태 복구 
    for (int i = 0; i < W; i++) {
        COPY[level][i] = film[level][i];
    }
    injectioncnt--;

    // #3. B로 바꾼다 -> level층 행의 값을 모두 1로 바꾼다
    for (int i = 0; i < W; i++)
        COPY[level][i] = 1;
    injectioncnt++;
    func(level + 1);
    for (int i = 0; i < W; i++) {
        COPY[level][i] = film[level][i];
    }
    injectioncnt--;
}

int main() {

    //freopen("input.txt", "r", stdin);

    int T; // testcase 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // reset : 전역에서 설정한 모든 변수, 배열등을 초기화 
        // #1. 첫번쨰 tc는 답 잘나오는데 뒤에서 부터 이상하다
        // #2. 중간것만 넣어봤을때는 잘나온다? -> 100% reset 문제
        injectioncnt = 0;
        ans = 21e8;
        memset(film, 0, sizeof(film));
        memset(COPY, 0, sizeof(COPY));

        // input
        cin >> D >> W >> K;
        // 필름 정보 입력
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> film[i][j];
                COPY[i][j] = film[i][j]; // 복사본
            }
        }

        // solve : 재귀적으로 푼다
        // 애초부터 안해봐도 되는 경우
        // -> 그냥 아무것도 안넣어도 통과하는 경우
        if (test())
            ans = 0;
        else
            func(0); // 0번행에서 시작하는 재귀

        // output
        cout << "#" << tc << " " << ans << '\n';
    }
}