//������� Ű�� ��ȣ�� �Է¹ް�
//Ű�� ū ������� ������ȣ���� Ȯ��
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <cstring>
using namespace std;
int DAT[1000001] = { 0 }; // index : Ű��, value : height 
int h[1000001] = { 0 };
int num[1000001] = { 0 };
int main() {
    int T;
    cin >> T;
    vector<string>res;
    //������� Ű�� �Է¹ް�
    //Ű�� ū ������� 0���� ���, ������� �켱������ ���� Ű
    //�Է� ���� ������� Ű�� ��еƴ��� Ȯ��
    for (int t = 0; t < T; t++) {
        memset(DAT, 0, sizeof(DAT));
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
        for (int i = 0; i < N; i++) {
            DAT[num[i]] = h[i];
        }
        int before = INT_MAX;
        int flag = true;
        for (int i = 1; i <= N; i++) {
            if (DAT[i] > before) {
                flag = false;
                break;
            }
            before = DAT[i];
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
