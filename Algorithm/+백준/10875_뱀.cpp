//https://cantcoding.tistory.com/12
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, N; // map의 크기, 회전 수
int nowDir = 1; //현재 dir

struct Node {
	int y;
	int x;
};
struct Line {
	Node s;
	Node e;
	int hv; //0 : h, 1 : v;
	int length;
};
vector<Line>v;
int ccw(Node A, Node B, Node C) {
	int a = A.x*B.y + B.x*C.y + C.x*A.y;
	int b = A.y*B.x + B.y*C.x + C.y*A.x;
	return a - b;
}
int dir[4][2] = { -1,0,0,1,1,0,0,-1 }; //위부터 시계방향
Node getEnd(Node from,int t) {
	int y = from.y + dir[nowDir][0] * t;
	int x = from.x + dir[nowDir][1] * t;
	return { y,x };
}
int ans = 0;
int isPossible(int order) {
	for(int i = 0; i < order - 1; i++) {
		int a, b,c,d;
		a= ccw(v[order].s, v[order].e, v[i].e);
		b= ccw(v[order].s, v[order].e, v[i].s);
		c= ccw(v[i].s, v[i].e, v[order].e);
		d= ccw(v[i].s, v[i].e, v[order].s);
		if (a+b==-4||a+b==4||c+d==4||c+d==-4) { // 안 겹친다
			continue;
		}
		if (a==0&&b==0&&c==0&&d==0) { //일자일때
			int bx = max(v[i].e.x, v[i].s.x);
			int sx = min(v[i].e.x, v[i].s.x);
			int by = max(v[i].e.y, v[i].s.y);
			int sy = min(v[i].e.y, v[i].s.y);

			if (v[i].hv == 0 && sx <= v[order].e.x <= bx) {//horizontal
				int ret = min(abs(sx - v[order].s.x), abs(bx - v[order].s.x));
				return ret;
			}
			if (v[i].hv == 1 && sy <= v[order].e.y <= by) {//vertical
				int ret = min(abs(sy - v[order].s.y), abs(by - v[order].s.y));
				return ret;
			}
			continue;
		}
		if (a + b == 0 || c + d == 0) { //교차
			if (v[order].hv == 0) {
				int ret = abs(v[i].e.x - v[order].s.x);
				return ret;
			}
			if (v[order].hv == 1) {
				int ret = abs(v[i].e.y - v[order].s.y);
				return ret;
			}
		}
		return -1; //-1일때는 t 그대로 더하기 -> 직교
	}
	return -2; // 이상없음
}
int main() {
	cin >> L >> N;
	Node point = { 0,0 };
	for (int i = 0; i < N; i++) {
		int t;
		char d;
		cin >> t >> d;
		v.push_back({ point,point,0 });
		Node End = getEnd(point, t);
		v[i].e = End;
		if (point.y == End.y) v[i].hv = 1;
		else v[i].hv = 0;
		point.y = End.y;
		point.x = End.x;
		if (d == 'R') nowDir = (nowDir + 1) % 4;
		else nowDir = (nowDir + 3) % 4;
		v[i].length = t;
	}

	for (int i = 0; i < N; i++) {

		if (v[i].e.y < L*(-1)) {
			ans += abs(v[i].s.y - (L*(-1))) + 1;
			break;
		}
		if (v[i].e.y > L) {
			ans += abs(v[i].s.y - L) + 1;
			break;
		}
		if (v[i].e.x < L*(-1)) {
			ans += abs(v[i].s.x - (L*(-1))) + 1;
			break;
		}
		if (v[i].e.x > L) {
			ans += abs(v[i].s.x - L) + 1;
			break;
		}

		int ret = isPossible(i);
		if (ret == -2) {//이상없음
			ans += v[i].length;
			continue;
		}
		if (ret == -1) { //직교
			ans += v[i].length;
			break;
		}
		ans += ret; //교차
		break;
	}
	cout << ans;
	return 0;
}