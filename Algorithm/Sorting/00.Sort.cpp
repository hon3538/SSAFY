// 정렬 -> 특정 집합의 요소들을 특정 기준으로 나열하는 것
// 정렬 알고리즘
// select

// bublle for( for() ) => O(N^2)
// 오름차순 기준으로 0,1 -> 1,2 -> 2,3 ... 으로 비교하면서
// 더 작은 것이 뒤에있으면 스왑해줌.
// 마지막 인덱스까지 과정 반복하고 마지막 인덱스의 값은 가장 큰 값이 되므로 fix
// 이 과정을 반복한다.

// insert
// Quick

// merge => O(NlogN)

// 근데 모든 알고리즘을 알필요는 없다..
// STL(Standard Templete Libraray)의 정렬 기능을 그냥 가져다가 쓸것이다.
// -> STL에서 구현된 정렬 알고리즘은 굉장히 안정적이다
// -> 또한 STL에서 만들어진 정렬의 시간복잡도는 항상 O(NlogN)을 보장한다.
// -> C++은 intro Sort
// -> heap 정렬, 삽입 정렬, quick 정렬
// -> 데이터 크기, 종류에 따라 적절한 알고리즘 사용함

#include <iostream>
#include <algorithm> // 정렬 기능이 포함된 라이브러리 (min,max)
#include <vector>
#include <string>
using namespace std;
struct Student
{
    string name;
    int n;
    int score;
};
// bool cmp(int left, int right)
// {
//     return left > right;
// }
// bool cmp(int left, int right)
// {
//     if (left > right) // 더 큰게 왼쪽에 있다 -> 원하는 상태
//         return true;
//     if (left < right) // 더 작은게 왼쪽에 있다 -> 원하지 않는 상태
//         return false;
//     //모든 조건들이 같을때
//     return false;
// }
bool cmp(int left, int right) // for QUIZ
{
    // 짝수 우선

    if (left % 2 == 0 && right % 2 == 1)
        return true;
    if (left % 2 == 1 && right % 2 == 0)
        return false;
    if (left % 2 == 0 && right % 2 == 0)
    {
        if (left > right) // 더 큰게 왼쪽에 있다 -> 원하는 상태
            return true;
        if (left < right) // 더 작은게 왼쪽에 있다 -> 원하지 않는 상태
            return false;
    }
    if (left % 2 == 1 && right % 2 == 1)
    {
        if (left > right) // 더 큰게 왼쪽에 있다 -> 원하는 상태
            return true;
        if (left < right) // 더 작은게 왼쪽에 있다 -> 원하지 않는 상태
            return false;
    }
    // 모든 조건들이 같을때
    return false;
}
bool ssafycmp(Student left, Student right)
{
    // #1 시험 점수 높은 사람중
    if (left.score > right.score)
        return true;
    if (left.score < right.score)
        return false;
    // #2 나이가 많은 사람,
    if (left.n > right.n)
        return true;
    if (left.n < right.n)
        return false;
    // #이름이 사전순으로 빠른사람
    if (left.name > right.name)
        return true;
    if (left.name < right.name)
        return false;
    return false;
}

int main()
{
    int arr[] = {1, 3, 5, 4, 2};
    // 정렬 방법
    // sort(RandomAccessLterator first, RandomAccessIterator Last)
    //  sort(배열의 시작주소(정렬을 하려고하는 시작위치),배열의 끝주소)
    //  first 부터, Last 이전까지 정렬
    // iterator : 포인터
    // 배열 자체 = 포인터
    //  cout<<arr; -> arr[0]이 존재하는 주소를 출력함
    // #1 오름차순
    // sort(arr, arr + 5); // default: sort(first,last,<)
    // #2 내림차순
    // sort(arr, arr + 5, cmp); // 내림차순
    // #3 사용자 정의 정렬
    // struct
    Student ssafy[5];
    ssafy[0] = {"홍의선", 12, 90};
    ssafy[1] = {"류병민", 10, 96};
    ssafy[2] = {"임꺽정", 15, 436};
    ssafy[3] = {"김건희", 26, 36};
    ssafy[4] = {"윤석열", 20, 43};
    sort(ssafy, ssafy + 5, ssafycmp);

    for (int i = 0; i < 5; i++)
    {
        cout << ssafy[i].name << " " << ssafy[i].n << " " << ssafy[i].score << '\n';
    }
    // QUIZ
    // 정렬 : 짝수 우선, 홀수 나중, 짝수는 내림차순, 홀수는 오름차순
    int v[] = {1, 3, 4, 5, 2};
    sort(v, v + 5, cmp);
    cout<<'\n';
    for (int i = 0; i < 5; i++)
    {
        cout << v[i]<<'\n';
    }
    //vector도 가능
    // vector<Player>p; 
    // sort(p.begin(), p.end(), cmp);
}