/*
문자열 하나 주어짐 -> 최대길이 400

부분문자열 400 -> 400 + 399 + 398...+1

400*(1+400)/2 => 80000개 
80000 순서대로 정렬
첫번쨰 부분문자열이 
6억 4천 -> 1억 연산 1초 -> 6초 60초 

400 번연산 -> 문자열 한번 비교

->> xxxx

구해야 K번쨰 문자열
8만개를 정렬 -> r

-> x
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define MAX_SIZE 401
class Trie{
public:
    char c;
    int cnt;
    unordered_map<char, Trie*> children;

    Trie(){
        c='\0';
        cnt=0;
    }
};
string s;
int len;
int makeTrie(Trie* now, int index){
    int cnt = 0; //자식 새로 생김?
    if(now->children.find(s[index])==now->children.end()){
        Trie* newNode = new Trie();
        cnt++; 
        now->children.insert({s[index], newNode});
    }
    
    if(index==len){
        now->cnt+=cnt;
        return cnt;
    }
    int ret = makeTrie(now->children[s[index]],index+1); //손주들 새로생긴 개수
    now->cnt+=(ret+cnt); // 자식 + 손주들 새로생긴 개수
    return ret+cnt;
}
char ans[MAX_SIZE];
void dfs(Trie* now, int depth, int K){

    for(char i='a';i<='z';i++){
        if(now->children.find(i)==now->children.end()) continue;
        if(now->children[i]->cnt<K){
            K-=now->children[i]->cnt;
            continue;
        }
        ans[depth]=i;
        dfs(now->children[i],depth+1, K);
        break;
    }
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int K;
        cin>>K;
        cin>>s;
        len=s.length();
        Trie* head = new Trie();
        //trie 구성 -> 재귀로 구성        
        for(int i=0;i<len;i++){
            makeTrie(head,i);
        }
        //K번째 찾기
        dfs(head, 0,  K);
        cout<<'#'<<t<<' '<<ans<<'\n';
    }

    return 0;
}