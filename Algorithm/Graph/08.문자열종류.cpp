#include <iostream>
#include <vector>
#include <string>

using namespace std;
int cnt = 0;
int main() {
	string s;
	cin >> s;
	string path;
	for (int i = 0; i < s.length(); i++) {
		if (path.find(s[i]) == -1) {//없으면
			cnt++;
			path += s[i];
		}
		else
			continue;
	}
	cout << cnt << "종류";
	return 0;
}