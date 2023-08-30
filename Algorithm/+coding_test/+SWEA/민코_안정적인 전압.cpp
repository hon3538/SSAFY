#include <iostream>
#include <unordered_map>
using namespace std;
int N;
int arr[200000];
unordered_map<long long, int> power; // key : 전압, value : 해당 전압 카운트
unordered_map<long long, int> current; // count와 똑같지만, 이것은 현재까지만 반영
// 해당 index가 0이 될때 총 0의 카운트
int res[200000];
//반복문을 돌리면서 해당 인덱스까지 0의 개수 + 현재 index가 0으로 바꼈을때
//뒤에 0이생길 개수
//현재 value 와 0 사이의 gap을 전압으로 가지는 개수 - 현재까지 있었던 gap의 개수
int main() {
	cin >> N;
	long long val = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		val += arr[i];
		// if (power.find(val) == power.end()) {
		// 	power.insert({ val,0 });
		// }
		power[val]++;
	}
	val = 0;
	int ans = -21e8;
	for (int i = 0; i < N; i++) {
		val += arr[i];
		// if (current.find(val) == current.end()) {
		// 	current.insert({ val,0 });
		// }
		res[i] = power[arr[i]] - current[arr[i]] + current[0];
		current[val]++;
		if (ans < res[i]) ans = res[i];
	}
	cout << ans;

	return 0;
}