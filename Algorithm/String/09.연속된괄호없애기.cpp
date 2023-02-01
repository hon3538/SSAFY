#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int len;
void rm(char c){
	//'(' 
	int len = s.length();
	int head = 0;
	while (1) {
		head = s.find(c, head);
		if (head == -1)
			break;
		int cnt = 0;
		while (1) {
			if (s[head + cnt] == c) {
				cnt++;
			}
			else break;
		}
		if (c == '^') {
			if (cnt >= 3)
				cnt --;
			else {
				head += 1;
				continue;
			}
		}
		s.erase(head, cnt-1);
		len -= cnt - 1;
		head +=1;
	}
}
void change() {

	int head=0;
	int tail;
	
	while (1) {
		head = s.find('^', head);
		if (head == -1)
			break;
		
		tail = s.find('^', head + 1);
		if (tail == -1)
			break;

		if (tail - head == 2 && (s[head + 1] != '(' || s[head + 1] != ')' || s[head + 1] != '_'))
			s[head+1] = '_';

		head = tail + 1;
	}
}
int main() {
	cin >> s;
	len = s.length();
	rm('(');
	rm(')');
	rm('^');
	change();
	cout << s;
	
	//괄호 중첩되면 1개로


	//^^^ 여러개면 ->2개로

	//눈과 눈사이는 _,(,) 가 아니면 _로 바꾸기

	
}
/* 카운트 안 하고 (( 이나 ^^^을 패턴을 찾을때마다 없애주는 반복문만들어줘도됨
근데 이래하면 패턴을 찾을때마다 반복문O(n)?을 사용하니까
비효율적일거같긴한데 생각하기는 쉬움 교수님도 일케 품

#include <iostream>
#include <string>
using namespace std;

string str;

void removeChar(char ch)
{
	//괄호 한개로 정리

	string tar;
	tar += ch;
	tar += ch;

	int a = -1;
	int b;
	while (1) {
		a = str.find(tar, a + 1);
		if (a == -1) break;

		for (int i = a; i <= str.length(); i++) {
			if (str[i] != ch) {
				b = i;
				break;
			}
		}

		int size = b - a - 1;
		str.erase(a, size);
	}
}

void step1()
{
	removeChar('(');
	removeChar(')');
}
void step2()
{
	//눈웃음 ^^ 두개로 정리

	int a = -1;
	int b;
	while (1) {
		a = str.find("^^^", a + 1);
		if (a == -1) break;

		for (int i = a; i <= str.length(); i++) {
			if (str[i] != '^') {
				b = i;
				break;
			}
		}

		int size = b - a - 2;
		str.erase(a, size);
	}

}
void step3()
{
	//눈과 눈 사이 _ 하나로 정리
	int a = -1;
	int b = 1;

	while (1) {
		a = str.find('^', a + 1);
		if (a == -1) break;
		if (a + 2 >= str.length()) break;

		if (str[a + 2] == '^') str[a + 1] = '_';
	}
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	cin >> str;

	step1();
	step2();
	step3();

	cout << str;

	return 0;
}

*/