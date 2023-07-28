#include <iostream>
#include <vector>
using namespace std;

vector<int> cows; //소들의 z점
vector<int> horse; //말들의 z점

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int N, M; //소의 수, 말의 수
        cin>>N>>M;
        int c1, c2; //소의 x위치, 말의 x위치
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
    }

    return 0;
}