#include <iostream>
#include <vector>
#include <string>
using namespace std;


//������� DFS

int mat[10][10]; // DAT -> ��� ��� ��ȣ�� ���� �� �ִ� X�� ũ�⸸ŭ

int N, E; //���, ���� ����
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
		//����ġ�� -> � ��쿡 �̱�� ���� �������� ������?
		//weight�� �̹� Min���� �Ѱ��� ���...
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