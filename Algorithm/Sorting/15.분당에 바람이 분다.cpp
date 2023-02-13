#include <iostream>
#include <vector>
#include <string>
using namespace std;

int map[3][3];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y, x, v;
		cin >> y >> x >> v;
		map[y][x] = v;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int storm;
		cin >> storm;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				if (map[y][x] == 0)
					continue;
				if (map[y][x] % 10 - storm <= 0) {
					map[y][x] /= 10;
				}
				else {
					map[y][x] -= storm;
				}
			}
		}
	}
	int cnt = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] != 0)
				cnt += to_string(map[y][x]).size();
		}
	}
	cout << cnt;
	return 0;
}