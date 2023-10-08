/*
높이 10인 완전 이진트리의 최대 노드 개수
1 + 2 + 4 + ..+2^10 = 약 2천

2천개 노드를 1000일 시뮬레이션 => 200만
*/
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

#define MAX 3000

int H, K, R; //조직 높이, 말단 업무 개수, 업무 진행 일수
int ans;
struct Node{
    queue<int> left_work;
    queue<int> right_work;
    queue<int> work;
}node[MAX];
void process(int day){ //노드 최대 2000개, O(2^(H+1))
    int lastCnt = pow(2,H);
    for(int i=1; i<lastCnt; i++){ // 말단 제외 윗 부서들
        if(node[i].right_work.empty()&&node[i].left_work.empty()) continue;

        int work;
        if(day%2==0){ // 짝수일 경우 오른쪽 일 처리
            if(!node[i].right_work.empty()){
                work = node[i].right_work.front();
                node[i].right_work.pop();
            }
        }
        else{// 홀수일 경우 왼쪽 일 처리
            if(!node[i].left_work.empty()){
                work = node[i].left_work.front();
                node[i].left_work.pop();
            }
        }

        if(i==1){ // 부서장의 경우
            ans += work;
        }else{ //말단이 아닌 나머지 사원일 경우
            if(i%2==0) node[i/2].left_work.push(work); //왼쪽 노드면 부모의 left q에 삽입
            else node[i/2].right_work.push(work); //오른쪽 노드면 부모의 right q에 삽입
        }
    }
    for(int i=lastCnt; i<2*lastCnt; i++){ //말단 사원들
        if(node[i].work.empty()) continue;
        int work = node[i].work.front();
        node[i].work.pop();

        if(i%2==0) node[i/2].left_work.push(work); //왼쪽 노드면 부모의 left q에 삽입
        else node[i/2].right_work.push(work); //오른쪽 노드면 부모의 right q에 삽입
    }
        
}
int main(){
    cin>>H>>K>>R;
    int lastCnt = pow(2,H);
    for(int i=lastCnt; i<2*lastCnt; i++){
        for(int j=0; j<K; j++){
            int w;
            cin>>w;
            node[i].work.push(w);
        }
    }
    for(int day=1; day<=R; day++){ // 1000
        process(day); // 2000
    } // 200만
    cout<<ans;
    return 0;
}