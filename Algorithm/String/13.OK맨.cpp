#include <iostream>
#include <string>

using namespace std;
// 1. OK맨이 싫어하는 단어 "bad", "no", "puck" 가 없어야 함 -> find
// 2. 연속적인 언더바 "_"가 총 5개 이하 -> find
// 3. 각 알파벳들 사용 횟수가 5회 이하 (대소문자 구분) -> DAT
// 4. 숫자가 없어야 함

int DAT[200];
string hate[4]={"bad","no","puck","_____"};
int isValid(string s){
    //1 & 2
    for(int i=0;i<4;i++){
        if(s.find(hate[i])!=-1)
            return 0;
    }
    //3 & 4
    for(int i=0;i<s.length();i++){
        if(s[i]=='_')
            continue;
        if(DAT[s[i]]>=5||(s[i]>='0'&&s[i]<='9'))
            return 0;
        DAT[s[i]]++;
    }
    return 1;
}
int main(){
    string s;
    cin>>s;
    if(isValid(s)){
        cout<<"pass";
    }else
        cout<<"fail";
    return 0;
}