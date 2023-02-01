#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


int nodeCnt, edgeCnt;
vector<int> v[6];
int visited[6] = { 0 };
int goal = 3;
int Min = INT_MAX;
int cnt = 0;
vector<int> path;
void dfs(int now) {

	//기저조건, 목적지 최소거리
	if (goal == now) {
		if (Min > cnt)
			Min = cnt;
		return;
	}

	for (int i = 0; i < v[now].size(); i++) {
		//now->to 찾기
		int to = v[now][i];
		if (visited[to] == 1)
			continue;
		visited[to] = 1;
		path.push_back(to);
		cnt++;
		cout << now << "에서 " << to << endl;
		dfs(to);
		cnt--;
		visited[to] = 0;
		path.pop_back();
	}
}

int main() {
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}
	int from = 0;
	dfs(from);

	cout << Min;
	return 0;
}