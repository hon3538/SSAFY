#include <iostream>

using namespace std;

int cnt;

void dfs(int num){
    //���� -> 1�ΰ�?
    if(num==1){
        return;
    }
    if(num%2==0){
        num/=2;
    }else num=num*3+1;
    cnt++;
    dfs(num);
}
int main(){
    int n;
    cin>>n;

    dfs(n);
    cout<<cnt;
    return 0;
}