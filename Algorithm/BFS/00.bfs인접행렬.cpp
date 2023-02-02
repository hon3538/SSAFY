#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int N;//����� ����
int M;//������ ����

int mat[10][10];//���� ���
void bfs(int start) {
	//1. queue �غ�
    queue<int>q;
    //queue�� ���� ��� ����
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