//힙 중간값 삭제 후 heapify 돌리는 기능 구현
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 100055
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node memory_pool[SIZE];
int current_index;
Node* _newNode(int data) {
    memory_pool[current_index].data = data;
    memory_pool[current_index].left = NULL;
    memory_pool[current_index].right = NULL;
    return &memory_pool[current_index++];
}


class MaxHeap {
    Node* tree[SIZE];
    int size;
public:
    MaxHeap() = default;
    void init() {
        size = 0;
    }
    void push(int data) {
        tree[++size] = _newNode(data);
        int child = size;
        int parrent = size >> 1;
        //부모랑 비교
        while (parrent > 0 && tree[child]->data > tree[parrent]->data) {
            swap(tree[child], tree[parrent]);
            child = parrent;
            parrent = child >> 1;
        }
    }
    void pop() {
        if (size == 0) return;
        int parrent = 1;
        tree[parrent] = tree[size--];
        int child = parrent << 1;
        while (child <= size) {
            int left = parrent * 2;
            int right = parrent * 2 + 1;
            //오른쪽이 없으면 왼쪾과만 비교
            if (right > size || tree[right]->data < tree[left]->data) {
                if (tree[left]->data > tree[parrent]->data) {
                    swap(tree[parrent], tree[left]);
                    parrent = left;
                }
                else break;
            }
            else {
                //오른쪾과 왼쪾 비교
                if (tree[parrent]->data < tree[right]->data) {
                    swap(tree[parrent], tree[right]);
                    parrent = right;
                }
                else break;
            }
            child = left;
        }
    }
    int top() {
        if (size == 0) return -1;
        return tree[1]->data;
    }
}mh;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        mh.init();
        int n;
        cin >> n;
        cout << '#' << t << ' ';
        for (int i = 0; i < n; i++) {
            int cmd;
            cin >> cmd;
            if (cmd == 1) {
                int x;
                cin >> x;
                mh.push(x);
            }
            else {
                cout << mh.top() << ' ';
                mh.pop();
            }
        }
        cout << '\n';
    }

    return 0;
}