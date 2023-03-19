#include <iostream>
#include <string>
using namespace std;

class DeQueue {
private:
    int arr[20000];
    int head = 10000;
    int rear = 9999;
    //b은 현재 위치
    //front도 현재 위치
public:
    void push_front(int n) {
        arr[--head] = n;
    }
    void push_back(int n) {
        arr[++rear] = n;
    }
    void pop_front() {
        if (rear - head == -1) {
            cout << -1 << '\n';
            return;
        }
        cout << arr[head++]<<'\n';
    }
    void pop_back() {
        if (rear - head == -1) {
            cout << -1 << '\n';
            return;
        }
        cout << arr[rear--]<<'\n';
    }
    void size() {
        cout << rear - head + 1<<'\n';
    }
    void empty() {
        if (rear - head == -1) {
            cout << 1 << '\n';
            return;
        }
        cout << 0 << '\n';
    }
    void front() {
        if (rear - head == -1) {
            cout << -1 << '\n';
            return;
        }
        cout << arr[head] << '\n';
    }
    void back() {
        if (rear - head == -1) {
            cout << -1 << '\n';
            return;
        }
        cout << arr[rear] << '\n';
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    DeQueue dq = DeQueue();
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if (input == "push_back") {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (input == "push_front") {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (input == "front") {
            dq.front();
        }
        else if (input == "back") {
            dq.back();
        }
        else if (input == "pop_front") {
            dq.pop_front();
        }
        else if (input == "pop_back") {
            dq.pop_back();
        }
        else if (input == "size") {
            dq.size();
        }
        else if (input == "empty") {
            dq.empty();
        }
    }
    return 0;
}