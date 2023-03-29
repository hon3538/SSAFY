#include <string.h>
#include <stdio.h>

int main()
{
	const char* p[7] = { "BTS", "BTS", "BBQ", "BTS", "BBQ", "ABCD", "AS"};
	char str[7][10];
	int n = 7;
	
	for (int i = 0; i < 7; i++) {
		strcpy(str[i], p[i]);
	}
	
	for (int y = 0; y < n; y++) {
		for (int x = y + 1; x < n; x++) {
			if (strcmp(str[y], str[x]) == 1) {
				char temp[10];
				strcpy(temp, str[y]);
				strcpy(str[y], str[x]);
				strcpy(str[x], temp);
			}
		}
	}
	
	char old[10] = { 0 };
	for (int y = 0; y < n; y++) {
		if (strcmp(old, str[y]) == 0) continue;
		printf("%s\n", str[y]);
		strcpy(old, str[y]);
	}
	
	return 0;
}