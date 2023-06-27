#include <iostream>
using namespace std;

#define MEMSIZE 10000

//Node
struct Node {
	int data;
	Node* prev;
	Node* next;
};
//memory pool
Node memory_pool[MEMSIZE];
int current_index = 0;

//메모리 풀로 새로운 노드 생성
Node* _newNode(int data) {
	memory_pool[current_index].data = data;
	memory_pool[current_index].next = nullptr;
	memory_pool[current_index].prev = nullptr;
	return &memory_pool[current_index++];
}

//doubly LinkedList
class DoublyLinkedList {
public:
	Node head;
	Node tail;

	DoublyLinkedList() = default;

	void init() {
		head.next = &tail;
		tail.prev = &head;
		current_index = 0;
	}
	void addNode(Node* target, int data) {
		//target 뒤에 node 삽입
		Node* newNode = _newNode(data);
		//new Node 를 앞뒤 노드와 연결
		newNode->next = target->next;
		newNode->prev = target;
		
		//앞뒤 노드를 new Node 로 연결
		target->next->prev = newNode;
		target->next = newNode;
	}
	void delNode(Node* target) {
		if (target == &head || target == &tail) return;

		//target을 삭제, target 연결 끊기
		target->next->prev = target->prev;
		target->prev->next = target->next;
		
	}
	Node* findOrder(int order) {
		//앞에서 부터 order 번째 위치에 data 삽입
		Node* now = &head;
		int cnt = 0;
		//now는 order 번째 node 바로 직전 노드
		while (cnt < order && now->next!=&tail) {
			cnt++;
			now = now->next;
		}
		return now;
	}
	void delInOrder(int order, int num) {
		//order 번째 노드부터 num 개수 숫자를 삭제
		Node* now = &head;
		int cnt = 0;
		//order 번째 찾기, now 는 삭제될 노드의 바로 직전 노드가 됨
		while (cnt<order && now->next != &tail) {
			now = now->next;
			cnt++;
		}
		//num 개수만큼 삭제
		for (int i = 0; i < num; i++) {
			delNode(now->next);
		}
	}
	void addBack(int data) {
		addNode(tail.prev, data);
	}
	void printTen() {
		Node* now = &head;
		for (int i = 0; i < 10; i++) {
			if (now->next == &tail) break;
			now = now->next;
			cout << now->data << ' ';
		}
		cout << '\n';
	}
}dll;

//inputs
int len, cmdCnt;

//datas input
void inputDatas() {
	int x, y;
	cin >> x >> y;
	Node* now = dll.findOrder(x);
	for (int i = 0; i < y; i++) {
		int s;
		cin >> s;
		dll.addNode(now, s);
		now = now->next;
	}
}
void addDatasToTail() {
	//data들을 맨뒤에 추가
	int y;
	cin >> y;
	
	for (int i = 0; i < y; i++) {
		int s;
		cin >> s;
		dll.addBack(s);
	}
}
void delDatas() {
	int x, y;
	cin >> x >> y;
	dll.delInOrder(x, y); // order, 갯수
}
int main() {
	for (int t = 1; t <= 10; t++) {
		dll.init();
		cin >> len;
		for (int i = 0; i < len; i++) {
			int data;
			cin >> data;
			dll.addBack(data);
		}
		//dll.printTen();
		cin >> cmdCnt;
		for (int i = 0; i < cmdCnt; i++) {
			char cmd;
			cin >> cmd;
			if (cmd == 'I') { //x 번째부터 y개 삽입
				inputDatas();
			}
			else if (cmd == 'A') { // 맨 뒤에 y개의 숫자 추가
				addDatasToTail();

			}
			else { // x번째 부터 y개 숫자 삭제
				delDatas();
			}
		}

		//출력
		cout<<'#'<<t<<' ';
		dll.printTen();
	}
	return 0;
}