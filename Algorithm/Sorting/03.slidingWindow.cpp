#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    int sum = v[0] + v[1] + v[2] + v[3];
    int min = sum;
    for (int i = 0; i < v.size() - 4; i++) {
        sum += v[i + 4];
        sum -= v[i];
        if (sum < min) {
            min = sum;
        }
    }
    cout << min;
    return 0;
}