#include <stdio.h>
#include <string.h>

void swap_str(char *x,char *y)
{
	int len_x=strlen(x);
	int len_y=strlen(y);
	int max_len=(len_x>len_y) ? len_x : len_y;
	char tmp[max_len+1];
	
	strcpy(tmp,x);
	strcpy(x,y);
	strcpy(y,tmp);
}

int main()
{
	char s1[]="ABCD";
	char s2[]="EFGH";
	
	printf("포인터 s1은 \"%s\"를 가리킵니다.\n",s1);
	printf("포인터 s2는 \"%s\"를 가리킵니다.\n",s2);
	
	swap_str(s1,s2);
	
	puts("\n포인터 s1과 s2의 값을 서로 교환했습니다.\n");
	
	printf("포인터 s1은 \"%s\"를 가리킵니다.\n",s1);
	printf("포인터 s2는 \"%s\"를 가리킵니다.\n",s2);
	
	return 0;
}
