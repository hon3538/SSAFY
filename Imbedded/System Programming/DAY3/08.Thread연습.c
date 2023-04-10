//main 에서 VVCC 함수를 37회 동시에 수행하는 코드를 작성한다.
#include <stdio.h>
#include <unistd.h>

pthread_t arr[37];
void* VVCC(void* p){
    int *a=(int*)p;
    printf("%d ",*a);
    return 0;
}
int main(){
    int list[37];
    for(int i=0;i<37;i++){
        list[i]=i+1;
        pthread_create(&arr[i],NULL,VVCC,&list[i]);
    }
    for(int i=0;i<37;i++) pthrad_join(arr[i],NULL);
    return 0;
}