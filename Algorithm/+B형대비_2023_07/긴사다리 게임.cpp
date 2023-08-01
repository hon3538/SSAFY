/*
set<int> s[101];
index는 x좌표
key는 y좌표
y좌표로 정렬

add 20만번 -> 20만 * log20만 = 약 340만
remove 5000 -> log20만 -> 8만 5천
numberOfCross 500 -> 최대 5천번의 가로줄 넘을 수 있음, -> 500*5000*11 = 2700만
-> set inbound 최악의 경우 x마다 2000개의 y값, log2000 = 11
participant 500 -> 위와 같이 2700만

찐찐 최악이여도 가능..
*/
#include <iostream>
#include <set>
using namespace std;

set<int, less<int>> x[101]; //작은거부터 오름차순

void init(){

}
void add(int mX, int mY){
    x[mX].insert(mY);
}
void remove(int mX, int mY){
    x[mX].erase(mY);
}
int numberOfCross(int mID){
    int mx = mID;
    int my = 0;
    //lower 같거나 큰
    //upper 큰
    while(1){
        
    }
}
int participant(int mX, int mY){

}