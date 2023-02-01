#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	string st;
	cin >> st;

	cout << st << endl;

	int len = st.length();
	for (int i = len - 1; i >= 0; i--) {
		cout << st[i];
	}

	return 0;
}