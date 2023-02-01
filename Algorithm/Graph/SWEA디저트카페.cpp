
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int v[20][20];
int n;
int visited[20][20] = { 0 };
int disert[101] = { 0 };
int Max = -1;
int rootY, rootX;
int pathLen = 0;
//대각선으로 사각선그려야함 -> 대각선 dir 각 한번씩만
int dir[4][2] = { 1,1,1,-1,-1,-1,-1,1}; //오른쪽아래부터 시계방향
// range 벗어난 점이 3개 이상이면 사각형 불가능
int isRange(int y, int x) { 
	if (y < 0 || x < 0 || x >= n || y >= n)
		return 0;
	return 1;
}
void dfs(int y,int x, int direction) {
	if (visited[y][x] && y == rootY && x == rootX) {
		
		if (Max < pathLen)
			Max = pathLen;
		return;
	}
	//backtracking
	if (direction >= 4)
		return;
	if (disert[v[y][x]] == 1)
		return;
	if (visited[y][x] == 1)
		return;
	//두번 꺾였을때 마름모 크기 구해서 이미 Max 를 넘길 수 없으면 return
	if (direction == 2) {
		if (Max >= (pathLen - 1) * 2)
			return;
	}
	visited[y][x] = 1;
	disert[v[y][x]] = 1;
	for (int i = direction; i <= direction+1; i++) {
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];
		if (!isRange(dy, dx)) {
			continue;
		}
		//동작 전
		pathLen++;
		dfs(dy, dx,i);
		//reset
		pathLen--;
	}
	disert[v[y][x]] = 0;
	visited[y][x] = 0;
}
int main() {
	int T;
	cin >> T;
	vector<int>ans;
	for (int t = 0; t < T; t++) {
		//reset
		Max = -1;
		pathLen = 0;
		//input
		cin >> n;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> v[y][x];
			}
		}
		//동작
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				rootY = y;
				rootX = x;
				dfs(y, x, 0);
				memset(visited, 0, sizeof(visited));
				memset(disert, 0, sizeof(disert));
			}
		}
		ans.push_back(Max);
	}
	//ans
	for (int i = 1; i <= T; i++) {
		cout << '#' << i << " " << ans[i - 1]<<'\n';
	}
}