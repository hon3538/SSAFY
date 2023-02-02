#include <iostream>
#include <queue>
using namespace std;

//Linkedlist(vector/qeueu) �� �޾��ְ� ������ �ϸ�
//ū index������ DAT ������� �ʰ� Ǯ �� ����
struct Node {
    int y, x;
    int num;
};

priority_queue<Node> q;

bool operator<(Node v, Node tar) {
    return tar.num < v.num;
}

int map[1100][1100];

int main()
{    
    int n;
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
            q.push({ y, x, map[y][x] });
        }
    }

    int direct[5][2] = { 0,0, -1,0, 1,0, 0,1, 0,-1 };
    int cnt = 0;
    Node ret;

    while (!q.empty()) {
        ret = q.top();
        q.pop();

        if (map[ret.y][ret.x] == 0) continue;

        for (int t = 0; t < 5; t++) {
            int ny = ret.y + direct[t][0];
            int nx = ret.x + direct[t][1];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (map[ny][nx] == 0) continue;
            map[ny][nx] = 0;
            cnt++;
        }

        if (cnt == n * n) {
            break;
        }
    }

    cout << ret.num << "��";

    return 0;
}