/*
MST 생각했지만, 모든 경로가 연결될 필요는 없음
Dijkstra + PS
Dijstra = path 10만개 정렬 10만*log10만 = 약 200만
PS = 10억 -> log10억 = 24

최대 약 5천만
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>
using namespace std;

struct Edge{
    int to;
    int value;
};
vector<Edge> gym[10001];
int visited[10001];
int N, M; // 체육관 수, path 수

bool dijkstra(int level){
    memset(visited,0,sizeof(visited));
    queue<Edge> q;
    q.push({1,0});
    visited[1] = 1;
    while(!q.empty()){
        Edge now = q.front();
        q.pop();
        if(now.to == N) return true;
        
        for(int i=0; i<gym[now.to].size(); i++){
            Edge next = gym[now.to][i];
            if(visited[next.to]==1) continue;
            if(next.value >= level) continue;
            visited[next.to] = 1;
            q.push(next);
        }
    }
    return false;
}
int parametricSearch(){
    int left = 0;
    int right = 1000000000;
    int ans=-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(dijkstra(mid)){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ans;
}
bool checkPrime(int num){
    // num 이 소수인지 확인하는법
    double middle = sqrt((double)num);
    for(int i=2; i<=middle; i++){
        if(num%i==0) return false;
    }
    return true;
}
int getMinPrime(int num){
    // num이 소수가 아니라면 소수로 만들기
    while(1){
        if(checkPrime(num)) return num;
        num++;
    }
}
int main(){
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int A, B, C; // 체육관 A, B value C
        cin>>A>>B>>C;
        gym[A].push_back({B,C});
        gym[B].push_back({A,C});
    }
    // 필요한 최소 레벨
    int minLevel = parametricSearch();
    // cout<<"minLevel : "<<minLevel<<'\n';
    // 소수 구하기
    int ret = getMinPrime(minLevel);
    cout<<ret;
    return 0;
}