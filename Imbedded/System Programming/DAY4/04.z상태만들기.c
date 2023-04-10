#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t child_pid= fork();
    if(child_pid >0){
        //parent
        while(1);
    }
    else if(child_pid ==0){
        //son

        //Die
    }
    return 0;
}