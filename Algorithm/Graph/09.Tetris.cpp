#include <iostream>
#include <vector>
#include <string>

using namespace std;

int tetris[5][4];

int isFull(int y) {
	for (int x = 0; x < 4; x++) {
		if (tetris[y][x] == 0)
			return 0;
	}
	return 1;
}
//y�������� ���� �� ĭ�� �̵�
void downBlock(int y) {
	for (int i = y; i > 0; i--) {
		for (int x = 0; x < 4; x++) {
			tetris[i][x] = tetris[i - 1][x];
		}
	}
	//�� ���ο� ����
	for (int x = 0; x < 4; x++) {
		tetris[0][x] = 0;
	}
}

int main() {
	
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> tetris[y][x];
		}
	}
	for (int y = 0; y < 5; y++) {
		if (isFull(y)) {
			downBlock(y);
		}
	}

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cout << tetris[y][x] << " ";
		}
		cout<<'\n';
	}
	return 0;
}