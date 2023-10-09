// DP_max[i][j] i~j 까지의 괄호 연산중 최대값
// DP_min[i][j] i~j 까지의 괄호 연산중 최솟값
// i==j일 때, 자신의 값 return

//처음엔 그냥 순서대로 계산=start~start op start+1~end
//start~start+1 op start+2~end 
// ... 반복 start~start+(end-start) op end~end 까지
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N;
vector<int>numbers;
vector<char>op;
struct Set {
	int Max;
	int Min;
};
int cal(int a, int b, char c) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
}
int DP_max[10][10];
int DP_min[10][10];
Set func(int start, int end) { //0~N/2 (마지막 index)
	if (start == end) {
		DP_max[start][end] = numbers[start];
		DP_min[start][end] = DP_max[start][end];
		return { DP_max[start][end],DP_min[start][end] };
	}
	if(DP_max[start][end]!=0) return {DP_max[start][end],DP_min[start][end]};
	
	int Max = -21e8;
	int Min = 21e8;
	for (int i = 0; i < end - start; i++) {
		Set a = func(start, start + i);
		Set b = func(start + i + 1, end);
		// Max op Max, Max op Min, Min op Min, Min op Max
		int ma;
		int mi;
		int ret1 = cal(a.Max, b.Max, op[start + i]);
		int ret2 = cal(a.Max, b.Min, op[start + i]);
		int ret3 = cal(a.Min, b.Max, op[start + i]);
		int ret4 = cal(a.Min, b.Min, op[start + i]);
		ma = max(ret1, ret2);
		ma = max(ma, ret3);
		ma = max(ma, ret4);

		mi = min(ret1, ret2);
		mi = min(mi, ret3);
		mi = min(mi, ret4);

		if (ma > Max) Max = ma;
		if (mi < Min) Min = mi;
	}

	DP_min[start][end] = Min;
	DP_max[start][end] = Max;
	return { Max,Min };
}
int main() {
	cin >> N;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2 == 0) //짝수가 num
			numbers.push_back(s[i] - '0');
		else
			op.push_back(s[i]);
	}
	Set ret=func(0, N/2);
	cout << ret.Max;
	return 0;
}