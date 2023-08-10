
#include <iostream>
#include <queue>
using namespace std;
int N;
struct cmp1 {
	bool operator()(int a,int b) {
		return a < b;
	}
};
struct cmp2 {
	bool operator()(int a, int b) {
		return a > b;
	}
};
priority_queue<int>Left;
priority_queue<int,vector<int>,greater<int>>Right;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); // 이거 없으면 ...

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		//비었으면 back 에 넣어
		if (Left.empty()) Left.push(n);
		else if (Left.size() == Right.size()) {
			Left.push(n);
		}
		else {
			Right.push(n);
		}

		if (!Left.empty() && !Right.empty() && Left.top() > Right.top()) {
			int toRight = Left.top();
			int toLeft = Right.top();
			Left.pop();
			Right.pop();
			Right.push(toRight);
			Left.push(toLeft);
		}
		cout << Left.top() << '\n';
	}

	return 0;
}