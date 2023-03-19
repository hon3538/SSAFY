//408ms
#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    int arr[2000000];
    int head = 0;
    int rear = -1;
public:
    void push(int n) {
        arr[++rear] = n;
    }
    void size() {
        cout << rear - head + 1 << '\n';
    }
    void empty() {
        if (rear - head == -1) {
            cout << 1<<'\n';
            return;
        }
        cout << 0<<'\n';
    }
    void pop() {
        if (rear - head == -1) {
            cout << -1 << '\n';
            return;
        }
        cout << arr[head++] << '\n';
    }
    void front() {
        if (rear - head == -1) {
            cout << -1 << '\n';
            return;
        }
        cout << arr[head] << '\n';
    }
    void back() {
        if ( rear - head == -1) { //내부함수 쓰지 말기
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
    int N;
    cin >> N;
    Queue q = Queue();
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if (input == "push") {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (input == "front") {
            q.front();
        }
        else if (input == "back") {
            q.back();
        }
        else if (input == "size") {
            q.size();
        }
        else if (input == "empty") {
            q.empty();
        }
        else if (input == "pop") {
            q.pop();
        }
    }


    return 0;
}