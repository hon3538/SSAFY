#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct worker {
	string name;
	int num;
};
int main() {
	
	int n;
	cin >> n;
	
	int DAT[10000] = { 0 };
	string name[10000];
	vector<string>ans;
	vector<int>list;
	for (int i = 0; i < n; i++) {
		string str;
		int k, num;
		cin >> k>>num;
		list.push_back(num);
		//1 회원가입
		if (k == 1) {
			string s;
			cin >> s;
			if (DAT[num] == 1) {
				str = "ERROR";
			}
			else {
				name[num] = s;
				DAT[num] = 1;
				str = "OK";
			}
		}
		else {
			//2 출입처리
			cout << num << " " << name[num];
			if (DAT[num]==1) {
				//Enter
				DAT[num] = 2;
				str = name[num] + " Enter";
			}
			else {
				DAT[num] = 1;
				str = name[num] + " Exit";
			}
		}
		ans.push_back(str);
	}
	for (int i = 0; i < n; i++) {
		cout << list[i] << " " << ans[i] << '\n';
	}
}