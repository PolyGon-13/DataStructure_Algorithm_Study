#include <stdio.h>

int str_ncmp(const char *s1,const char *s2,int n)
{
	int i;
    for(i=0;i<n;++i)
        if(s1[i]!=s2[i] || s1[i]=='\0' || s2[i]=='\0') // i번째 문자가 다르거나, 문자열의 끝에 도달했을 때
            return (unsigned char)s1[i]-(unsigned char)s2[i];
	
    return 0; // 두 문자열이 같은 경우
}

int main()
{
    char st[128];
    puts("\"STRING\"의 처음 3개의 문자와 비교합니다.");
    puts("\"XXXX\"를 입력하면 종료합니다.");
    
    while(1)
    {
        printf("문자열 st : ");
        scanf("%s", st);
        if (str_ncmp("XXXX", st, 3)==0)
            break;
        printf("str_ncmp(\"STRING\", st, 3) = %d\n",str_ncmp("STRING",st,3));
    }
    
    return 0;
}
