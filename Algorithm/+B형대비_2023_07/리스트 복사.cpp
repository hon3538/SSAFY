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
unordered_map<char*, int> nameToIndex; //list 이름을 index로 치환
int list_index = 0; // 현재까지 독립 list 개수
int originList[10][MAX_SIZE]; // root list 개수

void init() {
    nameToIndex.clear();
    list_index = 0;
}
void makeList(char mName[], int mLength, int mListValue[]) {
    if (nameToIndex.find(mName) == nameToIndex.end()) {
        //없으면
        nameToIndex.insert({ mName,list_index++ });
    }
    int index = nameToIndex[mName];
    listInfo[index].parrent = -1;
    listInfo[index].link = -1;
    listInfo[index].update_list.clear();
    for (int i = 0; i < mLength; i++) {
        originList[index][i] = mListValue[i];
    }
}
void copyList(char mDest[], char mSrc[], bool mCopy) {
    if (mCopy) { //전체 복사
        nameToIndex.insert({ mDest,list_index++ });
        int index = nameToIndex[mDest];
        int parrent = nameToIndex[mSrc];
        listInfo[index].parrent = parrent;
        listInfo[index].link = listInfo[parrent].update_list.size() - 1;
        listInfo[index].update_list.clear();
    }
    else { //주소만 복사
        nameToIndex.insert({ mDest,nameToIndex[mSrc] });
    }
}
void updateElement(char mName[], int mIndex, int mValue) {
    int index = nameToIndex[mName];
    listInfo[index].update_list.push_back({ mIndex,mValue });
}
int element(char mName[], int mIndex) {
    int index = nameToIndex[mName];
    int parrent = 0;
    int size = listInfo[index].update_list.size() - 1;
    while (parrent != -1 && size < 0) { // root 이고 update list 없으면 나가
        if (size < 0) {
            index = parrent;
            parrent = listInfo[index].parrent;
            size = listInfo[index].link;
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
