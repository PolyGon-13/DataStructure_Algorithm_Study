// Ver1.7-6
#include <stdio.h>
#include <string.h>

size_t str_len(const char *s)
{
	int len=0;
	
	while(*s++)
		len++;
	
	return len;
}

int main()
{
	char str[256];
	printf("문자열 : ");
	scanf("%s",str);
	printf("이 문자열의 길이는 %ld입니다.\n",str_len(str));
	
	return 0;
}

// Ver2.7-7
/*
#include <stdio.h>
#include <string.h>

size_t str_len(const char *s)
{
	size_t len=0;
	
	while(*s++)
		len++;
	
	return len;
}

int main()
{
	char str[256];
	printf("문자열 : ");
	scanf("%s",str);
	printf("이 문자열의 길이는 %ld입니다.\n",str_len(str));
	
	return 0;
}
*/

// Ver3.7-8
/*

*/
