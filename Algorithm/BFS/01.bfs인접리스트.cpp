#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int>list[10];
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        list[from].push_back(to);
    }
    int visited[100] = { 0 };
    queue<int>q;
    q.push(0);
    visited[0] = 1;
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        //Á¶°Ç
        cout << now << '\n';

        for (int next = 0; next < list[now].size(); next++) {
            int nextNode = list[now][next];
            if (visited[nextNode] > 0)
                continue;
            visited[nextNode] = visited[now]+1;
            q.push(list[now][next]);
        }
    }
    return 0;
}