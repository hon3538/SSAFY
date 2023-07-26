/*
규칙찾아보자
4 9
5 8
3 10
6 7
1 12
2 11
4 9
5 8
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int,int> um;
vector<int> min_value;
void getCycle(int a, int b, int k){
    int cnt=0;
    while(cnt<k){
        int m=min(a,b);
        if(um.find(m)!=um.end()) return;
        um.insert({m,cnt});
        min_value.push_back(m);
        cnt++; 
    }
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int A,B,K;
        um.clear();

        getCycle(A,B,K);
        int cycle = um.size();
        int index= K%cycle;
        cout<<'#'<<t<<' '<<index<<'\n';
    }

    return 0;
}