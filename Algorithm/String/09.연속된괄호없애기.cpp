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
	
	//��ȣ ��ø�Ǹ� 1����


	//^^^ �������� ->2����

	//���� �����̴� _,(,) �� �ƴϸ� _�� �ٲٱ�

	
}
/* ī��Ʈ �� �ϰ� (( �̳� ^^^�� ������ ã�������� �����ִ� �ݺ���������൵��
�ٵ� �̷��ϸ� ������ ã�������� �ݺ���O(n)?�� ����ϴϱ�
��ȿ�����ϰŰ����ѵ� �����ϱ�� ���� �����Ե� ���� ǰ

#include <iostream>
#include <string>
using namespace std;

string str;

void removeChar(char ch)
{
	//��ȣ �Ѱ��� ����

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
	//������ ^^ �ΰ��� ����

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
	//���� �� ���� _ �ϳ��� ����
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