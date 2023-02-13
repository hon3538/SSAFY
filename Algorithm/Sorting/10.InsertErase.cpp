#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    int score;
};
vector<Person>v;
void print() {
    for (int i = 0; i < v.size(); i++) {
        if (i >= 3)
            break;
        cout << v[i].name << " ";
    }
    cout << '\n';
}
int main() {
    int N;
    cin >> N;
    string name;
    int score;
    for (int i = 0; i < N; i++) {
        cin >> name >> score;
        
        for (int j = i - 1; j >= -1; j--) {
            if (j == -1) {
                v.insert(v.begin(), { name,score });
                print();
                break;
            }
            if (v[j].score > score) {
                v.insert(v.begin()+j+1, { name,score });
                print();
                break;
            }
        }
    }


    return 0;
}
//삽입될때마다 이전 요소들하고 값 비교, 내림차순의경우
//비교하다가 자신보다 큰 값을 만나면 그 index+1에 삽입
/*
struct Player {
	string name;
	int score; 
	int num; 
};

bool cmp(Player a, Player b) {
	if (a.score > b.score)
		return true;
	if (a.score < b.score)
		return false;
	if (a.num > b.num)
		return true;
	if (a.num < b.num)
		return false;
	return false; 
}

vector<Player>p; 
int n; 

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int score;
		cin >> name >> score;
		p.push_back({ name, score, i });
		sort(p.begin(), p.end(), cmp);
		if (p.size() < 3) {
			for (int i = 0; i < p.size(); i++)
				cout << p[i].name << " ";
			cout << '\n';
		}
		else {
			for (int i = 0; i < 3; i++) {
				cout << p[i].name << " ";
			}
			cout << '\n';
		}
	}
}
*/