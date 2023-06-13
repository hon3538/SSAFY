#include <iostream>
using namespace std;

#define MAX_SIZE 2001

//Node 
struct Node {
	int data;
	Node* prev;
	Node* next;
};
//memory pool
Node memory_pool[MAX_SIZE];
int current_index = 0;

//newNode
Node* _newNode(int data) {
	memory_pool[current_index].data = data;
	memory_pool[current_index].prev = nullptr;
	memory_pool[current_index].next = nullptr;
	return &memory_pool[current_index++];
}

//Doubly Linked List
class DoublyLinkedList {
	Node head;
	Node tail;
public:
	DoublyLinkedList() = default;
	void init() {
		head.next = &tail;
		tail.prev = &head;
		current_index = 0;
	}
	void addNode(Node* target, int data) {
		//target 뒤에 노드 삽입
		Node* newNode = _newNode(data);
		//new Node를 양옆 노드와 연결
		newNode->next = target->next;
		newNode->prev = target;
		//기존 연결 끊기
		target->next->prev = newNode;
		target->next = newNode;
	}
	void delNode(Node* target) {
		//target 노드 삭제
		target->prev->next = target->next;
		target->next->prev = target->prev;
	}
	void changeNode(Node* target, int data) {
		//target 노드의 data를 변경
		target->data = data;
	}
	void addBack(int data) {
		//맨 뒤에 Node 추가
		addNode(tail.prev, data);
	}
	Node* findNode(int index) {
		//index 로 노드 찾기
		Node* now = &head;
		int cnt = 0;
		while (cnt <= index) {
			//index를 가진 Node 가 없으면 null return
			if (now->next == &tail) return nullptr;
			now = now->next;
			cnt++;
		}
		return now;
	}
	
	void printAll() {
		Node* now = &head;
		while (now->next != &tail) {
			now = now->next;
			cout << now->data << ' ';
		}
		cout << '\n';
	}
};