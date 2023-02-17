#include <iostream>
#include <algorithm>
using namespace std;

int arr[] = { 3, 99, 21, 33, 4, 1, 5, 55, 7, 10 };

// binary search = 무조건 정렬이 필요하다. 
// binary search 언제 써야 효율적? 
// --> 내가 단순하게 하나의 값이 있는가? 체크할때 -> O(N)
// --> 여러번 찾아야 할때

void bs(int target) {    
   // #1. 내가 어떤 범위를 탐색하는가? 
   // --> 배열 내에만 존재하는 요소를 찾는다 : index 
   // --> 특정 정수 내의 범위이다 : 시작 끝 
   int left = 0;
   int right = 9; 
   int flag = 0; 
   
   while (left <= right) {
       // mid를 예측한다! 
       int mid = (left + right) / 2; 
       // 만약 mid가 내가 찾고자 하는 값이라면 
       if (arr[mid] == target) {
           // 찾았다! 
           flag = 1; 
           // 이미 찾았으면 더 탐색해볼 필요 X 
           break; 
       }
       else if (target < arr[mid]) {
           right = mid - 1; 
       }
       else if (target > arr[mid]) {
           left = mid + 1; 
       }
   }
   // 찾앗으면 1, 아니면 0
   cout << flag; 
}

int main() {
    int target; // 찾고자 하는 숫자
    cin >> target;

    // arr안에 이 target이 있느냐? 
    // O(N)
    // 예) 1000개의 정수가 있는 배열 -> 1000번의 Query 
    // O(N) * O(Q) = O(N^2) = 100만

    int flag = 0;
    for (int i = 0; i < 10; i++) {
       if (arr[i] == target)
           flag = 1; 
    }
    cout << flag; 

    // binary search
    // target을 찾아가는 이분탐색 

    // 예) 1000개의 정수가 있는 배열 -> 1000번의 Query 
    // O(Nlog(2)N) = 만번
    //O(NlogN+QlogN) => Q((N+Q)logN) => Q(NlogN)

    // O(NlogN)
    sort(arr, arr + 10); 
    // O(logN)
    bs(target); 

    
}
