#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// highest ã�� -> dfs ������
// �ִ� K���� -���� �ѹ� ��
// �ִ� ���� ���� ã��

// level -> NODE
// branch -> dir
int N, K;
int map[9][9];
int highest;
int lenMax;

void dfs(int level){
    //���� ���� -> ���̻� �� �� �ִ� ���� ���� ��
    //inRange and visited or ��� ���� ���̰� K�̻� �϶�  
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
            }
        }
    }
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