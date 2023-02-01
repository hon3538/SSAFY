#include <iostream>
#include <string>

using namespace std;

int main() {
	string log;
	cin >> log;
	int len = log.length();
	for (int i = 0; i < len; i++) {
		if(log[i]<'a')
			log[i] = log[i] - 'A' + 'a';
	}
	
	int cnt[2];
	string st[2] = { "pass","fail" };
	for (int i = 0; i < 2; i++) {
		cnt[i] = 0;
		int pos=-1;
		while (1) {
			pos = log.find(st[i], pos + 1);
			if (pos == -1)
				break;
			cnt[i]++;
		}
	}
	int rate = (cnt[0]*100 / (cnt[0] + cnt[1]));

	cout << rate << '%';
	return 0;
}