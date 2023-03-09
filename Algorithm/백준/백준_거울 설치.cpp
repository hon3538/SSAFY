//50 * 50
//* 불가
//# 입구 2개 반대편으로 가야함
//! 거울이 설치될 수 있는자리
//visited로 각 방향에서 들어오는 것을 체크
//같은 방향으로 들어오면 중복이므로 return
//다른 입구에 도착했을 때 거울 count
//dfs ? bfs ?
//bfs

#include <iostream>
using namespace std;
int N;
int map[50][50];
int bfs(){
    int ans;
    
}
int main(){
    cin>>N;
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            cin>>map[y][x];
        }
    }
    

}