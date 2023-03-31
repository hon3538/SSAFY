#include <stdio.h>
#include <string.h>

int main(){
    char input[50];
    while(1){
        printf("testshell >");
        scanf("%s",input);
        int LBA;
        char value[20];
        char *command;
        if(strcmp(input,"write")==0){
            scanf("%d %s",&LBA,value);
            sprintf(command,"ssd W %d %s",LBA,value);
        }else if(strcmp(input,"read")==0){
            scanf("%d",&LBA);
            sprintf(command,"ssd R %d",LBA);
        }else if(strcmp(input,"exit")==0){
            printf("Bye!\n");
            break;
        }else if(strcmp(input,"help")==0){
            printf("write : write [lba] [(0x)4byte value] -> write value to lba address in ssd\n");
             printf("read : read [lba] -> read value from ssd\n");
             printf("exit : exit -> quit testshell\n");
             printf("help : help -> show all commands\n");
             printf("fullwrite : fullwrite [(0x)4byte value]-> write value to every lba address in ssd\n"); 
             printf("fullread : fullread -> read values from every lba address\n");
            
        }else if(strcmp(input,"fullwrite")==0){
            scanf("%s",value);
            for(int i=0;i<100;i++){
                sprintf(command,"ssd W %d %s",LBA,value);
                system(command);
            }
        }else if(strcmp(input,"fullread")==0){
            for(int i=0;i<100;i++){
                sprintf(command,"ssd R %d",LBA);
                system(command);
                system("cat ./result.txt");
            }
        }else{
            printf("invalid command!\n");
        }

    }


    return 0;
}


