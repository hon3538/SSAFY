#include <iostream>
#include <string>
using namespace std;

int sum;
string N;
void recur(int now){

    //�������� index ==end?
    if(now==N.length())
        return;

    sum+=N[now]-'0';
    //level -> index, branch x;
    recur(now+1);
}
int main(){
    cin>>N;

    recur(0);
    cout<<sum;
    return 0;
}