#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
// 접수 창구 -> 정비창구
// 각 직원은 업무 처리시간이 다름
// 고객은 먼저온 순서대로(입력받은 순)으로 접수한다 (자리가없을경우 기다림)
// 접수창구 및 정비창구는 번호가 작은 곳 우선
// 정비는 먼저 접수 끝난순서대로, 동시에 끝날경우 접수 창구가 작은 순으로
// 각 사람의 접수와 정비 창구를 구하고 지갑분실한 사람과 같은 경우 번호를 더해서 출력
// 각 번호는 1번부터 시작했다! 나중에 -1씩 해주기

int N, M, K, A, B; // 접수 창구수, 정비 창구수, 고객수, 지갑분실고객 접수창구, 정비창구
struct Person
{
    int time;
    int rec;   // 번호
    int rep;   // 번호
    int order; // 고객번호
};
vector<int> workTime[2]; // 0:rec, 1:rep 업무시간
int End[2][10];          // 0: rec, 1:rep 각 창구의 업무끝나는 시간, 이 시간부터 이용 가능하다.

vector<Person> p;
bool cmp(Person o1, Person o2)
{
    if (o1.time == o2.time)
        return o1.rec < o2.rec; // 동시에 나올경우 접수창구 번호 낮은 순서로
    return o1.time < o2.time;   // 더빨리 끝나는 순으로
}
// 각 창구는 끝나는 시각으로 업데이트
// 각 창구를 일찍끝나는 순서로 업데이트 -> greedy?
void func()
{
    // 접수
    for (int k = 0; k < 2; k++) // 0 : 접수처, 1: 정비소
    {
        int order;
        int n;
        if (k == 0) n = N;
        else n = M;
        for (int i = 0; i < K; i++) // 고객마다
        {
            int flag = false; // 창구가 꽉차있는지 확인해서 가장 빨리 끝나는 창구를 업데이트
            int fast = 21e8;
            int num; // 해당 창구 번호
            for (int j = 0; j < n; j++) // 창구 순서
            {
                if (End[k][j] <= p[i].time)
                {                                // 창구 끝나는 시간이 사람 도착시간 이하면 비어있는거
                    p[i].time += workTime[k][j]; // 이 사람의 업무끝나는 시각
                    End[k][j] = p[i].time;
                    order = j;
                    flag = true;
                    break; // 업무 봤으면 다음 창구 안 가도됨
                }
                if (End[k][j] < fast)
                {
                    fast = End[k][j];
                    num = j;
                }
            }
            if (!flag)
            { // 아무 창구도 못갔으면
                p[i].time = fast + workTime[k][num];
                End[k][num] = p[i].time;
                order = num; // 접수 창구 번호
            }
            if (k == 0) p[i].rec = order;
            else p[i].rep = order;
        }
        // 끝나는 순서대로 sort
        if(k==0)
            sort(p.begin(), p.end(), cmp);
    }
}
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> M >> K >> A >> B;

        p.clear();
        memset(workTime, 0, sizeof(workTime));
        memset(End, 0, sizeof(End));


        for (int i = 0; i < N; i++)
        { // 접수직원 업무시간
            int a;
            cin >> a;
            workTime[0].push_back(a);
        }
        for (int i = 0; i < M; i++)
        { // 정비직원 업무시간
            int a;
            cin >> a;
            workTime[1].push_back(a);
        }
        for (int i = 0; i < K; i++)
        { // 고객이 도착한 시간
            int a;
            cin >> a;
            p.push_back({ a, -1, -1, i + 1 });
        }
        func();
        int sum = 0;
        for (int i = 0; i < K; i++)
        {
            if (p[i].rec == A - 1 && p[i].rep == B - 1)
            {
                sum += p[i].order;
            }
        }
        if (sum == 0)
            sum = -1;
        cout << '#' << t + 1 << ' ' << sum << '\n';
    }

    return 0;
}
