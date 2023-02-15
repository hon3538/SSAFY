#include <iostream>
#include <string>
using namespace std;
int N;
int population[25];
int T;
int parent[25];
int Find(int now) {
    if (parent[now] == now)
        return now;
    return parent[now] = Find(parent[now]);
}
void Union(int A, int B) {
    int pa = Find(A);
    int pb = Find(B);
    if (pa == pb)
        return;
    parent[pb] = pa;
    population[pa] += population[pb];
}
int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> population[i];
        parent[i] = i;
    }
    cin >> T;
    string s;
    char a, b;
    int cnt = 0;
    for (int i = 0; i < T; i++) {
        cin >> s>>a>>b;
        if (parent[a - 'A'] == -1 || parent[b - 'A'] == -1)
            continue;
        if (s != "war") {
            Union(a - 'A', b - 'A'); // 첫번째
        }
        else {
            int alliance1 = Find(a - 'A');
            int alliance2 = Find(b - 'A');
            //cout << alliance1 << ' ' << alliance2;
            int num1 = population[alliance1];
            int num2 = population[alliance2];
            
            if (num1 > num2) {
                for (int i = 0; i < N; i++) {
                    if (parent[i] == alliance2) {
                        parent[i] = -1;
                        cnt++;
                    }
                }
            }
            else if (num1 < num2) {
                for (int i = 0; i < N; i++) {
                    if (parent[i] == alliance1) {
                        parent[i] = -1;
                        cnt++;
                    }
                }
            }
            else {
                for (int i = 0; i < N; i++) {
                    if (parent[i] == alliance2 || parent[i] == alliance1) {
                        parent[i] = -1;
                        cnt++;
                    }
                }
            }
        }
    }

    cout << N - cnt;
    return 0;
}
/*
7
10 20 30 40 50 60 70
5
alliance A C
alliance F C
alliance D B
alliance A F
war D F


int N;
int parent[26];
int pop[26];
int isAlive[26];

int Find(int now) {
    if (now == parent[now])
        return now;
    return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa == pb)
        return;
    parent[pb] = pa;
    pop[pa] += pop[pb];
    pop[pb] = 0;
}

void war(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);

    if (pa == pb)
        return;

    if (pop[pa] > pop[pb]) {
        pop[pb] = 0;
    }
    else if (pop[pb] > pop[pa]) {
        pop[pa] = 0;
    }
    else {
        pop[pa] = 0;
        pop[pb] = 0;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pop[i];
        parent[i] = i;
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string cmd;
        char A, B;
        cin >> cmd >> A >> B;
        int a = A - 'A';
        int b = B - 'A';

        if (cmd == "alliance") {
            Union(a, b);
        }
        else {
            war(a, b);
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (pop[Find(i)] != 0)
            cnt++;
    }
    cout << cnt;
}
*/