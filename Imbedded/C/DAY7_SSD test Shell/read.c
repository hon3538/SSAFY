#include "header.h"

void read(int LBA){
    FILE *fp1=fopen("nand.txt","rb");
    char buf[30];
    memset(buf,0,sizeof(buf));

    fseek(fp1,LBA*4,0);
    fread(buf,sizeof(char),4,fp1);
    fclose(fp1);

    FILE *fp2=fopen("result.txt","wt");
    union Read{
        uint8_t c;
        struct{
            uint8_t a :4; 
            uint8_t b :4; 
        }r;
    }R; 
    fputc('0',fp2);
    fputc('x',fp2);
    for(int i=3;i>=0;i--){
        R.c=buf[i];
        fputc(R.r.b+'0',fp2);
        fputc(R.r.a+'0',fp2);
    }   
    fputc('\n',fp2);
    fclose(fp2);
}
