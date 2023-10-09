// 플레이어 수 N <=50000
// 단어의 개수M,  N < M <=50000
//모든 플레이어중 한 명만 남을 때까지 -> 5만번 게임진행

//규칙 1
//사람들은 ID의 오름차순으로 진행한다. -> DAT
//규칙 2
//주어진 목록에 있는 단어만 한 번씩 사용할 수 있으며, 사전순으로 먼저 사용한다
//규칙 3
//사용한 단어는 거꾸로했을 때 사용되지 않았다면 뒤집어서 단어목록에 추가한다.

//hashmap 만들어서 모든 단어와 뒤집은 단어 삽입 N*10
//각 단어별로 정렬 NlogN -> PQ 배열 (PQ [0~26])
//사용한 단어는 PQ.pop 
//사용한적 없는 뒤집은 단어를 각 단어 배열에 삽입 N(단어개수)*logN(삽입) 

//최종 10N+N+NlogN+NlogN

/// *** main.cpp ***
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<cstring>
using namespace std;
#define MAX_N 50000
#define MAX_M 50000
#define WORD_MAXLEN 11

vector<string>arr;
int dead[50001];
int NumPlayer;
int NumWords;
string getRev(string input) { // word 거꾸로
	int size = input.length();
	int i = 0;
	while (i < size / 2) {
		char temp = input[i];
		input[i] = input[size - 1 - i];
		input[size - 1 - i] = temp;
		i++;
	}
	return input;
}
unordered_map<string, int>um;//단어 목록 // 0이면 pq에 안 들어있는거, 1이면 리스트에 들어갔음
priority_queue<string, vector<string>, greater<string>>initial[26];

