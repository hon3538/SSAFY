// 여러개의 데이터가 연속적으로 존재할 때
// 특정한 범위의 데이터의 합을 구하는 방법
// 구간의 모든 요소를 더해나가면 O(N)인데 반해
// segment tree는 O(logN) 으로 구할 수 있다.

// 모든 값을 입력받을 때 tree 구조로 각 구간의 합을 저장한다.
// 1번 노드가 root이고 , node*2 가 왼쪽, node*2 + 1 이 오른쪽 노드이다.


// Segment Tree Idea -> 재귀 구현, DP
// 요소들의 index 중간값(mid)을 기준으로 계산한 값을 왼쪽과 오른쪽으로 나눈다.
// 구간이 아니게 되면 본인의 값을 리턴하고
// 구간의 경우는 아래 노드들의 값의 합을 저장하고 리턴한다

//값의 변경 역시 구간에 속하는 값들만 바꿔주면 되므로 O(logN)

#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000000

int N, M, K; //N 수의 개수, M 값의 변경 횟수, K 구간 합
long long tree[3000000]; //1000000 은 2의 20승, 20번 나눠진다는 의미
//1(안 나눈상태) 2 4 8.. 따라서 21개의 등비수열의 합이 곧 최대 필요 메모리 공간
long long input[MAX + 1];
int Left, Right; // 구하고자 하는 범위 index
int update_index; //바꿀 인덱스
long long update_value; //바꿀 숫자
long long init(int start, int end, int node) { //트리 구조로 배열 저장 (prefix sum 형태로)
	if (start == end) return tree[node] = input[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
long long sum(int start, int end, int node) {
	//범위 밖에 있는 경우는 더해주면 안 되므로 return 0
	if (end<Left || start>Right) return 0;

	//구하고자 하는 범위 안에 있는 구간이면 합 return
	if (start >= Left && end <= Right) return tree[node];

	//범위가 애매하면 구하고자 하는 구간을 반으로 나누어서 탐색
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2) + sum(mid + 1, end, node * 2 + 1);
}
void update(int start, int end, int node) {
	if (update_index<start || update_index>end) return;

	//현재 구간의 합에 이전값 빼주고 새값을 더해준다
	tree[node] -= input[update_index];
	tree[node] += update_value;

	if (start == end) return; //마지막 노드이면 

	int mid = (start + end) / 2;
	update(start, mid, node * 2);
	update(mid + 1, end, node * 2 + 1);
}
int main() {
	 ios::sync_with_stdio(false);
 	cin.tie(NULL);
 	cout.tie(NULL); 
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		long long value;
		cin >> value;
		input[i] = value; //i번째 value 
	}
	init(1, N, 1);
	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) { //b 번째수를 c로 바꿔라
			update_index = b;
			update_value = c;
			update(1, N, 1);
			input[update_index] = update_value; //값을 바꿔서 저장한다
		}
		else if (a == 2) { //b~c까지 구간합 출력
			Left = b;
			Right = c;
			cout << sum(1, N, 1) << '\n';
		}
	}
	return 0;
}
