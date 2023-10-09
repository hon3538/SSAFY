//inserChar
//커서가 있는 쪽에 삽입
//(300(해당 행의 커서위치탐색)+300(한칸씩밀림))*30000 = 1800만 180ms

//moveCursor
//좌표로 커서 이동하고 해당 문자 리턴
//300(해당 행의 커서위치 탐색)*30000=900만

//countChar
//커서 뒤의 특정 문자 개수 출력
//list 별로 알파벳 개수 저장,
//최대 300 행탐색 *40000 = 1200만 

//DLL 삽가능
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>
using namespace std;
#define CMD_INIT       100
#define CMD_INSERT     200
#define CMD_MOVECURSOR 300
#define CMD_COUNT      400

extern void init(int H, int W, char initStr[]);
extern void insertChar(char ch);
extern char moveCursor(int mr, int mc);
extern int countChar(char ch);
int Height;
int Width;
int cur; //현재 커서위치
int len; //현재 문자열 사이즈

struct Node {
    char ch;
    Node* next;
    Node* prev;
    Node() {
        ch = 0;
        next = NULL;
        prev = NULL;
    }
    void addNode(char c, Node* target) { //target 뒤에 추가됨
        ch = c;
        next = target->next;
        prev = target;
        target->next = target->next->prev = this;
    }
    void delNode() {
        next->prev = prev;
        prev->next = next;
        delete this;
    }
};
class DoublyLinkedList {
public:
    int size; //해당 행의 문자개수
    int arr[26]; //해당 행에서 각 알파벳의 개수
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        size = 0;
        memset(arr, 0, sizeof(arr));
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    void addFront(char c) {
        Node* newNode = new Node();
        newNode->addNode(c, head);
        size++;
        arr[c - 'a']++;
    }
    void addBack(char c) {
        Node* newNode = new Node();
        newNode->addNode(c, tail->prev);
        size++;
        arr[c - 'a']++;
    }
    void addWhere(char c, int n) { //n : x좌표에 삽입
        int i = 0;
        Node* now = head;
        while (i < n) {
            now = now->next;
            i++;
        }
        Node* newNode = new Node();
        newNode->addNode(c, now);
        size++;
        arr[c - 'a']++;
    }
    char getWhere(int n) { //n : x좌표에 있는 값(0~)
        int i = 0;
        Node* now = head->next;
        while (i < n) {
            now = now->next;
            i++;
        }
        return now->ch;
    }
    int fromCount(char c, int n) { //n : 현재 x좌표뒤부터 끝까지 특정 문자 count
        Node* now = head;
        int cnt = 0;
        int i = 0;
        while (now->next != tail) {
            if (i >= n) {
                if (now->next->ch == c) {
                    cnt++;
                }
            }
            i++;
            now = now->next;
        }
        return cnt;
    }
    char delBack() {
        if (head->next == tail) return 0;
        char c = tail->prev->ch;
        tail->prev->delNode();
        size--;
        arr[c - 'a']--;
        return c;
    }
    void debug(int n) {
        cout << n << "행 debug\n";
        Node* now = head;
        while (now->next != tail) {
            cout << now->next->ch << ' ';
            now = now->next;
        }
        cout << '\n';
    }
}dll[300];

void init(int H, int W, char initStr[]) {
    cur = 0;
    len = 0;
    for (int i = 0; i < 300;i++) {
        while (dll[i].size!=0) {
            dll[i].delBack();
        }
    }
    Height = H;
    Width = W;
    int t = 0;
    while (initStr[t] != '\0') {
        dll[t / W].addBack(initStr[t]);
        t++;
        len++;
    }
}
//한단계씩 tail을 다음 head로 옮기기
void update() {
    int row = cur / Width;

    while (dll[row].size > Width) {
        char c = dll[row].delBack();
        dll[row + 1].addFront(c);
        row++;
    }
}
void insertChar(char ch) {
    dll[cur / Width].addWhere(ch, cur % Width);
    update(); //insert했는데 width 넘기면 하나씩 밀어줘야함
    cur++;
    len++;
}
char moveCursor(int mr, int mc) {
    int y = mr - 1;
    int x = mc - 1;
    cur = y * Width + x;
    if (len == 0) {
        cur = 0;
        return '$';
    }
    if (cur >= len) {
        cur = len;
        return '$';
    }
    return dll[cur / Width].getWhere(cur % Width);
}
int countChar(char ch) {
    int sum = 0;
    int row = cur / Width;
    //현재 행에서는 직접 count
    sum += dll[row].fromCount(ch, cur % Width);
    //다음 행부터는 전체값 count
    while (row + 1 != Height && dll[++row].size != 0) {
        sum += dll[row].arr[ch - 'a'];
    }
    return sum;
}
void dd() {
    int i = 0;
    while (dll[i].size != 0) {
        dll[i].debug(i);
        i++;
    }
    cout << "cursor : " << cur << '\n';
    cout << '\n';
}
static bool run() {
    bool correct = false;
    int queryCnt;
    scanf("%d", &queryCnt);
    int H, W;
    char ch;
    static char initStr[90001];

    while (queryCnt--) {
        int cmd;
        scanf("%d", &cmd);

        if (cmd == CMD_INIT) {
            scanf("%d %d %s", &H, &W, initStr);
            init(H, W, initStr);
            correct = true;
        }
        else if (cmd == CMD_INSERT) {
            scanf(" %c", &ch);
            insertChar(ch);
        }
        else if (cmd == CMD_MOVECURSOR) {
            int mr, mc;
            scanf("%d %d", &mr, &mc);

            char ret = moveCursor(mr, mc);
            //cout << ret<<'\n';
            char ans;
            scanf(" %c", &ans);
            if (ret != ans) {
                correct = false;
            }
        }
        else if (cmd == CMD_COUNT) {
            scanf(" %c", &ch);

            int ret = countChar(ch);
           // cout << ret << '\n';
            int ans;
            scanf("%d", &ans);
            if (ret != ans)
            {
                correct = false;
            }
        }
        //dd();
    }
    return correct;
}

int main() {
    setbuf(stdout, NULL);
    //freopen("input.txt", "r", stdin);

    int T, SUCCESS;
    scanf("%d %d", &T, &SUCCESS);
    for (int tc = 1; tc <= T; tc++) {
    
        int score = run() ? SUCCESS : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
