
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Person {
	int point;
	int job;
	int id; // 고객 id
	int t; //기차 칸
}p[100001];
struct cmp {
	bool operator()(int a, int b)const {
		if (p[a].point == p[b].point) return p[a].id < p[b].id;
		return p[a].point > p[b].point;
	}
};
map<int, Person*, cmp>train[10]; //0~9 , key :pid, value person*
vector<Person*> jobs[1000]; //0~999, index :jid, value person*

int p_total; // 총 사람 수
int p_unit; // 한칸당 사람 수
void init(int N, int M, int J, int Point[], int JobID[])
{
	for (int i = 0; i < 10; i++) {
		train[i].clear();
	}
	for (int i = 0; i < 1000; i++) {
		jobs[i].clear();
	}
	p_total = N;
	p_unit = M;
	//N명 탑승객 , M명씩 열차 탑승 , 열차 최대 10칸
	for (int i = 0; i < N; i++) {
		p[i] = { Point[i],JobID[i],i,i / M };
		train[i / M].insert({ i,&p[i] });
		jobs[JobID[i]].push_back(&p[i]);
	}
}

void destroy()
{
	return;
}

int update(int uID, int Point)
{
	train[p[uID].t].erase(uID);
	p[uID].point += Point;
	train[p[uID].t].insert({ uID,&p[uID] });

	return p[uID].point;
}

int updateByJob(int JobID, int Point)
{
	//호출 300 * 인원 200 * 재정렬(log10000 + log10000) = 약 100만
	int sum = 0;
	for (int i = 0; i < jobs[JobID].size(); i++) {
		Person* pp = jobs[JobID][i];
		sum += update(pp->id, Point);
	}
	return sum;
}

int move(int num)
{
	//num 최대 5명
	queue<int> front[10];
	queue<int> back[10];

	int total = p_total / p_unit; // 객차 개수
	int ans = 0; //이동한 사람들의 포인트 합
	for (int i = 0; i < total; i++) {
		//첫번째는 제외
		if (i != 0) {
			//앞부분 앞에 보낼 것 저장
			for (int n = 0; n < num; n++) {
				front[i].push(train[i].begin()->first);
				train[i].erase(train[i].begin()->first);
			}
		}
		//마지막 제외
		if (i != total - 1) {
			//뒷부분 뒤에 보내기
			for (int n = 0; n < num; n++) {
				auto it = train[i].end();
				--it;
				back[i].push(it->first);
				train[i].erase(it->first);
			}
		}
	}
	for (int i = 0; i < total; i++) {
		//첫번째는 제외
		if (i != 0) {
			for (int n = 0; n < num; n++) {
				int now = front[i].front();
				front[i].pop();
				p[now].t = i - 1;
				ans += p[now].point;
				train[i - 1].insert({ now,&p[now] });
			}
		}
		//마지막 제외
		if (i != total - 1) {
			for (int n = 0; n < num; n++) {
				int now = back[i].front();
				back[i].pop();
				p[now].t = i + 1;
				ans += p[now].point;
				train[i + 1].insert({ now,&p[now] });
			}
		}
	}
	return ans;
}