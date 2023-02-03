#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cal(string s){
    int sum=0;
    if(s[0]!='-'){
        s='+'+s;
    }
    s+='+';
    int idx=0;
    for(int i=1;i<s.length();i++){
        if(!(s[i]>='0'&&s[i]<='9')){ //숫자가 아니면
            if(s[idx]=='-'){
                sum-=stoi(s.substr(idx+1,i-idx-1));
            }else{
                sum+=stoi(s.substr(idx+1,i-idx-1));
            }
            idx=i;
        }
    }
    return sum;
}
int main(){
    string str;
    cin>>str;
    
    cout<<cal(str);
    return 0;
}