extern void init(int N, int M, char words[50000][11]) {
	um.clear();
	for (int i = 0; i < 26; i++) {
		while (!initial[i].empty()) {
			initial[i].pop();
		}
	}
	memset(dead, 0, sizeof(dead));
	arr.clear();
	NumPlayer = N;
	NumWords = M;
	//모든 값(거꾸로 포함)을 해쉬에 집어넣고
	for (int i = 0; i < M; i++) {
		string word(words[i]);
		if (um.find(word) != um.end()) { //이미 거꾸로된 값(0)으로 업데이트 한 값이 초기 리스트로 들어온다면 1로 만들어줘야함
			um[word] = 1;
			initial[word[0] - 'a'].push(word);
			continue;
		}
		um.insert({ word,1 });
		initial[word[0] - 'a'].push(word);
		string rev = getRev(words[i]);

		um.insert({ rev,0 });
	}

}
extern int playGame(int playerId, char startCh) {
	int index = 0;
	int ret;
	arr.clear();

	while (1) {
		if (dead[playerId] == 1) { //최적화 필요할듯, 메모리풀 LinkedList
			playerId++;
			if (playerId > NumPlayer) playerId = 1;
			continue;
		}
		//사용할 수 있는 현재 이니셜의 단어가 더이상 없다면 탈락
		if (initial[startCh - 'a'].empty()) {
			ret = playerId;
			break;
		}
		string word = initial[startCh - 'a'].top();
		initial[startCh - 'a'].pop();

		//다음 플레이어와 다음 첫글자 세팅
		int last = word.length() - 1;
		startCh = word[last];
		playerId++;
		if (playerId > NumPlayer) playerId = 1;

		string rev = getRev(word);
		if (um[rev] == 0) { //이 단어를 거꾸로 했을 때, 리스트에 들어간적이 없다면
			arr.push_back(rev); //이판이 끝나고 해당 단어를 리스트에 넣어줄것이다
			um[rev] = 1; //안에 넣음
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		initial[arr[i][0] - 'a'].push(arr[i]);
	}
	dead[ret] = 1;
	return ret;
}

static char words[MAX_M][WORD_MAXLEN];

static bool run()
{
	bool ok = true;
	int N, M;
	int gameCnt;

	scanf("%d%d", &N, &M);
	for (int m = 0; m < M; m++) {
		scanf("%s", words[m]);
	}


	init(N, M, words);

	scanf("%d", &gameCnt);
	for (int i = 0; i < gameCnt; i++) { //playerID, startCh 입력받기
		int playerId, ret, ans;
		char startChar[2];

		scanf("%d", &playerId);
		scanf("%s", startChar);
		ret = playGame(playerId, startChar[0]);
		scanf("%d", &ans);
		if (ret != ans) {
			ok = false;
		}
	}
	return ok;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);

	int T, SUCCESS;
	scanf("%d%d", &T, &SUCCESS);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? SUCCESS : 0;
		printf("%d %d\n", tc, score);
	}

	return 0;
}
/*
1 100
4 4
ezone
event
tneve
enoze
3
3 e 2
3 t 1
3 e 4
*/
/* 메모리풀 linkedlist 최적화
// 플레이어 수 N <=50000
// 단어의 개수M,  N < M <=50000
//모든 플레이어중 한 명만 남을 때까지 -> 5만번 게임진행

//규칙 1
//사람들은 ID의 오름차순으로 진행한다. -> DAT
//규칙 2
//주어진 목록에 있는 단어만 한 번씩 사용할 수 있으며, 사전순으로 먼저 사용한다
//규칙 3
//사용한 단어는 거꾸로했을 때 사용되지 않았다면 뒤집어서 단어목록에 추가한다.

//hashmap 만들어서 모든 단어와 뒤집은 단어 삽입 N*10
//각 단어별로 정렬 NlogN -> PQ 배열 (PQ [0~26])
//사용한 단어는 PQ.pop 
//사용한적 없는 뒤집은 단어를 각 단어 배열에 삽입 N(단어개수)*logN(삽입) 

//최종 10N+N+NlogN+NlogN

/// *** main.cpp ***
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<cstring>
using namespace std;
#define MAX_N 50000
#define MAX_M 50000
#define WORD_MAXLEN 11

vector<string>arr;
class Order {
public:
	int prev;
	int next;
	Order(int _p = 0, int _n = 0) {
		prev = _p;
		next = _n;
	}
};
Order player_list[50003];

int NumPlayer;
int NumWords;
string getRev(string input) {
	int size = input.length();
	int i = 0;
	while (i < size / 2) {
		char temp = input[i];
		input[i] = input[size - 1 - i];
		input[size - 1 - i] = temp;
		i++;
	}
	return input;
}
unordered_map<string, int>um;//단어 목록 // 0이면 pq에 안 들어있는거, 1이면 들어있는데 사용 안 된거, 2이면 사용된거

priority_queue<string, vector<string>, greater<string>>initial[26];
extern void init(int N, int M, char words[50000][11]) {
	um.clear();
	for (int i = 0; i < 26; i++) {
		while (!initial[i].empty()) {
			initial[i].pop();
		}
	}
	for (int i = 0; i < N; ++i) {
		player_list[i].next = i + 1;
		player_list[i].prev = i - 1;
	}
	// 가장 양끝 따로 초기화
	player_list[0].prev = N - 1;
	player_list[N - 1].next = 0;

	arr.clear();
	NumPlayer = N;
	NumWords = M;
	//모든 값(거꾸로 포함)을 해쉬에 집어넣고
	for (int i = 0; i < M; i++) {
		string word(words[i]);
		if (um.find(word) != um.end()) { //이미 거꾸로된 값(0)으로 업데이트 한 값이 초기 리스트로 들어온다면 1로 만들어줘야함
			um[word] = 1;
			initial[word[0] - 'a'].push(word);
			continue;
		}
		um.insert({ word,1 });
		initial[word[0] - 'a'].push(word);
		string rev = getRev(words[i]);
		//if(um.find(rev)==um.end())
		um.insert({ rev,0 });
	}

}
extern int playGame(int playerId, char startCh) {
	int index = 0;
	int ret;
	arr.clear();
	//memset(arr, 0, sizeof(arr));

	int now_player = playerId - 1; // index화

	while (1) {
		//if (dead[playerId] == 1) { //최적화 필요할듯, 메모리풀 LinkedList
		//	playerId++;
		//	if (playerId > NumPlayer) playerId = 1;
		//	continue;
		//}
		//사용할 수 있는 현재 이니셜의 단어가 더이상 없다면 탈락
		if (initial[startCh - 'a'].empty()) {
			ret = playerId;
			int prev_player = player_list[now_player].prev;
			player_list[prev_player].next = player_list[now_player].next;

			int next_player = player_list[now_player].next;
			player_list[next_player].prev = player_list[now_player].prev;
			break;
		}

		string word = initial[startCh - 'a'].top();
		initial[startCh - 'a'].pop();
		now_player = player_list[now_player].next;


		//다음 플레이어와 다음 첫글자 세팅
		int last = word.length() - 1;
		startCh = word[last];
		playerId++;
		if (playerId > NumPlayer) playerId = 1;

		string rev = getRev(word);
		if (um[rev] == 0) { //이 단어를 거꾸로 했을 때, 리스트에 들어간적이 없다면
			arr.push_back(rev); //이판이 끝나고 해당 단어를 리스트에 넣어줄것이다
			um[rev] = 1; //안에 넣음
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		initial[arr[i][0] - 'a'].push(arr[i]);
	}
	return now_player+1;
}

static char words[MAX_M][WORD_MAXLEN];

static bool run()
{
	bool ok = true;
	int N, M;
	int gameCnt;

	scanf("%d%d", &N, &M);
	for (int m = 0; m < M; m++) {
		scanf("%s", words[m]);
	}


	init(N, M, words);

	scanf("%d", &gameCnt);
	for (int i = 0; i < gameCnt; i++) { //playerID, startCh 입력받기
		int playerId, ret, ans;
		char startChar[2];

		scanf("%d", &playerId);
		scanf("%s", startChar);
		ret = playGame(playerId, startChar[0]);
		scanf("%d", &ans);
		if (ret != ans) {
			ok = false;
		}
	}
	return ok;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);

	int T, SUCCESS;
	scanf("%d%d", &T, &SUCCESS);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? SUCCESS : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

*/