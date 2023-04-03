#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
Node* head=NULL;

class Single_list {
public:
    //list의 마지막에 추가
 
    void addNode(int data) {
        Node* newNode = new Node;
        Node* lastNode; //원래 있던 노드의 마지막 노드
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) { //리스트가 비어있을 경우
            head = newNode;
            // printf("%d\n",head->data);
            return;
        }
        //head는 index 0을 가리키는 역할
        lastNode = head;
        //하나씩 탐색하면서 마지막 노드를 찾는다 -> 완전탐색 개손해
        while (lastNode->next != NULL) { lastNode = lastNode->next; }

        lastNode->next = newNode;
    }
    //list의 가장 마지막 노드 삭제
    void delNode() {
        Node* prevNode;
        Node* delNode;
        if (head == NULL) return;
        if (head->next == NULL) {
            free(head->next);
            head == NULL;
            return;
        }
        prevNode = head;
        delNode = head->next;
        while (delNode->next != NULL) {
            prevNode = delNode;
            delNode = delNode->next;
        }
        free(delNode); //마지막 노드의 메모리 공간을 반환
        prevNode->next = NULL;
    }
    void allSearch() {
        Node* now;
        now = head;
        while (now!= NULL) {
            printf("%d\n", now->data);
            now = now->next;
        }
    }
};

int main() {
    Single_list sl;
    head = NULL;
    sl.addNode(3);
    sl.addNode(5);
    sl.delNode();
    sl.addNode(6);
    sl.allSearch();
    return 0;
}