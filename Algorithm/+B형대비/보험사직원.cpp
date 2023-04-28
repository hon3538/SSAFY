/// *** user.cpp ***
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
//N 도시 개수 350
//parent[0]=-1 => 루트를 의미

//그래프 정보
vector<int>v[351];
struct Path {
    int to;
    int time;
    vector<int> path;
    bool operator < (Path o) const {
        return time > o.time;
    }
};
struct Incident {
    int time; //접수시간
    int id;
    int city;
    int prio;
    int start; //시작시간
}event[100000];
int dist[351]; //a에서 b로가는 path, size가 시간
vector<int>p[351][351];
int cur; //현재 위치
struct cmp {
    bool operator()(int a,int b)const{
        if (event[a].prio == event[b].prio) return event[a].time < event[b].time;
        return event[a].prio > event[b].prio;
    }
};
set<int, cmp>list;
int s; //

void dijkstra(int city) {
    priority_queue<Path>pq;

    pq.push({ city,0,vector<int>() });
    dist[city] = 1;
    while (!pq.empty()) {
        Path now = pq.top();
        pq.pop();
        if (dist[now.to] < now.time) continue;
        if(city!=now.to)
            now.path.push_back(now.to);
        for (int i = 0; i < now.path.size(); i++) {
                p[city][now.to].push_back(now.path[i]);
         }

        for (int i = 0; i < v[now.to].size(); i++) {
            int next = v[now.to][i];
            if (dist[next] != 0 && dist[next] <= now.time + 1) continue;
            dist[next] = now.time + 1;
            pq.push({ next,now.time + 1,now.path });
        }
    }
}
void init(int N, int parent[]) {

    for (int i = 1; i < N; i++) {
        v[i].push_back(parent[i]);
        v[parent[i]].push_back(i);
    }
    //도로개수 350 * 도시개수 350 = 15만
    //도시 i부터 출발하여 모든 모시정보 저장
    for (int i = 0; i < N; i++) {
        dijkstra(i);

    }
}
//사건 접수시간, 사건 번호, 도시 번호 , 우선순위
//우선순위 같으면 더 빨리 발생한 사건
// 10만번
// 우선순위에 있는 애들 다 실행

void update(int t) {
    int start;
    if (!list.empty()) {
        start = event[*list.begin()].start;
    }

    while (!list.empty()) {
        int id = *list.begin();
        event[id].start = start;
        int end = start + p[cur][event[id].city].size();
        if (end <= t) {
            list.erase(id);
            start = end + 1;
            cur = event[id].city;
            continue;
        }
        break;
    }
}
void occur(int timeStamp, int caseID, int cityID, int priority) {
    //list 정리
    //끝난애들 정리
    update(timeStamp);
    //cur을
    event[caseID] = { timeStamp,caseID,cityID,priority,timeStamp };
    list.insert(caseID);
}

// 해당 시간에 사긴 취소
//이미 처리됐거나 이미 취소됐을 수 있음
// 10만번
void cancel(int timeStamp, int caseID) {
    //다시 업데이트
    update(timeStamp);
    if (list.find(caseID) != list.end()) list.erase(caseID);
}

// 이시간에 민철이가 위치한 도시 반환
// 10만번
int position(int timeStamp) {
    update(timeStamp);
    //cur를 최근 list에서 timeStemp 까지 시간 계산해서
    //다음 cur를 update 해주고 return 하기

    //아직 구현 안함.
    return cur;
}

//사건발생하면 민철이 다익스트라로 이동 하여 해당 사건 끝나는 시간 업데이트
//만약 그전에 취소되거나 다른 우선순위 사건이 들어오면 해당 끝나는 시간 삭제
//무탈히 끝나는 시간이 온다면 해야할 일 리스트에서 삭제


//다익스트라로 모든 도시사이 거리를 미리 저장(경로도 미리 저장..)
//일 리스트는 set으로 저장(case)
//현재 position부터 시간단위로 경로에 저장한 도시를 position 변수에 저장
