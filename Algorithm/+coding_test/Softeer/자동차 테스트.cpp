/*
n 5만
q 20만

n -> logN으로 탐색하여 중앙값을 찾고 왼쪽 오른쪽을 곱한다. 만약 중앙값이 존재하지
않으면 0
logN 탐색법은 바이너리 서치


20만 x log5만 = 320만 -> 0.032s
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 50000

// 5만 * 4byte = 20만 byte , 2mb + a
int arr[MAX]; 
int n, q;

bool cmp(int left, int right){
    return left < right;
}
int binarySearch(int left, int right, int target){
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == target){ // target 을 찾으면 왼쪽 오른쪽 곱하여 경우의 수 리턴
            return mid*(n-mid-1); 
        }else if(arr[mid] < target){ // target 보다 작으면 오른쪽에 있음
            left = mid + 1;
        }else{ // target 보다 크면 왼쪽에 있음
            right = mid - 1;
        }
    }
    return 0; // target 이 없으면 0 return
}
int main(){
    memset(arr,0,sizeof(arr)); 
    cin>> n >> q;
    for(int i=0; i<n; i++){ // input
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    sort(arr,arr+n,cmp);
    // for(int i=0; i<n; i++){ // sort test
    //     cout<<arr[i]<<' ';
    // }
    for(int i=0; i<q; i++){ // query
        int m;
        cin>>m;
        // binary search 
        // -1 : no result / else : 경우의 수
        cout<<binarySearch(0,n-1,m)<<'\n';
    }
}