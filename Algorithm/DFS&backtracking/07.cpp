#include <iostream>
using namespace std;

char ground[6] = "_____";

void print()
{
	for (int i = 0; i < 5; i++) {
		if (ground[i] == '0') cout << '_';
		else if (ground[i] == '_') cout << '_';
		else cout << ground[i];
	}
	cout << endl;
}

int main()
{
	int idx, timer;
	cin >> idx >> timer;

	ground[idx] = '0' + timer;

	int y;
	int before;

	for (y = timer - 1; y >= 0; y--) {
		print();

		before = idx;
		idx++;
		if (idx == 5) idx = 0;

		ground[before] = '_';
		ground[idx] = y + '0';
	}

	print();

	return 0;
}