#include <iostream>
#include <string>

using namespace std;

int main() {
	string input[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> input[i];
		int cnt = 0;
		int pos=-1;
		while (1) {
			pos = input[i].find("MCD", pos+1);
			if (pos == -1)
				break;
			cnt++;
		}
		sum += cnt;
	}
	cout << sum;
	return 0;
}