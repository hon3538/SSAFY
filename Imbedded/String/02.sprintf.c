#include <string.h>
#include <stdio.h>

void go(const char* input)
{
	char str[100];
	strcpy(str, input);

	//띄어쓰기를 '_' 로 바꾸기
	for (int i = 0; str[i]; i++) {
		if (str[i] == ' ') str[i] = '_';
	}

	//파싱
	float time;
	char msg[100];
	char result[100];

	sscanf(str, "[%f]%s", &time, msg);

	//'_'를 띄어쓰기로 바꾸기
	for (int i = 0; msg[i]; i++) {
		if (msg[i] == '_') msg[i] = ' ';
	}

	sprintf(result, "%d sec :%s", (int)time, msg);

	printf("%s\n", result);
}

int main()
{
	const char* p[3] = {
		"[000053.163123] MIN CO MIN CO MIN CO",
		"[004351.231231] EMBEDDED EM EM EM",
		"[123456.654321] HO HO HO KKK",
	};

	for (int y = 0; y < 3; y++) {
		go(p[y]);
	}

	return 0;
}
