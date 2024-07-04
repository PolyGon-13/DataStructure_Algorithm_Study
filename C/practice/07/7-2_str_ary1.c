#include <stdio.h>

int main()
{
	char st[8];
	
	st[0]='A';
	st[1]='B';
	st[2]='C';
	st[3]='D';
	st[4]='\0'; // 널 문자 안 넣으면 문자가 깨져서 나옴
	printf("문자열 st에는 \"%s\"가 들어있습니다.\n",st);
	
	return 0;
}
