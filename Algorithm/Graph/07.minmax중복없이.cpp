#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int num[10];
	string com;
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		num[n]=1;
	}
	cin >> com;
	int h = 0;
	int t = 9;
	for (int i = 0; i < 6; i++) {
		if (com[i] == 'm') {
			while (1) {
				if (num[h] == 1) {
					num[h] = 0;
					cout << h++;
					break;
				}
				h++;
			}
		}
		else {
			while (1) {
				if (num[t] == 1) {
					num[t] = 0;
					cout << t--;
					break;
				}
				t--;
			}
		}
	}
	return 0;
}