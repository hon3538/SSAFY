#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
char v[4][21]={
    "ABCDEFGHIJKLMNOPQRST",
    "HSDFGASDFSAFSDAFSAFF",
    "ASDFXCVCXVXBXBXCCXBB",
    "RETARYAWRAWERWERTWET"
};
void *encoding(void* in){
    int *n=(int*)in;
    for(int i=0;i<strlen(v[*n]);i++){
        v[*n][i]+=3;
    }

}
int main(){
    pthread_t t[4];
    int id[4];
    for(int i=0;i<4;i++){
        id[i]=i;
        pthread_create(&t[i],NULL,encoding,&id[i]);
        usleep(100*1000);
    }
    for(int i=0;i<4;i++){
        printf("%s\n",v[i]);
    }
    for(int i=0;i<4;i++){
        pthread_join(t[i],NULL);
    }

    return 0;
}
