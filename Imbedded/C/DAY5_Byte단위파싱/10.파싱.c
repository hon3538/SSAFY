//빅엔디안으로 들어온 데이터 파싱
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("binary","rb");
    uint8_t buf[14]; //112 bit, 14byte
    fread(buf,1,14,fp);


    union AAA{
    	uint8_t a[14];
    	struct{
    		uint16_t wegiht;
    		uint16_t pw;
    		uint16_t money;
    		uint8_t food[4];
    		uint8_t drink[4];
    	}e;
    }aaa;

    memcpy(aaa.a,buf,14);
    printf("%d %d %d ",aaa.e.wegiht,aaa.e.pw,aaa.e.money);
    for(int i=3;i>=0;i--){
    	printf("%c",aaa.e.food[i]);
    }
    printf(" ");
    for(int i=3;i>=0;i--){
        	printf("%c",aaa.e.drink[i]);
    }
    fclose(fp);

    return 0;
}
