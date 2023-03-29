#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int isNum(char* str)
{
	for (int i = 0; str[i]; i++) {
		if (!(str[i] >= '0' && str[i] <= '9')) return 0;
	}
	return 1;
}

int main()
{
	const char* vect = "DATA|32ALL|0|200|100|ABABC|200";
	char str[100];
	char result[100] = { 0 };
	
	int sum = 0;
	const char *div = "|";
	strcpy(str, vect);
	
	for (char* p = strtok(str, "|"); p != NULL; p = strtok(NULL, "|")) {
		if (isNum(p) == 0 && strcmp("0", p)) {
			//문자열
			strcat(result, p);
			strcat(result, "|");
		}
		else {
			//숫자
			sum += atoi(p);
		}
	}
	
	int n = strlen(result);
	result[n - 1] = '\0';
	
	printf("sum : %d\n", sum);
	printf("other : %s\n", result);
	
	return 0;
}
