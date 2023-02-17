#include <iostream>
#include <vector>
using namespace std;
//마지노선을 조리시간 T
//매점마다 특정 조리시간 동안 만들 수 있는 음식을 더해나가고
//끝에 음식 수가 사람 수만큼 만들 수 있으면 true
long long N; // 매점 개수, 관객수
long long M;
vector<long long>T;

bool condition(long long target) {
    long long size = T.size();
    long long cnt = 0;
    for (int i = 0; i < size; i++) {
        cnt+= target / T[i];
    }
    if (M <= cnt) {
        return true;
    }
    else return false;
}
int ps(long long left, long long right) {
    long long ans = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (condition(mid)) { //시간이 넉넉하다
            //좀 줄여도 된다
            right = mid - 1;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}
int main() {
    cin >> N >> M;
    long long Min = 21e8;
    for (int i = 0; i < N; i++) {
        long long t;
        cin >> t;
        if (Min > t)
           Min = t;
        T.push_back(t);
    }

    //최대조리시간은 한 가게에만 모든 사람이 줄섰을때
    //가장 조리시간이 적은 한 가게에 모든 사람이 줄선것이 최대 조리시간이 될것이다..
    //조리시간이 긴곳에 줄슬 이유가 없음..
    //long long maxTime=Max*M; 
    cout << ps(0, Min*M);
    return 0;
}