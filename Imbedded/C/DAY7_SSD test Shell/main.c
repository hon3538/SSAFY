#include "header.h"
int main(int argc, char* argv[] ){
    if(strcmp("W",argv[1])==0){
        int num=atoi(argv[2]);
        if(argc!=4||num<0||num>=100){
            printf("invalid command!\n");
            return 0;
        }
        write(num,argv[3]);
    }else if(strcmp("R",argv[1])==0){
        int num=atoi(argv[2]);
        if(argc!=3||num<0||num>=100){
            printf("invalid command!\n");
            return 0;
        }
        read(num);
    }else{
        printf("invalid command!\n");
    }   
    return 0;
}
