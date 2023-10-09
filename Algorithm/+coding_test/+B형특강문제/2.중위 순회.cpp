#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define MAX 101

char nodeList[MAX];
void travel_dfs(int node, int size) {
    if (node > size) return;
    if (nodeList[node] == 0) return;
    travel_dfs(node * 2, size);
    cout << nodeList[node];
    travel_dfs(node * 2 + 1, size);
}
void init() {
    memset(nodeList, 0, sizeof(nodeList));
}
int main() {
    for (int t = 1; t <= 10; t++) {
        init();
        int N;
        cin >> N;
        cin.ignore();
        for (int i = 0; i < N; i++) {
            string input;
            getline(cin, input);
            bool flag = false;
            // 1 A 2 3
            // 바로 index로 접근하면 안 됨, 11 B 22 23 일케 들어오면 input[2]==' ' 로 공백이 됨
            for (char c : input) {
                if (flag) {
                    nodeList[i + 1] = c;
                    break;
                }
                if (c == ' ') flag = true;
            }
        }
        cout << '#' << t << ' ';
        travel_dfs(1, N);
        cout << '\n';
    }


    return 0;
}