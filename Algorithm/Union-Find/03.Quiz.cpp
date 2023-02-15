//#문제
//N개의 회사가 있다
// 회사들이 경제가 안 좋아서 망하면서 M개의 인수합병 과정이 필요
// A가 B를 인수할 때, A회사가 대표회사가 되고,
// B회사로부터 10명의 개발자들을 빼온다.
// M개의 인수합병 과정을 거친 후, 각 회사에 몇 명의 개발자가 남아있는지를 출력
//input
/*
6 5 //회사 개수, 인수합병 몇 번
10 20 30 40 50 60 -> 개발자 수
0 1
3 0
3 4
4 3
2 5

3과 4를 합병했는데
4와 3을 다시 합병하려함..
따라서 Union을 하기 전에 이미 결합된 소속(같은소속)을 다시 결합하면 문제가 생길 수 있다

#1 Union을 하기 전에 결합 여부 확인
-> 이미 같은 소속이라면 결합하지 않아!
if(Find(A)==Find(B))
    continue;

#2 Union 함수내에서 결합 여부 확인
if(pa==pb)
    return;
*/
#include <iostream>

using namespace std;
int N,M;
int developer[20];
int parent[20];
int Find(int now){
    if(now==parent[now])
    return now;

    return parent[now]=Find(parent[now]);
}
void Union(int A,int B){
    int pa=Find(A);
    int pb=Find(B);
    if(pa==pb) // 이미 같은 소속이면 합병 x
        return;
    parent[pb]=pa;
    developer[pa]+=10;
    developer[pb]-=10;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        parent[i]=i;
        cin>>developer[i];
    }
    for(int i=0;i<M;i++){
        int A,B;
        cin>>A,B;
        Union(A,B);
    }
    for(int i=0;i<N;i++){
        cout<<developer[i]<<'\n';
    }
    return 0;
}