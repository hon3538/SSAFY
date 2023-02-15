// 팀개수 DAT -> index: 그룹장, value=팀(1) or not(0)
// DAT[index]==1 이면 개인 1이상이면 팀
#include <iostream>

using namespace std;

int DAT[26];
int N;
int parent[26];
int Find(int now)
{
    if (parent[now] == now)
        return now;
    return parent[now] = Find(parent[now]);
}
void Union(int A, int B)
{
    int pa = Find(A);
    int pb = Find(B);
    if (pa == pb)
        return;
    parent[pb] = pa;
}
int main()
{
    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char a,b;
        cin>>a>>b;
        Union(a-'A',b-'A');
    }
    for(int i=0;i<26;i++){
        DAT[Find(i)]++;
    }
    int alone=0;
    int team=0;
   
    for(int i=0;i<26;i++){
        if(DAT[i]==1){
            alone++;
        }else if(DAT[i]>1){
            team++;
        }
    }
    cout<<team<<'\n'<<alone;
    return 0;
}