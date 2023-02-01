#include <iostream>
#include <vector>
#include <string>
using namespace std;


//인접행렬 DFS

int mat[10][10]; // DAT -> 모든 노드 번호를 담을 수 있는 X의 크기만큼

int N, E; //노드, 간선 개수
int visited[10]; //
int goal = 3;
int weight = 0;
int Min = 21e8;
vector<int>path;
void dfs(int now) {
	if (now == goal) {
		
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}
		if (weight < Min) {
			Min = weight;
		}
		return;
	}

	for (int to = 0; to < N; to++) {
		if (mat[now][to] == 0)
			continue;
		if (visited[to] != 0) {
			continue;
		}
		//가지치기 -> 어떤 경우에 이길로 가면 가망성이 없을까?
		//weight이 이미 Min값을 넘겼을 경우...
		if (weight + mat[now][to] > Min) {
			continue;
		}
		weight += mat[now][to];
		path.push_back(to);
		visited[to] = 1;
		dfs(to);
		visited[to] = 0;
		weight -= mat[now][to];
		path.pop_back();

	}

}
int main() {
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		mat[from][to] = cost;
		mat[to][from] = cost;

	}

	return 0;
}