#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;

	//인접행렬 방식
	int adj[6][6] = {0}; // adh[from][to] = 갈 수 있는가?
	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}

	int node = 1; // 특정 from에서 갈 수 있는 모든 node(to) 찾기

	for (int to = 0; to <= 5; to++) {
		if (adj[node][to] == 0) continue;
		cout << "from->"<<to<<"로 갈 수 있다"<<endl;
	}

	//인접리스트 방식
	vector<int> v[6]; // v[from] : from에서 갈 수 있는 to들을 저장한 vector

	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;

		v[from].push_back(to);
	}

	//특정 from에서 갈 수 있는 모든 to 찾기
	node = 1; //from node
	for (int i = 0; i < v[node].size(); i++) {
		int to = v[node][i]; // 순서대로 to 꺼내기
		cout << to;
	}
}