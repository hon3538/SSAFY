#include <iostream>
#include <vector>
using namespace std;
//숫자 string이 주어짐 -> length /4  -> 각변에 위치한 16진수 개수
//왼쪽부터 높은자리이다.
//string length /4 가 각 변의 16진수 개수이다. 즉 length/4 -1 번 돌려서
//나올 수 있는 모든 숫자들을 중복없이 저장하고 내림차순 정렬한다.
//16 -> 10진수 변환 함수
//내림차순
int N,K; //총 16진수 개수, K 번째로 큰수 출력 
vector<char>v;
int toTen[200]; //index 16진수 -> 10진수

void move(){
    v.push_back(v[0]);
    v.erase(v.begin());
}
int getNum(int start){// start 부터 N/4-1까지
    int unit=1;
    int sum=0;
    for(int i=N/4-1;i>=0;i--){
        sum+=toTen[v[start+i]]*unit;
        unit*=16;
        //cout<<sum<<' '<<v[start+i]<<'\n';
    }
    return sum;
}
int main(){
    int T;
    cin>>T;
    for(char i='A';i<='F';i++){
        toTen[i]=i-'A'+10;
    }
    for(char i='0';i<='9';i++){
        toTen[i]=i-'0';
    }
    for(int t=0;t<T;t++){
        cin>>N>>K;
        for(int i=0;i<N;i++){
            char c;
            cin>>c;
            v.push_back(c);
        }
        // for(int i=0;i<4;i++){ // 4변 숫자
        //     int num=getNum(i*(N/4))
        // }
        cout<<getNum(0);
        /*
            1F71F71F71F7
        */
    }

    return 0;;
}