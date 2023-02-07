#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// highest ã�� -> dfs ������
// *�ִ�* K���� -���� �ѹ� -> K�� �ּ������� ����ؾ� ���ɼ� ���� now-next==1 !! 
// ���� : �ִ� ���� ���� ã��

// level -> NODE
// branch -> dir

int N, K;
int map[9][9];
int highest; // ������
int lenMax;
int used; //K

struct NODE {
    int y;
    int x;
};
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
void dfs(int level, NODE now) {
    //���� ������ ������, ������ ������ ������ �ʴ´�.
    if (lenMax < level) {
        lenMax = level;
    }
    int curHeight = map[now.y][now.x];
    int flag;
    map[now.y][now.x] = 100; // visitedó�� , �� �ҽÿ� ���� ������ K�� ����Ͽ� �ٽ� �ǵ��ƿ� �� �����ϱ�..?
    //ex) 7 (1,4) -> (0,4) 2 -> ��x ������ x �Ʒ�-4 ==1 ���� �̷���...
    for (int i = 0; i < 4; i++) {
        int dy = now.y + dir[i][0];
        int dx = now.x + dir[i][1];
        flag = false;
        if (dy < 0 || dx < 0 || dy >= N || dx >= N) //���� �������
            continue;
        int nextHeight = map[dy][dx];
        //�� ���ٸ� K ������� Ȯ���ؼ� ���̰� K-1���Ϸ� ���ٸ� ���� map�� ���� ��ġ -1�ؼ� ����
        if (curHeight <= nextHeight) {
            if (used || (nextHeight - curHeight >= K))
                continue;
            flag = true;
            used = true;
            map[dy][dx] = curHeight - 1;
        }
        dfs(level + 1, { dy,dx });
        if (flag) {
            used = false;
            map[dy][dx] = nextHeight;
        }
    }
    map[now.y][now.x] = curHeight;
}
void input();
int main()
{
    int T;
    cin >> T;
    vector<int> ans;
    for (int t = 0; t < T; t++)
    {
        // �������� �ʱ�ȭ
        highest = INT_MIN;
        lenMax = INT_MIN;
        input();

        // start
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (highest != map[y][x])
                    continue;
                used = false;
                dfs(1, { y,x });
            }
        }
        ans.push_back(lenMax);
    }
    for (int t = 0; t < T; t++) {
        cout << '#' << t + 1 << ' ' << ans[t] << '\n';
    }
    return 0;
}

void input()
{
    cin >> N >> K;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> map[y][x];
            if (highest < map[y][x])
                highest = map[y][x];
        }
    }
}