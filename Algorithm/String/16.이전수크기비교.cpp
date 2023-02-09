#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<string>v;

int maxIdx;
int Max=INT_MIN;

int getNum(string s){
	int len = s.length();
	int sum = 0;
	int two = 1;
	int idx = len;
	while (idx > 0) {
		if (idx != len) {
			two *= 2;
		}
		idx--;
		if(s[idx]=='1')
			sum += two;
	}
	return sum;
}
int main() {
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		v.push_back(s);
		int n = getNum(s);
		if (Max < n) {
			Max = n;
			maxIdx = i;
		}
	}
	cout << v[maxIdx];
	return 0;
}

