#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//문자열을 노드로,,, 해쉬? 
//나중에 다꺼내서 vector에 넣고 노드순으로 돌린다. 노드 -> 스트링으로 다시 바꿔준다.
int N;
int parent[100001];
struct Node{
    string s;
    int node;
};
vector<string>ans;
bool cmp2(string o1,string o2){
    return o1<o2;
}
vector<Node>res;

bool cmp(Node o1,Node o2){
    return o1.node<o2.node;
}
int Find(int now){
    if(now==parent[now])
        return now;

    return parent[now]=Find(parent[now]);
}
void Union(int A,int B){
    int pa=Find(A);
    int pb=Find(B);
    if(pa==pb)
        return;
    parent[pb]=pa;
}
int main(){
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
    cin>>N;
    int node=0;
    unordered_map<string,int>um;
   
    for(int i=0;i<N;i++){
        string a,b;
        cin>>a>>b;
        if(um.find(a)==um.end()){ //없다면
            um.insert({a,node++});
        }
        if(um.find(b)==um.end()){ //없다면
            um.insert({b,node++});
        }
        int A=um[a]; int B=um[b];
        if(Find(A)==Find(B)){ //같은 그룹이라면
            continue;
        }
        Union(A,B);
    }
    string s;
    cin>>s;
    int target=um[s];

    for(auto it=um.begin();it!=um.end();it++){
        res.push_back({it->first,it->second});
    }
    //부모 같은것들만 찾아서 ans vector에 담고 사전순 정렬
    for(int i=0;i<res.size();i++){
        if(Find(res[i].node)==Find(target))
            ans.push_back(res[i].s);
    }
    sort(ans.begin(),ans.end(),cmp2);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<'\n';
    return 0;
}
