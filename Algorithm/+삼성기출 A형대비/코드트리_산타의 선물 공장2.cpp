//쿼리 10만개
//벨트 10만개
//선물 10만개

#include <iostream>
#include <vector>
using namespace std;
int q;
int n,m; //벨트 개수(1~), 선물 개수(1~)
vector<int>belt[100001];
void factory(){ //공장 설립
    for(int i=1;i<=m;i++){
        int s;
        cin>>s;
        belt[s].push_back(i);   
    }
}
int main(){
    cin>>q;
    for(int i=0;i<q;i++){  //쿼리
        int command;
        cin>>command;
        if(command==100){ //공장설립
            cin>>n>>m;
            factory();
        }else if(command==200){//물건 모두 옮기기
        //a벨트의 모든 선물을 b벨트 앞으로 옮기고 b벨트 선물 개수 출력
            
        }else if(command==300){//앞 물건만 교체하기
        //a벨트 앞 선물과 b벨트 앞 선물 교체, 없으면 옮기기만,
        //b벨트 선물 개수 출력

        }else if(command==400){//물건 나누기
        //a벨트 선물 개수=n 일때, n/2  번째까지의 모든 선물을 b벨트 앞으로 옮김
        //b벨트의 선물 개수 출력

        }else if(command==500){//선물 정보 얻기
        //선물 번호가 주어질 때 앞번호와 뒷번호를 구해라

        }else if(command==600){//벨트 정보 얻기
        //벨트 번호가 주어질때 맨앞 선물과 맨뒤 선물을 구해라
        }

    }

    return 0;
}