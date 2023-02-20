#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//시작시간 관계없이 end가 빠른순으로 회의실을 배정한다.
int N;
struct schedule{
    int start;
    int end;
};
bool cmp(schedule left,schedule right){
    if(left.end==right.end){
        return left.start<right.start;
    }
    return left.end<right.end;
}
vector<schedule>v;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=0;
    int end=0;
    for(int i=0;i<N;i++){
        if(v[i].start<end)
            continue;
        end=v[i].end;
        cnt++;
    }
    cout<<cnt;
    return 0;
}