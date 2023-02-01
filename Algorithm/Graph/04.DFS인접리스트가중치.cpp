#include <iostream>
#include <vector>
#include <string>
using namespace std;


//��������Ʈ DFS

int mat[10][10]; // DAT -> ��� ��� ��ȣ�� ���� �� �ִ� X�� ũ�⸸ŭ

int N, E; //���, ���� ����
int visited[10]; //
int goal = 3;
int weight = 0;
int Min = 21e8;
vector<int>path;

//���ο� �ڷ���
struct Edge {
	int to;
	int cost;

};
vector<Edge>v[10]; // vector �� arr, vector size : node ����, �� vector�� arr size : ��������

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