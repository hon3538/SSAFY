//각 부모가 누군지 받아주고

//다 받은다음 각 노드마다 조상들을 저장해준다
//DP, 만약 두 숫자의 공통조상이면 같은 인덱스에 같은 조상이 들어가 있다

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;
int parent[10001];

vector<int>path[2]; //얘의 조상 path, path[n][k], n번 노드의 k번째 부모
 //n번 노드의 k번째 위 조상, 0번은 자기자신
void Find(int now, int n) { //0:a, 1:b path
	path[n].push_back(now);
	if (parent[now] == 0)
		return;
	Find(parent[now], n);
}
int bs() {
	int gap = path[1].size() - path[0].size(); // -면 1번이크고 +면 0번이 크고, 0이면 같은것
	//큰 사이즈 -작은사이즈 = 큰 벡터의 시작위치
	//index자체가 다르면 공통분모가 아니기 때문에
	int big = 0;
	int small = 1;

	if (gap > 0) { big = 1; small = 0; }
	gap = abs(gap);

	//여기서부터 ps
	int left = 0;
	int right = path[small].size() - 1;
	int ans;
	while (left <= right) {
		int mid = (left + right) / 2;
		//같으면 더아래로, 즉 right를 줄인다
		if (path[small][mid] == path[big][mid + gap]) {
			right = mid - 1;
			ans = path[small][mid];
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			parent[b] = a;
		}
		int a, b;
		cin >> a>> b;
		Find(a, 0);
		Find(b, 1);
		//경로 길이를 맞춰야함
		// 그다음 해당 index가 같은 값이면 공통 부모
		//bs로 index 탐색
		cout << bs()<<'\n';
        path[0].clear();
		path[1].clear();
	}


	return 0;
}