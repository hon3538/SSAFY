//hashmap -> DAT의 단점 보완
// n (1~20억) 정수가 있다! DAT[20억] ? 메모리 낭비
// 4*20억/ 1024*1024*1024 => 7.6 GB..

//따라서 필요한 값들만 bucket에 담고 그것을 다시 index(key)로 접근하면
//메모리 절약 가능
//이를 map의 본체인 Hash Function이라함
// int HashFunction(int key){
    //이 HashFunction의 효율성에 따라 시간복잡도가 결정됨
//     return value;
// }

// 단순히 num으로 나머지 계산 등을하여 key를 만든다면 다른 key임에도
// 같은 key로 인식할 수도 있음

//STL의 hashmap 은 O(1)~O(logN) 임,
//같은 키로만 값이 다 들어간다면(최악의경우) vector나 다름 없음 ->O(N)
//다른 키로 잘 분포되어 있다면 바로바로 접근 가능하므로 O(1)~O(logN)
#include <iostream>
#include <unordered_map>
using namespace std;

//hash map
//C++에서 쓸 수 있는 map의 종류는 두 개가 있다.
//#1 unordered_map (정렬되지 않는 맵)
//내부구조 -> hash-table
//만들고, 삭제, 탐색 O(1)~O(logN) -> 너무 양이 많지 않은 경우

//#2 map (정렬된 맵)
//내부구조 -> red-black tree
//새로만들고, 삭제하고, 탐색 등 기능이 O(logN)
//비교적으로 양이 많은 경우 불리하다 -> 정렬된 상태를 유지해야 되기 때문에
//string을 key로 쓸때 간혹가다 유리한 경우가 있다.

int main(){
    
    int arr[]={1,200000000,200000000,4,5};
    unordered_map<int,int>um;
    //만약 키값이 같다면 덮어씌우는게 아니라 무시하게 됨
    for(int i=0;i<5;i++){
        um.insert({arr[i],i});
    }
    cout<<um[200000000]<<'\n'; //1
    for(int i=0;i<5;i++){
        //만약 이미 키가 등록 되어있다면 value+1
    
        if(um.find(arr[i])!=um.end()){
            um[arr[i]]++;
        }else{ //키가 없다면 um.end()
            um.insert({arr[i],1});
        }
        cout<<um[arr[i]]<<'\n';
    }
    //만약 키가 없는 값을 출력한다면 뭐가 출력될까?
    cout<<um[3]; // 3은 없는데... 출력해보면 0이나옴
    //없는 키를 넣으면 생성이됨 um[key]-> 생성
    //따라서 원치 않는 값이므로 이런식으로 생성은 안 하는것이 좋음..
    //나중에 문제생길 우려

    //traversal / iteration
    //맵에 있는 못든것을 출력해봐라
    //traversal은 시간이 꽤 걸린다.. 모든 메모리를 찾아가야되기때문
    for(auto it = um.begin();it!=um.end();it++){
        cout<<it->first<<" "<<it->second<<'\n'; //key, value
    }
    //따라서 이건 잘 쓰지 않는다..

    //요소 지우고 싶으면 um.erase(key) -> 이것도 자주 사용하면 효율 안 좋음
}