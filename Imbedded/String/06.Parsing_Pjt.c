#include <stdio.h>


char top_log[3][20];
int cnt[3]={0};
//rank 미루는 함수 from 에 업데이트될것임
void moveRank(int from){
	for(int i=2;i>from;i--){
		strcpy(top_log[i],top_log[i-1]);
		cnt[i]=cnt[i-1];
	}
}
int main(){
	 FILE *fp =fopen("log.txt","r");

	 char buf[1000];
	 fgets(buf, 1000, fp);
	 char *before=strtok(buf,"combo");
	 printf("%s\n",before);
	 int count=1;

	 while(!feof(fp)){
		 char buf[1000];
		 //한줄 읽기
		 fgets(buf, 1000, fp);
		 char *p=strtok(buf,"combo");
		 //이전 시간과 비교
		 if(strcmp(before,p)==0){
			 count++;
		 }else{
			 //top들과 비교
			 for(int i=0;i<3;i++){ //cnt[i]가 비었으면 그걸 우선넣어줘야하는데 일단 스킵
				 if(cnt[i]<=count){
					moveRank(i);
					cnt[i]=count;
					strcpy(top_log[i],before);
					break;
				 }
			 }
			 // 새로 업데이트
			 strcpy(before,p);
			 count=1;
		 }
		//printf("%s\n",p);
		 //한줄 출력하기
		 //printf("%s",buf);
	 }
	 //마지막 예외처리
	 for(int i=0;i<3;i++){
	 	if(cnt[i]<=count){
	 		moveRank(i);
	 		cnt[i]=count;
	 		strcpy(top_log[i],before);
	 		break;
	 	}
	 }
	 for(int i=0;i<3;i++){
		// printf("%s %d\n",top_log[i],cnt[i]);
	 }
	 fclose(fp);
	 fp=fopen("log.txt","r");


	 while(!feof(fp)){
		 char buf[1000];
		 fgets(buf, 1000, fp);

		 for(int i=0;i<3;i++){
			 if(strstr(buf,top_log[i])!=NULL){
				 printf("%s",buf);
				 break;
			 }
		 }
	 }
	 fclose(fp);
	 return 0;
}

