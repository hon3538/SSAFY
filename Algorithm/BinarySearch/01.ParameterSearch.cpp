//Binary Search 는 target이 존재하는가 ? 의 대답을 찾고
//Parameter(매개변수) Search 는 lower bound / upper bound -> 마지노선(가능성)을 찾는 문제
//PS는 어디에 쓰이는가?
//바닷가에서 모래와 바다가 있는데 만약 바다에 안 들어가고 싶다?
// -> 어디까지가야 바다에 안 들어갈 수 있는 지 찾아야한다.
// -> Binary search 의 응용
// 중간에 놔둬보고 바다면 왼쪽, 땅이면 오른쪽으로 BS 해보면서 
// 마지노선(경계선)을 찾는다.
// 어쨋든 경계선은 하나이다..

//0~10 사이가 있을때, mid= 5일 때는 안전할 것이다 -> false
//(0+5)/2==2 일때 안전할 것이다 -> true
//(2+5)/2 ==3일때 안전할 것이다 -> true
//(3+5)/2 ==4일때 안전할 것이다 -> true;
//(4+5)/2 ...

//쉽게 이해하기
//1차원배열에서 왼쪽은 정답이 될 수 있는애들이 차곡차곡있고 
//오른쪽에는 안 되는 애들이 차곡차곡있다..
//우리는 되는 애들을 찾는게 아니고 되는 애와 안 되는 애 사이의 경계를 찾는다!
//그게 최대 효율이므로..
//예를들어 100길이의 츄러스를 일정한 크기로 잘라 5개를 만들어야한다
//50으로 자르면 2개 -> 25는 4개 -> 12는 8개(조건ok) => 여기서 끝나면 
//12길이의 츄러스 5개를 구하므로 나머지 40은 쓰이지 않게 된다..따라서
//(13+25)/2=19는 5개(ok) -> (20+25)=22 은 4개(x) -> (20+21)/2=20(5개)!
//-> left 21, right 21되면 안 됨.. 그다음 left 21 right 20이니까 break됨.   
#include <iostream>
using namespace std;
int N;
int arr[4];
int MAX;
int ans;
bool condition(int val){
    int sum=0;
    for(int i=0;i<N;i++){
        if(arr[i]>val)
            sum+=val; // 상한선만큼밖에 줄 수 없어
        else
            sum+= arr[i];
    }
    if(sum>MAX)
        return false;
    return true;
}
//**** 오른쪽값(high)는 배열의 크기가 아니라 마지막 인덱스!!!(배열크기-1)이다
void psearch(int low, int high){
    int left=low; // 상한선 범위의 가장 낮은값 =0원
    int right =high;// 상한선 범위의 가장 큰 값 = 내가 가진 전부

    while(left<=right){
        //mid는 곧 가능성이다, -> 정답이라고 가정한 값
        int mid=(left+right)/2;
        //이 가정이 정답이 될 수 있어?
        if(condition(mid)==true){
            //응
            ans=mid;
            //더 많은 금액을 줄 수 있겠네?
            //더 상한선을 높여도 되겠지?
            left=mid+1;
        }else{
            //아니 가능성 없어..금액이 오버돼
            //너무 상한선을 높게 잡았어
            //상한선의 크기를 낮춰
            right=mid-1;
        }
    }
}
int main(){
    //parameter search
    //ssafy 회사 - 연봉 협상시기
    //N명의 직원들이 있다
    //내가 사장 -> 각 직원들이 얼마만큼의 인상을 원하는지 알고 있다.
    //하지만 총 연봉을 올려줄 수 있는 금액은 정해져있다.
    //ex) N=4;
    //100 200 300 400
    //최대 금액 400

    //모두 최대한 주고 싶지만, 상한선을 정해야한다
    //상한선을 정했을 때, 만약 상한선보다 적게 원하면 다주고
    //아니면, 정한 이 상한선 만큼 준다
    //상한선을 얼마로 조정해야할까?

    //mid ==400/2 를 상한선으로 두고 나눠준다 ->최대금액(350) over
    //mid->200/2==100 상한선 ->  최대금액 같다
    //mid -> (100+200)/2 -> 최대급액 voer 
    //mid ->(100+150)/2 ....

    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> arr[i]; 
    cin >> MAX;
    psearch(0, MAX); 
    

}
/*
#include <iostream>
#include <algorithm>
using namespace std;

int N; 
int arr[4]; 
int MAX; 

bool condition(int val) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > val)
            sum += val; // 상한선만큼밖에 줄수 없어
        else
            sum += arr[i]; 
    }
    if (sum > MAX)
        return false; 
    return true; 
}

void psearch(int low, int high) {
    int left = low; // 상한선 범위의 가장 낮은값 = 0원
    int right = high; // 상한선 범위의 가장 큰 값 = 내가 가진 전부
    int ans = 0; 
    while (left <= right) {
        // 가능성 -> 정답이라고 가정한 값 
        int mid = (left + right) / 2; 
        // 이 가능성이 정답이 될수 있어? 
        if (condition(mid) == true) {
            // 정답이 될 가능성이 있는 값을 찾았다!
            ans = mid; 
            // 더 많은 금액을 줄 수 있는가?
            // 더 상한선을 높게 잡아도 가능한가? 
            left = mid + 1; 
        }
        else {
            // 이 값이 정답이 될수 없어 
            // 너무 상한선을 높게 잡았다
            // 상한선의 가장 큰 값의 범위를 낮춘다. 
            right = mid - 1; 
        }
    }
    cout << ans;
}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> arr[i]; 
    cin >> MAX;
    psearch(0, MAX); 
    
}
*/