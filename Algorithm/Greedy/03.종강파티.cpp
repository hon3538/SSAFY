#include <iostream>
#include <algorithm>

using namespace std;
int N,M; // 사람 수 , 마트 수
int set[50]; //6병세트 가격
int one[50]; //한병당 가격
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>set[i]>>one[i];
    }
    sort(set,set+M);
    sort(one,one+M);

    int setCnt=N/6;
    int notSet=N%6;
    int sum=0;
    if(set[0]<one[0]*6){
        sum+=setCnt*set[0];
        if(set[0]<one[0]*notSet)
            sum+=set[0];
        else sum+=one[0]*notSet;
    }else{
        sum=N*one[0];
    }
    cout<<sum;
    return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, m; 
int six = 2134567890;
int one = 2134567890;

int main() {
	cin >> n >> m;
	// 입력을 받으면서 6팩의 가격이 가장 싼 곳과, 낱개가 가장 싼 곳을 찾음
	for (int i = 0; i < m; i++) {
		int sixcost, onecost; 
		cin >> sixcost >> onecost;
		if (sixcost < six)
			six = sixcost;
		if (onecost < one)
			one = onecost; 
	}

	// greedy : 싼거부터 
	
	// ** 만약 낱개 6개를 구입하는게 6팩을 구매하는거보다 싸다면 -> 낱개로만 구입
	if (one * 6 < six)
		cout << one * n; 

	else {
		// 일단 6팩으로 필요한만큼 구입
		int bought = n / 6; 
		// 이정도가 남음 (6개 이하)
		n %= 6;  

		// 낱개로 남은 개수를 사는게 더 비싸다면
		if (n * one > six) {
			// 6팩을 하나 더 구매
			bought++; 
			cout << bought * six; 
		}
		else {
			cout << bought * six + one * n; 
		}
	}
}
*/