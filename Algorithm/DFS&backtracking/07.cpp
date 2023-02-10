#include <iostream>
#include <vector>

using namespace std;

struct NODE
{
    int y;
    int x;
};
int map[4][3];
int datY[26];
int datX[26];
vector<NODE> v;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            cin >> map[y][x];
            if (map[y][x] >= 'A' && map[y][x] <= 'Z')
            {
                datY[map[y][x] - 'A'] = y;
                datX[map[y][x] - 'A'] = x;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (datY[i] != 0)
            continue;
        v.push_back({datY[i], datX[i]});
    }

    for (int d = 0; d < 5; d++)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int dy=v[i].y+dir[d%4][0];
            int dx=v[i].x+dir[d%4][1];
            if(dy<0||dx<0||dy>=4||dx>=3)
                continue;
            if(map[dy][dx]!='_')
                continue;
            map[dy][dx]=map[v[i].y][v[i].x];
            map[v[i].y][v[i].x]='_';
        }
    }

    for(int y=0;y<4;y++){
        for(int x=0;x<3;x++){
            cout<<map[y][x];
        }
        cout<<'\n';
    }
    return 0;
}