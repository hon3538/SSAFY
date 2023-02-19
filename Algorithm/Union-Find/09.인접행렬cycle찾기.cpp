#include <iostream>
#include <vector>
using namespace std;

int map[100][100];
int N;
int parent[100];
int Find(int now) {
	if (now == parent[now])
		return now;
	return parent[now] = Find(parent[now]);
}
void Union(int A, int B) {
	int pa = Find(A);
	int pb = Find(B);
	if (pa == pb)
		return;
	parent[pb] = pa;
}
int main() {
	cin >> N;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = y+1; x < N; x++) {
			if (map[y][x] != 1)
				continue;
			if (Find(y) == Find(x)) {
				flag = 1;
				break;
			}
			Union(y, x);
		}
		if (flag==1) {
			break;
		}
	}
	if (flag==1)
		cout << "cycle 발견";
	else cout << "미발견";

	return 0;
}