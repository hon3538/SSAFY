/*
init 1
numberOfcandidate 15만
maxArea 50

init -> 5개 숫자 delta의 설치할 수 있는 좌표를 저장한다. map
5*5*5*5*5*400 = 약 150만
수면높이 맵 저장 = 20x20(맵크기) * 10(수면 높이) =4000

numberOfCandidate -> init에서 delta 조합을 이용.. O(1)*4(방향) -> 60만
maxArea -> 각 블럭이 들어갈 수 있는 최대 경우의수 5000천개 * 50
각 수면 높이에 따른 map과 그 떄의 남아있는 육지 개수를 init에서 저장해놓는다

가로와 세로를 따로 관리하는게 좋을 듯
*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int y, x;
};
int map[20][20];
int map_size;
unordered_map<int, vector<Node>> vertical;
unordered_map<int, vector<Node>> horizontal;
unordered_set<int> done_v;
unordered_set<int> done_h;

int seaLevelMap[11][20][20];
int seaLevelBlocks[11];
void saveCombi(int length, int hash, bool vh)
{
	int mask = 1;
	for (int i = 1; i < length; i++)
	{
		mask = mask * 10 + 1;
	}
	if (vh == 0)
	{ // horizon
		for (int y = 0; y < map_size; y++)
		{
			for (int x = 0; x <= map_size - length; x++)
			{
				int num = 0;
				for (int i = 0; i < length; i++)
				{
					num = num * 10 + map[y][x + i];
				}
				if ((hash + num) % mask == 0)
				{
					horizontal[hash].push_back({ y, x });
				}
			}
		}
	}
	else
	{ // vertical
		for (int x = 0; x < map_size; x++)
		{
			for (int y = 0; y <= map_size - length; y++)
			{
				int num = 0;
				for (int i = 0; i < length; i++)
				{
					num = num * 10 + map[y + i][x];
				}
				if ((hash + num) % mask == 0)
				{
					vertical[hash].push_back({ y, x });
				}
			}
		}
	}
}
void setDelta(int level, int length, int hash, bool opt)
{ // opt는 delta 조합이 맞는지(가장 낮은값 포함해야함)
	if (level == length)
	{
		if (opt)
		{
			if (done_h.find(hash) == done_h.end())
			{
				saveCombi(length, hash, 0);
				done_h.insert(hash);
			}
			if (done_v.find(hash) == done_v.end())
			{
				saveCombi(length, hash, 1);
				done_v.insert(hash);
			}
		}
		return;
	}
	bool ori = opt;
	for (int i = 1; i <= 5; i++)
	{
		hash = hash * 10 + i;
		if (i == 1)
			opt = true;
		setDelta(level + 1, length, hash, opt);
		opt = ori;
		hash = hash / 10;
	}
}
int visited[20][20];
int dir[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
void floodfill(int level, int y, int x)
{
	queue<Node> q;
	q.push({ y, x });

	while (!q.empty())
	{
		Node now = q.front();

		for (int i = 0; i < 4; i++)
		{
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= map_size || dx >= map_size)
				continue;
			if (map[dy][dx] < level)
				continue;
			if (visited[dy][dx] == 1)
				continue;
			visited[dy][dx] = 1;
			seaLevelBlocks[level]++;
			q.push({ dy, dx });
		}
	}
}
void init(int N, int mMap[20][20])
{

	map_size = N;
	vertical.clear();
	horizontal.clear();
	done_h.clear();
	done_v.clear();
	memset(seaLevelBlocks, 0, sizeof(seaLevelBlocks));
	memcpy(map, mMap, sizeof(mMap));
	// delta 구하기 가장 낮은 값을 0으로
	for (int l = 2; l <= 5; l++)
	{
		setDelta(0, l, 0, false);
	}
	// 해수면 높이에 따른 모든 맵 정보 저장
	for (int i = 1; i <= 10; i++)
	{
		memset(visited, 0, sizeof(visited));
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (visited[y][x] == 1)
					continue;
				if (map[y][x] < i)
					continue;
				floodfill(i, y, x);
			}
		}
	}
}
int numberOfCandidate(int M, int mStructure[5])
{
	int hash = 0;
	int reverse = 0;
	for (int i = 0; i < M; i++)
	{
		hash = hash * 10 + mStructure[i];
		reverse = reverse * 10 + mStructure[M - i - 1];
	}
	if (M == 1)
		return map_size * map_size;
	int ans = (vertical[hash].size() + horizontal[hash].size());
	if (hash != reverse)
	{
		ans =ans +(vertical[reverse].size() + horizontal[reverse].size());
	}
	return ans;
}
int maxArea(int M, int mStructure[5], int mSeaLevel)
{
	int hash = 0;
	int reverse = 0;
	for (int i = 0; i < M; i++)
	{
		hash = hash * 10 + mStructure[i];
		reverse = reverse * 10 + mStructure[M - i - i];
	}
	int ans = 0;
	int max = 0;
	vector<Node>* p[4] = { &horizontal[hash], &vertical[hash], &horizontal[reverse], &vertical[reverse] };
	for (int ptr = 0; ptr < 4; ptr++)
	{
		for (int i = 0; i < (*p)[ptr].size(); i++)
		{
			Node now = (*p)[ptr][i];
			int cnt = seaLevelBlocks[mSeaLevel];
			for (int j = 0; i < M; j++)
			{
				if ((map[now.y][now.x + j] < mSeaLevel) && (map[now.y][now.x + j] + mStructure[j] >= mSeaLevel))
					cnt++;
			}
			if (max < cnt)
				max = cnt;
		}
	}
	return max;
}