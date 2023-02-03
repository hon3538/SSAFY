#include <iostream>
#include <vector>

using namespace std;
// 1�� ���� - ���� Ž��
// A�� ���ʿ� ����� ��ĵ��� �����ϴ�.
// A�� �����ϴ�.
// A�� �����ʿ� ����� ��ĵ��� �����ϴ�.
// 2�� ���� - ���� Ž��
// A�� �����ϴ�.
// A�� ���ʿ� ����� ��ĵ��� �����ϴ�.
// A�� �����ʿ� ����� ��ĵ��� �����ϴ�.
// 3�� ���� - ���� Ž��
// A�� ���ʿ� ����� ��ĵ��� �����ϴ�.
// A�� �����ʿ� ����� ��ĵ��� �����ϴ�.
// A�� �����ϴ�. 

vector<int>map[1001];
vector<int>rule[3];

int visited[1001];
void dfs(int now){
    if(now==-1||visited[now]==1)
        return;
    visited[now]=1;
    int next;
    
    rule[1].push_back(now); //�� -> ��, ����Ž��
    //����
    next=map[now][0];
    dfs(next);

    rule[0].push_back(now); // �� -> �߾� -> ��, ����Ž��

    //������ 
    next=map[now][1];
    dfs(next);

    rule[2].push_back(now); // �� -> �� -> �߾�, ����Ž��
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