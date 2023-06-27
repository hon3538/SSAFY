//팀으로 dll array 만들고
//각 팀안에서 평판점수로 그룹화(dll)

#include <iostream>
using namespace std;

#define TEAM_CNT 6
#define SCORE_GROUP_CNT 6
#define ID_CNT 100001
//Soldier Node 생성 
struct Soldier {
	int mid;
	int mTeam;
	Soldier* prev;
	Soldier* next;
};
//soldier memory pool
Soldier memory_pool[ID_CNT];

//team 연결리스트 생성
class TeamDLL {
	Soldier head[SCORE_GROUP_CNT];
	Soldier tail[SCORE_GROUP_CNT];
	
public:
	TeamDLL() = default;
	void init() {
		for (int i = 1; i < SCORE_GROUP_CNT; i++) {
			head[i].next = &tail[i];
			tail[i].prev = &head[i];
		}
	}
	void _addNode(Soldier* target,int mID) {
		//새 노드 연결
		memory_pool[mID].next = target->next;
		memory_pool[mID].prev = target;
		//기존 연결 해제
		target->next->prev = &memory_pool[mID];
		target->next = &memory_pool[mID];
	}
	void addNode(int mID, int mScore, int mTeam) {//hire
		//mScore 그룹의 맨뒤에 노드 추가
		memory_pool[mID].mid = mID;
		memory_pool[mID].mTeam = mTeam;
		_addNode(tail[mScore].prev, mID);
	}
	void delNode(int mID) { //fire
		memory_pool[mID].next->prev = memory_pool[mID].prev;
		memory_pool[mID].prev->next = memory_pool[mID].next;
	}
	void updateNode(int mID,int mScore){
		delNode(mID);
		addNode(mID, mScore,memory_pool[mID].mTeam);
	}
	void moveAll(int from, int to) {
		if (from == to) return;
		//from 그룹의 head를 to 그룹의 맨뒤에 연결
		tail[to].prev->next = head[from].next;
		head[from].next->prev = tail[to].prev;
		//from 그룹의 맨 마지막노드를 to 그룹의 tail과 연결
		tail[to].prev = tail[from].prev;
		tail[from].prev->next = &tail[to];
		//from 그룹의 head, tail 연결
		head[from].next = &tail[from];
		tail[from].prev = &head[from];
	}
	int getBest() {
		//평판점수가 가장 높은 병사의 고유 번호 반환
		int best=-1;
		for (int i = SCORE_GROUP_CNT-1; i > 0;i--) {
			if (head[i].next == &tail[i]) continue;
			
			Soldier* now = &head[i];
			while (now->next != &tail[i]) {
				now = now->next;
				if (best < now->mid) {
					best = now->mid;
				}
			}
			return best;
		}
	}
	/*void printAll() {
		for (int i = 1; i < 6; i++) {
			cout << "평가점수 그룹: " << i << '\n';
			Soldier* nowNode = &head[i];
			while (nowNode->next != &tail[i]) {
				nowNode = nowNode->next;
				cout << nowNode->mid<<' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}*/
}teams[6];

