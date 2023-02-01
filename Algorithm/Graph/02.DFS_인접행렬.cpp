#include <iostream>
#include <vector>

using namespace std;


int nodeCnt, edgeCnt;
int adj[6][6]={0, }; // adj[from][to] = �� �� �ִ°�? 
void dfs(int now) {

	//��������

	for (int to = 1; to <= nodeCnt; to++) {
		//��Ϳ� ��������� ����� �κ�, ����ġ��(������ �� �Ǻ�)
		if (adj[now][to] == 0) continue; // now -> to �� �� �� ������ ����
		//�̸� �Ǻ��ϰ� ���� ������ �������� ��� ��Ͱ� ����
		//�� ��尡 1 3, 3 5, 5 1 �� ��� ���� ������ ������...
		//���� node masking �ʿ�

		cout << now << "���� " << to << "�� ���ϴ�!" << endl;
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