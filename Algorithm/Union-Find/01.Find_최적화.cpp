//Find 의 시간 복잡도 최악의 경우
//O(N); 100개의 node 가있을경우 100->99->98->...->0 부모찾기까지 N 번
//근데 너무 노가다임.. 따라서 path Compression(경로 압축)을 통한 최적화 작업 필요
//한번에 100의 소속이 0이라는 것을 알게되면 얼마나 좋을까..?
//일단 처음엔 노가다를 한번 해야됨.. 그러고 최종 소속을 알게되었을 때
//부모를 최종소속으로 update 해주면 O(1)로 바로 찾아갈 수 있음
//정확히 경로 압축 후의 시간복잡도는 O(A(N)).. A:아커만..?애커먼?
//A은 엄청 작은 수를 의미 O(1)~O(logN)

//장점 : 시간의 효율성이 대폭 상승한다
//단점 : 돌이킬 수가 없음, 첫 상태는 따로 저장해놓으면 되지만,
//특정 시점에서의 상태를 알 수 없음

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

int parent[20];
int N,M;
int Find(int now){
    if(now==parent[now]){
        return now;
    }
    
    //최종 소속을 찾고 돌아왔을때 모든 노드를 최종 소속으로 update
    return parent[now]= Find(parent[now]);
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