// 왜 정렬과 PQ는 left, right 가 반대인가?
// sort는 left right 비교
// PQ는 부모노드와 자식노드 비교하므로
// left(parent) <right(child) 이면 return true; 를 해주면 내림차순 정렬 된다.
//heapify가 알아서 부모를 위로 올림..?

#include <iostream>
#include <queue>
using namespace std;

struct NODE{
    int y,x;
};
//#3 priority_queue<NODE,vector<NODE>,cmp>pq;
struct cmp { //따로 만들어줌
    bool operator()(NODE a,NODE b){
        if(a.y<b.y) return false;
        if(a.y>b.y) return true;
        if(a.x<b.x) return false;
        if(a.x>b.x) return true;
        return false;
    }
};
//#2 priority_queue<NODE2>pq;
struct NODE2{
    int y,x;
    
    //struct 내부 안의 노드와 다음 노드를 비교함
    //const 는 내 자신의 (y,x)가 정렬을 하거나 pq에 들어갔을 때,
    // 중간에 값이 바뀌면 큰일 나므로 값을 고정시킨다.
    bool operator<(NODE next)const{
        if(y<next.y) return false;
        if(y>next.y) return true;
        if(x<next.x) return false;
        if(x>next.x) return true;
        return false;
    }
};
// #3 priority_queue<NODE>pq; 권장하지 않음
bool operator < (NODE a,NODE b) { //따로 만들어줌
        if(a.y<b.y) return true;
        if(a.y>b.y) return false;
        if(a.x<b.x) return true;
        if(a.x>b.x) return false;
        return false;
}

int main(){
    // #1 정상적인 방법 

    //#2 구조체 자체에 < operator의 기준을 잡아주는 방법

    //#3 < 연산자 자체를 overriding ->권장하지 않음
    // < 자체를  overriding하는데 만약에 내가 특정 구조체를 다른 우선순위로 N개를 관리해야한다면?
    priority_queue<NODE>pq;
    pq.push({1,2});
    pq.push({500,500,});
    pq.push({100,100});
    while(!pq.empty()){
        cout<<pq.top().y<<" "<<pq.top().x<<'\n';
        pq.pop();
    }

}