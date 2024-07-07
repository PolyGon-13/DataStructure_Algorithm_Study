#include <stdio.h>

const char* str_chr(const char *s,int c)
{	
	while(*s!='\0')
	{
		if(*s==(char)c)	
			return s;
		s++;
	}
	return NULL;
}

int main()
{
	char str[128];
	char ch;
	
	printf("문자열 : ");
	scanf("%s",str);
	
	getchar();
	
	printf("검색할 문자 : ");
	scanf("%c",&ch);
	
	const char *result=str_chr(str,ch);
	
	if(result==NULL)
		printf("문자 %c은(는) 문자열에 없습니다.\n",ch);
	else
		printf("문자 %c은(는) %ld번째에 있습니다.\n",ch,result-str+1);
	
	return 0;
}
