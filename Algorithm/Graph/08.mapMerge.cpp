#include <iostream>
#include <vector>
#include <string>

using namespace std;

//A에서 max 3개, B에서 min 3개 c에서 min2개 max1개
int A[3][3] = { 2,6,3,7,1,1,3,4,2 };
int B[2][4] = { 6,4,2,4,1,1,5,8 };
int C[2][3] = { 9,2,3,4,2,1 };

int map[3][3];

int main() {
	int map[3][3];
	int DAT[10] = { 0 };
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			DAT[A[y][x]]++;
		}
	}
	int i = 0;
	int idx = 9;
	while (i<3) {
		if (DAT[idx] >= 1) {
			DAT[idx]--;
			map[0][i] = idx++;
			i++;
		}
		idx--;
	}

	int DAT2[10] = { 0 };
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 4; x++) {
			DAT2[B[y][x]]++;
		}
	}
	i = 0;
	idx = 0;
	while (i < 3) {
		if (DAT2[idx] >= 1) {
			DAT2[idx]--;
			map[1][i] = idx--;
			i++;
		}
		idx++;

	}
	int DAT3[10] = { 0 };
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 3; x++) {
			DAT3[C[y][x]]++;
		}
	}
	i = 0;
	idx = 0;
	int t = 9;
	while (i < 3) {
		if (i < 2) {
			if (DAT3[idx] >= 1) {
				DAT3[idx]--;
				map[2][i] = idx--;
				i++;
			}
			idx++;
		}
		else {
			if (DAT3[t] >= 1) {
				map[2][i] = t;
				i++;
			}
			t--;
		}
	}

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << map[y][x] << " ";
		}
		cout << '\n';
	}
	return 0;
}
/*
#include<iostream>
using namespace std;
int main() {
	int A[3][3] = {
		2,6,3,
		7,1,1,
		3,4,2
	};
	int B[2][4] = {
		6,4,2,4,
		1,1,5,8
	};
	int C[2][3] = {
		9,2,3,
		4,2,1
	};
	int arr[3][3];
	int x, y;
	for (int i = 0; i < 3; i++) {
		for (x = 0; x < 3; x++) {
			if (x == 0) y = i; // 0행일때 y=i열(0,1,2)에 max값을 넣을 차례
			else y = 0;
			for (; y < 3; y++) {
				if (A[0][i] < A[x][y]) {
					int tmp = A[0][i];
					A[0][i] = A[x][y];
					A[x][y] = tmp;
				}
			}
		}
		arr[0][i] = A[0][i];
		for (x = 0; x < 2; x++) {
			if (x == 0) y = i;
			else y = 0;
			for (; y < 4; y++) {
				if (B[0][i] > B[x][y]) {
					int tmp = B[0][i];
					B[0][i] = B[x][y];
					B[x][y] = tmp;
				}
			}
		}
		arr[1][i] = B[0][i];
		for (x = 0; x < 2; x++) {
			if (x == 0) y = i;
			else y = 0;
			for (; y < 3; y++) {
				if (i == 2) {
					if (C[0][2] < C[x][y]) {
						int tmp = C[0][2];
						C[0][2] = C[x][y];
						C[x][y] = tmp;
					}
				}
				else {
					if (C[0][i] > C[x][y]) {
						int tmp = C[0][i];
						C[0][i] = C[x][y];
						C[x][y] = tmp;
					}
				}
			}
		}
		arr[2][i] = C[0][i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}*/