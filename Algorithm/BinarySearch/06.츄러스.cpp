#include <iostream>
#include <vector>
using namespace std;
int N, K;
int Max;
vector<int>chu;
bool condition(int length) {
    int size = chu.size();
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        cnt += chu[i] / length;
    }
    if (cnt >= K)
        return true;
    else return false;
}
int ps(int left, int right) {
    int ans=0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (condition(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        chu.push_back(n);
        if (n > Max)
            Max = n;
    }
    cout << ps(0, Max);
    return 0;
}