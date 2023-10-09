//https://softeer.ai/practice/info.do?idx=1&eid=1309
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
//대회가 3개, 참가자 N명은 각대회에 참가하여 0~1000 점수 받음
//각 대회의 등수를 출력(입력순으로)
//각 대회 점수를 합친 최종 등수를 출력
//점수 sorting 하고 ps로 해당 점수의 등수 확인(중복일 경우 맨앞 등수), DAT에 해당 점수의 등수 담음
//DAT가 0이아니면 ps안하고 바로 DAT return

int N;
int ordered[4][100001]; //정렬될거
int origin[4][100001]; //원본
bool cmp(int n1, int n2) {
    return n1 > n2;
}
int DAT[3001]; // index: 점수, value: 등수
int ps(int target, int v[]) { //해당 점수의 등수 찾기
    int left = 0;
    int right = N - 1; //끝사람 index ->2
    int ans = -1;
    if (DAT[target] != 0) {
        //cout << "target: " << target << '\n';
        return DAT[target];
    }
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == target) {
            ans = mid;
            right = mid - 1;
        }
        else if (v[mid] < target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    //ans 0등부터 시작하므로
    DAT[target] = ans + 1;
    return ans + 1;
}
int main() {
    cin >> N;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            ordered[i][j] = input; // i번쨰 대회에서 j번쨰 사람의 점수   
            origin[i][j] = input;
        }
    }
    int i = 0;
    for (int i = 0; i < N; i++) { //총대회 점수 합산
        ordered[3][i] = (origin[0][i] + origin[1][i] + origin[2][i]);
        origin[3][i] = (origin[0][i] + origin[1][i] + origin[2][i]);
    }
    for (int i = 0; i < 4; i++) {
        sort(ordered[i], ordered[i] + N, cmp); //내림차순정렬
    }
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < N; j++) {
            cout << ps(origin[i][j], ordered[i]);
            if (j != N - 1) {
                cout << ' ';
            }
        }
        if (i != 3) {
            cout << '\n';
        }
        memset(DAT, 0, sizeof(DAT));
    }
    return 0;
}
