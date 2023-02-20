#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Score{
    int coding;
    int interview;
};
int N;
vector<Score>v;
bool cmp(Score left,Score right){
    if(left.coding==right.coding){
        return left.interview<right.interview;
    }
    return left.coding<right.coding;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-i-1;j++){
            if(v[N-1-i].coding>v[j].coding&&v[N-1-i].interview>v[j].interview){
                cnt++;
                break;
            }
        }
    }
    cout<<N-cnt;
    return 0;
}

/* 이게 정답인듯...
#include <iostream>
#include <algorithm>
using namespace std;

struct Cand {
	int coding;
	int interview;
};

bool cmp(Cand a, Cand b) {
	if (a.coding < b.coding)
		return true;
	if (a.coding > b.coding)
		return false;
	return false; 
}

int n;
Cand cands[100001]; 

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int coding, interview; 
		cin >> coding >> interview; 
		cands[i] = { coding, interview }; 
	}

	// 코딩 시험점수 우선 -> 정렬
	sort(cands, cands + n, cmp); 

	// 1등은 무조건 합격 
	int cnt = 1;
	int standard = cands[0].interview;
	for (int i = 1; i < n; i++) {
		// 만약 코테 1등의 점수보다 면접 등수가 높다면 (낮은게 높은것) 
		if (cands[i].interview < standard) {
			standard = cands[i].interview;
			// 한명이 더 합격했다!
			cnt++; 
		}
	}
	cout << cnt;
}
*/