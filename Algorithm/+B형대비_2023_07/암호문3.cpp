#include <iostream>
using namespace std;

#define SIZE 1000000

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node memory_pool[SIZE];
int current_index;

Node* _newNode(int data) {
    memory_pool[current_index].data = data;
    memory_pool[current_index].next = NULL;
    memory_pool[current_index].prev = NULL;
    return &memory_pool[current_index++];
}

class DoublyLinkedList {
private:
    Node head;
    Node tail;

    void _insert(Node* target, int data) {
        //target 뒤에 삽입
        Node* now = _newNode(data);
        now->prev = target;
        now->next = target->next;

        target->next->prev = now;
        target->next = now;
    }
    void _delete(Node* target) {
        //target 뒤 노드 삭제
        if (target->next == &tail) return;
        target->next = target->next->next;
        target->next->prev = target;
    }
public:
    DoublyLinkedList() = default;
    void init() {
        head.next = &tail;
        tail.prev = &head;
    }
    void pushBack(int data) {
        _insert(tail.prev, data);
    }
    void insNode(Node* target, int data) {
        _insert(target, data);
    }
    void delNode(Node* target) {
        _delete(target);
    }
    Node* findNode(int x) {
        //앞에서 부터 x번쨰 암호문 출력
        Node* now = &head;
        int cnt = 0;
        while (now->next != &tail) {
            if (cnt == x) break;
            now = now->next;
            cnt++;
        }
        return now;
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
void init() {
    current_index = 0;
    dll.init();
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        dll.pushBack(data);
    }
}
void insert() {
    //x번쨰 암호문 다음에 y개의 암호문 삽입
    int x, y;
    cin >> x >> y;
    Node* target = dll.findNode(x);
    for (int i = 0; i < y; i++) {
        int s;
        cin >> s;
        dll.insNode(target, s);
        target = target->next;
    }
}
void del() {
    //x번째 암호문 바로 뒤부터 y개 암호문 삭제
    int x, y;
    cin >> x >> y;
    Node* target = dll.findNode(x);
    for (int i = 0; i < y; i++) {
        dll.delNode(target);
    }
}
void pushback() {
    //맨뒤에 y개의 암호문 삽입
    int y;
    cin >> y;
    for (int i = 0; i < y; i++) {
        int s;
        cin >> s;
        dll.pushBack(s);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int t = 1; t <= 10; t++) {
        init();
        //dll.printTen();
        //qeury
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char cmd;
            cin >> cmd;
            if (cmd == 'I') {//삽입
                insert();
               // dll.printTen();
            }
            else if (cmd == 'D') { //삭제
                del();
                //dll.printTen();
            }
            else { //추가
                pushback();
                //dll.printTen();
            }
        }
        cout << '#' << t << ' ';
        dll.printTen();
    }
    return 0;
}