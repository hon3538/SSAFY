/*

false 복사는 주소값만 저장하고..
true 복사는 전체 복사인데.. 20만 * 5000 은 안 된다..
변화된 값만 저장하는 법?
각 주소 단위로 최근 값을 유지 할 수 있다면?
초기 list 10개 -> 20만개

update한 것들만 관리
update 최대 10만번

각 update time에는 index, value가 들어있고
각 주소의 최근 update time을 저장

해당 주소의 update chain을 만들고 싶다
map<주소,vector<update time>> 추가해나가고

만약 전체 복사가 이루어 지면
map<new 주소, vector<update time>> 을 만들고,
parrent = 주소
link = 부모의 vector size -1 을 넣는다.

*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

#define MAX_SIZE 200001

struct Update {
    int index;
    int value;
};
struct List {
    int parrent; //부모 index
    int link; //부모의 최근 update index
    vector<Update> update_list;
    List() {
        parrent = -1;
        link = -1;
    }
};
List listInfo[5050]; // 최대 list 개수 5010개
unordered_map<string, int> nameToIndex; //list 이름을 index로 치환
 // makeList가 처음 10번 연속 실행되는 것이 아니므로 따로 origin index를 관리하지 않으면
 // 복사된 list가 origin index(0~10) 을 가질 수 있다..
int origin_index = 0;
int list_index = 10; // 현재까지 독립 list 개수
int originList[10][MAX_SIZE]; // root list 개수

void init() {
    nameToIndex.clear();
    origin_index = 0;
    list_index = 10; // 초기화 잘줄것.. 0으로 줬어서 고생함
}
void makeList(char mName[], int mLength, int mListValue[]) {
    string name = string(mName); 
    //string 아니고 char*을 key로 주면 주소값을 넘기기 때문에
    //값이 같아도 다른 hash값을 가짐..
    if (nameToIndex.find(name) == nameToIndex.end()) {
        //없으면
        nameToIndex.insert({ name,origin_index++ });
    }
    int index = nameToIndex[name];
    listInfo[index].parrent = -1;
    listInfo[index].link = -1;
    listInfo[index].update_list.clear();
    for (int i = 0; i < mLength; i++) {
        originList[index][i] = mListValue[i];
    }
}
void copyList(char mDest[], char mSrc[], bool mCopy) {
    string dest = string(mDest);
    string src = string(mSrc);
    if (mCopy) { //전체 복사
        nameToIndex.insert({ dest,list_index++ });
        int index = nameToIndex[dest];
        int parrent = nameToIndex[src];
        listInfo[index].parrent = parrent;
        listInfo[index].link = listInfo[parrent].update_list.size() - 1;
        listInfo[index].update_list.clear();
    }
    else { //주소만 복사
        nameToIndex.insert({ mDest,nameToIndex[src] });
    }
}
void updateElement(char mName[], int mIndex, int mValue) {
    string name = string(mName);
    int index = nameToIndex[name];
    listInfo[index].update_list.push_back({ mIndex,mValue });
}
int element(char mName[], int mIndex) {
    string name = string(mName);
    int index = nameToIndex[name];
    int parrent = listInfo[index].parrent;
    int size = listInfo[index].update_list.size() - 1;
    // parrent != -1 && size < 0 으로 줬었음.. 반복문이 돌아갈 수 있는 조건을 넣을것!
    while (parrent != -1 || size >= 0) { // root 이고 update list 없으면 나가
        //cout << size << '\n';
        if (size < 0) {
            size = listInfo[index].link; 
            index = parrent;
            parrent = listInfo[index].parrent;
            //size = listInfo[index].link; 변경된 index의 link를 넣어줘서 고생함;
            continue;
        }
        // 찾았으면 해당 값 return
        if (listInfo[index].update_list[size].index == mIndex) {
            return listInfo[index].update_list[size].value;
        }
        // 못 찾았으면
        size--;
    }
    //끝까지 update 없으면
    return originList[index][mIndex];
}
