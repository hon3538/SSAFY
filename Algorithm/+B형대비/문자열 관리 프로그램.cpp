// ***user.cpp***

#include <iostream>
#include <deque>
#include <unordered_map>
#include <string>
using namespace std;

//문자열 최대 길이 15만
deque<char>str;
int isFront;
unordered_map<string,int>front_map[26]; //0 이 head부터, 1이 back부터
unordered_map<string,int>back_map[26];
void front_put(char c){
    //c를 받으면 뒤를 탐색해서 4번 넣어
    string s1=to_string(c);
    string s2=to_string(c);
    int end=str.size()-1;
    //정방향
    if(front_map[s1[0]-'a'].find(s1)==front_map[s1[0]-'a'].end())  
        front_map[s1[0]-'a'].insert({s1,0});
    front_map[s1[0]][s1]++;
    //역방향
    if(back_map[s2[0]-'a'].find(s2)==back_map[s2[0]-'a'].end())  
        back_map[s2[0]-'a'].insert({s2,0});
    back_map[s2[0]][s2]++;
    for(int i=0;i<=end;i++){
        if(i==3) break; //이전 세 개의 문자만 보면됨
        s=to_string(str[end-i])+s;
        if(front_map[s[0]-'a'].find(s)==front_map[s[0]-'a'].end())  front_map[s[0]-'a'].insert({s,0});
        front_map[s[0]-'a'][s]++;
    }
}
void front_pop(char c,int order){
    string s=to_string(c);
    int end=str.size()-1;
    front_map[s[0]-'a'][s]--;
    for(int i=0;i<=end;i++){
        if(i==3) break;
        s=to_string(str[end-i])+s;
        front_map[s[0]-'a'][s]--;
    }
}

void back_put(char c){
    string s=to_string(c);
    int len=str.size()-1;
    int start=0;

    if(back_map[s[0]-'a'].find(s)==back_map[s[0]-'a'].end())  
        back_map[s[0]-'a'].insert({s,0});
    back_map[s[0]][s]++;
    for(int i=0;i<=len;i++){
        if(i==3) break; //이전 세 개의 문자만 보면됨
        s=to_string(str[i])+s;
        
        if(back_map[s[0]-'a'].find(s)==back_map[s[0]-'a'].end())  back_map[s[0]-'a'].insert({s,0});
        back_map[s[0]-'a'][s]++;
    }
}
void back_pop(char c,int order){
    string s=to_string(c);
    int len=str.size()-1;
    back_map[s[0]-'a'][s]--;
    for(int i=0;i<=len;i++){
        if(i==3) break;
        s=to_string(str[i])+s;
        back_map[s[0]-'a'][s]--;
    }
}
//문자열은 deq 로 관리 
void init(char mainStr[]) {
    int len=strlen(mainStr)-1;
    for(int i=0;i<=len;i++){
        front_put(mainStr[i]);
        back_put(mainStr[i]);
        str.push_back(mainStr[i]);
    }
}

//4길이를 넣으면 16번 실행
//3만번 호출 -> 50만.. 가능
void pushBack(char newStr[]) {
    for(int i=0;i<strlen(newStr);i++){
            front_put(newStr[i]);
            back_put(newStr[i]);
        if(isFront){
            str.push_back(newStr[i]);
        }else{
            
        }
    }
}
 
//100번, 15만 번제거, 1번 제거당 4번, 6000만 가능
void popBack(int n) {
}

//앞뒤만 바꿔줌 3만번
void reverseStr() {
    isFront=!isFront;
}
 
//unodered_map으로 관리 3만
//거꾸로 된 map도 관리 3만
int getCount(char subStr[]) {
    return 0;
}