#include <iostream>
#include <limits.h>
using namespace std;
// 2칸 , 7칸 씩 뛸 수 있다.
//  각 칸에서 최대가 되는 값을 저장하면서 finish도달
//
int n;
int map[200]; // start : 0, end : n+1;
int DP[200];
int steps[2] = { 2, 7 };
int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> map[i];
	}
	map[0] = 0;
	for (int i = 0; i <= n + 7; i++)
	{
		DP[i] = -21e8;
	}
	DP[0] = 0;

	for (int j = 2; j <= n + 7; j++)
	{
		if (j <= n + 2) {
			if (DP[j - 2] + map[j] > DP[j])
				DP[j] = DP[j - 2] + map[j];
		}
		if (7 <= j) {
			if (DP[j - 7] + map[j] > DP[j]) {
				DP[j] = DP[j - 7] + map[j];
			}
		}
		
	}
	 int max = INT_MIN;
	 for (int i = n + 1; i <= n + 7; i++) {
	 	//cout << DP[i] << ' ';
	 	if (max < DP[i])
	 		max = DP[i];

	 }
	cout << max;
	return 0;
}
/* Bottom-Up
#include <iostream>
using namespace std;

int arr[200];
int dp[200];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	//Bottom-Up
	int MIN = -21e8;
	for (int i = 0; i <= N + 5; i++)
		dp[i] = MIN;

	// 일단 2칸씩 가는 칸을 모두 채움 -> 2에서 7칸을 점프해서 N을 5만큼 넘어갈수 있는 공간까지 확인한다
	dp[0] = 0;
	for (int i = 2; i <= N+5; i++) {
		dp[i] = dp[i - 2] + arr[i];
	}

	// 7까지 점프하는 방법은 0->7 하나
	dp[7] = 7;
	// 이후로부터 특정 칸에 도달하기 위한 값 = 2칸 전에서 점프했거나, 7칸 전에서 점프했거나
	for (int i = 7; i <= N + 5; i++) {
		dp[i] = max(dp[i - 7] + arr[i], dp[i - 2] + arr[i]);
	}

	int ans = -21e8;

	// N~N+5까지의 공간중 최대값을 확인
	for (int i = N; i <= N + 5; i++) {
		if (dp[i] > ans)
			ans = dp[i];
	}
	cout << ans;
}
*/

/* Top-Down
#include <iostream>
using namespace std;

int memo[1000];
int map[1000];

int getPoint(int n)
{
	if (n == 0) return 0;
	if (n < 0) return -999999;
	if (memo[n] != 0) return memo[n];

	int a = getPoint(n - 2);
	int b = getPoint(n - 7);

	int ret = a;
	if (ret < b) ret = b;

	memo[n] = ret + map[n];
	return memo[n];
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> map[i];

	int max = -21e8;
	//(n + 1) ~ (n + 5)
	for (int i = 1; i <= 5; i++) {
		int ret = getPoint(n + i);
		if (ret > max) max = ret;
	}

	cout << max;

	return 0;
}
*/