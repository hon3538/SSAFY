#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;



int main(){
    for(int i=0;i<5;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
//swap(map[y][1],map[y][3]) -> string library
    for(int y=0;y<5;y++){
        int temp=v[y][3];
        v[y][3]=v[y][1];
        v[y][1]=temp;
    }
    int flag =false;
    for(int i=0;i<5;i++){
        if(v[i]=="MAPOM"){
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"yes";
    else cout<<"no";
    return 0;
}