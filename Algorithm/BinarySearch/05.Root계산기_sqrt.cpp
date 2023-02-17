#include <iostream>

using namespace std;
int N;

bool condition(long long target) {
    if (target * target <= N) {
        return true;
    }
    else return false;
}
int sqrt(int right) {
    int ans;
    int left = 0;
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
    cin >> N;
    cout << sqrt(N);

    return 0;
}