#include <iostream>
using namespace std;
char map[3][3];

int DAT[26];
int team[26][26];
int p[26];
int main(){
    for(int y=0;y<3;y++){
        for(int x=0;x<3;x++){
            char c;
            cin>>c; 
            map[y][x]=c;
        }
    }

    for(int y=0;y<3;y++){
        int a=-1;
        int b=-1;
        int cnt=0;
        for(int x=0;x<3;x++){
            int num=(int)(map[y][x]-'A');
            DAT[num]++;
            if(a==-1){
                a=num;
            }
            if(a!=num)
                b=num;
            if(DAT[num]>1){
                cnt++;
            }
        }
        if(cnt==1){ // 두 사람

        }
        else if(cnt==2){ // 한 사람 

        }
    }

    return 0;
}