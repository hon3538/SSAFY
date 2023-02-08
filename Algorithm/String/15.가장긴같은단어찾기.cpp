#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

string longStr, shortStr;
int main() {
	string s1, s2;
	cin >> s1>> s2;
	if (s1.length() > s2.length()) {
		longStr = s1;
		shortStr = s2;
	}
	else {
		longStr = s2;
		shortStr = s1;
	}
	int shortLen = shortStr.length();
	string max;
	for (int u = 1; u <= shortLen; u++) {
		for (int i = 0; i <= shortLen-u; i++) {
			string target = shortStr.substr(i, u);
			if (longStr.find(target) == -1) {
				continue;
			}
			max = target;
			break;
		}
	}
	cout << max;
	return 0;
}