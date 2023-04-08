#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int q, n, m; // 쿼리 10만, 선물 10만, 벨트 10

struct Node {
    int ID;
    int W;
    Node* prev;
    Node* next;

    Node() {
        prev = NULL;
        next = NULL;
        ID = -1;
        W = -1;
    }
    Node(int id, int w, Node* p) {
        //p 노드 뒤에 연결해라
        ID = id;
        W = w;
        //현재꺼 연결하고
        next = p->next;
        prev = p;

        //앞뒤에들 이걸로 연결시키고
        p->next->prev = this;
        p->next = this;
    }
    void delNode() {
        prev->next = prev;
        next->prev = prev;
        delete this;
    }
    
};
//hash map 배열로 각각 벨트별로 저장
unordered_map<int, Node*>um;
class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    Node* addFront(int id, int w) {
        return new Node(id, w, head);
    }
    Node* addBack(int id, int w) {
        return new Node(id, w, tail->prev);
    }
    void delFront() {
        if (head->next == tail) return;
        head->next->delNode();
    }
    void delBack() {
        if (head->next == tail) return;
        tail->prev->delNode();
    }
    void show() {
        Node* now = head;

        while (now->next != tail) {
            cout << "ID:" << now->next->ID << " W:" << now->next->W << '\n';
            now = now->next;
        }
        cout << '\n';
    }
}dll[11];

//공장 설립
void factory() {
    cin >> n >> m;
    vector<int>id;
    for (int i = 0; i < n; i++) {
        int inputID;
        cin >> inputID;
        id.push_back(inputID);
    }
    for (int i = 0; i < n; i++) {
        int ww;
        cin >> ww;
        Node* now = dll[i / (n / m) + 1].addBack(id[i], ww);
        um.insert({ id[i],now });
    }
}
//물건 하차
void getBox() {
    int w_max;
    cin >> w_max;
    int res = 0;
    for (int i = 1; i <= m; i++) {
        if (dll[i].head->next == dll[i].tail) continue;
        int id=dll[i].head->next->ID;
        int w = dll[i].head->next->W;
        dll[i].delFront();

        if (w<= w_max) {
            res +=w;
            um.erase(id);
        }
        else {
            dll[i].addBack(id, w);
        }
    }
    cout << res << '\n';
}
//물건 제거
void delBox() {
    int r_id;
    cin >> r_id;
    if (um.find(r_id) != um.end()) {
        um[r_id]->delNode();
        um.erase(r_id);
        cout << r_id << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}
//물건 확인

//벨트 고장

//debug()
void debug() {
    for (int i = 1; i <= m; i++) {
        cout << i << " 번 벨트\n";
        dll[i].show();
    }
}
int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int command;
        cin >> command;
        if (command == 100) {
            factory();
          //  debug();
        }
        else if (command == 200) {
            getBox();
        }
        else if (command == 300) {
            delBox();
        }
        else if (command == 400) {

        }
        else if (command == 500) {

        }
    }

    return 0;
}