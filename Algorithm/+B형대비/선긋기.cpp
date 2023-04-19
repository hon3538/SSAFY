// add 
// 각 x마다 hashset, key: y좌표
// 있으면 오른쪽에 가로선 있는거

// remove hashmap  key:y 값 value: Node(y,x) pointer 의 y값만 변경

// getCrossCnt(int ID) 500번
//-> 해당 ID 사람이 y좌표가 10억 도달할때까지 가로선 개수
// (pq를 배열에 옮김 20000 + ps로 해당 x열에서 y값 찾기 (log20000)*(5000번))*호출 500번
// (20000+17*5000)*500 = 5천만
// pq에서 빼면 다시 pq에 어떻게 넣어줄건데..NlogN이 또들어

// getID(int x,int y) 500번
// -> 현재 게임판 기준으로 (x,y)를 지나는 사람의 ID
// -> 5천만
// set에서 bs 를 어떻게 쓸건데... -> upper_bound 활용
// index로 접근 가능한 자료구조 필요

// lower bound , upper bound 로 풀기
// https://word.tistory.com/13
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_CROSS 400
#define CMD_LINE 500


set<int> m[101]; // key :y
//set<int,greater<int>> m2[101]; // 내림차순, 큰거 우선
int Size[101];

void init()
{
	for (int i = 0; i <= 100; i++) {
		m[i].clear();
		//m2[i].clear();
	}
	memset(Size, 0, sizeof(Size));
}
void add(int x, int y)
{
	//200000*logN
	m[x].insert(y);
	//m2[x].insert(y);
	Size[x]++;
}

void remove(int x, int y)
{
	//5000*logN
	m[x].erase(y);
	//m2[x].erase(y);
	Size[x]--;
}

int getCrossCnt(int ID) //x==ID, y==0 에서 출발
{
	//ps 로 찾어 5000*log20000 = 8만 5천
	int cnt = 0;
	int x = ID;
	int y = 0;
	while (1) {
		auto ret1 = m[x - 1].upper_bound(y);
		auto ret2 = m[x].upper_bound(y);
		
		if (ret1 == m[x-1].end() && ret2 == m[x].end()) break;

		if (ret1 == m[x - 1].end()) {
			y = *ret2;
			x = x+1;
		}
		else if (ret2 == m[x].end()) {
			y = *ret1;
			x = x -1;
		}
		else if (*ret1 < *ret2) {
			x = x - 1;
			y = *ret1;
		}
		else if (*ret1 > *ret2) {
			x = x + 1;
			y = *ret2;
		}
		cnt++;
	}
	return cnt;

}

int getID(int x, int y)
{
	//arr로 옮겨, 2만
	int dx = x;
	int dy = y;
	while (1) {
		auto ret1 = m[dx-1].lower_bound(dy);
		auto ret2 = m[dx].lower_bound(dy);
		
		if (ret1==m[dx-1].begin() && ret2 == m[dx].begin()) break;
		if (ret1 == m[dx-1].begin()) {
			dy = *(--ret2);
			dx = dx + 1;
			continue;
		}
		else if (ret2 == m[dx].begin()) {
			dy = *(--ret1);
			dx = dx - 1;
			continue;
		}
		ret1--;
		ret2--;
		if ( *ret1> *ret2) {
			dy = *ret1;
			dx = dx - 1;
		}
		else if (*ret1 < *ret2) {
			dy = *ret2;
			dx = dx + 1;
		}
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
			//remove(x, y);
			break;
		case CMD_CROSS:
			scanf("%d", &ID);
			//userAns = getCrossCnt(ID);
			//cout << userAns << '\n';
			scanf("%d", &ans);
			if (userAns != ans)
			{
				isCorrect = false;
			}
			break;
		case CMD_LINE:
			scanf("%d %d", &x, &y);
			//userAns = getID(x, y);
			//cout << userAns << '\n';
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