#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_string(const void *a,const void *b)
{
	return strcmp((const char *)a,(const char *)b);
	// 포인터 a를 const char * 타입으로 캐스팅
}

int compare_string_pointers(const void *a,const void *b)
{
	return strcmp(*(const char **)a,*(const char **)b);
	// 포인터 a가 가리키는 메모리 주소에 있는 값
	// char *은 문자열을 가리키는 포인터를 의미
	// char **은 문자열 포인터를 가리키는 포인터를 의미
}

int main()
{
	char a[][7]={"LISP","C","Ada","Pascal"};
	char *p[]={"LISP","C","Ada","Pascal"};
	int i;
	
	qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),compare_string);
	puts("a배열 정렬완료!");
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		printf("%s\n",a[i]);
	putchar('\n');
	
	qsort(p,sizeof(p)/sizeof(p[0]),sizeof(p[0]),compare_string_pointers);
	puts("p배열 정렬완료!");
	for(i=0;i<sizeof(p)/sizeof(p[0]);i++)
		printf("%s\n",p[i]);
	
	return 0;
}
