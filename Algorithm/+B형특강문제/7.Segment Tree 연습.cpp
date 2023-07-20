#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAX 2100000000
int list_length, q;
int list[100001]; //100000개 -> suffix 방식으로 데이터 저장
//int segmentTree[400000]; // 각 구간의 합 -> 이문제에선 사실 필요없음
//index -> 구간의 id
//tree 맨위의 root node 1, left 2 right 3
//left = index*2, right = index*2 + 1 

struct Node {
    int max, min;
};
Node stNode[400000]; //각 구간에서 최대값과 최소값

void input() {
    //init
    cin >> list_length >> q;
    // arr 
    int n;
    for (int i = 1; i <= list_length; i++) {
        cin >> n;
        //list[i] = list[i - 1] + n;
        list[i] = n;
    }
}
//segment tree initial
//왼쪽 구간, 오른쪽 구간 의 각각의 min max 값

Node initializeSeg(int left, int right, int index) {
   // segmentTree[index] = list[right] - list[left - 1];
    if (left == right) {
        stNode[index].max = list[right];
        stNode[index].min = list[right];
        return stNode[index];
    }
    int mid = (left + right) / 2;
    Node l = initializeSeg(left, mid, index * 2); //left
    Node r = initializeSeg(mid + 1, right, index * 2 + 1); //right

    stNode[index].max = max(l.max, r.max);
    stNode[index].min = min(l.min, r.min);
    return stNode[index];
}
//target index 의 숫자를 target num으로 바꾼다
Node update(int target_index, int target_num, int left, int right, int index) {
    if (target_index < left || target_index > right) return { -1, MAX };
    //segmentTree[index] += (target_num - list[target_index]);
    if (left == right) { // 이곳이 target_index 이므로 list 실제 업데이트해주고 return
        //list[target_index] = target_num;
        stNode[index].max = target_num;
        stNode[index].min = target_num;
        return stNode[index];
    }

    int mid = (left + right) / 2;
    Node l = update(target_index, target_num, left, mid, index * 2);
    Node r = update(target_index, target_num, mid + 1, right, index * 2 + 1);
    stNode[index].max = max(l.max, r.max);
    stNode[index].min = min(l.min, r.min);
    return stNode[index];
}
Node getGap(int left, int right, int index, int t_left, int t_right) {
    // 해당 범위에서 max, min 값 찾기
    if (t_right < left || t_left > right) return { -1, MAX };
    if (t_left <= left && right <= t_right) return stNode[index];

    int mid = (left + right) / 2;
    Node l = getGap(left, mid, index * 2, t_left, t_right);
    Node r = getGap(mid + 1, right, index * 2 + 1, t_left, t_right);

    return { max(l.max,r.max),min(l.min, r.min) };
}
void query(int t) {
    vector<int> ans;
    for (int i = 0; i < q; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        a++;
        if (n == 0) {
            //a index 값을 b로 변경
            update(a, b, 1, list_length, 1);
        }
        else {
            //a~b-1 중 max - min 을 출력
            Node ret = getGap(1, list_length, 1, a, b);
            ans.push_back(ret.max - ret.min);
        }
    }
    cout << '#' << t << ' ';
    for (int res : ans) {
        cout << res << ' ';
    }
    cout << '\n';
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        //input
        input();
        //init
        initializeSeg(1, list_length, 1);
        //query
        query(t);
    }
    return 0;
}