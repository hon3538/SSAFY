//https://www.acmicpc.net/problem/2252 백준 줄세우기
//순서가 정해져 있는 작업을 차례로 수행해야 할 때,
//그 순서를 정렬하기 위해 사용
//자료구조 queue로 구현

//위상정렬이 가능한 조건
//DAG(Directed Acyclic Graph) : 사이클이 존재하지 않는 단방향 그래프
//O(V+E) , V:정점 개수  E: 간선 개수

//순서
//1. 그래프 정보를 저장하면서 진입차수도 저장한다
//*진입차수: 자신에게 들어오는 노드의 개수
//2. 진입차수가 0인 정점들을 queue에 push
//3. q에서 원소를 꺼내어 현재 노드와 연결된 간선 다 제거
//*간선을 제거하지 않고 연결된 노드들의 진입차수만 -1씩해주면됨 (사이클이 없기때문에)
//4. 진입차수가 0이된 노드들은 다시 queue에 push
//5. 위 반복  

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define NODE_MAX 10000
int N; // 정점 개수
int V;// 간선 개수
int inDegree[NODE_MAX]; //진입차수
vector<int>v[NODE_MAX]; //그래프 정보
queue<int>q; // 위상 정렬을 위한 진입차수 0 큐

//hint : 모든 노드를 한번 씩 들리기 때문에 N번 탐색한다.
//N번 탐색하기 전에 끝난다면 사이클이 존재하여 모든 노드를 탐색하지 못한다는 의미이다.
void topology_sort(){
    for(int i=0;i<N;i++){
        if(inDegree[i]==0) q.push(i);
    }

    for(int i=0;i<N;i++){
        if(q.empty()){
            cout<<"사이클 발생";
            return;
        }
        int now=q.front();
        q.pop();

        cout<<now<<'\n';
        for(int j=0;j<v[now].size();j++){
            int next=v[now][i];
            inDegree[next]--;
            if(inDegree[next]==0) q.push(next);

        }
    }
}

int main(){
    cin>>N>>V;
    for(int i=0;i<V;i++){
        int a,b;
        cin>>a>>b; //a에서 출발해서 b로
        inDegree[b]++;
        v[a].push_back(b);
    }

}