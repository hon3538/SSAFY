//쿼리 10만개
//벨트 10만개
//선물 10만개

#include <iostream>
#include <vector>
using namespace std;
int q;
int n, m; //벨트 개수(1~), 선물 개수(1~)
struct Node {
    int present;
    Node* prev;
    Node* next;
};

Node* head[100001] = { NULL }; //각 linkedlist
Node* tail[100001] = { NULL }; //각 linkedlist
class LinkedList {
public:
    void addFront(int s, int data) { //index를 받아서 사용하기..
        Node* newNode = new Node;
        newNode->present = data;
        newNode->prev = NULL;
        if (head[s] == NULL) {
            head[s] = newNode;
            head[s]->next = NULL;
            tail[s] = newNode;
            return;
        }
        newNode->next = head[s]->next;
        head[s] = newNode;
    }
    void addBack(Node* head, Node* tail, int data) {
        Node* newNode = new Node();
        newNode->present = data;
        newNode->next = NULL;
  
        if (tail == NULL) {
            tail = newNode;
            tail->prev = NULL;
            head = newNode;
            return;
        }
        newNode->prev = tail->prev;
        tail = newNode;
    }
    void delNode(Node* head, Node* tail, int data) {
        Node* prev;
        Node* delNode;
        if (head == NULL) return;
        if (head->next == NULL) {
            free(head->next);
            head = NULL;
            return;
        }
        prev = head;
        delNode = head->next;
        while (delNode->next == NULL) {
            prev = delNode;
            delNode = delNode->next;
        }
        free(delNode);
        prev->next = NULL;
    }
    Node* searchNode(Node* head, Node* tail, int order) { //order번째
        Node* target;
        target = head;
        int num = 1;
        while (num < order) {
            target = target->next;
            num++;
        }
        return target;
    }
};
LinkedList list;

int listSize[100001];
void factory() { //공장 설립
    for (int i = 1; i <= m; i++) {
        int s;
        cin >> s;
        
        list.addFront(s, i);

        printf("%d ", head[s]->present);
        listSize[s]++;
    }
    for (int i = 1; i <= n; i++) {
        Node* now = head[i];
        printf("%d", i);
        if (now == NULL) continue;
        printf("%d", i);
        while (now != NULL) {
            cout << now->present << ' ';
            now = now->next;

        }
        cout << '\n';
    }
}
int main() {
    cin >> q;
    for (int i = 0; i < q; i++) {  //쿼리
        int command;
        cin >> command;
        if (command == 100) { //공장설립
            cin >> n >> m;
            factory();
        }
        else if (command == 200) {//물건 모두 옮기기
            //a벨트의 모든 선물을 b벨트 앞으로 옮기고 b벨트 선물 개수 출력

        }
        else if (command == 300) {//앞 물건만 교체하기
            //a벨트 앞 선물과 b벨트 앞 선물 교체, 없으면 옮기기만,
            //b벨트 선물 개수 출력

        }
        else if (command == 400) {//물건 나누기
            //a벨트 선물 개수=n 일때, n/2  번째까지의 모든 선물을 b벨트 앞으로 옮김
            //b벨트의 선물 개수 출력

        }
        else if (command == 500) {//선물 정보 얻기
            //선물 번호가 주어질 때 앞번호와 뒷번호를 구해라

        }
        else if (command == 600) {//벨트 정보 얻기
            //벨트 번호가 주어질때 맨앞 선물과 맨뒤 선물을 구해라
        }

    }

    return 0;
}