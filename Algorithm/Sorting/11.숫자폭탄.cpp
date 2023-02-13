#include <iostream>
#include <vector>
using namespace std;

vector<int>v;
bool cmp(int left, int right) {
    return true;
}
void print() {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    int isSame = 0;

    //아래는 연속된 모든 폭탄 제거코드임, 근데 3개 단위로 연속폭탄제거하는거였음..
    // for (int i = v.size()-1; i > 0; i--) { // 
    //     if (v[i] == v[i - 1]) {
    //         isSame++;
    //     }
    //     else if (isSame != 0) {
    //         v.erase(v.end()-1 -i, v.end()- i + isSame);
    //         isSame = 0;
    //     }
    // }
    for (int i = v.size()-1; i > 0; i--) { // 
        if (v[i] == v[i - 1]) {
            isSame++;
        }
        else if (isSame != 0||isSame==3) {
            v.erase(v.end()-1 -i, v.end()- i + isSame);
            isSame = 0;
        }
    }
    print();
    //next와 비교하면서 같으면 isSame ++
    //next와 다르고 isSame>0이면 현재 idex포함 isSame만큼 erase
    //마지막 sort 
    return 0;
}