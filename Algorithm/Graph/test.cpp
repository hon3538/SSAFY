#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string>res;
    //순서대로 키를 입력받고
    //키를 큰 순서대로 0부터 배분, 같을경우 우선순위가 낮은 키
    //입력 받은 순서대로 키가 배분됐는지 확인

    for (int t = 0; t < T; t++) {
        int DAT[251] = { 0 }; // index : 키, value : 키 번호
        int N;
        cin >> N;
        int key = 1;
        vector<int>student(N);
        vector<int>ans(N);
        for (int i = 0; i < N; i++) {
            int height;
            cin >> height;
            student[i] = height;
            DAT[height]++;
        }

        for (int i = 250; i >= 0;i--) {
            if (DAT[i] == 0)
                continue;
            
            for (int j = 0; j < N; j++) {
                if (student[j] == i) {
                    ans[j] = key++;
                }
            }
       }
        
             int flag=true;
            for(int i=0;i<N;i++){
                 int input;
                 cin>>input;
                 if(input!=ans[i]){
                     flag=false;
                     break;
                 }
            }
            if(!flag)
                 res.push_back("NO");
             else res.push_back("YES");
    }

     for(int i=0;i<T;i++){
         cout<<res[i]<<'\n';
     }
    return 0;
}
