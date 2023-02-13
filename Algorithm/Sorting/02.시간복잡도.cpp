#include <iostream>

using namespace std;

// 상수는 O(1)
// 여러 logN 은 N에서 단계가 지날때마다 반씩 줄어드는 경우 ex) 이분법


int ans[4]={21,2,2,2};
int main(){
    int n;
    cin>>n;
    cout<<ans[n-1];

    return 0;
}
/*
1번 소스코드

#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 10000; i++) {
		cout << "#";
	}

	return 0;
}


2번 소스코드

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x <= y; x++) {
			cout << "#";
		}
	}

	return 0;
}




3번 소스코드

#include <iostream>
using namespace std;
int n;
void abc()
{
	for (int i = 0; i < n; i++) {
		cout << "#";
	}
}

int main()
{
	cin >> n;
	for (int y = 0; y < n; y++) {
		abc();
		abc();
		abc();
	}
	
	return 0;
}




4번 소스코드

#include <iostream>
using namespace std;
int main()
{
	int n; 
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 5; x++) {
			for (int z = 0; z < n; z++) {
				cout << "#";
			}
		}
	}

	return 0;
}
*/