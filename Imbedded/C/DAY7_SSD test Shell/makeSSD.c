#include <stdio.h>
 
 int main(){
     FILE *fp=fopen("nand.txt","r+");
    
     for(int i=0;i<100;i++){
         for(int j=0;j<4;j++){
             fputc('0',fp);
         }
     }   
    fputc('\n',fp);  
    fclose(fp);
    return 0;
 }
