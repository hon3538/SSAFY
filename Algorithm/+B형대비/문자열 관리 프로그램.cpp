// ***user.cpp***

#include <iostream>
#include <deque>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

//문자열 최대 길이 15만
deque<char>str;
int way; // 0 정방향 1 역방향
unordered_map<string, int>front_map[26]; //0 이 head부터, 1이 back부터
unordered_map<string, int>back_map[26];
void back_put(char c) { //정방향일때
    //c를 받으면 뒤를 탐색해서 4번 넣어
    string s1(1, c);
    string s2(1, c);
    int end = str.size() - 1;
    //정방향
    if (front_map[s1[0] - 'a'].find(s1) == front_map[s1[0] - 'a'].end())
        front_map[s1[0] - 'a'].insert({ s1,0 });
    front_map[s1[0] - 'a'][s1]++;
    //역방향
    if (back_map[s2[0] - 'a'].find(s2) == back_map[s2[0] - 'a'].end())
        back_map[s2[0] - 'a'].insert({ s2,0 });
    back_map[s2[0] - 'a'][s2]++;
    for (int i = 0; i <= end; i++) {
        if (i == 3) break; //이전 세 개의 문자만 보면됨
        string temp(1, str[end - i]);
        s1 = temp + s1;
        s2 = s2 + temp;
        
        if (front_map[s1[0] - 'a'].find(s1) == front_map[s1[0] - 'a'].end())  front_map[s1[0] - 'a'].insert({ s1,0 });
        front_map[s1[0] - 'a'][s1]++;
        if (back_map[s2[0] - 'a'].find(s2) == back_map[s2[0] - 'a'].end()) back_map[s2[0] - 'a'].insert({ s2,0 });
        back_map[s2[0] - 'a'][s2]++;
    }
}
void front_put(char c) { //앞에 넣을때, 즉 역방향일때
    string s1(1, c);
    string s2(1, c);
    int len = str.size() - 1;
    //정방향
    if (front_map[s1[0] - 'a'].find(s1) == front_map[s1[0] - 'a'].end())
        front_map[s1[0] - 'a'].insert({ s1,0 });
    front_map[s1[0] - 'a'][s1]++;
    //역방향
    if (back_map[s2[0] - 'a'].find(s2) == back_map[s2[0] - 'a'].end())
        back_map[s2[0] - 'a'].insert({ s2,0 });
    back_map[s2[0] - 'a'][s2]++;
    for (int i = 0; i <= len; i++) {
        if (i == 3) break; //이전 세 개의 문자만 보면됨
        string temp(1, str[i]);
        s1 = s1+temp;
        s2 = temp+s2;
        if (front_map[s1[0] - 'a'].find(s1) == front_map[s1[0] - 'a'].end())  front_map[s1[0] - 'a'].insert({ s1,0 });
        front_map[s1[0] - 'a'][s1]++;
        if (back_map[s2[0] - 'a'].find(s2) == back_map[s2[0] - 'a'].end()) back_map[s2[0] - 'a'].insert({ s2,0 });
        back_map[s2[0] - 'a'][s2]++;
    }
}
void front_pop(char c) { //앞에서 뺄때, 역방향일떄
    string s1(1, c);
    string s2(1, c);
    int end = str.size() - 1;
    front_map[s1[0] - 'a'][s1]--;
    back_map[s2[0] - 'a'][s2]--;
    for (int i = 0; i <= end; i++) {
        if (i == 3) break;
        string temp(1,str[i]);
        s1 = s1 + temp;
        s2 = temp + s2;
        front_map[s1[0] - 'a'][s1]--;
        back_map[s2[0] - 'a'][s2]--;
    }
}
void back_pop(char c) { //정방향일때
    string s1(1, c);
    string s2(1, c);
    int end = str.size() - 1;
    front_map[s1[0] - 'a'][s1]--;
    back_map[s2[0] - 'a'][s2]--;
    for (int i = 0; i <= end; i++) {
        if (i == 3) break;
        string temp(1, str[end-i]);
        s1 = temp + s1;
        s2 = s2 + temp;
        front_map[s1[0] - 'a'][s1]--;
        back_map[s2[0] - 'a'][s2]--;
    }
}
//문자열은 deq 로 관리 
void init(char mainStr[]) {
    str.clear();
    way=0; // 0 정방향 1 역방향
    for (int i = 0; i < 26; i++) {
        front_map[i].clear();
        back_map[i].clear();
    }
    int len = strlen(mainStr) - 1;
    for (int i = 0; i <= len; i++) {
        back_put(mainStr[i]);
        str.push_back(mainStr[i]);
    }
}

//4길이를 넣으면 16번 실행
//3만번 호출 -> 50만.. 가능
void pushBack(char newStr[]) {
    for (int i = 0; i < strlen(newStr); i++) {
        if (way == 0) { //정방향
            back_put(newStr[i]);
            str.push_back(newStr[i]);
        }
        else {
            front_put(newStr[i]);
            str.push_front(newStr[i]);
        }
    }
}

//100번, 15만 번제거, 1번 제거당 4log15만=80 번, 6000만 가능
void popBack(int n) {
    int len = str.size() - 1;
    for (int i = 0; i < n; i++) {
        if (way == 0) {
            char c = str[len - i];
            str.pop_back();
            back_pop(c);
        }
        else { //역방향
            char c = str[0];
            str.pop_front();
            front_pop(c);
        }
    }
}

//앞뒤만 바꿔줌 3만번
void reverseStr() {
    if (way == 0) way = 1;
    else way = 0;
}

//unodered_map으로 관리 3만
//거꾸로 된 map도 관리 3만
int getCount(char subStr[]) {
    int ans;


    if (way == 0) {
        if (front_map[subStr[0]-'a'].find(subStr) == front_map[subStr[0]-'a'].end())
            return 0;
        ans = front_map[subStr[0]-'a'][subStr];
    }
    else {
        if (back_map[subStr[0]-'a'].find(subStr) == back_map[subStr[0]-'a'].end())
            return 0;
        ans = back_map[subStr[0]-'a'][subStr];
    }
    return ans;
}