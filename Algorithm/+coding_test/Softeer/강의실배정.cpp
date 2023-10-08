/*
한 강의실에 최대한 많은 강의 할당 -> Greedy

강의 개수 N <= 100만
1 <= start time < end time <= 10억 시간

*strategy
시간
강의들을 end time 기준으로 sort -> 100만 * log100만 = 약 2400만
100만개 강의들을 Greedy(다음 강의의 시작시간이 현재 강의 end time보다 같거나 뒤라면 counting) 반복문 = 100만
0.25s

메모리
100만*2*4byte = 800만 byte, 8mb

*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000

int N;
struct Lecture{
    int s_time;
    int e_time;
}lecture_list[MAX];

bool cmp(Lecture left, Lecture right){
    return left.e_time < right.e_time;
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int s, e;
        cin>> s >> e;
        lecture_list[i]= {s,e};
    }
    
    sort(lecture_list,lecture_list+N,cmp);
    // for(int i=0;i <N; i++){
    //     cout<<lecture_list[i].e_time<<' ';
    // }
    int ans = 1;
    int lastTime = lecture_list[0].e_time;
    for(int i=1; i<N; i++){
        if(lastTime<=lecture_list[i].s_time){
            ans++;
            lastTime = lecture_list[i].e_time;
        }
    }
    cout<<ans;
    return 0;
}