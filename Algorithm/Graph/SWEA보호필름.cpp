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
int D; // �β�
int W; // ���� ũ��
int K; // �հ� ���� (K����ŭ �������� ����� ������ �־�� �Ѵ�)
int film[20][20]; // ��ȣ�ʸ�
int COPY[20][20]; // ���纻
int injectioncnt = 0; // ��ǰ�� ������ Ƚ��
int ans = 21e8; // �� 21��

bool test() {
    // ���� �������� K�� �̻� ����� A �Ǵ� B�� ��� ���� �ִ°�? 
    for (int i = 0; i < W; i++) {
        // ���� ���� ���� �� ���� �ִ� �� -> ���� 
        int base = COPY[0][i]; // ������ �� ���� �ִ°�
        int cnt = 0;
        // �� ���� ��ȿ�Ѱ�? 
        int flag = 0; // 0 -> ��ȿ���� �ʴ� 1-> ��ȿ�ϴ�
        for (int j = 0; j < D; j++) {
            // ���� ���� ���� �ִ� ���� ĭ�� base�� �����ϴٸ�
            // ���ӵ� ������ ��ǰ�� �ϳ� �� ã�Ҵ�!
            if (base == COPY[j][i]) {
                cnt++;
                // cnt�� �ø��� ����-> ���� K�̻��� ���ӵǴ� ������ ����ٸ� 
                if (cnt >= K) {
                    // ���� �� ���� ��ȿ�ϴ�!
                    flag = 1;
                    break; // �� ���� ��ȿ�ϴ�, ���� ���� �Ѿ����!
                }
            }
            else {
                // base�� ��ü -> ���⼭���� �� �ٸ� ��ǰ�� ���ӵǴ� ������ ���� �� �ִ�!
                base = COPY[j][i];
                // base�� �ٲ������ -> ���ο� ���ӵǴ� ��ǰ�� �Ѱ� ã�Ҵ�!
                cnt = 1;
            }
        }
        // ���� ���� ���� �� üũ�ߴµ�, ��ȿ���� �ʴ�?
        // ���� �� ������ FAIL -> �ҷ�ǰ
        if (flag == 0)
            return false;
    }
    // test ���!
    return true;
}

void func(int level) {
    // ���� ���� -> D�� ����� �����ϸ�
    if (level == D) {
        // �����׽�Ʈ 
        if (test() == true) {
            // �ּ� ��ǰ ���� Ƚ��
            if (injectioncnt < ans)
                ans = injectioncnt;
        }
        return;
    }

    // backtracking -> ���� ���� ������ ��ǰ�� ���� �̹� ans���� ������
    // �� ���� �������� ������ -> ���ư���! 
    if (injectioncnt > ans)
        return;

    // ��� ���� -> 3���� ������ ������ �� �ִ�.
    // #1. �ƹ��͵� ���Ѵ�
    func(level + 1);

    // #2. A�� �ٲ۴� -> level�� ���� ���� ��� 0���� �ٲ۴�
    for (int i = 0; i < W; i++)
        COPY[level][i] = 0;
    injectioncnt++;
    func(level + 1);
    // ���ö� ������ ���� 
    for (int i = 0; i < W; i++) {
        COPY[level][i] = film[level][i];
    }
    injectioncnt--;

    // #3. B�� �ٲ۴� -> level�� ���� ���� ��� 1�� �ٲ۴�
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
        // reset : �������� ������ ��� ����, �迭���� �ʱ�ȭ 
        // #1. ù���� tc�� �� �߳����µ� �ڿ��� ���� �̻��ϴ�
        // #2. �߰��͸� �־�������� �߳��´�? -> 100% reset ����
        injectioncnt = 0;
        ans = 21e8;
        memset(film, 0, sizeof(film));
        memset(COPY, 0, sizeof(COPY));

        // input
        cin >> D >> W >> K;
        // �ʸ� ���� �Է�
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> film[i][j];
                COPY[i][j] = film[i][j]; // ���纻
            }
        }

        // solve : ��������� Ǭ��
        // ���ʺ��� ���غ��� �Ǵ� ���
        // -> �׳� �ƹ��͵� �ȳ־ ����ϴ� ���
        if (test())
            ans = 0;
        else
            func(0); // 0���࿡�� �����ϴ� ���

        // output
        cout << "#" << tc << " " << ans << '\n';
    }
}