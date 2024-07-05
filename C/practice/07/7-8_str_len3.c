#include <stdio.h>
#include <string.h>

int str_len(const char *s)
{
	const char *p=s; // 문자열의 시작 주소
	
	while(*s)
		s++;
	// while문이 끝난 시점에서 s는 문자열의 마지막 주소를 가리키고 있음
	
	return s-p;
}

int main()
{
	char str[256];
	printf("문자열 : ");
	scanf("%s",str);
	printf("이 문자열의 길이는 %d입니다.\n",str_len(str));
	
	return 0;
}
