// 3명이상 한팀
// head방향대로 움직여
// 공때려 -> 맞으면 그팀 점수 획득

// 플루드 필로 팀번호 정하기 int team[n][n]
// 해당 팀정보 저장(struct) : head , tail, 팀원들 좌표

// 라운드 시작
// 각 팀단위로 시뮬 진행
// 꼬리좌표부터 사람이 있는 곳으로 이동, head만 사람 없는 길로 이동
// 좌표는 map에 표시
// 공던져, 맞은 사람의 위치 team[][] 확인해서 count

#include <iostream>
#include <queue>
using namespace std;
int n, m, k; // 격자 20,팀개수 5,라운드수 1000
int map[20][20];
int visited[20][20] = {0}; // floodfill 용
int team[20][20];
struct Node
{
    int y, x;
};

struct Team
{
    vector<Node> mems;
    int head;
    int tail;
    int point;
} teams[6]; // 1번부터 시작

int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void ball(int round)
{
    // round%n 단위로 바뀜
    int how = (round / n) % 4;
    int y;
    int x;
    // 첫번쨰에서 반시계로 돌리면됨
    if (how == 0)
    {
        y = round % n;
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] >= 1 && map[y][x] <= 3)
            { // 사람이면
                teams[team[y][x]].point += 1;
                swap(teams[team[y][x]].head, teams[team[y][x]].tail);
                return;
            }
        }
    }
    else if (how == 1)
    {
        x = round % n;
        for (int y = n - 1; y >= 0; y--)
        {
            if (map[y][x] >= 1 && map[y][x] <= 3)
            {
                teams[team[y][x]].point += 1;
                swap(teams[team[y][x]].head, teams[team[y][x]].tail);
                return;
            }
        }
    }
    else if (how == 2)
    {
        y = n - 1 - round % n;
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] >= 1 && map[y][x] <= 3)
            {
                teams[team[y][x]].point += 1;
                swap(teams[team[y][x]].head, teams[team[y][x]].tail);
                return;
            }
        }
    }
    else if (how == 3)
    {
        x = n - 1 - round % n;
        for (int y = n - 1; y >= 0; y--)
        {
            if (map[y][x] >= 1 && map[y][x] <= 3)
            {
                teams[team[y][x]].point += 1;
                swap(teams[team[y][x]].head, teams[team[y][x]].tail);
                return;
            }
        }
    }
}
void setTeam(int y, int x, int teamNum)
{
    queue<Node> q;
    q.push({y, x});
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    team[y][x] = teamNum;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        team[now.y][now.x] = teamNum;
        for (int i = 0; i < 4; i++)
        {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= n || dx >= n)
                continue;
            if (map[dy][dx] == 0)
                continue;
            if (visited[dy][dx] == 1)
                continue;
            visited[dy][dx] = 1;
            q.push({dy, dx});
        }
    }
}
void floodfill(int y, int x, int num)
{
    queue<Node> q;
    q.push({y, x}); // 무조건 시작위치로 들어옴
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    teams[num].head = 0;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        teams[num].mems.push_back({now.y, now.x});
        for (int i = 0; i < 4; i++)
        {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= n || dx >= n)
                continue;
            if (map[dy][dx] == 0 || map[dy][dx] == 4)
                continue;
            if (visited[dy][dx] == 1)
                continue;
            visited[dy][dx] = 1;
            q.push({dy, dx});
        }
    }
    teams[num].tail = teams[num].mems.size() - 1;
}
int shadow[20][20];
void move()
{
    memset(shadow, 0, sizeof(shadow));
    for (int i = 1; i <= m; i++)
    {
        int size = teams[i].mems.size();
        int head = teams[i].head;
        if (head == 0)
        {
            Node h = teams[i].mems[0];
            map[h.y][h.x] = 0;
            shadow[h.y][h.x] = 1;
            for (int d = 0; d < 4; d++)
            {
                int dy = h.y + dir[d][0];
                int dx = h.x + dir[d][1];
                if (dy < 0 || dx < 0 || dy >= n || dx >= n)
                    continue;
                if (map[dy][dx] != 4)
                    continue;
                map[dy][dx] = 1;
                teams[i].mems[0].y = dy;
                teams[i].mems[0].x = dx;
            }
            for (int m = 1; m < size; m++)
            {
                Node mem = teams[i].mems[m];
                for (int d = 0; d < 4; d++)
                {
                    int dy = mem.y + dir[d][0];
                    int dx = mem.x + dir[d][1];
                    if (dy < 0 || dx < 0 || dy >= n || dx >= n)
                        continue;
                    if (shadow[dy][dx] != 1)
                        continue;
                    map[dy][dx] = 1;
                    teams[i].mems[m].y = dy;
                    teams[i].mems[m].x = dx;
                }
            }
        }
        else
        {
            Node t = teams[i].mems[size-1];
            map[t.y][t.x] = 0;
            shadow[t.y][t.x] = 1;
            for (int d = 0; d < 4; d++)
            {
                int dy = t.y + dir[d][0];
                int dx = t.x + dir[d][1];
                if (dy < 0 || dx < 0 || dy >= n || dx >= n)
                    continue;
                if (map[dy][dx] != 4)
                    continue;
                map[dy][dx] = 1;
                teams[i].mems[0].y = dy;
                teams[i].mems[0].x = dx;
            }
            for (int m = size-2; m >= 0; m--)
            {
                Node mem = teams[i].mems[m];
                for (int d = 0; d < 4; d++)
                {
                    int dy = mem.y + dir[d][0];
                    int dx = mem.x + dir[d][1];
                    if (dy < 0 || dx < 0 || dy >= n || dx >= n)
                        continue;
                    if (shadow[dy][dx] != 1)
                        continue;
                    map[dy][dx] = 1;
                    teams[i].mems[m].y = dy;
                    teams[i].mems[m].x = dx;
                }
            }
        }
    }
}
int main()
{

    cin >> n >> m >> k;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> map[y][x];
        }
    }
    // floodfill -> 팀 위치 및 정보 저장
    int cnt = 1;
    for (int y = 0; y < n; y++)
    { // team 번호를 정하고
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] == 0)
                continue;
            if (team[y][x] != 0)
                continue;
            setTeam(y, x, cnt++);
        }
    }
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        { // 팀원 정보를 저장
            if (map[y][x] != 1)
                continue;
            floodfill(y, x, team[y][x]);
        }
    }
    for (int i = 0; i < k; i++)
    { // 라운드
        // move
        move();
        ball(i);
    }
    int sum=0;
    for(int i=1;i<=m;i++){
        sum+=teams[i].point;
    }
    cout<<sum;
    return 0;
}
