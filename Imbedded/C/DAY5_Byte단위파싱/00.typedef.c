#include<stdio.h>

// 타입명이 맘에 들지 않을 때(길 때) 사용한다.

typedef long long ll;
typedef unsigned char u;
typedef double hong;
typedef float euiseon;
int main(){
    long long t=12341346436346;
    ll t2=1231234365346;
    
    hong a=1.123456;
    euiseon b=0.123456;

    printf("%.4lf %2f\n",a,b);
    return 0;
}