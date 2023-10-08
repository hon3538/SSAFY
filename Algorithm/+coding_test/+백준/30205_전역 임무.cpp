/*
각 기지에서 아이템과 적군을 따로 분리하여 관리한다 
500(기지수)*500(아이템 적군 분리를 위한 완전탐색) = 25만

적군은 가장 낮은 애부터 잡는 것이 유리하므로 sorting 한다 
500*(기지수)*500log500(sort) = 250만
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500
int N, M;
long long P; //적군 기지 수, 각 기지의 층수, 김병장의 전투력
int item_cnt[MAX]; // 각 기지의 아이템 수
vector<int> enemy[MAX]; // 각 기지의 적군 파워 -> sort 필요

bool cmp(int a, int b){
    return a<b;
}
int main(){
    cin>>N>>M>>P;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int input;
            cin>>input;
            if(input==-1){
                item_cnt[i]++;
            }else{
                enemy[i].push_back(input);
            }
        }
    }
    //sort
    for(int i=0; i<N; i++){
        sort(enemy[i].begin(), enemy[i].end(), cmp);
    }
    //check
    int ans = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<enemy[i].size(); j++){
            while(enemy[i][j]>P){
                if(item_cnt[i]==0){
                    ans = 0;
                    break;
                }
                item_cnt[i]--;
                P *= 2;
            }
            if(ans == 0) break;
            P += enemy[i][j];
        }
        while(item_cnt[i]>0){
            item_cnt[i]--;
            P *= 2;
        }
        // cout<<i<<" order power : "<< P<<'\n';
        if(ans == 0) break;
    }
    cout<<ans;
    return 0;
}
/*
엣지 케이스
입력이 최소로 들어오는 경우
1. 기지수 1, 각 기지 층수 1, 
*/