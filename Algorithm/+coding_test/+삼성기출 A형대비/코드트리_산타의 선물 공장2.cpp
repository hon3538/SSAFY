//쿼리 q 10만
//벨트 n 10만
//선물 m 10만
#include <iostream>
using namespace std;
//node 구현
struct Node {
	Node* prev;
	Node* next;
	int data;

	Node() {
		prev = next = NULL;
		data = -1;
	}
	Node(int n, Node* before) { //before 노드 뒤에 삽입되어라       
		next = before->next;
		prev = before;
		next->prev = this;
		prev->next = this;
		data = n;
	}
	void delNode() {
		prev->next = next;
		next->prev = prev;
		delete this;
	}
};
//list 구현
Node* gifts[100001];
int cnt;
class DLL {

public:
	Node* head;
	Node* tail;
	int size;
	DLL() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	void addFront(int data) {
		//포인터 변수만 선언하면 메모리 할당은 안 돼있나?
		gifts[data] = new Node(data, head);
		size++;
	}
	void addBack(int data) {
		gifts[data] = new Node(data, tail->prev);
		size++;
	}
	int delFront() {
		if (head->next == tail) return 0;
		head->next->delNode();
		
		size--;
		return 1;
	}
	int delBack() {
		if (head->next == tail) return 0;
		tail->prev->delNode();
		size--;
		return 1; //성공
	}
	Node* findNode(int data) { //선물 번호로 정보 얻기
		if (head->next == tail) return NULL;
		Node* now = head;
		while (now->next != tail) {
			if (now->next->data == data) return now->next;
			now = now->next;
		}
		return NULL;
	}
	Node* divGift(int n) { //n 번째 노드 출력
		if (head->next == tail) return NULL;
		Node* now = head->next;
		cnt = 1;
		while (cnt < n) {
			now = now->next;
			cnt++;
		}
		return now;
	}
	void show() {
		if (head->next == tail) {
			cout << "\nsize :" << size << '\n';
			return;
		}
		Node* now = head->next;
		while (now != tail) {
			printf("%d ", now->data);
			now = now->next;
		}
		
		cout << '\n';
		cout << "size :"<<size << '\n';
	}
}list[100001];

int n, m; //벨트개수, 선물개수 
void debug() {
	printf("------------\n");
	for (int i = 1; i <= m; i++) {
		printf("%d 번째 벨트 :",i);
		list[i].show();
	}
	printf("------------\n");
}
void factory() {
	for (int i = 1; i <= m; i++) {
		int input;
		cin >> input;
		list[input].addBack(i);
	}
}
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int command;
		cin >> command;
		if (command == 100) { //공장 설립
			cin >> n >> m;
			factory();
			//debug();
		}
		else if (command == 200) { //물건 모두 옮기기
			//상수시간 복잡도
			int src, dst; //src의 모든 선물 dst로 옮기기
			cin >> src >> dst;

			list[dst].head->next->prev = list[src].tail->prev;
			list[src].tail->prev->next = list[dst].head->next;
			list[dst].head->next = list[src].head->next; //head next 바꿔
			list[dst].head->next->prev = list[dst].head;

			//기존 리스트에서 떼주기
			list[src].head->next = list[src].tail;
			list[src].tail->prev = list[src].head;

			list[dst].size += list[src].size;
			list[src].size = 0;
			cout << list[dst].size << '\n';
			//debug();
		}
		else if (command == 300) { //src 벨트 앞 선물을 dst 앞 선물과 교체
			int src, dst;
			cin >> src >> dst;
			//상수시간 복잡도
			int s = list[src].head->next->data;
			int d = list[dst].head->next->data;

			list[src].delFront();
			list[dst].delFront();
			if (d != -1) {
				list[src].addFront(d);
			}
			if (s != -1) {
				list[dst].addFront(s);
			}
			//debug();
			cout << list[dst].size << '\n';
		}
		else if (command == 400) { //물건 나누기
			int src, dst;
			cin >> src >> dst;
			int target = list[src].size / 2;
			if (target == 0) {
				cout << list[dst].size << '\n';
				continue;
			}
			Node* node = list[src].divGift(target); // 최대 5만 x100회 ㄱㅊ
			Node* temp = node->next;

			//node를 dst head에 연결
			node->next = list[dst].head->next;
			list[dst].head->next->prev = node;

			//dst head를 src head가 가리키는 곳으로 변경
			list[dst].head->next = list[src].head->next;
			list[dst].head->next->prev = list[dst].head;

			//src node 이후를 head 랑 연결
			temp->prev = list[src].head;
			list[src].head->next = temp;

			list[dst].size += cnt;
			list[src].size -= cnt;
			cnt = 0;
			//debug();
			cout << list[dst].size << '\n';
			
		}
		else if (command == 500) { //선물 정보 얻기
			int p;
			cin >> p;
			int a, b;
			Node* ret = gifts[p]; 
			if (ret->prev == list[i].head) {
				a = -1;
			}
			else {
				a = ret->prev->data;
			}

			if (ret->next == list[i].tail) {
				b = -1;
			}
			else {
				b = ret->next->data;
			}
			cout << a + 2 * b << '\n';
		}
		else if (command == 600) { //벨트 정보 얻기
			int belt;
			cin >> belt;
			int a, b;
			int c = list[belt].size;
			if (c == 0) {
				a = -1;
				b = -1;
			}
			else {
				a = list[belt].head->next->data;
				b = list[belt].tail->prev->data;
			}
			cout << a + 2 * b + 3 * c << '\n';
		}
	}

	return 0;
}