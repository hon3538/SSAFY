#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> cows; //소들의 z점
vector<int> horse; //말들의 z점
int N, M; //소의 수, 말의 수
int c1, c2; //소의 x위치, 말의 x위치
bool cmp(int left, int right){
    return left <= right;
}
int getDit(int z1, int z2){
    return sqrt(pow(z1-z2,2)+pow(c1-c2,2));
}
int ps(int target, int left, int right){
    int ans=2100000000;

    while(left<=right){
        int mid = (left+right) / 2;

        if(cows[target] <= horse[mid]){
            if(ans > horse[mid]-cows[target]){
                ans = horse[mid] - cows[target];
            }
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N>>M;
        cin>>c1>>c2; 
        for(int i=0;i<N;i++){
            int z;
            cin>>z;
            cows.push_back(z);
        }
        for(int i=0;i<M;i++){
            int z;
            cin>>z;
            horse.push_back(z);
        }
        //정렬
        sort(cows.begin(), cows.end(), cmp);
        sort(horse.begin(), horse.end(), cmp);
        
        int cnt=0;
        int mid_dit=210000000;
        for(int i=0;i<=N;i++){
            //소를 기준으로 
            int ret = ps(i,0,M-1);
            if(mid_dit==ret) cnt++;
            if(mid_dit>ret){
                cnt=1;
                mid_dit=ret;
            }
        }
        int ans = sqrt(pow(ans,2)+pow(c1-c2,2));
        cout<<'#'<<t<<' '<<ans<<' '<<cnt<<'\n';
    }

    return 0;
}