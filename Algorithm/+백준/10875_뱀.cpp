//1000개 의 선 n^2
// 100만 개

// 선의 시작점과 끝점을 저장
// 겹치는지, 바깥으로 나가는지 확인

#include <iostream>
#include <vector>
using namespace std;
int L, N; // L : 맵크기, N : 회전 횟수
struct Line {
	int s_y, s_x; //시작좌표
	int e_y, e_x; //끝 좌표
};
vector<Line> v;

int isPossible(int order) {
	int by2, sy2, bx2, sx2;
	if (v[order].e_y > v[order].s_y) {
		by2 = v[order].e_y;
		sy2 = v[order].s_y;
	}
	else {
		by2 = v[order].s_y;
		sy2 = v[order].e_y;
	}
	if (v[order].e_x > v[order].s_x) {
		bx2 = v[order].e_x;
		sx2 = v[order].s_x;
	}
	else {
		bx2 = v[order].s_x;
		sx2 = v[order].e_x;
	}
	//order 이전 까지 선과 다 비교
	for (int i = 0; i < order; i++) {
		int by, sy, bx, sx;
		if (v[i].e_y > v[i].s_y) {
			by = v[i].e_y;
			sy = v[i].s_y;
		}
		else {
			by = v[i].s_y;
			sy = v[i].e_y;
		}
		if (v[i].e_x > v[i].s_x) {
			bx = v[i].e_x;
			sx = v[i].s_x;
		}
		else {
			bx = v[i].s_x;
			sx = v[i].e_x;
		}
		// y 좌표가 이전 y범위안에 포함되고
		// x좌표 범위안에 이전 x좌표가 포함되면 포함되는거 ㅋ
		if (sy <= v[order].e_y&&v[order].e_y <= by) {
			if (sx2 <= v[i].e_x&&v[i].e_x <= bx2) {
				return 0;
			}
		}
		// x좌표가 이전 x범위 안에 포함되고
		// y좌표 범위안에 이전 y좌표가 포함되면 포함되는거 ㅋ
		if (sx <= v[order].e_x&&v[order].e_x <= bx) {
			if (sy2 <= v[i].e_y&&v[i].e_y <= by2) {
				return 0;
			}
		}
	}
	return 1;
}
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
void findEnd(int d, int t, int *y, int *x) {
	*y = *y + dir[d][0] * t;
	*x = *x + dir[d][1] * t;
}
int main() {
	cin >> L >> N;
	int d = 1; //위부터 시계방향으로
	int dy = 0;
	int dx = 0;
	for (int i = 0; i < N; i++) {
		int t; // 이 시간만큼 현재 방향으로 가고
		char b; // 다음방향을 b로 틀어라
		cin >> t >> b;
		v.push_back({ dy,dx }); //시작지점 set
		findEnd(d, t,&dy, &dx);
		v[i].e_y = dy;
		v[i].e_x = dx;
		if (b == 'R') d = (d + 1) % 4;
		else d = (d + 3) % 4;
	}

	for (int i = 0; i < N; i++) {
		//현재선이 바깥을 나가는지?
		if (v[i].e_y > L || v[i].e_x > L || v[i].e_y < L*(-1) || v[i].e_x < L*(-1)) {

		}
		//이 선이 그려질 수 있는가?
		if (isPossible(i)) {

		}
	}
	return 0;
}
