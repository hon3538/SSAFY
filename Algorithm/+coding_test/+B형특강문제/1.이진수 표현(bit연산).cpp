#include <iostream>
using namespace std;

char ans[2][4] = { "OFF","ON" };

int bitCheck(int n, int m) {
    for (int i = 0; i < n; i++) { //반복문으로 비트 하나씩 옮겨가며 체크
        if ((m & (1 << i)) == 0) return 0;
        //(m>>i)&1 이렇게 확인해도됨..
        //반복문이 사용되므로 손해
    }
    return 1;
}
int bitCheck2(int n, int m) {
    int mask = (1 << n) - 1;
    int temp = m | mask;
    if (temp == m) return 1;
    return 0;
}
int bitCheck3(int n, int m){
    int mask = (1 << n) - 1;
    if(mask==(m&mask)) return 1;
    return 0;
}
int main() {
    int testCase;
    cin >> testCase;
    //각 testCase
    for (int t = 1; t <= testCase; t++) {
        int N, M; 
        cin >> N >> M; //입력

        cout << '#' << t << ' ' << ans[bitCheck3(N, M)] << '\n';
    }

    return 0;
}

/*
정수 N, M 이 주어질 때, M의 이진수 표현의 마지막 N 비트가 모두 1로 켜져 있는지 아닌지를 판별하여 출력하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.
이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.
각 테스트 케이스는 다음과 같이 구성되었다.
첫 번째 줄에 정수 N, M이 주어진다. (1 ≤ N ≤ 30 , 0 ≤ M ≤ 108)


[출력]
각 테스트 케이스마다 한 줄씩
마지막 N개의 비트가 모두 켜져 있다면 ON
아니면 OFF 를 출력하라.
*/