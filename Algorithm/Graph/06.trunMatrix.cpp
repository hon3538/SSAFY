#include <iostream>
using namespace std;


char v[3][4] = { " 54","3  ","  1" };

void turn() {
	char clone[3][3];
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			clone[x][2-y] = v[y][x];
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			v[y][x] = clone[y][x];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		turn();
	}
	
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (v[y][x] == ' ') {
				cout << '_';
			}
			else cout << v[y][x];
		}
		cout << '\n';
	}

	return 0;
}