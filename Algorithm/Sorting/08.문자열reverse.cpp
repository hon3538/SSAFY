#include <iostream>
#include <string>
#include <algorithm> // reverse
using namespace std;


int main(){
    int P,N;
    cin>>P>>N;

    for(int i=0;i<N;i++){
        P*=2;
        string s=to_string(P);
        reverse(s.begin(),s.end());
        P=stoi(s);
    }
    cout<<P;
    return 0;
}
/* 구현도 가능
void reverse(string& str)
{
	string temp;
	int n = str.length();

	for (int i = n - 1; i >= 0; i--) {
		temp += str[i];
	}

	str = temp;
}

*/