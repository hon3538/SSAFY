#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int N;//노드의 개수
int M;//간선의 개수

int mat[10][10];//인접 행렬
void bfs(int start) {
	//1. queue 준비
    queue<int>q;
    //queue에 시작 노드 삽입
    q.push(start);

    while(!q.empty()){
        int now=q.front();
        q.pop();

        
        for(int next=0;next<N;next++){
            if(mat[now][next]=0){
                continue;
            }
            
            q.push(next);
        }

    }
}
int main() {
	cin >> N >> M;
	queue<int>q;

	for (int i = 0; i < M; i++) {

		int from, to;
		cin >> from >> to;
		//
		mat[from][to] = 1;
	}


}