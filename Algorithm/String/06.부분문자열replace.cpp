#include <iostream>
#include <string>

using namespace std;

string ban[5] = { "KFC","MC","BICMAC","SHACK","SONY" };
string after[5] = { "#BBQ#","#BBQ#","#MACBOOK#","#SHOCK#","#NONY#" };
int main() {
	string st;
	cin >> st;

	string temp;

	for (int i = 0; i < 5; i++) {
		
		int size = st.length();
		int len = ban[i].length();
		int pos = -len;
		while (1) {
			pos = st.find(ban[i], pos + len);
			if (pos == -1)
				break;
			temp = st.substr(0, pos);
			temp += after[i];
			temp += st.substr(pos + len,size-pos-len+1);
			/*
			st.erase(pos, len);
			st.insert(pos, after[i]);
			pos+=after[i].length();
			*/
			st = temp;
		}
		
	}
	cout << st;
	return 0;
}