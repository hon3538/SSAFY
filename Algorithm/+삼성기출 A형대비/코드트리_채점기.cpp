#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int Q, N; // 명령어 수 5만, 채점기 수 5만

//init
struct Problem {
	int inTime;
	int pt; //우선순위
	string url;
	string domain;
	int id;
	bool operator < (Problem o) const {
		if (pt == o.pt) {
			return inTime > o.inTime;
		}
		else return pt > o.pt;
	}
};
priority_queue<Problem>pq[301];
int pq_num;
unordered_map<string, priority_queue<Problem>>w_list; //domain , 's list
unordered_set<string>u_already; // url check

unordered_set<string>d_grading; //domain check
struct GradingMachine {
	int start;
	int end;
};
GradingMachine grading[301]; //index 채점기 번호, value : 채점 시작 시간, 0이면 쉬는중
unordered_map<string,GradingMachine> domainTime;

string getDomain(string url) {
	int head = 0;
	int tail = url.find('/', head);
	return url.substr(head, tail);
}
int getID(string url) {
	int head = url.find('/', 0) + 1;
	return stoi(url.substr(head, url.size() - head));
}
void addUrl(int t,int priority, string url){
    string domain = getDomain(url);
	int id = getID(url);
    // domain list가 없으면 추가해
    if(w_list.find(domain)==w_list.end()){
	    w_list.insert({domain,pq[pq_num++]});
    }
    // 이미 해당 url이 있으면 넘어가
    if(u_already.find(url)!=u_already.end()) return;

    // url을 맞는 domain의 list에 넣어
    w_list[domain].push({t,priority,url,domain,id});
    u_already.insert(url);
}
void init() {
	//N개의 채점기, 초기 url 주어짐 (도메인/문제ID)
	string url;
	cin >> N >> url;
	addUrl(0,1,url);
}
//채점 요청
void request() {
	int t, p;
	string url;
	cin >> t >> p >> url;
	addUrl(t,p,url);
}
//채점 시도
int isValid(int t,int i){ // 부적절 여부 확인
    if(pq[i].empty()) return 0;
    //불가능 조건
    Problem now=pq[i].top();
    if(d_grading.find(now.domain)!=d_grading.end()) return 0;
    if(domainTime.find(now.domain)!=domainTime.end()){
        int start=domainTime[now.domain].start;
        int end=domainTime[now.domain].end;
        int gap=end-start;
        if(t<start+3*gap) return 0;
    }
    return 1;
}
void tryGrading() {
	int t;
	cin >> t;
    Problem res={21e8,21e8};
	//t초에 대기큐에서 채점 가능한 경우를 모두 찾고
    //그 중 우선순위가 가장 높은 채점 task를 찾아라
    int index=-1;
    for(int i=0;i<300;i++){
        if(pq[i].empty()) continue;
        //불가능 조건
        if(!isValid(t,i)) continue;
        
        //우선순위 따짐
        if(res.pt>pq[i].top().pt){
            index=i;
            res=pq[i].top();
        }else if(res.pt==pq[i].top().pt){
            if(res.inTime>pq[i].top().inTime){
                index=i;
                res=pq[i].top();
            }
        }
    }
    
    if(res.inTime==21e8)
    //GradingMachine grading[301]; 
   //몇번 채점기에 넣어야할지?
   int i=1;
    for(;i<=300;i++){
        if(grading[i].start>grading[i].end) continue;
        break;
    }
    

}
int main() {
	cin >> Q;


	for (int q = 0; q < Q; q++) {
		int command;
		cin >> command;

		if (command == 100) {

		}
		else if (command == 200) {

		}
		else if (command == 300) {

		}
		else if (command == 400) {

		}
		else if (command == 500) {

		}
	}

	return 0;
}