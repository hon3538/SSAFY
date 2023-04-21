#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int get_condition(int arr[5]){
    int sum=0;
    for(int i=0;i<4;i++){
        sum*100;
        sum+=arr[i];
    }
    return sum;
}
struct Room{
    int hid;
    int rid;
    int condition;
    int price;
};
//key : hotel id, value: 방정보 배열
unordered_map<int,vector<Room*>>hotels;
Room room_arr[100001];
int room_cnt;

//condition에 해당하는 방들
vector<Room*>vr[1601];
int c_cnt;
unordered_map<int,vector<Room*>>c_rooms;

//방 id로 접근, value : (key:시작, value:end)
unordered_map<int,map<int,int>>rid_book;
void init(int N, int roomCnt[]) {

}

void addRoom(int hotelID, int roomID, int roomInfo[]) {
    int condition =get_condition(roomInfo);
    int price=roomInfo[4];
    room_arr[room_cnt]={hotelID,roomID,condition,price};
    
    hotels[hotelID].push_back(&room_arr[room_cnt]);
    //condition 에 해당하는 방번호 넣기, 
    if(c_rooms.find(condition)==c_rooms.end()) c_rooms.insert({condition,vr[c_cnt++]});
    c_rooms[condition].push_back(&room_arr[room_cnt]);
    room_cnt++;
}
//해당 방이 가능한지 확인
int isValid(int rid,int start,int end){
    //upperbound 써서 해당 체크인 시간을 찾는다.
    auto it =rid_book[rid].upper_bound(start);
    if(it!=rid_book[rid].end()){
        //다음게 있으면 컨디션 비교
        if(end>it->first) return -1; 
    }
    //이전값 있는지 확인 (본인이 시작인지 확인)
    if(it!=rid_book[rid].begin()){
        --it;
        //있으면 비교
        if(it->second>start) return -1;
    }
    return 1;
}
int findRoom(int requirements[]) {
    //날짜 겹치는 거 어떻게 확인?
    //조건 맞는 방들을 하나씩 탐색 (1000)
    //방찾으면 logN번 탐색으로 가능 여부 찾음
    int start=requirements[0];
    int end=requirements[1];
    int condition=0;
    for(int i=0;i<4;i++){
        condition*100;
        condition+=requirements[i+2];
    }
    int idx=0;
    int ans=-1;
    while(1){
    //방마다 해당 방번호의 체크인 체크아웃 날짜를 ordered맵으로 저장, 
        if(c_rooms[condition].size()<=idx) break;
        
        Room temp =*c_rooms[condition][idx];
        //이 방이 되나요? 되면 해당 날짜에 예약하고
        //안 되면 다음 방 보세요
        if(isValid(temp.rid,start,end)==1){
            rid_book[temp.rid].insert({start,end});
            ans=temp.rid;
            break;
        }
        idx++;
    }
    return ans;
}

int risePrices(int hotelID) {
    return 0;
}