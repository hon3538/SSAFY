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
int tree[2000000]; //1000000 은 2의 20승, 20번 나눠진다는 의미
//1(안 나눈상태) 2 4 8.. 따라서 21개의 등비수열의 합이 곧 최대 필요 메모리 공간
int input[MAX+1];
int init(int start,int end, int node){ //트리 구조로 배열 저장 (prefix sum 형태로)
	if (start == end) return tree[node]=input[node];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
int sum(int start, int end, int node){

}

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		int value;
		cin >> value;
		input[i] = value; //i번째 value 
	}
	for (int i = 0; i < M + K; i++) {

	}


	return 0;
}
