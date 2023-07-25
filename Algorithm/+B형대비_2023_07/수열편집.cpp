#include <iostream>
using namespace std;

#define SIZE 2010

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node memory_pool[SIZE];
int current_index;

Node* _newNode(int data) {
    memory_pool[current_index].data = data;
    memory_pool[current_index].prev = NULL;
    memory_pool[current_index].next = NULL;
    return &memory_pool[current_index++];
}

class DoublyLinkedList {
private:
    Node head;
    Node tail;
    int size;
    void _insert(Node* target, int data) {
        //target 앞에 추가
        Node* now = _newNode(data);
        now->next = target;
        now->prev = target->prev;

        target->prev->next = now;
        target->prev = now;
    }
    void _delete(Node* target) {
        //target 삭제
        target->next->prev = target->prev;
        target->prev->next = target->next;
    }
public:
    DoublyLinkedList() = default;
    void init() {
        head.next = &tail;
        tail.prev = &head;
        current_index = 0;
        size = 0;
    }
    void pushback(int data) {
        _insert(&tail, data);
        size++;
    }
    void insNode(Node* target, int data) {
        //target 앞에 추가
        _insert(target, data);
        size++;
    }
    void delNode(Node* target) {
        _delete(target);
        size--;
    }
    void change(Node* target, int data) {
        target->data = data;
    }
    Node* findNode(int x) {
        //x 번 index 노드 찾기
        Node* now = &head;
        for (int i = 0; i <= x; i++) {
            now = now->next;
        }
        return now;
    }
    int getSize() {
        return size;
    }
}dll;
void insertFunc() {
    int index;
    int data;
    cin >> index >> data;
    Node* target = dll.findNode(index);
    dll.insNode(target, data);
}
void deleteFunc() {
    int index;
    cin >> index;
    Node* target = dll.findNode(index);
    dll.delNode(target);
}
void changeFunc() {
    int index;
    int data;
    cin >> index >> data;
    Node* target = dll.findNode(index);
    dll.change(target, data);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        dll.init();
        int N, M, L; //수열 길이, 명령어 횟수, 출력 인덱스 번호
        cin >> N >> M >> L;
        for (int i = 0; i < N; i++) {
            int n;
            cin >> n;
            dll.pushback(n);
        }
        for (int i = 0; i < M; i++) {
            char c;
            cin >> c;
            if (c == 'I') insertFunc();
            else if (c == 'D')deleteFunc();
            else changeFunc();
        }
        cout << '#' << t << ' ';
        if (dll.getSize() <= L) cout << -1 << '\n';
        else {
            cout << dll.findNode(L)->data << '\n';
        }
    }
    return 0;
}