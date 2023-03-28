//strchr 문자검색
//strstr 문자열 검색

// char vect[10]="ABCDEFG";
// printf("%s",strstr(vect,"BCD"));
// printf("%s",strchr(vect,'C'));

#include <stdio.h>
#include <string.h>
int main(){
    char vect[100]="DBABCEQABC";
    char tar[4]="ABC";
    //printf("%s",strstr(vect,"ASDCCC")); //ABCEQABC
    for(char *p=strstr(vect,tar);p!=NULL;strcpy(p,strstr(vect,tar))){
        //p는 찾은 문자열부터 들어가있음
        //특정문자 tar 앞에 있는 문자열 temp에 저장
        char front[20]={0};
        strncpy(front,vect,strlen(vect)-strlen(p));
        //특정문자 없앤 것 temp에 cat
        char back[20]={0};
        strcat(back,&p[strlen(tar)]);            
    }
    return 0;
}
/*
#include <string.h>
#include <stdio.h>

int main(){
	char vect[100] = "DBABCEQABC";
	char tar[4] = "ABC";

	int tn = strlen(tar);

	while (1){
		char *p = strstr(vect, tar);
		if (p == NULL) break;
		strcpy(p, p + tn);
	}

	printf("%s", vect);
	return 0;
}


*/