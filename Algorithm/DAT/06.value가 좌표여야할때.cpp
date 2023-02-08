#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NODE
{
    int y;
    int x;
};
string map[4];
int datY[26];
int datX[26];
vector<NODE> v;
int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
int main()
{
    for (int y = 0; y < 4; y++)
    {
        cin >> map[y];
        for (int x = 0; x < 3; x++)
        {
            if (map[y][x] >= 'A' && map[y][x] <= 'Z')
            {
                datY[map[y][x] - 'A'] = y+1;
                datX[map[y][x] - 'A'] = x+1;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (datY[i] == 0)
            continue;
        v.push_back({ datY[i]-1, datX[i]-1});
    }

    for (int d = 0; d < 5; d++)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int dy = v[i].y + dir[d % 4][0];
            int dx = v[i].x + dir[d % 4][1];
            if (dy < 0 || dx < 0 || dy >= 4 || dx >= 3)
                continue;
            if (map[dy][dx] != '_')
                continue;
            map[dy][dx] = map[v[i].y][v[i].x];
            map[v[i].y][v[i].x] = '_';
            v[i].y = dy;
            v[i].x = dx;
        }
    }

    for (int y = 0; y < 4; y++) {
        cout <<map[y]<< '\n';
    }
    return 0;
}
/* 강사님은 일케함, 난 3중 for문 쓰기싫어서 DAT를 Y,X 두 개 만듦
for (alpa = 'A'; alpa <= 'Z'; alpa++) {

		for (y = 0; y < 4; y++) {
			for (x = 0; x < 3; x++) {
				if (vect[y][x] == alpa) {
					player[n++] = { alpa, x, y };
				}
			}
		}
	}
*/