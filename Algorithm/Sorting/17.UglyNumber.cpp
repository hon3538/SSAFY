#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//나머지가 0이 아닐때까지 2로 나눔 -> 값이 1이 되면 true
//나머지가 0이 아닐때까지 3으로 나눔 -> 값이 1이되면 true
//5로 나눴는데 나머지가 0이 아니면 false; else true;

struct cmp {
    bool operator()(long long left, long long right) {
        return left > right;
    }
};
priority_queue<long long,vector<long long>,cmp>pq;
vector<long long>v;
void dividedBy() {
    long long num = 1;
    int size = 0;
    pq.push(1);
    long long before = 0;
    while (size < 1500) {
        long long num = pq.top();
        pq.pop();
        //cout << num << '\n';
        if (before == num) {
            continue;
        }
        before = num;
        v.push_back(num);
        size++;

        pq.push(num * 2);
        pq.push(num * 3);
        pq.push(num * 5);
    }
    
}
int main() {
    //priority_queue<int,vector<int>,cmp>pq;
    
    dividedBy();
    int input;
    cin >> input;
    vector<long long>order;
    for (int i = 0; i < input; i++) {
        int n;
        cin >> n;
        order.push_back(v[n - 1]);
    }
    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << ' ';
    }
    return 0;
}