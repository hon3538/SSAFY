#include <iostream>
using namespace std;

//비트 연산
//Bit = 가장 작은 데이터 단위
//1byte = 8bit

//비트 연산자
//A & B (AND) : A와 B가 모두 true면 1, 아니면 0 
//A | B (OR)  : 둘 중 하나만 true 면 1, 아니면 0
//A ^ B (XOR) : 둘이 같으면 1, 서로다르면 0 
//~ (NOT) : 0이면 1, 1이면 0
// << N (left shift) : 모든 비트를 N칸 왼쪽으로 이동 
// >> N (right shift): 모든 비트를 N칸 오른쪽으로 이동


int main(){
    // int A=3; //0011
    // int B=5; //0101
    // //AND 
    // int C =A&B;
    // cout<<C<<'\n'; // 1

    // // OR
    // C=A|B;
    // cout<<C<<'\n'; //7

    // //XOR
    // C=A^B;
    // cout<<C<<'\n'; //6

    // int original=35;
    // int a=12314235;
    // int b=15346537;
    // int c=original^a^b^a^b; // original
    //주로 암호화에 많이 쓰임 값 바꿔놓고 나중에 복호화할때 다시 XOR해주면 돌아옴


    //NOT
    // C=~A; //0011 
    // cout<<C<<'\n'; //-4 -> -3이 안나오고 -4로 나옴 
    //~original = -original -1
    //int 4byte
    //음수 만드는법
    // 0000000 00000000 ...00000011 -> 11111111...11111100
    // 1111111 11111111...11111100 -> 여기에 마지막 비트에만 +1(flip)
    // -> 111111....11111101 -> -3 
    // 
    
    //shift 연산 (부호는 그대로 따라온다)
    // int G=A>>1;
    // cout<<G<<'\n'; // 1

    // int H=A<<2; 
    // cout<<H<<'\n'; // 12

    //비트 연산 언제 쓰는데?
    //#1 문제가 노골적인 비트연산 문제이다
    //#2 (비트 관련문제) 비트마스킹(bit masking)

    //Bit Masking #1
    //특정 비트를 바꾸는 방법
    //B=5 => 0101
    // int N=1; // B의 N번째 비트를 1로 바꿔라
    // int res= B | (1<<N);

    // //Bit Masking #2
    // //특정 bit를 토글
    // int N=2;
    // int res= B ^ (1<<N); //같으면 0, 다르면 1
    // return 0;
    // //특정 비트를 삭제
    // int N=3;
    // int res=B & (~(1<<N));
    int N=5;
    int arr2[5]={1,2,3,4,5};
    /*
    00000
    00001
    00010
    00011
    .
    .
    11111
    */
    for(int i=1;i<(1<<N);i++){ //1 1 1 1 1 =>31, 32 는 1을 N번 left shift 시킨것임
        int mask=i;
        int idx=0;

        while(mask){
            if(mask&1){
                cout<<arr2[idx]<<' ';
            }
            idx++;
            mask >>= 1;
        }
        cout<<'\n';
    }
}