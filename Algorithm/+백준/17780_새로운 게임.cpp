#include <iostream>
#include <vector>
using namespace std;
int N, K;
int map[12][12];
int status[12][12][3]; // 맨 밑과 맨 위 정보, 몇 개 있는지?
int sum = 0; //합쳐지면 ++
struct Node {
	int y, x;
	int d;
};
vector<Node>v;
int dir[4][2] = { 0,1,0,-1,-1,0,1,0 }; // ->, <-, 위, 아래
void update(int ny, int nx, int n) {
	int bottom = status[v[n].y][v[n].x][0];
	int top = status[v[n].y][v[n].x][1];
	if (status[ny][nx][0] == 0) { //갈 칸에 암것도 없으면
		status[ny][nx][0] = bottom;
	}

	status[ny][nx][1] = top;
	status[ny][nx][2] += status[v[n].y][v[n].x][2];
	if(sum<status[ny][nx][2])
		sum = status[ny][nx][2];
	status[v[n].y][v[n].x][0] = 0;
	status[v[n].y][v[n].x][1] = 0;
	status[v[n].y][v[n].x][2] = 0;
	v[top].y = ny;
	v[top].x = nx;
	v[bottom].y = ny;
	v[bottom].x = nx;
}
void deb() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << '(' << status[y][x][0] << ',' << status[y][x][1] << ") ";
		}
		cout << '\n';
	}
}
void red(int dy, int dx, int i) {
	//누구 있으면 나의 첫번째껄 마지막에
	int bottom = status[v[i].y][v[i].x][0];
	int top = status[v[i].y][v[i].x][1];
	if (status[dy][dx][0] != 0) {
		status[dy][dx][1] = bottom;
	}
	else {//없으면 내껄 뒤집어서
		status[dy][dx][0] = top;
		status[dy][dx][1] = bottom;

	}
	status[dy][dx][2] += status[v[i].y][v[i].x][2];
	if (sum < status[dy][dx][2])
		sum = status[dy][dx][2];
	status[v[i].y][v[i].x][0] = 0;
	status[v[i].y][v[i].x][1] = 0;
	status[v[i].y][v[i].x][2] = 0;
	v[bottom].y = dy;
	v[bottom].x = dx;
	v[top].y = dy;
	v[top].x = dx;
}
int run() {
	int turn = 0;
	//0 흰 1빨 2파
	while (turn <= 1000) {
		turn++;
		// deb();
		// cout << '\n';
		for (int i = 1; i <= K; i++) { //1~K번말 한번씩 이  
			if (status[v[i].y][v[i].x][0] != i) continue;
			int dy = v[i].y + dir[v[i].d][0];
			int dx = v[i].x + dir[v[i].d][1];
			int revDir;
			if (v[i].d <= 1) revDir = (v[i].d + 1) % 2;
			else revDir = (v[i].d + 1) % 2 + 2;
			if ((dy < 0 || dx < 0 || dy >= N || dx >= N) || map[dy][dx] == 2) {
				dy = v[i].y + dir[revDir][0];
				dx = v[i].x + dir[revDir][1];
				v[i].d = revDir;
				if ((dy < 0 || dx < 0 || dy >= N || dx >= N) || map[dy][dx] == 2) {
					continue;
				}
				else if (map[dy][dx] == 1) {
					red(dy, dx, i);
				}
				else {
					update(dy, dx, i);
				}
			}
			else if (map[dy][dx] == 0) { // 흰색인경우, 딴게 있으면 끝값만 바꾸고 없으면 ㄱㄱ
				update(dy, dx, i);
			}
			else if (map[dy][dx] == 1) { //빨간색이면,
				red(dy, dx, i);
			}
			// deb();
			// cout << '\n';

		}
		if (sum >= 4)
			break;
	}
	if (turn > 1000) return -1;
	return turn;
}
int main() {
	cin >> N >> K;
	//map 입력
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	v.push_back({ 0,0,0 }); // 예외처리, index 1부터 시작하기 위함
	//말 정보 입력
	for (int i = 1; i <= K; i++) {
		int y, x, d; //y,x, 방향
		cin >> y >> x >> d; //y,x 는 1부터시작
		v.push_back({ y - 1,x - 1,d - 1 });
		status[y - 1][x - 1][0] = i;
		status[y - 1][x - 1][1] = i;
		status[y - 1][x - 1][2] = 1;
	}

	cout << run();
	return 0;
}