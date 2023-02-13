#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Set{
    int n;
    char c;
    bool operator < (Set next) const{
        if(n<next.n)return false;
        if(n>next.n)return true;
        if(n==next.n){
            if(c<next.c) return false;
            if(c>next.c) return true;
        }
        return false;
    }
};

int main(){
    int N;
    cin>>N;
    int n;
    char c;
    priority_queue<Set>pq;
    for(int i=0;i<N;i++){
        cin>>n>>c;
        pq.push({n,c});
    }
    
    while(!pq.empty()){
        Set temp=pq.top();
        pq.pop();
        cout<<temp.n<<" "<<temp.c<<'\n';
    }
    return 0;
}