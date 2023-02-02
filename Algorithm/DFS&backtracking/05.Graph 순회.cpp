#include <iostream>
#include <vector>
using namespace std;


int map[101][101];
int visited[101];
vector<int>pre;
vector<int>post;
void dfs(int now){


    for(int i=0;i<101;i++){
        int to =map[now][i];
        if(visited[to]==1)
            continue;
        visited[to]=1;
        pre.push_back(to);
        dfs(to);
        post.push_back(to);

        //visited[to]=0;
    }

//전위 순회

//후위 순회
}
int main(){
    int N,K,S;
    cin>>N>>K>>S;
    
    for(int i=0;i<K;i++){
        int from,to;
        cin>>from>>to;
        map[from][to]=1;
    }
    dfs(S);
    for(int i=0;i<pre.size();i++)
        cout<<pre[i];
    for(int i=0;i<post.size();i++)
        cout<<pre[i];
}