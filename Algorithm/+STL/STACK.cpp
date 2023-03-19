#include <iostream>
#include <string>
using namespace std;

int stack[10000];
int t = -1;
void push(int n) {
    t++;
    stack[t] = n;
}
void pop() {
    if (t == -1) {
        cout << t << '\n';
        return;
    }
    cout << stack[t]<<'\n';
    t--;
}
void top() {
    if (t ==-1) {
        cout << t<<'\n';
        return;
    }
    cout << stack[t] << '\n';
}
void empty() {
    if (t == -1) cout << 1 << '\n';
    else cout << 0 << '\n';
}
void size() {
    cout << t + 1 << '\n';
}
int main() {
        ios::sync_with_stdio(false);
     	cin.tie(NULL);
     	cout.tie(NULL); 
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        int num;
        if (input == "push") {
            cin >> num;
            push(num);
        }
        else if (input == "top") {
            top();
        }
        else if (input == "pop") {
            pop();
        }
        else if (input == "empty") {
            empty();
        }
        else {
            size();
        }
    }
    return 0;
}