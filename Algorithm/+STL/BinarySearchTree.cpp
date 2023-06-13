#include <iostream>
using namespace std;

#define MAX_SIZE 1000
//Node 정의
struct Node{
    int key;
    Node* left;
    Node* right;
};
//memory pool
Node memory_pool[MAX_SIZE];
int current_index;

//newNode
Node* _newNode(int x){
    memory_pool[current_index].key=x;
    memory_pool[current_index].left=nullptr;
    memory_pool[current_index].right=nullptr;
    return &memory_pool[current_index++];
}

class BinarySearchTree{
    Node* root;
public:
    BinarySearchTree()=default;
    void init(){
        root=nullptr;
        current_index=0;
    }
    void insert(int x){
        root=_insert(root,x);
    }
    void remove(int x){
        root=_remove(root,x);
    }
    bool find(int x){
        Node* now=root;
        while(now!=nullptr){
            if(now->key==x) return true;
            now = now->key > x ? now->left : now->right;
        }
        return false;
    }
    void travel(int type){
        //type 0: pre-order(전위순회) -> root -> left -> right
        //type 1: in-order(중위순회) -> left -> root -> right
        //type 2: post-order(후위순회) -> left -> right -> root
        char* arr[3] ={"pre","in","post"};
        cout<<arr[type]<<"-order\n";
        _travel(root,type);
        cout<<'\n';
        
    }
private:
    //now 를 루트로 가지는 서브트리
    Node* _insert(Node* now, int x){
        if(now==nullptr) return _newNode(x);
        //작으면 왼족, 크면 오른쪽
        if(now->key>x){
            now->left=_insert(now->left,x);
        }
        if(now->key<x){
            now->right=_insert(now->right,x);
        }
        //Binary Serach Tree는 원소의 중복을 허용 안 하므로 같은경우는 그냥 return
        return now;
    }
    //root가 now인 서브트리에서 key값이 x인 노드를 삭제하고 그 서브트리의 root를 리턴
    Node* _remove(Node* now, int x){
        if(now==nullptr) return now;

        if(x<now->key){
            now->left=_remove(now->left,x);
        }
        if(x>now->key){
            now->right=_remove(now->right,x);
        }
        if(x==now->key){
            //왼쪽이 비었으면 오른쪽 리턴
            if(now->left==nullptr) return now->right;
            //오른쪽이 비었으면 왼쪽 리턴
            if(now->right==nullptr) return now->left;
            //둘다 안 비어 있으면, 오른쪽에서 최솟값 또는 왼쪽에서 최대값이 와야함
            int min_key=find_min_key(now->right);
            now->key=min_key;
            now->right=_remove(now->right, min_key);
        }
        return now;
    }
    int find_min_key(Node* now){
        //now에서 가장 최소 key 찾기
        Node* temp=now->left;
        while(temp->left!=nullptr){
            temp=temp->left;
        }
        return temp->key;
    }
    void _travel(Node* now, int type){
        if(now==nullptr) return;

        //전위 순회
        if(type==0) cout<<now->key<<' ';
        _travel(now->left,type);
        //중위 순회
        if(type==1) cout<<now->key<<' ';
        _travel(now->right,type);
        //후위 순회
        if(type==2) cout<<now->key<<' ';
    }
};


int main(){


    return 0;
}

//Tree 란?
//모든 정점이 연결되어 있으며, 사이클이 없는 그래프

//Binary Search Tree 란?
//모든 각 정점의 간선이 최대 2개이며,
//왼쪽 서브트리는 자기보다 작은 값을, 오른쪽은 큰 값을 저장하는 트리이다.

//문제점
//0,1,2,3,4,5,6... 을 순서대로 삽입하면 마치 연결리스트처럼 된다
//삽입시에 시간복잡도는 O(N)이 된다.

//높이가 H인 트리에 노드를 꽉채워 넣으면 크기가 (2^(H+1) -1)/2-1 = 2^(H+1) -1 이 된다
//즉, N <= 2^(H+1) -1 이므로
//H >= log2_(N+1) -1 >= log2_N 이다.
//이렇게 높이가 O(logN)인 트리를 height_balaced 하다고 한다.
//이런 트리에서는 삽입/삭제/탐색이 모두 O(logN)이 보장되며,
//삽입/삭제 시마다 높이를 balanced하게 조절하는 BST를 Self-Balanced Binary Search Tree라고한다
//예시로는 Red-Black Tree, Splay Tree, B-Tree 등이 있다.

