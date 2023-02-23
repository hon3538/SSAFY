#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M; // 설치 명령어수, 폭파 명령어 수
int map[1000][1000];
struct Bomb
{
    int id;
    int y, x;
    bool operator<(Bomb o) const
    {
        return id > o.id;
    }
};
int dir[5][2] = {0, 0, -1, 0, 0, 1, 1, 0, 0, -1};
priority_queue<Bomb> pq;
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N + M; i++)
    {
        int id, y, x;
        cin >> id;
        if (id == 0)
        {
            int flag=false;
           while(!pq.empty()){
                Bomb now = pq.top();
                pq.pop();
                if (map[now.y][now.x] == 1){
                    continue;
                }
                else
                {
                    flag=true;
                    for (int i = 0; i < 5; i++)
                    {
                        int dy=now.y+dir[i][0];
                        int dx=now.x+dir[i][1];
                        if(dy<0||dx<0||dy>=1000||dx>=1000)
                            continue;
                        map[dy][dx]=1;
                    }
                    cout<<now.id;
                    break;
                }
           }
           if(!flag)
                cout<<-1;
            cout<<'\n';
        }
        else
        {
            cin >> y >> x;
            pq.push({id, y, x});
        }
    }
    return 0;
}