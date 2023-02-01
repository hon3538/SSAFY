#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
	int max = 0;

	int H, W;
	cin >> H >> W;
	int DAT[10000001] = { 0 };
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			int n;
			cin >> n;
			DAT[n]++;
			if (DAT[n] > max) {
				max = DAT[n];
			}
		}
	}
	int val = 0;
	for (int i = 1; i <= 10000000; i++) {
		if (DAT[i]==max) {
			val = i;
			break;
		}
	}

	cout << val;
	return 0;
}