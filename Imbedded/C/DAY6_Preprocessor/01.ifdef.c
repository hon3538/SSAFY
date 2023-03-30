#define RELEASE
//#define DEBUG

//define이 돼있는 경우만 컴파일 진행
//define 전처리 지시기만으로 debug모드 변환이 쉽게 할 수 있음
//DEBUG 모드엔 코드를 똑같이 작성하고 trace를 위한 코드를 추가하여 DEBUGGING 실시

#ifdef DEBUG
int main() {
	int a = 20;
	return 0;
}
#endif

#ifdef RELEASE
int main() {
	int a = 1000;
	return 0;
}
#endif