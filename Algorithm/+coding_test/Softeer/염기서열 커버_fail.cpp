/*
각 염기서열끼리 서로 하나의 초염기서열로 커버될 수 있는 지 확인
커버되면 초기 초염기서열 개수 N 개에서 -1
커버 된 염기서열은 다른 염기서열에게 선택받지 못하도록 visit check

단, 어느 순서로 
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//O(M)
bool canCover(const string& s1, const string& s2) {
    // 두 염기서열을 비교하여 하나의 염기서열이 다른 염기서열을 커버할 수 있는지 확인합니다.
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '.' || s2[i] == '.') continue;
        if (s1[i] != '.' && s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> goodSequences(N);
    for (int i = 0; i < N; i++) {
        cin >> goodSequences[i];
    }

    vector<bool> covered(N, false); // 각 좋은 염기서열이 커버되었는지 여부를 나타내는 배열

    int minSequences = N; // 초기에 모든 좋은 염기서열을 커버하기 위해서는 N개의 초염기서열이 필요합니다.

    //N*N*M = 
    for (int i = 0; i < N; i++) { 
        if (covered[i]) continue; // 이미 커버된 염기서열은 스킵합니다.

        for (int j = i + 1; j < N; j++) {
            if (!covered[j] && canCover(goodSequences[i], goodSequences[j])) {
                // i번째 염기서열이 j번째 염기서열을 커버할 수 있다면 j를 커버된 것으로 표시
                covered[j] = true;
                minSequences--; // 새로운 초염기서열 추가
            }
        }
    }

    cout << minSequences << endl;

    return 0;
}
