/*
trie
단어를 추가할 때마다, 알파벳 경로마다 1씩 추가해줌
해당 알파벳을 몇번 지났다는 의미
단어가 끝나는 마지막 알파벳은 표시해줌

i번째 정렬된 단어를 찾고 싶다?
a~z부터 보면서 i 보다 작은 개수인 시작단어들을 거를 수 있다.

*/
#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_SIZE 401
class Trie {
public:
	char c;
	int cnt;
	bool isEnd;
	unordered_map<char, Trie*> children;
	Trie() {
		c = '\0';
		cnt = 0;
		isEnd = false;
	}
};
char ans[MAX_SIZE];
void dfs(Trie* now,int depth,int K) {
	if (now->isEnd) {//마지막 문자라면
		K--;
	}
	if (K == 0) {//원하는 단어를 찾았다면
		ans[depth] = '\0';
		return;
	}
	for (char i = 'a'; i <= 'z'; i++) {
		if (now->children.find(i) == now->children.end()) continue;
		if (K - now->children[i]->cnt > 0) { //내가 원하는 index의 단어가 이쪽 그룹에 없음
			K -= now->children[i]->cnt;
			continue;
		}
		ans[depth] = i;
		dfs(now->children[i], depth+1, K);
		break;
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int K;
		string s;
		cin >> K >> s;
		int len = s.length();
		Trie* head = new Trie();
		for (int i = 0; i < len; i++) {
			Trie* now = head;
			for (int j = i; j < len; j++) {
				//하나씩 trie 저장
				if (now->children.find(s[j]) == now->children.end()) {
					//없으면
					Trie* newNode = new Trie();
					newNode->c = s[j];
					now->children.insert({ s[j], newNode });
				}
				now = now->children[s[j]];
				now->cnt++;
			}
			now->isEnd = true;
		}
		//K번쨰 찾기
		int cnt = 0;
		Trie* now = head;
		dfs(head, 0, K);
		cout << '#' << t << ' ' << ans << '\n';
		delete head;
	}

	return 0;
}