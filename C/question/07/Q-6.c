#include <stdio.h>
#include <string.h>

const char* str_chr(const char *s,int c)
{	
	int len=strlen(s);
	const char *p=s+len-1; // 문자열의 끝을 가리키는 포인터
	// s는 문자열의 시작을 가리키고 있고, 문자열의 길이를 더하고 1을 빼주면 문자열의 끝을 가리키는 포인터가 된다.
	
	while(p>=s)
	{
		if(*p==(char)c)
			return p;
		p--;
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
