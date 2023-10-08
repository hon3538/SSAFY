/*
각 사람 id로 점수를 저장,
점수로 sorting
10만개 브루트포스 하며 순서대로 id에 등수를 부여

4번 반복
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
struct Person{
    int id;
    int score[4];
}people[100000];

int rankList[100000]; // 각 사람의 1~3 대회 순위 및 최종 

bool cmp0(Person a, Person b){
    return a.score[0] > b.score[0];
}
bool cmp1(Person a, Person b){
    return a.score[1] > b.score[1];
}
bool cmp2(Person a, Person b){
    return a.score[2] > b.score[2];
}
bool cmp3(Person a, Person b){
    return a.score[3] > b.score[3];
}
void printRank(int contest){
    int cnt = 0; // 공동 수상자 체크
    rankList[people[0].id] = 1;
    for(int r=1; r<N; r++){
        if(people[r-1].score[contest]==people[r].score[contest]){
            cnt++;
            rankList[people[r].id] = r+1-cnt;
        }
        else{
            rankList[people[r].id] = r+1;
            cnt = 0;
        }
    }
    for(int i=0; i<N; i++){
        cout<<rankList[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    cin>>N;
    for(int r=0; r<3; r++){
        for(int i=0; i<N; i++){
            cin>>people[i].score[r];
            people[i].id = i;
        }
    }
    for(int i=0; i<N; i++){
        people[i].score[3] = people[i].score[0] + people[i].score[1] + people[i].score[2];
    }
    sort(people, people+N, cmp0);
    printRank(0);
    sort(people, people+N, cmp1);
    printRank(1);
    sort(people, people+N, cmp2);
    printRank(2);
    sort(people, people+N, cmp3);
    printRank(3);
    // for(int i=0;i<N; i++){
    //     cout<< people[i].id;
    //     cout<<'\n';
    // }

    return 0;
}