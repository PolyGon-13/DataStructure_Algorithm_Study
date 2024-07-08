#include <stdio.h>

char upper(char c)
{
	if(c>='a' && c<='z')
		return c-32;
	else
		return c;
}

int compare(char c1,char c2)
{
	return upper(c1)-upper(c2);
}

int str_cmpic(const char *s1,const char *s2)
{
	while(*s1 && *s2)
	{
		int diff=compare(*s1,*s2);
		if(*s1=='\0')
			return 0;
		s1++;
		s2++;
	}
	
	return compare(*s1,*s2);
}

int str_ncmpic(const char *s1,const char *s2,int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		if(*s1=='\0' || *s2=='\0')
			return compare(*s1,*s2);
		int diff=compare(*s1,*s2);
		if(diff!=0)
			return diff;
		s1++;
		s2++;
	}
	
	return 0;
}

int main()
{
    char st[128];
    puts("\"STRING\"의 처음 3개의 문자와 비교합니다.");
    puts("\"XXXX\"를 입력하면 종료합니다.");
    
    while(1)
    {
        printf("문자열 st : ");
        scanf("%s",st);
        if(str_ncmpic("XXXX",st,3)==0)
            break;
        printf("%d %d\n",str_cmpic("STRING",st),str_ncmpic("STRING",st,3));
    }
    
    return 0;
}
