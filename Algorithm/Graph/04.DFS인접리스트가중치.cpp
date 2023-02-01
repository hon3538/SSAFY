#include <iostream>
#include <vector>
#include <string>
using namespace std;


//인접리스트 DFS

int mat[10][10]; // DAT -> 모든 노드 번호를 담을 수 있는 X의 크기만큼

int N, E; //노드, 간선 개수
int visited[10]; //
int goal = 3;
int weight = 0;
int Min = 21e8;
vector<int>path;

//새로운 자료형
struct Edge {
	int to;
	int cost;

};
vector<Edge>v[10]; // vector 의 arr, vector size : node 개수, 각 vector의 arr size : 간선개수

void dfs(int now) {

	for (int i = 0; i < v[now].size(); i++) {
		Edge next = v[now][i];
		if (visited[next.to] == 1)
			continue;
		weight += next.cost;
		visited[next.to] = 1;
		dfs(next.to);
		visited[next.to] = 0;
		weight -= next.cost;
	}
}
int main() {
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		
		v[from].push_back({to,cost});
		v[to].push_back({from,cost});
	}

	return 0;
}