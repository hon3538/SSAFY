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

set<int> x[101]; //작은거부터 오름차순

void init(){
    for(int i=0;i<101;i++){
        x[i].clear();
    }
}
void add(int mX, int mY){
    x[mX].insert(mY);
}
void remove(int mX, int mY){
    x[mX].erase(mY);
}
int numberOfCross(int mID){
    int cnt=0;
    int mx = mID;
    int my = 0;
    //lower 같거나 큰
    //upper 큰
    while(1){
        //다음 y찾아
        auto right = x[mx].upper_bound(my);
        auto left = x[mx-1].upper_bound(my);

        //둘다 end() 일 경우 break
        if(right==x[mx].end()&&left==x[mx-1].end()) break;

        if(right==x[mx].end()){//right 가 없거나 left가 더 가까운 경우
            mx--;
            my = *left;
        }
        else if(left==x[mx -1].end()){ // left 가 없거나 right가 더 가까운 경우
            mx++;
            my = *right;
        }else if(*left<*right){
            mx--;
            my = *left;
        }else{
            mx++;
            my = *right;
        }
        cnt++;
    }
    return cnt;
}
int participant(int mX, int mY){
    //해당 좌표에서 위로 올라가
    while(1){
        auto right = x[mX].lower_bound(mY);
        auto left = x[mX-1].lower_bound(mY);

        //둘 다 없으면 나가 ( begin 은 첫번째 원소를 가리킴, 즉, mY다 큰 첫번째 원소가 begin이면 위엔 아무것도 없음 )
        if(right == x[mX].begin() && left == x[mX-1].begin()) break;
        if(right == x[mX].begin()){ //오른쪾 찾은게 begin이야 ? 즉 위에 아무것도 없어? 
            mX--;
            mY=*(--left);
            continue;
        }else if(left == x[mX -1].begin()){ // 왼쪽 줄에 위에 가로선 없어?
            mX++;
            mY=*(--right);
            continue;
        }
        
        //위에서 이미 mY보다 큰 요소가 최소 두 개 이상 있음을 확인했다.
        //둘다 begin이 아니라는 것은 mY보다 작은 원소가 최소 하나 이상 있다는 것이다.
        left--;
        right--;
        if(*left>*right){
            mX--;
            mY=*left;
        }else{
            mX++;
            mY=*right;
        }
    }
    return mX;
}