/*
LCA
level 맞추기
공통 조상 구하기
N<100000
parrent[i][j]=k, i의 2^j번째 조상 k
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 100001

int parrent[SIZE][20];
int level[SIZE];
vector<int> children[SIZE];
int getNodeInLevel(int target_level, int node){
    //node의 조상중 target level을 가진 조상 구하기
    int cnt=0;
    while(level[node]!=target_level){
        cnt++;
        if(level[parrent[node][cnt]]<target_level){
            node = parrent[node][cnt-1];
            cnt=0;
        }
    }
    return node;
}
int getCommonNode(int A, int B){
    int cnt=0;
    while(parrent[A][0]!=parrent[B][0]){
        cnt++;
        if(parrent[A][cnt]==parrent[B][cnt]){
            A=parrent[A][cnt-1];
            B=parrent[B][cnt-1];
            cnt=0;
        }
    }
    return parrent[A][0];
}
int getDist(int A,int B){
    //A와 B 거리 맞추기
    int gap=level[A]-level[B];
    if(gap>0){
        swap(A,B); //A를 더 level 작게 유지
    }else gap*=-1;

    int node = getNodeInLevel(level[A],B);
    if(node==A) return gap;
    int commonNode = getCommonNode(A, node);
    int dit = level[A]-level[commonNode];
    int ans = gap + dit*2;
    
    return ans;
}
int func(){
    int ans=0;
    queue<int> q;
    int pre=1;
    for(int i=0;i<children[1].size();i++) q.push(children[1][i]);

    while(q.empty()){
        int now = q.front();
        q.pop();
        ans+=getDist(pre,now);
        pre=now;
        for(int i=0;i<children[now].size();i++) q.push(children[now][i]);
    }
    return ans;
}
void init(){
    memset(parrent,0,sizeof(parrent));
    memset(level,0,sizeof(level));
    for(int i=0;i<SIZE;i++) children[i].clear();
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        init();
        int N;
        cin>>N;
        level[1]=0;
        for(int i=2;i<=N;i++){
            cin>>parrent[i][0];
            children[parrent[i][0]].push_back(i);
            parrent[i][1]=parrent[parrent[i][0]][0];
            level[i]=level[parrent[i][0]] + 1;

        }
        //조상들 설정
        for(int j=2;j<20;j++){
            for(int i=2;i<=N;i++){
                parrent[i][j] = parrent[parrent[i][j-1]][j-1];
            }
        }
        
        cout<<'#'<<t<<' '<<func()<<'\n';
    }

    return 0;
}