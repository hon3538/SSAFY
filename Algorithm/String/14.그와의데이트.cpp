#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string s;

int main(){
    
    cin>>s;
    int size=s.length();
    int tail=-1;
    int idx;
    
    int res=1;
    
    if(s[6]=='.'){
        if(s[5]=='X')
            res*=9;
        
    }else if(s[6]=='X'){
        if(s[5]=='X'){
            res*=3;
        }
    }

    if(s[size-1]=='X'){
        if(s[size-2]=='X'){
            res*=31;
        }else if(s[size-2]!='3'){
            res*=10;
        }else{
            res*2;
        }
    }else {
        if(s[size-2]=='X'){
            if(s[size-1]<=1)
                res*=3;
            else
                res*=2;    
        }
    }
    cout<<res;
    return 0;
}
/*
#include <iostream>
#include <string>
using namespace std;

int isPossible(string tar, string xx)
{
	if (tar.length() != xx.length()) return 0;
	
	//X가 아니라 숫자인데, 똑같은 값이 아니면 탈락
	if (xx[0] != 'X' && xx[0] != tar[0]) return 0;	
	if (tar.length() == 1) return 1;

	if (xx[1] != 'X' && xx[1] != tar[1]) return 0;
	return 1;
}

int getMon(string mon)
{
	int cnt = 0;
	for (int i = 1; i <= 12; i++) {
		string tar = to_string(i);
		cnt += isPossible(tar, mon);
	}
	return cnt;
}

int getDay(string day)
{
	int cnt = 0;
	for (int i = 1; i <= 31; i++) {
		string tar = to_string(i);
		cnt += isPossible(tar, day);
	}
	return cnt;
}

int main()
{
	string mon, day;
	string input;

	cin >> input;
	//input = "2025.X.1X";
	
	int dot = input.find('.', 5);
	mon = input.substr(5, dot - 4 - 1);
	day = input.substr(dot + 1);

	int a = getMon(mon);
	int b = getDay(day);
	cout << a * b;

	return 0;
}
*/