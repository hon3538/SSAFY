#include <iostream>
#include <string>

using namespace std;
// 1. OK���� �Ⱦ��ϴ� �ܾ� "bad", "no", "puck" �� ����� �� -> find
// 2. �������� ����� "_"�� �� 5�� ���� -> find
// 3. �� ���ĺ��� ��� Ƚ���� 5ȸ ���� (��ҹ��� ����) -> DAT
// 4. ���ڰ� ����� ��

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