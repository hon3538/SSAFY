#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string>res;
    //������� Ű�� �Է¹ް�
    //Ű�� ū ������� 0���� ���, ������� �켱������ ���� Ű
    //�Է� ���� ������� Ű�� ��еƴ��� Ȯ��

    for (int t = 0; t < T; t++) {
        int DAT[251] = { 0 }; // index : Ű, value : Ű ��ȣ
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
