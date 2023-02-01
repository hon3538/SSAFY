#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string>words;
	string st;
	cin >> st;
	int len = st.length();

	int head = 0;
	int tail = 0;
	
	while (head<len) {
		if (st[head] == '_') {
			head++;
			continue;
		}

		tail = st.find("_", head + 1);
		if (tail == -1)
			tail = len;
		words.push_back(st.substr(head, tail - head));

		head = tail + 1;
	}
	
	for (int i = 0; i < words.size(); i++) {
		cout << i + 1 << '#' << words[i] << endl;
	}
}