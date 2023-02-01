#include <iostream>
#include <string>
#include <vector>
using namespace std;


int isNumber(string s) {
	for (int x = 0; x < 5; x++) {
		if (s[x] < '0' || s[x]>'9')
			return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	vector<string>result;
	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		int len = st.length();
		int pos=0;
		while (1) {
			pos = st.find("[", pos);
			if (pos == -1)
				break;
			
			int right = st.find("]", pos);
			//��ȣ �� ������ 5�������� �˻�
			if (right - pos - 1 != 5) {
				pos += 1;
				continue;
			}

			//��� ������ �������� Ȯ��
			if (isNumber(st.substr(pos + 1, 5)))
				result.push_back(st.substr(pos, right - pos+1));
			
			pos += right - pos + 1;
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}


/* ������ �ڵ�
#include <iostream>
#include <string>
using namespace std;

int isValid(string tar)
{
	if (tar.length() != 5) return 0;
	for (int i = 0; i < 5; i++) {
		if (!(tar[i] >= '0' && tar[i] <= '9')) return 0;
	}
	return 1;
}

void go(string str)
{
	int a = 0;
	int b;

	while (1) {
		a = str.find('[', a);
		if (a == -1) return;
		b = str.find(']', a + 1);
		if (b == -1) return;

		string temp = str.substr(a + 1, b - a - 1);
		if (isValid(temp) == 1) {
			cout << "[" << temp << "]\n";
		}
		a = b + 1;
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		go(str);
	}

	return 0;
}*/