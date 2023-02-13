#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

string input;
string head[2] = { "http://","https://" };
int size_h=0;
string tail[4] = { ".com",".co.kr",".org",".net" };

void toSmall() {
	int i = 0;
	while (i < input.size()) {
		input[i] = tolower(input[i]);
		i++;
	}
}

int getCount(string input) {

	int h;
	int t = -1;
	int min = INT_MAX;
	int cnt = 0;
	while (1) {
		for (int i = 0; i < 2; i++) {
			int index = input.find(head[i], t + 1);
			if (index == -1)
				continue;
			if (min > index) {
				min = index;
				size_h = head[i].size();
			}
		}
		h = min;
		min = INT_MAX;

		for (int i = 0; i < 4; i++) {
			int index = input.find(tail[i], h + 1);
			if (index == -1)
				continue;
			if (min > index) {
				min = index;
			}
		}
			t = min;
		min = INT_MAX;

		if (h == INT_MAX ||t==INT_MAX) {
			return cnt;
		}
		if (t - (h + size_h) >= 3)
			cnt++;
	}
}
int main() {
	cin >> input;

	toSmall();

	cout << getCount(input)<<"개";

	return 0;
}