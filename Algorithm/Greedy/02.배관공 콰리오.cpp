#include <iostream>
#include <algorithm>
using namespace std;
int N, L;
int leak[1000];
bool cmp(int left, int right) {
    return left < right;
}
int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> leak[i];
    }
    sort(leak, leak + N, cmp);
    int gap = L + 1;
    int start = leak[N - 1];
    int cnt = 1;
    for (int i = N - 1; i >= 0; i--) {
        gap = start - leak[i];
        if (gap >= L) {
            start = leak[i];
            cnt++;
            gap = 0;
        }
    }
    cout << cnt;
    return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int L;
int leaks[1001];

int main() {
	cin >> n >> L;
	for (int i = 0; i < n; i++)
		cin >> leaks[i];

	// sort
	// greedy : 맨 왼쪽의 파이프부터 막을 것.
	sort(leaks, leaks + n);

	// 일단 구멍은 한개 이상이니, 무조건 1개는 사용
	int cnt = 1;
	// 첫번째 구멍을 이 첫번째 테이프를 사용해서 막을 것.
	int now = leaks[0];

	// 두번째 구멍부터 확인
	for (int i = 1; i < n; i++) {
		// 만약 첫번째 테이프로 다음 구멍까지 커버가 가능하다면 -> 테이프를 하나 더 쓸 필요 없으니 pass
		if (leaks[i] - now < L)
			continue;
		else {
			// 지금 구멍 갱신
			now = leaks[i];
			cnt++;
		}
	}
	cout << cnt;
}
*/