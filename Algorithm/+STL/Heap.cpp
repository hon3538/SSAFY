<<<<<<< HEAD
//최대 힙 조건
//1. 모든 부모 노드는 자식노드보다 값이 같거나 크다
//2. 완전 이진 트리

//특징
//가장 큰 값을 찾는데 O(1) 이다
//삽입 : O(logN)
//삭제 : O(logN)
=======
#include <iostream>
#include <algorithm>
// #include <vector>
using namespace std;

#define MAX 100001

class MaxHeap {
    int data[MAX];
    int size;
public:
    MaxHeap() = default;

    void init() {
        size = 0;
    }

    void push(int n) {
        //맨끝에 추가
        data[++size] = n;
        //부모랑 비교
        int child = size;
        int parrent = child >> 1;
        while (parrent > 0 && data[parrent] < data[child]) {
            //root가 아니고, 부모보다 값이 클때 swap
            swap(data[parrent], data[child]);

            child = parrent;
            parrent = child >> 1;
        }
    }

    int top() {
        return data[1];
    }
    int getSize() {
        return size;
    }
    void pop() {
        if (size == 0) return;
        //맨위루트와 마지막 노드 swap 하고 마지막 노드 삭제
        data[1] = data[size--];
 
        //root 노드를 자식과 비교해가며 swap
        int node = 1;
        while (node <= (size >> 1)) { // 마지막 부모
            int left = (node <<1);
            int right = (node <<1) + 1;

            //right가 없으면 left와만 비교
            if (right > size ||data[left]>data[right]) {
                if (data[left] > data[node]) {
                    swap(data[left], data[node]);
                    node = left;
                }
                else break;
            }
            else { //right 있으면 left와 right 우선 비교,
                if (data[right] > data[node]) {
                    swap(data[right], data[node]);
                    node = right;
                }
                else break;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MaxHeap mh = MaxHeap();
    int T;
    cin >> T;
    int ans[100000];
    int ans_size = 0;
    for (int t = 1; t <= T; t++) {
        mh.init();
        ans_size = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int cmd;
            cin >> cmd;
            if (cmd == 1) { //data x 삽입
                int x;
                cin >> x;
               mh.push(x);
            }
            else if (cmd == 2) {
                if (mh.getSize() == 0) ans[ans_size++] = -1;
                else ans[ans_size++] = mh.top();
                mh.pop();
            }
        }
        cout << '#' << t << ' ';
        for (int i = 0; i < ans_size; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
>>>>>>> aaed46ee0e60770702fafe9e5f41c587c398f5a6
