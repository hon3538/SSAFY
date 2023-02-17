#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string>input;

int ps(int left, int right, int index) {
    int ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        //cout << left<<' '<<right<<' '<<mid<<' '<<ans << '\n';
        if (input[index][mid] == '#') {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    ans=(ans + 1) * 100 / input[index].size();
    return ans;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }
    for (int i = 0; i < N; i++) {
        //cout << input[i].length()<<'\n';
        cout << ps(0, input[i].length() - 1, i)<<"%\n";
    }

    return 0;
}