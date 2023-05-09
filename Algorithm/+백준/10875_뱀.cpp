//1000개 의 선 n^2
// 100만 개

// 선의 시작점과 끝점을 저장
// 겹치는지, 바깥으로 나가는지 확인

#include <iostream>
#include <vector>
using namespace std;
int L, N;
vector<int> t;
vector<char> d;


int isPossible(int order) { //해당선이 생길 수 있는지 ?
	
}

int main() {
	cin >> L >> N;
	for (int i = 0; i < N; i++) {
		int a;
		char b;
		cin >> a >> b;
		t.push_back(a);
		d.push_back(b);
	}
	
	return 0;
}
