#include <iostream>
#include <vector>
using namespace std;
//각 팀 구성에서 headsum의 최댓값이 가장 작은 팀 구성은?
// headsum의 최대값 즉, Max값이 마지노석이 된다. Max 값을 움직여서 
// 조건을 만족시키는지 확인한다.
int N, T;
vector<int>brain;

int condition(int target) { //팀이 같거나 많이 나오면 true, 팀이 적게 나오면 false;
    //팀이 많이 나온다 -> target이 작다 
    //팀이 적게 나온다 -> target이 크다
    int team;
    for (int start = 0; start < N; start++) {
        int sum = 0;
        team = 1;
        for (int i = 0; i < N; i++) {
            if (brain[(start + i) % N] > target) //원소하나가 target 보다 커버리면 팀구성 자체가 불가능
                return 0;
            int check = sum + brain[(start + i) % N];
            if (check <= target) {
                sum += brain[(start + i) % N];
                continue;
            }
            sum = brain[(start + i) % N];
            team++;
        }
        if (team == T) { //가능
            return 1;
        }
    }
    if (team > T)
        return 0; //팀이 더 많으므로 target 값이 더 크다
    else return -1; // 팀이 적으므로 target 값이 더 작다
}
/* 예를 들어 T=3 으로 주어진다면
교수님은 해당 target에서 나올 수 있는 팀 구성이 가작 작은 경우를 return했다
target보다 낮은 팀이 3개도 있고 2개도 존재할 수 있다. 하지만 가장 target이 낮을 때를 구하는 것이 관건이다.
따라서 2개의 팀을 구할 수 있다는 것은 target을 더 낮춰서 딱 3개의 팀이 나올 수 있는 경우를 구할 수 있다는 것을 의미한다
해당 target으로 구할 수 있는 팀이 딱 3개로만 이루어져 있는 경우를 구해야되고, 
target을 계속 낮춰가며 3개팀으로도 구성이 안 될 때까지 반복한다.
최솟값이 4개팀이 되기 직전! 즉 마지막 3개팀으로 만들 수 있는 경우가 마지노선이 된다.
*/


int ps(int max) {
    int left = 0;
    int right = max;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int res = condition(mid);
        if (res == 1) {
            ans = mid;
            right = mid - 1;
        }
        else if (res == 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}
int main() {
    cin >> N >> T;
    int Max = 0;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        brain.push_back(n);
        Max += n;
    }

    cout << ps(Max);
    return 0;
}
/*
#include <iostream>
using namespace std;

int n, t;
int arr[501];
int total = 0;
int maxval = -1;

int maketeam(int val) {
    int team = 2134567890;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int cnt = 1;
        for(int j = i; j < i + n; j++) {
            if(sum + arr[j%n] <= val)
                sum += arr[j % n];
            else {
                sum = arr[j % n];
                cnt++; // 팀 추가
            }
        }
        if (cnt < team) // 최소한의 팀 -> 합이 제일 클 것
            team = cnt;
    }
    return team;
}

int binarysearch() {

    // left -> t==n일때 최대값 (max)
    // right -> t==1일때 값 (total)
    int left = maxval;
    int right = total;
    int ans;
    while (left <= right) {
        int mid = (left + right) / 2; // 팀의 능력치 기준값
        int team = maketeam(mid);
        if (team > t)
            left = mid + 1;
        else {
            right = mid - 1;
            ans = mid;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > maxval)
            maxval = arr[i];
        total += arr[i];
    }
    cout << binarysearch();
}
*/