/*void debugging() {
	for (int i = 1; i < 6; i++) {
		cout << "Team 번호 :" << i << '\n';
		teams[i].printAll();
	}
}*/
void init() {
	for (int i = 1; i < 6; i++) {
		teams[i].init();
	}
}
//10만
void hire(int mID, int mTeam, int mScore) {
	teams[mTeam].addNode(mID, mScore,mTeam);
}
//10만
void fire(int mID) {
	int team = memory_pool[mID].mTeam;
	teams[team].delNode(mID);
}
//10만
void updateSoldier(int mID, int mScore) {
	int team = memory_pool[mID].mTeam;
	teams[team].updateNode(mID, mScore);
}
//10만
void updateTeam(int mTeam, int mChangeScore) {
	//mChange가 양수일 경우
	if (mChangeScore >= 0) {
		for (int i = SCORE_GROUP_CNT - 1; i > 0; i--) {
			int to = i + mChangeScore;
			if (to > SCORE_GROUP_CNT - 1) to = SCORE_GROUP_CNT - 1;
			teams[mTeam].moveAll(i, to);
		}
	}
	else { //mChangeScore 가 음수일 경우
		for (int i = 1; i <SCORE_GROUP_CNT; i++) {
			int to = i + mChangeScore;
			if (to < 1) to = 1;
			teams[mTeam].moveAll(i, to);
		}
	}
}
//100
int bestSoldier(int mTeam) {
	return teams[mTeam].getBest();
}
/*
문제 설명]

병사들을 관리하는 프로그램을 작성하고자 한다.

병사들은 각각 고유번호, 소속팀, 평판 점수를 가지고 있다.

프로그램은 아래의 기능들을 수행할 수 있어야 한다.

병사 고용
병사 해고
병사의 평판 점수 변경
특정 팀에 속한 병사들의 평판 점수를 일괄 변경
특정 팀 안에서 가장 평판 점수가 높은 병사를 검색
아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 Java에 대해서는 제공되는 Solution.java와 UserSolution.java를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init()

각 테스트 케이스의 처음에 호출된다.

테스트 케이스의 시작 시 고용된 병사는 없다.

void hire(int mID, int mTeam, int mScore)

고유번호가 mID, 소속팀이 mTeam, 평판 점수가 mScore인 병사를 고용한다.

한 테스트 케이스 내에서 동일한 mID를 가진 병사가 여러 번 고용되는 경우는 없음이 보장된다.

 

Parameters

mID : 고유번호 (1 ≤ mID ≤ 100,000)

mTeam : 소속팀 (1 ≤ mTeam ≤ 5)

mScore : 평판 점수 (1 ≤ mScore ≤ 5)

void fire(int mID)

고유번호가 mID인 병사를 해고한다.

fire() 함수 호출 시, 고유번호가 mID인 병사가 고용되어 있음이 보장된다.

 

Parameters

mID : 고유번호 (1 ≤ mID ≤ 100,000)

void updateSoldier(int mID, int mScore)

고유번호가 mID인 병사의 평판 점수를 mScore로 변경한다.

고유번호가 mID인 병사가 고용되어 있음이 보장된다.

 

Parameters

mID : 고유번호 (1 ≤ mID ≤ 100,000)

mScore : 평판 점수 (1 ≤ mScore ≤ 5)

void updateTeam(int mTeam, int mChangeScore)

소속팀이 mTeam인 병사들의 평판 점수를 모두 변경한다.

소속팀이 mTeam인 병사가 한 명 이상 고용되어 있음이 보장된다.

 

updateTeam() 함수에서의 평판 점수 변경은 아래의 규칙에 따른다.

‘변경 전 평판 점수 + mChangeScore’가 5보다 클 경우, 평판 점수를 5로 변경한다.

‘변경 전 평판 점수 + mChangeScore’가 1보다 작을 경우, 평판 점수를 1로 변경한다.

그 외의 경우, 평판 점수를 ‘변경 전 평판 점수 + mChangeScore’로 변경한다.

 

Parameters

mTeam : 소속팀 (1 ≤ mTeam ≤ 5)

mChangeScore : 평판 점수의 변화량 (-4 ≤ mChangeScore ≤ 4)

int bestSoldier(int mTeam)

소속팀이 mTeam인 병사들 중 평판 점수가 가장 높은 병사의 고유번호를 반환한다.

평판 점수가 가장 높은 병사가 여러 명일 경우, 고유번호가 가장 큰 병사의 고유번호를 반환한다.

소속팀이 mTeam인 병사가 한 명 이상 고용되어 있음이 보장된다.

 

Parameters

mTeam : 소속팀 (1 ≤ mTeam ≤ 5)

 

Returns

평판 점수가 가장 높은 병사의 고유번호

 

[예제]
*/