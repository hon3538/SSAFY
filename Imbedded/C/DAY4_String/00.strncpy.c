#include <stdio.h>
#include <string.h>
struct Node{int a,b;};
void insertStr(char *str,char *input,char *target,int index){
	memset(str,0,10);
	strncpy(str,input,index);
	strcat(str,target);
	strcat(str,&input[index]);
}
int main(){
	char vect[10]="ZXXVQ";
	char result[10];
	insertStr(result,vect,"ABC",2); //2번 인덱스에 ABC 삽입
	printf("%s",result);
	return 0;
}
