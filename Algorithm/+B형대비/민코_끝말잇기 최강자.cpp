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
//사용한 단어는 hashmap에서 삭제 N*O(1)
//각 단어별로 정렬 NlogN -> PQ 배열 (PQ [0~26])
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
using namespace std;
#define MAX_N 50000
#define MAX_M 50000
#define WORD_MAXLEN 11


string getRev(string input){
    int size=input.length();
    int i=0;
    while(i<size){
        i++;
        int temp=input[i];
        input[i]=input[size-1-i];
        input[size-1-i]=temp;
    }
    return input;
}
unordered_map<string,int>um;//단어 목록
struct cmp{
    bool operator()(string s1,string s2){
        return s1>s2; //사전순 정렬
    }
};
priority_queue<string,vector<string>,cmp>initial[26];
extern void init(int N, int M, char words[MAX_M][WORD_MAXLEN]){
    um.clear();
    for(int i=0;i<26;i++){
        while(!initial[i].empty()){
            initial[i].pop();
        }
    }

    //모든 값(거꾸로 포함)을 해쉬에 집어넣고
    for(int i=0;i<M;i++){
        um.insert({words[i],1});
        initial[words[i][0]-'A'].push(words[i]);
        string rev=getRev(words[i]);
        um.insert({rev,1});
    }

}
extern int playGame(int playerId, char startCh){
    
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
    for (int i = 0; i < gameCnt; i++) {
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