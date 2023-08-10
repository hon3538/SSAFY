//자식을 담은 배열
//재귀 구성으로 자식 탐색, 자식들이 target을 모두 포함하고 있으면 해당 노드 리턴
//size 구하는 함수 구현
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_NODE 10001

int children[MAX_NODE][2]; // index1 : 부모 노드, index2: 왼쪽 오른쪽 자식노드
int common;
int searchCommon(int node, int a, int b) {
	//이미 찾은 경우
	if (common != 0) return 0;
	//target을 찾을 경우
	if (node == a || node == b) return 1;
	//아무것도 없는 경우
	if (node == 0) return 0;
	int ret= searchCommon(children[node][0], a, b) + searchCommon(children[node][1], a, b);

	//가장 가까운 공통 조상은 첫 common 노드
	if (common == 0 && ret == 2) common = node;
	return ret;
}
int getSize(int node) {
	if (node == 0) return 0;
	//양쪽 자식의 자손들 + 자기자신 = node 를 root로 한 서브트리의 size
	return getSize(children[node][0]) + getSize(children[node][1])+1;
}
int T;
int V, E, A, B;
void init() {
	common = 0;
	memset(children, 0, sizeof(children));
}
void input() {
	for (int i = 0; i < E; i++) {
		int p, c;
		cin >> p >> c;
		if (children[p][0] != 0) children[p][1] = c;
		else children[p][0] = c;
	}
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> V >> E >> A >> B;
		init();
		input();
		searchCommon(1,A, B);
		int ans = getSize(common);
		cout << '#' << t << ' ' << common << ' ' << ans << '\n';
	}

	return 0;
}
/*
예를 들어, 위의 이진 트리에서 정점 8과 13의 공통 조상은 정점 3과 1 두 개가 있다.

이 중 8, 13에 가장 가까운 것은 정점 3이고, 정점 3을 루트로 하는 서브 트리의 크기(서브 트리에 포함된 정점의 수)는 8이다.

[입력]

가장 첫 번째 줄에 테스트케이스의 수가 주어진다.

각 케이스의 첫 번째 줄에는 정점의 개수 V(10 ≤ V ≤ 10000)와 간선의 개수 E, 공통 조상을 찾는 두 개의 정점 번호가 주어진다.

각 케이스의 두 번째 줄에는 E개 간선이 나열된다. 간선은 항상 “부모 자식” 순서로 표기된다.

위에서 예로 든 트리에서 정점 5와 8을 잇는 간선은 “5 8”로 표기된다.

정점의 번호는 1부터 V까지의 정수이며, 루트 정점은 항상 1번이다.

[출력]

각 테스트케이스마다 '#t'(t는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 가장 가까운 공통 조상의 번호와 그것을 루트로 하는 서브 트리의 크기를 공백으로 구분하여 출력하라.
*/