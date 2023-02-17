#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int>v;
vector<int>k;
char bs(int left,int right,int target){

    while(left<=right){ //left==right==mid 가 될때가 마지막 탐색이 된다
        int mid=(left+right)/2;
        if(target==v[mid]){
            return 'O';
        }
        else if(target>v[mid]){
            left=mid+1;
        }else if(target<v[mid]){
            right=mid-1;
        }
    }
    return 'X';
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        k.push_back(a);        
    }
    int size=k.size();
    sort(v.begin(),v.end());
    
    for(int i=0;i<size;i++){
        cout<<bs(0,v.size(),k[i]);
    }

    return 0;
}