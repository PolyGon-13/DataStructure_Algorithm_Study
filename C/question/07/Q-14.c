#include <stdio.h>
#include <string.h>

char *str_rstr(const char txt[],const char pat[])
{
	int pt=0;
	int pp=0;
	int pp_last=0;
	
	while(txt[pt]!='\0')
		pt++;
	while(pat[pp]!='\0')
		pp++;
	
	pp_last=pp-1; // 패턴의 마지막 인덱스
	
	while(pt>=0 && pp>=0)
	{
		if(txt[pt]==pat[pp])
		{
			pt--;
			pp--;
		}
		else
		{
			pt+=pp_last-1; 
			// 일치하지 않는다면 현재 pt 위치를 기준으로 나머지 값들은 일치해도 앞선 패턴들과 일치하지 않았기 때문에 서로 다름
			// 그렇기에 패턴의 마지막 인덱스에서 1을 뺀 값을 더해주면 비교할 필요 없는 인덱스들은 모두 건너뛸 수 있음
			pp=pp_last; // 패턴 커서는 다시 마지막 인덱스로 이동
		}
	}
	if(pp==-1)
		return &txt[pt+1]; // 일치하는 경우에 마지막까지 pt--를 수행하고 오기 때문
	
	return NULL;
}

int main()
{
	char *idx;
	char s1[256];
	char s2[256];
	puts("보이어-무어법");
	printf("텍스트 : ");
	scanf("%s",s1);
	printf("패턴 : ");
	scanf("%s",s2);
	
	idx=str_rstr(s1,s2);
	if(idx==-1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n",idx-s1+1);
	
	return 0;
}
