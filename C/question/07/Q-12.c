#include <stdio.h>
#include <string.h>
#include <limits.h>

void _print(const char txt[],const char pat[],int txt_len,int pat_len,int pt,int pp)
{
	int i=0,k=0;
	
	if(pp!=pat_len-1) // 현재 패턴 커서가 가장 처음(패턴 배열의 마지막 요소)을 가리키고 있지 않을 때
		printf("    ");
	else // 패턴 커서가 가장 처음을 가리키고 있을 때
	{
		printf("%2d  ",pt-pp); 
		// 텍스트 커서에서 패턴 커서를 뺀 값 = 현재 텍스트 커서의 위치를 마지막으로 하는 패턴 배열만큼의 길이
		k=pt-pp;
	}
	
	for(i=0;i<txt_len;i++)
		printf("%c ",txt[i]); // 텍스트 배열 출력
	putchar('\n');
	
	printf("%*s%c\n",pt*2+4,"",(txt[pt]==pat[pp]) ? '+' : '|');
	
	printf("%*s",(pt-pp)*2+4,"");
	for(i=0;i<pat_len;i++)
		printf("%c ",pat[i]);
	printf("\n\n");
}

int bm_match(const char txt[],const char pat[])
{
	int pt,pp;
	int txt_len=strlen(txt);
	int pat_len=strlen(pat);
	int skip[UCHAR_MAX+1];
	
	for(pt=0;pt<=UCHAR_MAX;pt++)
		skip[pt]=pat_len;
	// unsigned char형으로 출력할 수 있는 모든 문자의 개수만큼 배열의 크기로 설정하고 모든 인덱스의 요소를 패턴의 크기로 설정
	
	for(pt=0;pt<pat_len-1;pt++)
		skip[pat[pt]]=pat_len-pt-1; 
	//skip 배열에서 pat[pt]는 패턴의 문자를 의미하므로 패턴에 들어있는 문자만을 이용하고 있음
	// 마지막에 나오는 위치의 인덱스가 k이면 패턴을 옮길 크기는 n-k-1
	
	
	while(pt<txt_len)
	{
		pp=pat_len-1; // 길이는 1부터 시작하지만, 배열의 인덱스는 0부터 시작하기 때문
		while(_print(txt,pat,txt_len,pat_len,pt,pp),txt[pt]==pat[pp])
		// _print함수를 먼저 실행하고 txt[pt]==pat[pp]를 평가
		{
			if(pp==0) // 모든 패턴을 만족시켜 패턴의 앞쪽 끝에 도달한 경우
				return pt; // 현재 텍스트를 가리키고 있는 커서를 반환
			pp--;
			pt--;
		}
		int a=skip[txt[pt]];
		int b=pat_len-pp;
		pt+=(skip[txt[pt]]>pat_len-pp) ? skip[txt[pt]] : pat_len-pp;
	}
	
	return -1;
}

int main()
{
	char s1[256];
	char s2[256];
	puts("보이어-무어법");
	printf("텍스트 : ");
	scanf("%s",s1);
	printf("패턴 : ");
	scanf("%s",s2);
	
	int idx=bm_match(s1,s2);
	if(idx==-1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n",idx+1);
	
	return 0;
}
