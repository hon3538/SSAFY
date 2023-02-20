#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, T;
int coco, target;
int DAT[101];
vector<int> v[101];
int main()
{
    cin >> N >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> coco >> target;
    queue<int> q;
    q.push(coco);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            if (DAT[next] == 1)
                continue;
            DAT[next] = 1;
            q.push(next);
        }
    }
    if (DAT[target] == 1)
    {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}