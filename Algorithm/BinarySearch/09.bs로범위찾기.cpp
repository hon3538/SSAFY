#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//two 포인터 활용 -> qeury 가 너무 많음..
int N, Q; //광물수, 연구원 수
//binary search로 앞과 뒤를 찾음
struct Info {
    int left;
    int right;
};
vector<int>v; //광물강도
vector<Info>p; //연구원이 원하는 범위 list
int bs1(int target) { //start 지점 찾기
    int left = 0;
    int right = N-1;
    int ans = 21e8;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] >= target) {
            right = mid - 1;
            ans = mid;
        }else {
            left = mid + 1;
        }
    }
    return ans;
}
int bs2(int target) { //end 지점 찾기
    int left = 0;
    int right = N-1;
    int ans=-21e8;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] <= target) {
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }   
    }
    return ans;
}
int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back({ a,b });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < Q; i++) {
        int left = bs1(p[i].left);
        int right = bs2(p[i].right);
       // cout << left << ' ' << right;
        
        if (left > right)
            cout << 0 << '\n';
        else
        cout << right- left+1 << '\n';
    }
    return 0;
}
/*
29 1
201427251 -824504127 -400487798 -114373664 3203925 -467784277 556057451 34827406 -439803154 399365014 -736588689 343558686 -587378750 3409502 765625511 422124006 344749071 375911904 -255555944 164079444 475209669 -953573395 -737119837 30512216 -330004429 -505251400 -439420189 -816963768 -765805248
870482910 933299402
30

정답 0
*/