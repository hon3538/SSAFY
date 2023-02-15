// Union Find ->Disjoint Set(분리 집합) 이라고 하기도 함
// : 결합을 찾는다 -> 소속/그룹을 만들고 유지/관리하는 알고리즘
// Union-> 서로 두 개의 다른 집합을 결합하는 작업
// Find -> 특정 소속에 속한 멤버가 "어떤 소속에 포함되어 있는가?" 를 찾아가고, 판단하는 작업
// 즉, 소속을 찾아가는 작업

//재귀로 구성
//찾을 요소의 부모->부모->최종부모 이런식으로 구성하여 최종 소속을 찾는다


#include <iostream>

using namespace std;
/* A의 부모는 B다
18 15
3 0
6 3
9 6
10 6
11 6
4 1
7 4
12 7
13 7
14 7
5 2
8 5
15 8
16 8
17 8
*/
//Find: 소속을 찾아가는 알고리즘
//#1 정보(부모정보)를 저장할 parent가 필요

int parent[20];
int N,M;
int Find(int now){
    //종료 조건
    //now의 부모가 나랑 같다면 -> 소속을 찾았다!
    //parent의 default를 0으로 초기화 해줬기 때문에
    //최종 부모가 0이 아니여도 0으로 나온다.
    //따라서 초기화를 항상 index==value 같은 값으로 초기화 해준다.
    if(now==parent[now]){
        return now;
    }

    //재귀 구성
    //내가 대장이 아니면 내 부모를 찾아가라
    return Find(parent[now]);

}
int main(){
    cin>>N>>M;
    for(int i=0;i<20;i++){
        parent[i]=i;
    }
    for(int i=0;i<M;i++){
        int A,B;
        cin>>A>>B;
        //A의 부모는 B다
        parent[A]=B;
    }
    int input;
    cin>>input;
    cout<<Find(input);
    
    return 0;
}