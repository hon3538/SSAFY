#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


struct cmp{
    bool operator()(string s1,string s2){
        //길이순 오름차순
        if(s1.size()>s2.size())return true;
        if(s1.size()<s2.size())return false;
        if(s1.size()==s2.size()){
            //사전순 오름차순
            if(s1>s2) return true;
            if(s1<s2) return false;
        }
        return false;
    }
};
int main(){
    int n;
    cin>>n;
    priority_queue<string,vector<string>,cmp>pq;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        pq.push(s);
    }

    while(!pq.empty()){

        cout<<pq.top()<<'\n';
        pq.pop();
    }
    return 0;
}