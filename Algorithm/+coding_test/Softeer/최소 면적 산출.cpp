/*
Edge case
- color(20개)와 점(100개)이 최대일 경우
    - 같은 color 5개씩 5^20 승 -> backtracking 최소 넓이 넘기면 out
    - 한 color가 80개
- color가 1개, 점이 100개 일 경우

*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAX_INT 0x7fffffff
#define MIN_INT -0x7fffffff
int N, K; // 점 개수, 컬러 종류
struct Node{
    int y, x;
};
vector<Node> color[21];

int minAns = MAX_INT;
Node minNode = {MAX_INT, MAX_INT};
Node maxNode = {MIN_INT, MIN_INT};
void dfs(int level){ // level, 왼쪽위, 오른쪽 아래 꼭지점
    int area = (maxNode.x-minNode.x)*(maxNode.y-minNode.y);
    if(level != 0){
        if(area >= minAns) return;
    }
    if(level == K){ 
        minAns = area;
        return;
    }
    Node minTemp = {minNode.y, minNode.x};
    Node maxTemp = {maxNode.y, maxNode.x};
    for(int i=0; i<color[level+1].size(); i++){
        Node now = color[level+1][i];
        
        if(minNode.y > now.y) minNode.y = now.y;
        if(minNode.x > now.x) minNode.x = now.x;
        if(maxNode.y < now.y) maxNode.y = now.y;
        if(maxNode.x < now.x) maxNode.x = now.x;

        dfs(level+1);
        //복구
        minNode = {minTemp.y, minTemp.x};
        maxNode = {maxTemp.y, maxTemp.x};
    }
}
int main(){
    cin>>N>>K;
    for(int i=0; i<N; i++){
        int y, x, k;
        cin>>x>>y>>k;
        color[k].push_back({y,x});
    }
    dfs(0);
    cout<< minAns;
    return 0;
}
