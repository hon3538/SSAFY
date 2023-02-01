#include <iostream>
#include <vector>

using namespace std;


int nodeCnt, edgeCnt;
int adj[6][6]={0, }; // adj[from][to] = 갈 수 있는가? 
void dfs(int now) {

	//기저조건

	for (int to = 1; to <= nodeCnt; to++) {
		//재귀와 기능적으로 비슷한 부분, 가지치기(가능한 지 판별)
		if (adj[now][to] == 0) continue; // now -> to 로 갈 수 없으면 무시
		//미리 판별하고 들어가기 때문에 기저조건 없어도 재귀가 끝남
		//단 노드가 1 3, 3 5, 5 1 의 경우 무한 루프가 생성됨...
		//따라서 node masking 필요

		cout << now << "에서 " << to << "로 갑니다!" << endl;
		dfs(to);

	}
}

int main() {
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;

		adj[from][to] = 1;
	}
	int from = 1;
	dfs(from);

	return 0;
}