/// *** user.cpp ***
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <queue>
using namespace std; 
//N 도시 개수 350
//parent[0]=-1 => 루트를 의미

//그래프 정보
vector<int>v[351];
struct Path{
    int to;
    int time;
    vector<int> path;
};
int dist[351]; //a에서 b로가는 path, size가 시간
vector<int>p[351][351];

void dijkstra(int city){
    priority_queue<Path>pq;

    pq.push({city,0,vector<int>()});
    dist[city]=1;
    while(!pq.empty()){
        Path now =pq.top();
        pq.pop();
        if(dist[now.to]<now.time) continue;
        for(int i=0;i<now.path.size();i++){
            p[city][now.to].push_back(now.path[i]);
        }

        for(int i=0;i<v[now.to].size();i++){
            int next=v[now.to][i];
            if(dist[next]!=0&&dist[next]<=now.time+1) continue;
            dist[next]=now.time+1;
            now.path.push_back(next);
            pq.push({next,now.time+1,now.path});
        }
    }
}
void init(int N, int parent[]) {
    
    for(int i=1;i<N;i++){
        v[i].push_back(parent[i]);
        v[parent[i]].push_back(i);
    }
    //도로개수 350 * 도시개수 350 = 15만
    //도시 i부터 출발하여 모든 모시정보 저장
    for(int i=0;i<N;i++){
        dijkstra(i);
    }
}
//사건 접수시간, 사건 번호, 도시 번호 , 우선순위
//우선순위 같으면 더 빨리 발생한 사건
// 10만번
// 우선순위에 있는 애들 다 실행
// 
void occur(int timeStamp, int caseID, int cityID, int priority) {

}

// 해당 시간에 사긴 취소
//이미 처리됐거나 이미 취소됐을 수 있음
// 10만번
void cancel(int timeStamp, int caseID) {
 
}

// 이시간에 민철이가 위치한 도시 반환
// 10만번
int position(int timeStamp) {
 return 0;
}

//사건발생하면 민철이 다익스트라로 이동 하여 해당 사건 끝나는 시간 업데이트
//만약 그전에 취소되거나 다른 우선순위 사건이 들어오면 해당 끝나는 시간 삭제
//무탈히 끝나는 시간이 온다면 해야할 일 리스트에서 삭제


//다익스트라로 모든 도시사이 거리를 미리 저장(경로도 미리 저장..)
//일 리스트는 set으로 저장(case)
//현재 position부터 시간단위로 경로에 저장한 도시를 position 변수에 저장
