//F면 
//1. 부모가 업데이트를 했을 시 그것의 최근값
//2. 업데이트 없을 시, 그위로 올라간다
//3. 부모가 T라면 copy time 직전에 업데이트 된 값을 찾는다.
// 아무것도 없을 시에 초기 값을 가진다.
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define LIST_LENGTH_MAX 200001
#define NODE_MAX 5050
#define ORIGINAL_MAX 10


//original
int listArr[ORIGINAL_MAX][LIST_LENGTH_MAX];
int listIndex;
int timeLine;
//부모
struct Node{
    string parrent;
    int birth;
    int family;
    bool copyStyle;
    vector<int> update_index;
    vector<int> update_data;
    vector<int> timeLine;
};
//node memory pool
Node memory_pool[NODE_MAX];
int nodeIndex;

unordered_map<string,Node*> node; // string 과 Node 매핑
Node* _newNode(string parrent, int time, bool copyStyle){
    memory_pool[nodeIndex].birth=time;
    memory_pool[nodeIndex].parrent=parrent;
    memory_pool[nodeIndex].family=-1; // make로 만든 노드들만 list index를 가짐
    memory_pool[nodeIndex].copyStyle=copyStyle; //true 면 깊은복사(독립), false면 주소복사(의존)
    return &memory_pool[nodeIndex++];
}

void init(){
    listIndex=0;
    nodeIndex=0;
    timeLine=0;
    node.clear();

}
void makeList(char mName[], int mLength, int mListValue[]){
    for(int i=0;i<mLength;i++){
        listArr[listIndex][i]=mListValue[i];
    }
    string name=string(mName);
    Node *newNode = _newNode("", timeLine++,true);
    newNode->family=listIndex++;
    node.insert({name, newNode});

    
}
void copyList(char mDest[], char mSrc[], bool mCopy){
    string dest=string(mDest);
    string src=string(mSrc);
    Node *newNode=_newNode(src, timeLine++, mCopy);
    node.insert({dest,newNode});
}
void updateElement(char mName[], int mIndex, int mValue){
    string name=string(mName);
    Node* target=node[name];

    target->timeLine.push_back(timeLine++);
    target->update_index.push_back(mIndex);
    target->update_data.push_back(mValue);
}
int element(char mName[], int mIndex){
    int time;
    //부모로 하나씩 타고 올라가면서 확인
}

int main(){


    return 0;
}