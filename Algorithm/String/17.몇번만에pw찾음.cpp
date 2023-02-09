#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int n;
string s;
char res[5];
int ans[11];
int cnt;
int flag = false;
//백트랙킹
//비밀번호가 하나라도 틀리면 return

int isValid(int level) {
	if (res[level] != s[level])
		return 0;
	return 1;
}
int pow(int level) {
	int num = 1;
	for (int i = 0; i < 3-level; i++) {
		num *= 26;
	}
	return num;
}
//알파벳 26개,,, 한번 건너뛸때마다 26번 스킵, 남은 level 승 만큼 cnt 추가
//level 0에서 스킵이면 1,2,3 level 건너 뛰므로 26^3번를 count에 plus해준다.
void dfs(int level) {
	if (level == 4) {
		cnt++;
		flag = true;
		return;
	}
	for (char i = 'A'; i <= 'Z'; i++) {
		if (flag)
			return;
		res[level] = i;
		if (!isValid(level)) {
			cnt += pow(level);
			continue;
		}
		dfs(level + 1);
	}
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		cnt = 0;
		flag = false;
		dfs(0);
		ans[i] = cnt;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}

