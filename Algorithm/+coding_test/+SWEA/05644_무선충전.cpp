//A 와 B의 이동경로가 주어졌을 때, 두 명의 충전한 양의 최댓값을 구하라
//충전 범위가 겹치면 하나 선택 (보통은 더 높은 성능으로 충전)
//한 배터리에 두명 들어오면 분배, 따라서 충전 범위가 겹칠 경우 BC1+BC2 로 
//따로 접속하는 게 이득

//배터리가 겹치는 맵은 어떻게 표현 ?
//맵 말고 사람의 좌표와 배터리 좌표를 비교하여 거리 안이면 해당 범위 내에 있는 것
//vector를 통해 배터리충전중인 사람 체크

//배터리 ~8개, 맵 10x10, 범위 ~4
//시간복잡도 2(사람)*100(최대시간) *8(배터리 수)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Battery {
	int y, x;
	int c;
	int p;
	int n;
};
struct Node {
	int y, x;
};
bool cmp(Battery o1, Battery o2) {
	return o1.p > o2.p;
}
int MT, BC;// 이동 시간, 배터리 개수
vector<int>A; // 이동 방향 벡터 0 이동x, 1상 2우 3하 4좌
vector<int>B;
Node AP; //현재 좌표
Node BP;
vector<Battery>bat;
int dir[5][2] = { 0,0,-1,0,0,1,1,0,0,-1 };

int func() {
	int ans = 0;
	AP = { 0,0 };
	BP = { 9,9 };
	vector<Battery>Apq;
	vector<Battery>Bpq;

	for (int i = 0; i <= MT; i++) {
		Apq.clear();
		Bpq.clear();
		//각 배터리간 거리 계산하여 범위내면 저장
		for (int j = 0; j < BC; j++) {
			int dit = abs(AP.y - bat[j].y) + abs(AP.x - bat[j].x);
			if (dit <= bat[j].c)
				Apq.push_back(bat[j]);
			dit = abs(BP.y - bat[j].y) + abs(BP.x - bat[j].x);
			if (dit <= bat[j].c)
				Bpq.push_back(bat[j]);
		}
		//성능순으로 충전량을 더한다, 서로 다른 충전기에 연결한다
		//분배되는것은 생각 안 해도 됨.
		//겹칠때는 ? A+B가 최대가 되도록하는..
		sort(Bpq.begin(), Bpq.end(), cmp);
		sort(Apq.begin(), Apq.end(), cmp);
		if (Apq.size() == 0 && Bpq.size() != 0) {
			ans += Bpq[0].p;
		}
		int max = 0;
		for (int a = 0; a < Apq.size(); a++) {
			int m = Apq[a].p;
			for (int b = 0; b < Bpq.size(); b++) {
				if (Apq[a].n == Bpq[b].n) //같은 배터리면 넘어가
					continue;
				if (Apq[a].p + Bpq[b].p > m)
					m = Apq[a].p + Bpq[b].p;
			}
			if (max < m)
				max = m;
		}
		ans += max;
		//한칸 씩 이동
		if (i == MT)
			break;
		AP.y += dir[A[i]][0];
		AP.x += dir[A[i]][1];
		BP.y += dir[B[i]][0];
		BP.x += dir[B[i]][1];
	}
	return ans;
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		//input
		cin >> MT >> BC;
		A.clear();
		B.clear();
		bat.clear();
		for (int i = 0; i < MT; i++) {
			int d;
			cin >> d;
			A.push_back(d);
		}
		for (int i = 0; i < MT; i++) {
			int d;
			cin >> d;
			B.push_back(d);
		}
		for (int i = 0; i < BC; i++) {
			int y, x, c, p; // 배터리 좌표, 범위, 충전량
			cin >> x >> y >> c >> p;
			bat.push_back({ y-1,x-1,c,p,i });
		}
		//구현
		cout <<'#'<<t+1<<' '<< func()<<'\n';

	}

	return 0;
}
