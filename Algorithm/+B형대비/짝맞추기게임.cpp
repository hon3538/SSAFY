#include <iostream>
#include <vector>
using namespace std;

extern bool checkCards(int indexA, int indexB, int diff);


//0번을 기준으로 2N번까지 비교
//한 번 비교마다 PS logN번찾음
//0번을 기준으로한 offset 값을 기준으로 배열에 index값 저장
//같은 offset들의 모든 조합 넣어보기
//한 offset 당 카드는 총 4장이고, 4C2 -> 6가지 조합 나올 수 있음
int ps(int b) { // 0번과 b의 offset 리턴,
    //offset은 최대 5만
    //최소 0
    int left = 0;
    int right = 50000;
    int ans;
    while (left <= right) {
        int mid = (left + right) / 2;
        //true 면 실제 갭이 더 작거나 같은 경우
        //false 면 실제 갭이 더 큰 경우
        //
        if (checkCards(0, b, mid) == true) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}
vector<int> v[50001];
int card[2];
void dfs(int offset, int level, int n) {
    if (level == 2) {
        checkCards(card[0], card[1], 0);
        return;
    }
    for (int i = n; i < v[offset].size(); i++) {
        card[level] = v[offset][i];
        dfs(offset, level + 1, i + 1);
        card[level] = 0;
    }
}
void playGame(int N) {
    for (int i = 0; i < 50001; i++) {
        v[i].clear();
    }
    for (int i = 1; i < 2 * N; i++) {
        int ret = ps(i);
        v[ret].push_back(i);
    }
    for (int i = 1; i < N; i++) {
        dfs(i, 0, 0);
    }
}