//특정 장치의 초기화 코드를 작성
//Camera 없는 보드의 Firmware 빌드 : make
//Camera 있는 보드의 Firmware 빌드 : make camera
//make에 따라 define이 달라짐

//HW 초기화 코드를 Define에 따라 넣거나 안 넣을 수 있음
// 즉 #error로 컴파일 중단 시킬 수 있음

//#define ENGINE

#ifndef ENGINE
	#error 해당 장치가 있어야 합니다.
#endif

int main() {
	return 0;
}

