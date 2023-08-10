#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Size, m, n;
vector<int> mList;
vector<int> nList;

vector<int> mSum;
vector<int> nSum;

vector<int> mSumList;
int nDAT[1000001];

void getSum() {
	mSum.push_back(mList[0]);
	nSum.push_back(nList[0]);
	for (int i = 1; i < 2*m; i++) {
		mSum.push_back(mSum[(i - 1)] + mList[i%m]);
	}
	for (int i = 1; i < 2*n; i++) {
		nSum.push_back(nSum[i - 1] + nList[i%n]);
	}
}
void getSumList() {
	for (int i = 1; i < m; i++) { //크기가 1 인 구간부터 m-1인 구간까지 모든 합
		for (int j = 0; j < m; j++) {
			mSumList.push_back(mSum[j + i] - mSum[j]);
		}
	}
	mSumList.push_back(mSum[m - 1]);
	for (int i = 1; i < n; i++) { //크기가 1 인 구간부터 m인 구간까지 모든 합
		for (int j = 0; j < n; j++) {
			nDAT[nSum[j + i] - nSum[j]]++;
		}
	}
	nDAT[nSum[n - 1]]++;
}
int getAns() { //A피자의 크기가 들어올때 가능한 모든 경우 리턴
	int ans = 0;
	
	for (int i = 0; i < mSumList.size(); i++) {
		if (Size < mSumList[i]) continue;
		if (Size == mSumList[i]) {
			ans++;
			continue;
		}
		int target = Size - mSumList[i];
		ans += nDAT[target];
	}
	ans += nDAT[Size];
	return ans;
}
int main() {
	cin >> Size >> m >> n;
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		mList.push_back(input);
	}
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		nList.push_back(input);
	}
	getSum();
	getSumList();
	int ret =getAns();
	cout << ret;

	return 0;
}