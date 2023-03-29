#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
union Par{
	uint8_t datas[11];
	struct{
		uint8_t head[5];
		uint8_t body[4];
		uint8_t tail[2];
	}b;
};
int main(){
	//보낼 데이터
	uint8_t target[11]={0x12,0x12,0x12,0x12,0x12,0xAB,0xCD,0x98,0x76,0xEF,0x54};

	//받을 영역
	uint8_t receiveData[11];

	//데이터를 전달 받음
	memcpy(receiveData,target,11);

	union Par p;
	memcpy(p.datas,receiveData,11);


	for(int i=0;i<5;i++){
		printf("%2x ",p.b.head[i]);
	}
	printf("\n");
	for(int i=0;i<4;i++){
		printf("%2x ",p.b.body[i]);
	}
	printf("\n");
	for(int i=0;i<2;i++){
		printf("%2x ",p.b.tail[i]);
	}
	return 0;
}
