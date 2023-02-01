#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string>split(string s, char c) {

	vector<string> arr;
	int head = 0;
	int tail = s.find(c, 0);
	
	if (tail == -1) {
		arr.push_back(s);
		return arr;
	}

	while (1) {
		string temp = s.substr(head, tail - head);
		if (temp != "") {
			arr.push_back(temp);
		}
		head = tail + 1;
		tail = s.find(c, tail + 1);
		if (tail == -1) {
			string temp = s.substr(head, tail - head);
			if (temp != "") {
				arr.push_back(temp);
			}
			break;
		}
	}
	return arr;
}

int main() {
	string st;
	cin >> st;
	vector<string>v=split(st,'|');
	vector<string>mail;
	for (int i = 0; i < v.size(); i++) {
		mail.push_back(split(v[i], '.')[0]);
	}
	
	for (int i = 0; i < v.size(); i++) {
		vector<string>vv = split(mail[i], '@');
		cout << "[#" << vv[0] << "] " << vv[1] << endl;
	}
	
}