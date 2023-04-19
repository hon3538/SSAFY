
//init
//N , roomCnt[]
//N 개의 호텔이 있고 roomCnt[i] 는 id가 i+1 인 호텔의 방 개수이다
// N 1~1000, 방개수 1~100 
//방개수 총 10만개

//addRoom(hID,rID,rInfo[])
//hID 호텔의 rID 룸을 추가한다.
// 룸정보는 roomInfo[5]
//[0]지역~10, [1]침대수2~10 [2]객실종류1~4 [3]조망종류1~4 [4]가격10000~20000
// add는 각 호텔의 방개수만큼 실행된다

//findRoom(int requirements[]) 10000회
//조건이 부합하는 것중 가장 저렴한 방
//가격이 같으면 ID가 작은 객실
//체크인 체크아웃 기간과 겹치는 방은 예약 x

//risePrise(int hotelID) 500회
//해당 호텔의 모든 객실 가격 10% 인상됨
// 인상 후 가격 반환
// 500*100 
// 포인터로 방 접근

//1. findRoom
// 기간 겹치는지 비교 어떻게? ->세그먼트 트리
// 구간마다 겹치면 방의 ID 저장(set) (addRoom)
// 방개수 10만개*log(20000) => 170만

//findRoom 은 해당 구간 탐색 (log20000)해서 없는 ID 찾기


// 구간에 안 겹치는 방리스트중 (logN)
// 최저 가격을 1로 알 수 있다면?
// 예약하면 해당 구간에(방 ID set으로 체크)
// 

//지역 침대수 객실 종류 조망종류 -> 고정 값 -> ID 로 활용
//지역 *100000 침대수 *10000 객실*100 조망 으로 ID 할당 -> 1600가지 조합 가능

//만든 ID(map<ID,PQ>) 로 배열 정렬(가치와 룸id로)
//만든 ID의 방id로 segment tree 확인 log20000
//조건 부합하면 id 출력
//부합 안 하면? 다음 index 계속 탐색 

//가격 인상은 해당 호텔의 가격을 포인터로 접근하여 다 올리고
//호텔의 방이 있는 배열만 정렬 최대 100개

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

struct Room{
    int hid;
    int rid;
    int condition;
    int price;
};
vector<Room*>hotel[1001];
Room v[100001];
int Size[1001];//각 호텔의 방 개수
int room_cnt;
//segment tree 20000 -> 200000정도
//각 구간에 room id가 겹치는지만 확인->set
unordered_set<int>st[200000]; //key : room id
int cond_index;
void init(int N, int roomCnt[]) {
    for(int i=1;i<=N;i++){
        Size[i]=roomCnt[i-1];
    }
}
// addRoom
bool cmp(Room o1,Room o2){
    if(o1.price==o2.price) return o1.rid<o2.rid;
    return o1.price<o2.price;
}

//key :condition, value : vector
vector<Room>cond_vector[1601];
unordered_map<int,vector<Room>>condition_map;
//key를 condition, value를 head(Room*)으로 만들어서 list를 만든다면?
// 가격 바꿀떄 정렬필요한데 어케할건데..
//맵은 키값으로만 정렬하므로 value와 id 둘다 고려 못함
//

void addRoom(int hotelID, int roomID, int roomInfo[]) {
    int condition=0;
    for(int i=0;i<4;i++){
        condition*=100;
        condition+=roomInfo[i];
    }
    v[room_cnt]={hotelID,roomID,condition,roomInfo[4]};
    hotel[hotelID].push_back(&v[room_cnt]); //해당 호텔의 방을 주소로 저장
    if(condition_map.find(condition)==condition_map.end()){
        condition_map.insert({condition,cond_vector[cond_index++]});
    }
    condition_map[condition].push_back(v[room_cnt]);
    room_cnt++;
}

int findRoom(int requirements[]) { //만번
    int start=requirements[0];
    int end=requirements[1];
    int condition=0;
    for(int i=0;i<4;i++){
        condition*100;
        condition+=requirements[2+i];
    }
    int index=
    while(1){
        int id=
        int ret=s(start,end,); //0이면 가능 1이면 불가능

    }
    

    return 0;
}

int risePrices(int hotelID) {
    return 0;
}