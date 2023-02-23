#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
//접수 창구 -> 정비창구
//각 직원은 업무 처리시간이 다름
//고객은 먼저온 순서대로(입력받은 순)으로 접수한다 (자리가없을경우 기다림)
//접수창구 및 정비창구는 번호가 작은 곳 우선
//정비는 먼저 접수 끝난순서대로, 동시에 끝날경우 접수 창구가 작은 순으로
//각 사람의 접수와 정비 창구를 구하고 지갑분실한 사람과 같은 경우 번호를 더해서 출력
//각 번호는 1번부터 시작했다! 나중에 -1씩 해주기

int N, M, K, A, B; //접수 창구수, 정비 창구수, 고객수, 지갑분실고객 접수창구, 정비창구
struct Person {
    int time;
    int rec; //번호
    int rep; //번호
    int order; //고객번호
};
vector<int>rec; // rec의 업무시간
vector<int>rep; // rep의 업무시간
int endRec[10]; //각 창구의 업무끝나는 시간, 이 시간부터 이용 가능하다.
int endRep[10];
vector<Person>p;
bool cmp(Person o1, Person o2) {
    if (o1.time == o2.time)
        return o1.rec < o2.rec; //동시에 나올경우 접수창구 번호 낮은 순서로
    return o1.time < o2.time; //더빨리 끝나는 순으로
}
//각 창구는 끝나는 시각으로 업데이트
//각 창구를 일찍끝나는 순서로 업데이트 -> greedy?
void func() {
    //접수
    for (int i = 0; i < K; i++) {
        int flag = false; // 창구가 꽉차있는지 확인해서 가장 빨리 끝나는 창구를 업데이트
        int fast = 21e8;
        int num; // 해당 창구 번호
        for (int j = 0; j < N; j++) {
            if (endRec[j] <= p[i].time) { //창구 끝나는 시간이 사람 도착시간 이하면 비어있는거
                p[i].time += rec[j]; //이 사람의 업무끝나는 시각
                endRec[j] = p[i].time;
                p[i].rec = j;
                flag = true;
                break; //업무 봤으면 다음 창구 안 가도됨
            }
            if (endRec[j] < fast) {
                fast = endRec[j];
                num = j;
            }
        }
        if (!flag) { // 아무 창구도 못갔으면 
            p[i].time = fast + rec[num];
            endRec[num] = p[i].time;
            p[i].rec = num; //접수 창구 번호
        }
       // cout<<'\n'<<"번호:"<<i<<" 창구:"<<p[i].rec<<" 끝시간:"<<p[i].time;
    }
    //끝나는 순서대로 sort
    sort(p.begin(), p.end(), cmp);
    //정비
    for (int i = 0; i < K; i++) {
        int flag = false; // 창구가 꽉차있는지 확인해서 가장 빨리 끝나는 창구를 업데이트
        int fast = 21e8;
        int num; // 해당 창구 번호
        for (int j = 0; j < M; j++) {
            if (endRep[j] <= p[i].time) { //창구 끝나는 시간이 사람 도착시간 이하면 비어있는거
                p[i].time += rep[j]; //이 사람의 업무끝나는 시각
                endRep[j] = p[i].time;
                p[i].rep = j;
                flag = true;
                break; //업무 봤으면 다음 창구 안 가도됨
            }
            if (endRep[j] < fast) {
                fast = endRep[j];
                num = j;
            }
        }
        if (!flag) { // 아무 창구도 못갔으면 
            p[i].time = fast + rep[num];
            endRep[num] = p[i].time;
            p[i].rep = num; //접수 창구 번호
        }
       // cout<<'\n'<<p[i].time;
    }

}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M >> K >> A >> B;
        rec.clear();
        rep.clear();
        p.clear();

        memset(endRec, 0, sizeof(endRec));
        memset(endRep, 0, sizeof(endRep));

        for (int i = 0; i < N; i++) { //접수직원 업무시간
            int a;
            cin >> a;
            rec.push_back(a);
        }
        for (int i = 0; i < M; i++) { //정비직원 업무시간 
            int a;
            cin >> a;
            rep.push_back(a);
        }
        for (int i = 0; i < K; i++) { //고객이 도착한 시간
            int a;
            cin >> a;
            p.push_back({ a,-1,-1,i + 1 });
        }
        func();
        int sum = 0;
        for (int i = 0; i < K; i++) {
            if (p[i].rec == A - 1 && p[i].rep == B - 1) {
                sum += p[i].order;
            }
        }
        if (sum == 0)
            sum = -1;
        cout << '#' << t + 1 << ' ' << sum << '\n';
    }

    return 0;
}
/*
10
1 1 2 1 1
5
7
7 10
2 2 6 1 2
3 2
4 2
0 0 1 2 3 4
2 1 4 2 1
2 5
1
0 1 3 10
4 1 10 3 1
4 6 4 8
1
0 3 4 4 5 6 9 9 9 10
2 2 8 2 1
10 3
2 9
0 2 3 3 4 6 6 7
3 2 10 1 2
5 5 8
3 5
0 0 4 7 8 8 9 9 10 10
4 2 30 4 2
3 2 2 10
2 6
0 2 2 4 5 6 7 9 9 15 15 16 17 18 18 19 19 22 23 24 24 24 25 25 25 26 27 27 28 29
5 2 70 5 1
6 6 6 4 5
5 6
0 0 0 1 1 5 6 8 10 12 12 14 15 15 17 17 18 18 19 19 22 24 26 26 28 30 30 31 32 32 32 33 33 33 34 35 35 35 37 38 40 40 41 42 46 46 47 48 48 51 53 54 55 56 56 57 59 60 61 61 63 63 64 65 65 66 67 67 70 70
4 3 100 1 3
9 9 5 2
8 7 8
0 3 5 6 10 12 13 14 15 15 19 19 20 20 21 22 22 23 23 26 26 26 26 30 31 33 33 35 36 39 39 39 40 40 41 41 42 43 43 45 47 48 49 50 50 51 51 51 51 51 52 54 58 58 59 60 60 60 60 61 61 62 62 63 63 66 69 69 69 70 71 72 73 73 74 75 76 76 79 81 82 82 82 85 87 87 88 91 91 91 94 94 96 96 96 98 98 99 99 100
5 3 100 1 1
9 10 3 5 3
8 8 10
0 0 0 0 1 1 3 3 4 5 7 8 8 9 9 11 11 13 14 15 16 17 17 18 19 19 22 22 23 23 25 26 26 27 27 30 30 34 34 36 36 38 41 44 44 45 45 47 47 49 50 50 51 53 53 58 61 62 62 63 64 65 67 67 69 70 72 73 75 76 77 80 80 80 81 81 83 83 83 84 87 87 89 89 89 90 90 91 92 93 93 93 93 95 95 98 99 100 100 100
*/