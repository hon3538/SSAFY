#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>

extern void init(int N, int roomCnt[]);
extern void addRoom(int hotelID, int roomID, int roomInfo[]);
extern int findRoom(int requirements[]);
extern int risePrices(int hotelID);

static int roomCnt[1005];

const static int ADDROOM = 100;
const static int FINDROOM = 200;
const static int RISEPRICES = 300;
const static int END = 400;

static int hotelID = 0;
static int roomID = 0;
static int roomInfo[5] = { 0, };
static int requirementsInfo[6] = { 0, };

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>
using namespace std;

int get_condition(int arr[5]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum *= 100;
        sum += arr[i];
    }
    return sum;
}
struct Room {
    int hid;
    int rid;
    int condition;
    int price;
};
//key : hotel id, value: 방정보 배열
Room room_arr[100001];
unordered_map<int, vector<Room*>>hotels;
int room_cnt;

//방 id로 접근, value : (key:시작, value:end)
//예약된 날짜 저장하는 맵

unordered_map<int, map<int, int, less<int>>>rid_book;
//condition에 해당하는 방들

struct cmp {
    bool operator()(int A, int B) const {
        if (room_arr[A].price == room_arr[B].price) return room_arr[A].rid < room_arr[B].rid;
        return room_arr[A].price < room_arr[B].price;
    }
};
set<int, cmp>set_room[1601]; //key : rid
int c_cnt;

unordered_map<int, set<int, cmp>>c_rooms;


void init(int N, int roomCnt[]) {
    memset(room_arr, 0, sizeof(room_arr));
    hotels.clear();
    room_cnt = 0;

    rid_book.clear();
    //condition에 해당하는 방들
    for (int i = 0; i < 1601; i++) {
        set_room[i].clear();
    }
    c_cnt = 0;
    c_rooms.clear();
}
void addRoom(int hotelID, int roomID, int roomInfo[]) {
    int condition = get_condition(roomInfo);
    int price = roomInfo[4];
    room_arr[roomID] = { hotelID,roomID,condition,price };
    hotels[hotelID].push_back(&room_arr[roomID]);
    //condition 에 해당하는 방번호 넣기, 
    if (c_rooms.find(condition) == c_rooms.end()) {
        c_rooms.insert({ condition,set_room[c_cnt++] });
    }
    c_rooms[condition].insert(roomID);
}
//해당 방이 가능한지 확인
int isValid(int rid, int start, int end) {
    //upperbound 써서 해당 체크인 시간을 찾는다.
    auto it = rid_book[rid].upper_bound(start);
    if (it != rid_book[rid].end()) {
        //다음게 있으면 컨디션 비교
        if (end > it->first) return -1;
    }
    //이전값 있는지 확인 (본인이 시작인지 확인)
    if (it != rid_book[rid].begin()) {
        --it;
        //있으면 비교
        if (it->second > start) return -1;
    }
    return 1;
}
int findRoom(int requirements[]) {
    //날짜 겹치는 거 어떻게 확인?
    //조건 맞는 방들을 하나씩 탐색 (1000)
    //방찾으면 logN번 탐색으로 가능 여부 찾음
    int start = requirements[0];
    int end = requirements[1];
    int condition = 0;
    for (int i = 0; i < 4; i++) {
        condition *= 100;
        condition += requirements[i + 2];
    }
    int idx = 0;
    int ans = -1;
    if (c_rooms.find(condition)==c_rooms.end()) return ans;
    auto it = c_rooms[condition].begin();
    while (it != c_rooms[condition].end()) {
        //방마다 해당 방번호의 체크인 체크아웃 날짜를 ordered맵으로 저장,
            //이 방이 되나요? 되면 해당 날짜에 예약하고
            //안 되면 다음 방 보세요
        if (isValid((*it), start, end) == 1) {
            rid_book[(*it)].insert({ start,end });
            ans = (*it);
            break;
        }
        ++it;
    }
    return ans;
}

int risePrices(int hotelID) {
    int ans = 0;
    for (int i = 0; i < hotels[hotelID].size(); i++) {
        int rid = hotels[hotelID][i]->rid;
        int condition = hotels[hotelID][i]->condition;
        c_rooms[condition].erase(rid);
        hotels[hotelID][i]->price += hotels[hotelID][i]->price / 10;
        ans += hotels[hotelID][i]->price;
        c_rooms[condition].insert(rid);
    }
    return ans;
}
static int run(int _score)
{
    int n, score = _score;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", roomCnt + i);

    init(n, roomCnt);

    int cmd, user_ans, correct_ans;
    for (int q = 0; ; q++)
    {
        scanf("%d", &cmd);

        switch (cmd)
        {
        case ADDROOM:
            scanf("%d%d", &hotelID, &roomID);
            for (int i = 0; i < 5; i++)
                scanf("%d", roomInfo + i);
            addRoom(hotelID, roomID, roomInfo);
            break;
        case FINDROOM:
            for (int i = 0; i < 6; i++)
                scanf("%d", requirementsInfo + i);
            user_ans = findRoom(requirementsInfo);
           // cout << user_ans << '\n';
            scanf("%d", &correct_ans);
            if (user_ans != correct_ans)
                score = 0;
            break;
        case RISEPRICES:
            scanf("%d", &hotelID);
            user_ans = risePrices(hotelID);
           // cout << user_ans << '\n';
            scanf("%d", &correct_ans);
            if (user_ans != correct_ans)
                score = 0;
            break;
        case END:
            return score;
        default:
            score = 0;
            break;
        }
    }


    return score;
}

int main()
{
    setbuf(stdout, NULL);
    //freopen("input.txt", "r", stdin);

    int tc, score;
    scanf("%d%d", &tc, &score);

    for (int t = 1; t <= tc; t++)
    {
        printf("#%d %d\n", t, run(score));
    }

    return 0;
}
/*
1 100
3 2 6 10
100 1 1 2 2 2 1 14629
100 1 2 2 3 1 2 10203
100 2 3 2 3 1 1 15374
100 2 4 1 2 2 1 10795
100 2 5 2 2 1 2 17701
100 2 6 1 3 2 2 13757
100 2 7 1 3 1 2 13569
100 2 8 1 3 2 2 17424
100 3 9 1 3 2 1 18267
100 3 10 2 3 1 2 11378
100 3 11 1 3 1 1 11800
100 3 12 2 3 2 2 16613
100 3 13 1 3 2 1 13157
100 3 14 2 3 1 2 10064
100 3 15 1 3 2 1 12999
100 3 16 1 3 1 2 13642
100 3 17 2 2 2 2 14388
100 3 18 2 2 2 2 16089
200 23 24 1 3 1 2 16
*/