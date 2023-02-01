#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;

	//������� ���
	int adj[6][6] = {0}; // adh[from][to] = �� �� �ִ°�?
	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}

	int node = 1; // Ư�� from���� �� �� �ִ� ��� node(to) ã��

	for (int to = 0; to <= 5; to++) {
		if (adj[node][to] == 0) continue;
		cout << "from->"<<to<<"�� �� �� �ִ�"<<endl;
	}

	//��������Ʈ ���
	vector<int> v[6]; // v[from] : from���� �� �� �ִ� to���� ������ vector

	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;

		v[from].push_back(to);
	}

	//Ư�� from���� �� �� �ִ� ��� to ã��
	node = 1; //from node
	for (int i = 0; i < v[node].size(); i++) {
		int to = v[node][i]; // ������� to ������
		cout << to;
	}
}