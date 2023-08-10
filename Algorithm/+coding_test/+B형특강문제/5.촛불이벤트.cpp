/*
k-> 10^9 까지 가능 10억
*/

#include <iostream>
#include <math.h>
using namespace std;

long long N;

long long getAns(long long left, long long right) {
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long temp = mid * (mid + 1) / 2;
        if (temp == N) return mid;
        else if (temp < N) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
       cout << '#' << t << ' ' << getAns(0,10000000000) << '\n';;
    }


    return 0;
}