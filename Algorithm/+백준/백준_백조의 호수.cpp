
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int R, C;
char map[1500][1500];
int visited[1500][1500];
int Max;
struct NODE {
	int y, x;
	int c; //c-1 = 해당 위치를 며칠뒤에 갈 수 있는지?
	bool operator < (NODE o) const {
		return c > o.c;
	}
};
vector<NODE>point;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int dijkstra(int y, int x) {
	priority_queue<NODE>pq;
	visited[y][x] = 1;
	pq.push({ y,x,1 });
	int Max = -21e8;
	while (!pq.empty()) {
		NODE now = pq.top();
		pq.pop();
        if (Max < now.c)
			    Max = now.c;
		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			if (visited[dy][dx] != 0) continue;

			int next = now.c;
			if (map[dy][dx] == 'X') next++;
			if (map[dy][dx] == '.') next = 1;
            
            if (dy == point[1].y&&dx == point[1].x){
                if (Max < next)
			            Max = next;
                 return (Max - 1) / 2 + (Max - 1) % 2;
                 
            }
			visited[dy][dx] = next;
			pq.push({ dy,dx,next });
		}
	}
	return -1;
}
int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL); 
	cin >> R >> C;
	
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'L') {
				point.push_back({ y,x,1 }); //거위 위치
			}
		}
	}
	
		int ans=dijkstra(point[0].y, point[0].x);
	 if (ans == 0) //처음에 거위가 얼음위에있나..?
		ans = 1;
	 cout << ans;
	return 0;
}

/*

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int R, C;
char map[1500][1500];
int visited[1500][1500];
int Max;
struct NODE {
	int y, x;
	int c; //c-1 = 해당 위치를 며칠뒤에 갈 수 있는지?
	bool operator < (NODE o) const {
		return c > o.c;
	}
};
vector<NODE>point;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int dijkstra(int y, int x) {
	priority_queue<NODE>pq;
	visited[y][x] = 2;
	pq.push({ y,x,2 });
	int Max = -21e8;
	//도착지를 왔을때 now.c가 1이면 물에있다가 온거고
	//1이 아니면 벽으로 갖혀있다.
	while (!pq.empty()) {
		NODE now = pq.top();
		pq.pop();
		if (Max < now.c) 
			Max = now.c;
		if (now.y == point[1].y&&now.x == point[1].x) {
			if (now.c == 1) {
				return (Max - 1) / 2 + (Max - 1) % 2;
			}
			else return Max - 1;
		}

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			if (visited[dy][dx] != 0) continue;

			int next = now.c;
			if (map[dy][dx] == 'X'|| map[dy][dx] == 'L') next++;
			if (map[dy][dx] == '.') next = 1;

			visited[dy][dx] = next;
			pq.push({ dy,dx,next });
		}
	}
	return -1;
}
int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL); 
	cin >> R >> C;
	
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'L') {
				point.push_back({ y,x,1 }); //거위 위치
			}
		}
	}
	
		int ans=dijkstra(point[0].y, point[0].x);
	 if (ans == 0) //처음에 거위가 얼음위에있나..?
		ans = 1;
	 cout << ans;
	return 0;
}

*/