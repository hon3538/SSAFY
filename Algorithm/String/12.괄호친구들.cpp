#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int cal(string s){
    int ret=0;
    int tail;

    for(int i=0;i<s.length();i++){
        if(s[i]=='['){
            tail=s.find(']',i+1);
            ret+=stoi(s.substr(i+1,tail-i-1));
            i=tail;    
        }else if(s[i]=='{'){
            tail=s.find('}',i+1);
            ret*=stoi(s.substr(i+1,tail-i-1));
            i=tail;
        }
    }
    return ret;
}

int main(){
    string s;
    cin>>s;
    cout<<cal(s);
    return 0;
}