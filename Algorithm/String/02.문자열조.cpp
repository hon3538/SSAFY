#include <iostream>
#include <string>

using namespace std;

int n;
string st[100];
string cr = "CHRISTMAS";
int mask[100] = {0};
int cnt = 0;
void func(int level,string s) {
	if (cr.find(s)) {
		return;
	}

	if (level == 4) {
		cnt++;
		return;
	}


	for (int i = 0; i < n; i++) {
		if (mask[i] == 1)
			continue;

		mask[i] = 1;
		func(level + 1,s+st[i]);
		mask[i] = 0;
	}
}
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st[i];
	}
	func(0, "");
	
	cout << cnt;
	return 0;
}