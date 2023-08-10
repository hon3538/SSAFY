#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX 20
int map[MAX][MAX];

unordered_set<int,int> um[6]; //key: id, value: count
int path[6];

void dfs(int level, int size) {
	if (level == size) {
		int key = 0;
		for (int i = 0; i <size; i++) {
			key *= 10;
			key += path[i];
		}
		if(isValid())
		um[size].insert(key);
		return;
	}
	for (int i = 1; i <= 5; i++) {
		path[level] = i;
		dfs(level + 1, size);
		path[level] = 0;
	}
}
void init(int N, int *mMap[]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int a;
			cin >> a;
			mMap[y][x] = a;
		}
	}
	//2~5개의 크기 블록들의 경우를 모두 저장
	for (int i = 2; i <= 5; i++) {
		dfs(0, i, 0);
	}
}

int main() {


	return 0;
}