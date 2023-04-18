// add 
// 각 x마다 hashset, key: y좌표
// 있으면 오른쪽에 가로선 있는거
// 2만개, 배열에 삽입
// pq 20000log20000 = 20000*(1+4*4) =34만


// remove hashmap  key:y 값 value: Node(y,x) pointer 의 y값만 변경
//  

// getCrossCnt(int ID) 500번
//-> 해당 ID 사람이 y좌표가 10억 도달할때까지 가로선 개수
// (pq를 배열에 옮김 20000 + ps로 해당 x열에서 y값 찾기 (log20000)*(5000번))*호출 500번
// (20000+17*5000)*500 = 5천만
// pq에서 빼면 다시 pq에 어떻게 넣어줄건데..NlogN이 또들어




// getID(int x,int y) 500번
// -> 현재 게임판 기준으로 (x,y)를 지나는 사람의 ID
// -> 5천만
//set에서 bs 를 어떻게 쓸건데...
//index로 접근 가능한 자료구조 필요
//
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_CROSS 400
#define CMD_LINE 500

struct Node {
    int y, x;
};
map<int, int> m; //y, Node*
vector<Node>arr; // map과 arr모두 x 배열로 만들어서 y들을 따로 관리하기..
int Size = 0;
int ans_x;
int ps(int x, int y) { //해당 x열의 y행에서 아래로 가장가까운 y 출력
    int left = 0;
    int right = Size-1;
    int ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].y > y) {
            if (arr[mid].x == x) {
                ans = arr[mid].y;
                ans_x = arr[mid].x + 1;
            }
            else if (arr[mid].x == x - 1) {
                ans = arr[mid].y;
                ans_x = arr[mid].x;
            }
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}
int ps_id(int x, int y) { //해당 x열의 y행에서 위로 가장 가까운 y출력
    int left = 0;
    int right = Size-1;
    int ans = -1;
    ans_x = x;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].y < y) {
            if (arr[mid].x == x) {
                ans = arr[mid].y;
                ans_x = arr[mid].x + 1;
            }
            else if (arr[mid].x == x - 1) {
                ans = arr[mid].y;
                ans_x = arr[mid].x;
            }
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}
void init()
{
    m.clear();
    arr.clear();
    Size = 0;
    ans_x = 0;
}
void add(int x, int y)
{
    //20000*logN
    m.insert({ y,x });
}

void remove(int x, int y)
{
    //5000*logN
    m.erase(y);
}
int getCrossCnt(int ID) //x==ID, y==0 에서 출발
{
    //arr로 옮겨, 2만
    arr.clear();
    for (auto it = m.begin(); it != m.end(); it++) {
        arr.push_back({ it->first,it->second });
    }
    //ps 로 찾어 5000*log20000 = 8만 5천
    Size=arr.size();
    int cnt = 0;
    int x = ID;
    int y = 0;
    while (1) {
        y = ps(x, y);
        x = ans_x;
        if (y == -1) break;
        cnt++;
    }
    return cnt;
}

int getID(int x, int y)
{
    //arr로 옮겨, 2만
    arr.clear();
    for (auto it = m.begin(); it != m.end(); it++) {
        arr.push_back({ it->first,it->second });
    }
    Size=arr.size();
    int dx = x;
    int dy = y;
    while (1) {
        dy = ps_id(dx, dy);
        dx = ans_x;
        if (dy == -1) break;
    }
    return dx;
}

static bool run()
{
    int numQuery;

    int x, y, ID;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd)
        {
        case CMD_INIT:

            init();
            isCorrect = true;
            break;
        case CMD_ADD:
            scanf("%d %d", &x, &y);
            add(x, y);
            break;
        case CMD_REMOVE:
            scanf("%d %d", &x, &y);
            remove(x, y);
            break;
        case CMD_CROSS:
            scanf("%d", &ID);
            userAns = getCrossCnt(ID);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        case CMD_LINE:
            scanf("%d %d", &x, &y);
            userAns = getID(x, y);
            scanf("%d", &ans);
            if (userAns != ans)
                isCorrect = false;
            break;
        }
    }
    return isCorrect;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
/*
1 100
100
200 2 3
500 2 6
200 3 4
500 2 6
200 3 5
500 4 6
500 2 6
2

*/