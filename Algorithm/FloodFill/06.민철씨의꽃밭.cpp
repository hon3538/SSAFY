//씨앗심음
//하루뒤에 꽃핌
//땅 숫자만큼 삼
//땅 숫자만큼 DAT[k]~DAT[k+땅숫자] 모두 +1씩 ㅋ
//DAT[day] 하나씩 보면서 가장 큰값 출력
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int N, M; // 밭의 크기
int Y, X; // 시작 위치
struct Node {
    int y, x;
    int days;
};
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int map[500][500];
int start[500][500];

int main() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
            if (map[y][x]==0)
                start[y][x] = -1;
        }
    }
    cin >> Y >> X;

    queue<Node>q;
    q.push({ Y,X,0 });
    start[Y][X] = 1;
    int total = 0;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        total = now.days + 1;
        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= N || dx >= M)
                continue;

            if (start[dy][dx] != 0)
                continue;
            int nextDay = now.days + 1;
            start[dy][dx] = nextDay + 1;
            q.push({ dy,dx,nextDay });
        }
    }
   // print();
    int size = N * M;
    //int picks = y * M + x;
    //Max>=size-picks+cnt 이면 가망없으므로 다음꺼
    int Max = INT_MIN;
    int maxIdx;
    for (int day = 0; day <= total; day++) {
        int isPossible = true;
        int cnt = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                int picks = y * M + x+1;
                int end = start[y][x] + map[y][x];
                if (start[y][x]>0&&day >= start[y][x] && day < end) {
                    cnt++;
                }
                if (size - picks + cnt <= Max) {
                    isPossible = false;
                    break;
                }
            }
            if (!isPossible)
                break;
        }
        if (!isPossible)
            continue;
        if (cnt > Max) {
            Max = cnt;
            maxIdx = day;
        }
    }


    //씨앗이 다 번지기까지 걸린 일수를 구하면 그 사이값만 보면되잖아..
    // startday~endday 까지만 확인하면 되잖어..그 사이에 모든 씨앗이 심어지니까
   
    
    cout << maxIdx << "일\n" << Max << "개";
    return 0;
}
/* //bfs를 day단위로 돌림, 씨앗심으면 q에 넣어주고 다음날되면 꽃개수 count, 또 bfs들어감
// 꽃이 죽을날을 저장해놓고 bfs나올때마다 죽은 꽃 개수 빼주고 Max랑 비교
import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m; // n : 세로 크기, m : 가로 크기
    static int[][] MAP;
    static int[][] visited;
    // index일이 지난 후 몇개의 꽃이 죽을지를 저장
    // index : 일 수, value : 죽을 꽃의 수
    // 최대 일자의 값 : 비옥함의 최대치 (1,000,000) + 퍼짐의 횟수 (약 707)
    static int[] DAT = new int[1100000];
    static Queue<Pos> q = new LinkedList<>();
    static int[] xdir = { 0, 0, 1, -1 };
    static int[] ydir = { 1, -1, 0, 0 };
    static int maxval = Integer.MIN_VALUE;
    static int maxday;
    static int cnt = 0;
    static int day = 0;

    static class Pos {
        int x, y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static void bfs() {
        // 단계별 bfs
        // 하루동안의 퍼짐만 확인
        int qsize = q.size();
        for (int qq = 0; qq < qsize; qq++) {
            Pos now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nextx = now.x + xdir[i];
                int nexty = now.y + ydir[i];
                // 범위 체크
                if(nextx < 0 || nexty < 0 || nextx >= n || nexty >= m)
                    continue;
                // 방문 기록이 있는 곳은 pass
                if(visited[nextx][nexty] == 1)
                    continue;
                // 꽃이 안피는 땅은 pass
                if(MAP[nextx][nexty] == 0)
                    continue;
                DAT[MAP[nextx][nexty] + day]++;
                q.add(new Pos(nextx, nexty));
                visited[nextx][nexty] = 1;
            }
        }
    }

    public static void main(String args[]) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        // init
        MAP = new int[n][m];
        visited = new int[n][m];
        // input
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                MAP[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        q.add(new Pos(x, y));
        visited[x][y] = 1;
        DAT[MAP[x][y]]++;
        while (!q.isEmpty()) {
            // 큐에 들어간 꽃의 개수, 즉, 다음날 피어지게 될 꽃의 수를 누적
            cnt += q.size();
            // 다음날
            day++;
            // 씨앗 퍼짐 BFS
            bfs();
            // 피어날 꽃의 수 - 전날 죽었을 꽃만큼을 감소
            cnt -= DAT[day-1];
            // 최대값 갱신
            if(cnt > maxval) {
                maxval = cnt;
                maxday = day;
            }

        }
        System.out.println(maxday+"일");
        System.out.println(maxval+"개");
    }
}
*/