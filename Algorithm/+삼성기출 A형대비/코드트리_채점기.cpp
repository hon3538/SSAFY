#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int Q,N; // 명령어 수 5만, 채점기 수 5만

//init
struct Problem{
    int inTime;
    int pt; //우선순위
    string url;
    bool operator < (Problem o) const{
        if(pt==o.pt){
            return inTime>o.inTime;
        }else return pt>o.pt;
    }
};
priority_queue<Problem> w_list; //wating list
unordered_set<string>u_wating; // url check
unordered_set<string>u_grading; 
int grading[50001]; //index 채점기 번호, value : 채점 시작 시간, 0이면 쉬는중
void init(){
    //N개의 채점기, 초기 url 주어짐 (도메인/문제ID)
    string url;
    cin>>N>>url;
    w_list.push({0,1,url});
    u_wating.insert(url);
}
//채점 요청
void request(){
    int t,p;
    string url;
    cin>>t>>p>>url;
    if(u_wating.find(url)!=u_wating.end()) return;
    w_list.push({t,p,url});
    u_wating.insert(url);
}
//채점 시도
void tryGrading(){
    int t;
    cin>>t;
    Problem now=w_list.top();
}
int main(){
    cin>>Q;
    for(int q=0;q<Q;q++){
        int command;
        cin>>command;
        if(command==100){ 

        }else if(command==200){

        }else if(command==300){
            
        }else if(command==400){
            
        }else if(command==500){
            
        }
    }

    return 0;
}