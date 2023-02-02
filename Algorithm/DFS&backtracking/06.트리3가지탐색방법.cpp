#include <iostream>
#include <vector>

using namespace std;
// 1번 패턴 - 후위 탐색
// A의 왼쪽에 연결된 장식들이 켜집니다.
// A가 켜집니다.
// A의 오른쪽에 연결된 장식들이 켜집니다.
// 2번 패턴 - 전위 탐색
// A가 켜집니다.
// A의 왼쪽에 연결된 장식들이 켜집니다.
// A의 오른쪽에 연결된 장식들이 켜집니다.
// 3번 패턴 - 후위 탐색
// A의 왼쪽에 연결된 장식들이 켜집니다.
// A의 오른쪽에 연결된 장식들이 켜집니다.
// A가 켜집니다. 

vector<int>map[1001];
vector<int>rule[3];

int visited[1001];
void dfs(int now){
    if(now==-1||visited[now]==1)
        return;
    visited[now]=1;
    int next;
    
    rule[1].push_back(now); //왼 -> 오, 전위탐색
    //왼쪽
    next=map[now][0];
    dfs(next);

    rule[0].push_back(now); // 왼 -> 중앙 -> 오, 후위탐색

    //오른쪽 
    next=map[now][1];
    dfs(next);

    rule[2].push_back(now); // 왼 -> 오 -> 중앙, 후위탐색
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int from,left,right;
        cin>>from>>left>>right;
        map[from].push_back(left);
        map[from].push_back(right);
    }
    dfs(1);
    for(int i=0;i<3;i++){
        for(int j=0;j<rule[i].size();j++){
            cout<<rule[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}