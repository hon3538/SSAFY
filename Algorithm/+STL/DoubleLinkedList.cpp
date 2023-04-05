#include <iostream>
using namespace std;
struct Node{
    Node* prev;
    Node* next;
    int data;

    Node(){
        prev=next=NULL;
        data=0;
    }
    Node(int i, Node* n){//n뒤에 추가
        data=i;
        prev=n;
        next=n->next;
        next->prev=this;
        prev->next=this;
    }
    void delNode(){
        prev->next=next;
        next->prev=prev;
        delete this;
    }
};
class LinkedList{
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList(){
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(int data){
        Node* newNode=new Node(data,head);        
    }
    void addBack(int data){
        Node* newNode=new Node(data,tail->prev);
    }
    void frontDelete(){
        if(head->next==tail) return;
        head->next->delNode();
    }
    void endDelete(){
        if(head->next==tail) return;
        tail->prev->delNode();
    }
    
    void printfAll(){
        if(head->next==tail) return;
        Node* now=head;
        while(now->next!=tail){
            printf("%d ",now->next->data);
            now=now->next;
        }
        cout<<'\n';
    }
}list;

int main(){
    list.addFront(1);
    list.addFront(2);
    list.addBack(5);
    list.printfAll();
    list.endDelete();
    list.frontDelete();
    list.printfAll();
    return 0;
}