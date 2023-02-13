#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Student
{
    string name;
    int n;
    int score;
    bool operator <(Student right) const { // 이처럼 구조체 내에 operator를 선언해도 된다.
        if(score>right.score)return true;
        if(score<right.score)return false;
        if(n>right.n)return true;
        if(n<right.n) return false;
        if(name>right.name) return true;
        else return false;
    }
};

struct ssafycmp{ //아니면 이렇게 빼서 할 수도 있음
    bool operator()(Student left, Student right){
        if(left.score>right.score)return true;
        if(left.score<right.score)return false;
        if(left.n>right.n)return true;
        if(left.n<right.n) return false;
        if(left.name>right.name) return true;
        else return false;
    }
};
//sort
//sort(first,last,cmp) default cmp : <
//-> 작은 것부터 앞으로 가는 오름 차순 정렬 left<right 작은거 우선 정렬
//pq
//priority_queue<type, container, cmp> default cmp: <
//->큰거부터 나오는 MAX heap, left<right 큰 것부터 우선순위 정렬
//즉 sort 와 pq는 반대임
struct cmp
{
    //PQ : < => MAX Heap
    //sort때와 동일한 생각으로 기준고 싶다면 아래처럼 생각하기
    //올바른 상황(즉, 내가 원하는 상황일때)-> return false;
    bool operator()(int left, int right)
    {
        // return left>right;
        if (left > right)
            return true;
        if (left < right)
            return false;
        return false;
    }
};
int main()
{
    int arr[] = {1, 4, 5, 3, 2};

    // #1 default : MAX heap : (int에서) 가장 큰 값이 우선순위를 갖는다.
    priority_queue<int, vector<int>, cmp> pq;
    // 삽입 : push()
    // 삭제 : pop()
    // 맨위 :(우선순위가 가장 높은 값) return :q.top()
    // 비어있는가? : empty()

    for (int i = 0; i < 5; i++)
    {
        pq.push(arr[i]); // 넣을 때 heapify 동작
    }

    // 출력
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop(); // 추출할 때도 heapify 동작
    }

    // #2 MIN heap
    //  priority_queue<typename,container,less>
    //  typename : 자료형
    //  container : vector
    //_Pr : less => <
    //  less : sort처럼 Compare cmp가 아니고 '함수 구조체'이다
    // 함수로 넣어주면 안 되고, 구조체 함수를 만들어서 넣어야 한다.
    //  priority_queue<int, vector<int>,less<int>>


    // #3 사용자 정의 heap
    priority_queue<Student,vector<Student>,ssafycmp>pqq;
    // priority_queue<Student>
    pqq.push({ "홍의선",12,90 });
    pqq.push({ "류병민",10,96 });
    pqq.push({ "임꺽정",15,436});
    pqq.push({ "김건희",26,36 });
    pqq.push({ "윤석열",20,43 });
    while(!pqq.empty()){
        cout<<pqq.top().name<<" "<<pqq.top().score<<'\n';
    }

    // sort 와 priority queue 언제 쓰는가
    // sort : O(NlogN)
    // PQ : 삽입과 추출 O(logN)

    //예시1) N개의 정수를 입력 받고 가장 큰 수를 출력하라
    // sort : 입력받고 -> 정렬 -> arr[N-1]==O(NlonN)
    //PQ : 입력받으면서 PQ 삽입(logN) -> heapify -> pq.top() // peek

    //예시2) N개의 Query
    //1 -> 삽입
    //2 -> 현재 가장 큰 값 삭제
    //0 -> 현재 가장 큰 값 출력
    //sort : Q * O(NlogN)
    //PQ : 삽입 O(logN) , 현재 가장 큰 값 삭제 O(logN), 가장 큰 값 출력 O(1)

    //sort는 딱 한번의 정렬로 해결이 가능할 때
    //PQ는 계속해서 새로운 값이 삽입, 추출될 때 -> 변화가 있을 때

    
}