/*
가로 10 ~ 100만
세로 0~1만

최대 4층 높이 직사각형 블럭이 떨어짐
현재 상태에서 블럭의 최대 높이는 ?

맨아래 가득 차면 없어짐
가득 찼는지 어떻게 확인?
0~100만의 value가 곧 가득 찬 값

구간 단위 value update 는 lazy하게 관리
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_SIZE 4000000
struct Ans{
    int top;
    int count;
};
struct Node{
    int cnt;
    int max_height;
    int min_height;
    Node(){
        cnt = 0;
        max_height = 0;
        min_height = 0;
    }
};
Node segment_tree[MAX_SIZE];
int lazy[MAX_SIZE];
void lazy_update(int left, int right, int index){
    if(lazy[index]==0) return;

    segment_tree[index].cnt += (left-right+1)*lazy[index];
    segment_tree[index].max_height += lazy[index];
    segment_tree[index].min_height += lazy[index];
    lazy[index] = 0;
}
Node update(int left, int right, int index, int t_left, int t_right, int t_height){
    lazy_update(left, right, index);
    if(t_right<left || right < t_left) return segment_tree[index];
    if(t_left <= left && right <= t_right){
        segment_tree[index].cnt += (left-right+1)*t_height; 
        segment_tree[index].max_height += t_height;
        segment_tree[index].min_height += t_height;

        if(left!=right){
            lazy[index*2] += t_height;
            lazy[index*2 + 1] += t_height;
        }
        return segment_tree[index];
    }
    int mid = (left + right) / 2;
    Node a = update(left, mid, index*2, t_left, t_right, t_height);
    Node b = update(mid + 1, right, index*2 + 1, t_left, t_right, t_height);
    
    segment_tree[index].cnt = a.cnt + b.cnt;
    segment_tree[index].max_height = max(a.max_height, b.max_height);
    segment_tree[index].min_height = min(a.min_height, b.min_height);

    return segment_tree[index];
}
// 너비 10<=c<=100만
int col_max;
void init(int c){
    col_max = c;
    for(int i=0;i< MAX_SIZE;i++){
        segment_tree[i].cnt = 0;
        segment_tree[i].max_height = 0;
        segment_tree[i].min_height = 0;
    }
}
Ans dropBlock(int mCol, int mHeight, int mLength){ //3천번
    //mCol~(mCol+mLength - 1) target 구간
    update(0, col_max - 1, 1, mCol - 1, mCol + mLength -1, mHeight);
    //최대 높이에서 최소 높이를 빼야, 없어질 블록들을 반영한 최고 높이가 됨.
    int top = segment_tree[1].max_height - segment_tree[1].min_height;
    // 현재까지 블록 개수에서 밑에 꽉채워진(없어진) 블록개수를 빼면 현재 남은 블록 개수
    int count = segment_tree[1].cnt - (col_max * segment_tree[1].min_height);
    return {top, count };
}   
