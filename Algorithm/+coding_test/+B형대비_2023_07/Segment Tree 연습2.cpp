/*
index(id)가 짝수이면 -, 홀수이면 + return
참고로 1번이 root index임

시작 index가 짝수면 -1곱해, 홀수면 그대로
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//최대 길이 10만개, 쿼리 10만개
//10만*log10만

#define MAX_SIZE 400000
long long segment_index[400000];
int arr_list[100001];

long long init(int left, int right, int index) {
    if (left == right) {
        if (left % 2 == 0) return segment_index[index] = arr_list[left] * -1;
        else return segment_index[index] = arr_list[left];
    }
    int mid = (left + right) / 2;
    long long a = init(left, mid, index * 2);
    long long b = init(mid + 1, right, index * 2 + 1);
    return segment_index[index] = a + b;
}
void update(int left, int right, int index, int t_index, int t_value) {
    if (t_index < left || t_index > right) return; //범위 벗어난 경우
    if (left == right) {
        if (t_index % 2 == 0) segment_index[index] = t_value * -1;
        else segment_index[index] = t_value;
        arr_list[t_index] = t_value;
        return;
    }
    int gap = t_value - arr_list[t_index];
    if (t_index % 2 == 0) { //짝수이면 음수값이기 때문에 -1을 곱해서 더해준다
        segment_index[index] += gap * -1;
    }
    else segment_index[index] += gap; //홀수이면 +값이기 때문에 차이를 그대로 더해줌

    int mid = (left + right) / 2;
    update(left, mid, index * 2, t_index, t_value);
    update(mid + 1, right, index * 2 + 1, t_index, t_value);
}
long long getAns(int left, int right, int index, int t_left, int t_right) {
    if (t_right < left || t_left > right) return 0;
    if (t_left <= left && right <= t_right) return segment_index[index];

    int mid = (left + right) / 2;
    long long a = getAns(left, mid, index * 2, t_left, t_right);
    long long b = getAns(mid + 1, right, index * 2 + 1, t_left, t_right);
    return a + b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> ans;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, q;
        cin >> n >> q;
        ans.clear();

        for (int i = 1; i <= n; i++) {
            int input;
            cin >> input;
            arr_list[i]=input;
        }
        init(1, n, 1);
        //query
       
        for (int i = 0; i < q; i++) {
            int cmd;
            cin >> cmd;
            if (cmd == 0) {
                int index, value;
                cin >> index >> value;
                update(1, n, 1, index+1, value);
            }
            else {
                int left, right;
                cin >> left >> right;
                long long ret = getAns(1, n, 1, left+1, right);
                if ((left + 1) % 2 == 0) ret *= -1;
                ans.push_back(ret);
            }
        }
        cout << '#' << t << ' ';
        for (long long n : ans) cout << n << ' ';
        cout <<'\n';
    }

    return 0;
}