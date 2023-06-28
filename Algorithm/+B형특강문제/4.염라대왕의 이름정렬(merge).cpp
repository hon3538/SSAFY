/*
2만개
merge sort * 문자열 최대 길이-> O(NlogN*50)
*/
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

#define NAME_MAX 20001

string arr[NAME_MAX];
string temp[NAME_MAX];
unordered_set<string> us;
int current_index;

bool isLongger(string a, string b) {
    if (a.length() > b.length()) return true;
    if (a.length() < b.length()) return false;

    return a > b;
}
void arrayFunc(int left, int right) {
    if (left == right) {
        return;
    }
    int mid = (left + right) / 2;

    arrayFunc(left, mid);
    arrayFunc(mid + 1, right);

    //정렬
    int left_min = left;
    int right_min = mid + 1;
    int index = left;
    while (left_min <= mid || right_min <= right) {
        if (left_min == mid + 1) {
            temp[index++] = arr[right_min];
            right_min++;
        }
        else if (right_min == right + 1) {
            temp[index++] = arr[left_min];
            left_min++;
        }
        else if(isLongger(arr[left_min], arr[right_min])){
            temp[index++] = arr[right_min];
            right_min++;
        }
        else {
            temp[index++] = arr[left_min];
            left_min++;
        }
    }
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}
void init() {
    current_index = 0;
    us.clear();
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            if (us.find(s) != us.end()) continue;
            us.insert(s);
            arr[current_index++] = s;
        }
        arrayFunc(0, current_index - 1);
        cout << '#' << t << '\n';
        for (int i = 0; i < current_index; i++) {
            cout << arr[i] << '\n';
        }
    }
    return 0;
}
