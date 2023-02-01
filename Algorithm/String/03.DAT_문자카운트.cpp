#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int main() {
	int count[200] = { 0 };
	string st;
	cin >> st;

	char max = 0;
	char min = 'A';
	
	int len = st.length();
	for (int i = 0; i < len; i++) {
		++count[st[i]];
	}

	for (char i = 'A'; i <= 'Z'; i++) {
		if (count[i] > count[max]) {
			max = i;
		}
		if (count[i] < count[min]) {
			min = i;
		}
	}
	cout << max << endl;
	cout << min;
	return 0;
}