#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct NODE {
	char c;
	NODE* next;
};
NODE *head;
NODE *last;
void addNode(char a) {
	if (head == NULL) {
		head = new NODE();
		head->c = a;
		last = head;
	}
	else {
		last->next = new NODE();
		last = last->next;
		last->c = a;
	}
}

int main() {
	int n;
	cin >> n;
	n -= 11;

	for (int i = 0; i < 4; i++) {
		addNode('A' + n + i);
	}
	NODE* p = head;
	while (p != NULL) {
		cout << p->c;
		p = p->next;
	}
	return 0;
}