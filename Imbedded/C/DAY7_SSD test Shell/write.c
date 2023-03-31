#include "header.h"

uint32_t toDec(char *s){
    uint32_t res=0;
    int num=1;
    for(int i=7;i>=0;i--){
        if(s[i]<='9'&&s[i]>='0'){
            res+=num*(s[i]-'0');
        }else{
            res+=num*(s[i]-'a'+10);
        }
        num*=16;
    }   
    return res;
}
void write(int LBA, char* value){
     FILE *fp;
     fp=fopen("nand.txt","r+");
     char *s; 
     fseek(fp,LBA*4,0);

     union trans{
        uint32_t num;
        uint8_t arr[4];
     }t; 
    value+=2;
    t.num=toDec(value);
    for(int i=0;i<4;i++){
        fputc(t.arr[i],fp);
    }   
    fclose(fp);
}
