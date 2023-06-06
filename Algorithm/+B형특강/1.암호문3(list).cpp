#include <iostream>
using namespace std;

#define MemorySize 10000

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class LinekedList {
public:
    Node head;
    Node tail;
    Node node_pool[MemorySize];
    int node_count;

    void init() {
        head.next = &tail;
        tail.prev = &head;
        node_count = 0;
    }
    Node* newNode(Node* cur, int data) {
        node_pool[node_count].data = data;
        node_pool[node_count].prev = cur;
        node_pool[node_count].next = cur->next;

        cur->next->prev = &node_pool[node_count];
        cur->next = &node_pool[node_count];

        return &node_pool[node_count++];
    }
    void addNode(Node* cur, int data) {
        //cur node 의 바로 뒤에 삽입
        Node* now = newNode(cur, data);
    }
    void delNode(Node* cur) {
        //cur 삭제
        if (head.next == &tail) return;
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    }
    void delAtoB(int A, int B) {
        Node* now = &head;
        for (int i = 0; i < A; i++) {
            now = now->next;
        }
        for (int i = 0; i < B; i++) {
            delNode(now->next);
        }
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
int main() {
    LinekedList dl;
    dl.init();
    for (int i = 0; i < 10; i++) {
        dl.addNode(dl.tail.prev, i);
    }
    dl.delAtoB(0,3);
    dl.printAll();
    return 0;
}