#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Req {
	int requetedTime; //요청 시간
	int p; //제품
	int l; //라인
	int e; //장비
	int term; //시간
}r[20001];
int num;
unordered_map<int, Req*>pld_list; //제품아이디 -> 정보
unordered_map<int, int> State; //제품아이디-> 상태저장
queue<Req*>waitList[500]; //상품 번호 저장
int t_line[500]; // 제품이 가동중인 시간
Req* p_line[500]; // 각 라인의 가동중인 제품 
int equip[500]; //장비사용 끝나는 시간

int l_cnt;
int e_cnt;
//생산라인 500개
//서로다른 장비 수 500
void init(int L, int M) {
	l_cnt = L;
	e_cnt = M;
}

void update(int time) {
	//각 공장 라인 최신화
	for (int i = 0; i < l_cnt; i++) {
		while (!waitList[i].empty()) {
			Req *next = waitList[i].front();
			//아직 생산중이면
			if (time < t_line[i]) break;
			//장비 사용 불가능하면
			if (equip[next->e] > time) break;

			waitList[i].pop();
			if (t_line[i] < next->requetedTime) {
				t_line[i] = next->requetedTime + next->term;
			}
			else {
				t_line[i] += next->term;
			}

			if (equip[next->e] < next->requetedTime) {
				equip[next->e] = next->requetedTime + next->term;
			}
			else {
				equip[next->e] += next->term;
			}
			if (p_line[i]!=NULL) { //처음이면, 생산 리스트가 없으므로 제외
				State[p_line[i]->p] = 3; //완료
			}
			p_line[i] = next;
			State[next->p] = 2;
		}
	}
}

//2만호출
int request(int tStamp, int pld, int mLine, int eld, int mTime) {
	//mLine에서 생산 중인 제품의 ID를 반환
	//없는 경우 -1
	r[num] = { tStamp,pld,mLine,eld,mTime };
	waitList[mLine].push(&r[num]);
	State.insert({ pld,1 });
	pld_list.insert({ pld,&r[num] });
	num++;
	update(tStamp);
	if (t_line[mLine] <= tStamp) return -1;
	return p_line[mLine]->p;
}
//2만호출
int status(int tStamp, int pld) {
	update(tStamp);
	if (State.find(pld) == State.end()) return 0;
	return State[pld];
}


