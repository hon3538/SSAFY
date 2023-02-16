#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M;
struct Edge {
    int to;
    int cost;
    bool operator < (Edge o) const {
        return cost > o.cost;
    }
};
vector<Edge>v[1000];
vector<char>sex;

int prim(int start) {
    priority_queue<Edge>pq;
    pq.push({ start,0 });
    int connected[1000] = { 0 };
    int sum = 0;
    int cnt = 0;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        if (connected[now.to] == 1)
            continue;
        connected[now.to] = 1;
        sum += now.cost;
        cnt++;
        for (int to = 0; to < v[now.to].size(); to++) {
            Edge next = v[now.to][to];
            if (connected[next.to] == 1)
                continue;
            if (sex[next.to] == sex[now.to])
                continue;
            pq.push({ next.to,next.cost });
        }
    }
    if (cnt == N) {
        return sum;
    }
    else return -1;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) { //성별
        char c;
        cin >> c;
        sex.push_back(c);
    }
    for (int i = 0; i < M; i++) { // 도로 정보
        int u, t, d;
        cin >> u >> t >> d;
        v[u-1].push_back({ t-1,d });
        v[t - 1].push_back({ u-1,d });
    }

    cout << prim(0);
    return 0;
}

/*
민코는 지속되는 코로나 때문에 연애를 못한지 너무 오래되었다.

캠퍼스 커플을 꿈꾸던 민코는 금년부터 다시 학교에 돌아가면서반드시 연애를 하겠다는 마음으로 대학교간의 도로 정보를 기반으로 미팅 앱을 만들기로 결심했다.

이 앱은 사용자들이 원활히 이성들을 만나기 위해 LOVE 경로를 제공한다. 이 경로는 3가지 특징을 가지고 있다.

LOVE 경로는 이성의 대학간만으로 이루어져 있다. 즉, 남초 대학은 여초 대학, 여초 대학은 남초 대학으로만 경로가 연결된다.
사용자들이 다양한 사람들과 미팅할 수 있도록 어떤 대학교에서 출발해도 다른 대학교로 이동 가능한 경로이다.
연애를 하고픈 사용자들이 1초의 시간이라도 낭비를 방지하고자 LOVE 경로의 길이는 최소가 되어야 한다.
대학교들의 정보가 주어졌을 때, 미팅 앱에서 제공할 최소 LOVE 경로의 거리를 구해보자.

첫번째 줄에 학교의 수 N와 학교를 연결하는 도로의 개수 M이 주어진다. (2 ≤ N ≤ 1,000) (1 ≤ M ≤ 10,000)
두번쨰 줄에 각 학교가 남초 대학교라면 M, 여초 대학교라면 W이 주어진다.
다음 M개의 줄에 u v d가 주어지며 u학교와 v학교가 연결되어 있으며 이 거리는 d임을 나타낸다. (1 ≤ u, v ≤ N) , (1 ≤ d ≤ 1,000)
*/

