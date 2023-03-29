//한번 막대 던질때마다 미네랄이 떨어지는지 확인
//floodfill 로 확인
//떨어지면 새맵으로 update
//현재 맵을 clone하고
#include <iostream>
using namespace std;
int R,C;
int N;
int map[100][100];

void remove(int isLeft,int height){
    if(isLeft%2==0){
        int x=0;
        while(x<N){
            if(map[height][x]=='x'){
                map[height][x]='.';
                break;
            }
            x++;
        }
    }else{
        int x=N-1;
        while(x>=0){
            if(map[height][x]=='x'){
                map[height][x]='.';
                break;
            }
            x--;
        }
    }
}
int main(){
    cin>>R>>C;
    for(int y=0;y<R;y++){
        for(int x=0;x<C;x++){
            cin>>map[y][x];
        }
    }
    cin>>N;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        remove(i,n);
    }
    return 0;
}