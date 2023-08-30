#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct min_cmp {
	bool operator()(int a, int b){
		return a > b;
	}
};
struct max_cmp {
	bool operator()(int a, int b) {
		return a < b;
	}
};
priority_queue<int, vector<int>, min_cmp> min_heap;
priority_queue<int, vector<int>, max_cmp> max_heap;


void init() {
	while (!min_heap.empty()) min_heap.pop();
	while (!max_heap.empty()) max_heap.pop();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		int N, A;
		cin >> N >> A;
		min_heap.push(A);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b) swap(a, b);
			max_heap.push(a);
			min_heap.push(b);

			int left_top = max_heap.top();
			int right_top = min_heap.top();
			if (left_top > right_top) {
				max_heap.pop();
				min_heap.pop();
				min_heap.push(left_top);
				max_heap.push(right_top);
			}
			ans += min_heap.top();
			ans %= 20171109;
		}
		cout << '#' << t << ' ' << ans<<'\n';
	}
}