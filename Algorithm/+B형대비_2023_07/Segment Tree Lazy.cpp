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
using namespace std;

#define MAX_SIZE 4000000
int segment_tree[MAX_SIZE];
int lazy[MAX_SIZE];
void update(int left, int right, int index, int t_left, int t_right, int t_height){
    if(t_right<left || right < t_left) return;
    if(t_left <= left && right <= t_right){
        segment_tree[index] += 
    }
}
// 너비 10<=c<=100만
void init(int c){

}
int dropBlock(int mCol, int mHeight, int mLength){ //3천번
    //mCol~(mCol+mLength - 1) target 구간
}
