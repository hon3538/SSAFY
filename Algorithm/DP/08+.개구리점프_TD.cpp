#include <iostream>

using namespace std;
//Top down으로 풀거임
//재귀 branch는 방향
//기저조건은 map==0 이거나 범위 벗어났거나
//DP는 min으로 초기화
//초기값
int H,W;
int map[1001][1001];
int DP[1001][1001]; // index는 좌표, value 는 해당 좌표에서 최댓값
int dir[3][2]={1,-1,1,0,1,1};
int func(int y,int x){
    if(y<0||x<0||y>=H||x>=W)
        return -21e8;
    if(y==H-1)
        return map[y][x];
    if(DP[y][x]!=0)
        return DP[y][x];

    int Max=-21e8;
    for(int i=0;i<3;i++){
        int dy=y+dir[i][0];
        int dx=x+dir[i][1];
        if(dy<0||dx<0||dy>=H||dx>=W)
            continue;
        if(map[dy][dx]==0)
            continue;
        int ret=func(dy,dx);
        if(Max<ret)
            Max=ret;
    }
    return DP[y][x]=Max+map[y][x];
}
int main(){
    cin>>H>>W;
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            cin>>map[y][x];
        }
    }
    cout<<func(0,0);
    return 0;
}