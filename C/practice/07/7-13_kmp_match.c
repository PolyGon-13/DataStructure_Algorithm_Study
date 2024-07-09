#include <stdio.h>

int kmp_match(const char txt[],const char pat[])
{
	int pt=1; // kmp법에서 패턴끼리 비교하여 다시 시작값의 표를 작성하기 위해 시작포인트를 1번 인덱스로 지정
	int pp=0;
	int skip[1024]; // 다시 시작값의 표를 저장할 배열
	
	skip[pt]=0;
	while(pat[pt]!='\0')
	{
		if(pat[pt]==pat[pp]) // 패턴끼리 일치하는 부분 발견
			skip[++pt]=++pp;
		else if(pp==0) // 패턴끼리 일치X && pp가 0인 경우
			skip[++pt]=pp;
		else // 패턴끼리 일치X && pp가 0이 아닌 경우
			pp=skip[pp]; // 이전에 일치했던 부분 제외
	}
	
	pt=pp=0;
	while(txt[pt]!='\0' && pat[pp]!='\0')
	{
		if(txt[pt]==pat[pp]) // 문자끼리 일치하는 경우
		{
			pt++;
			pp++;
			// 텍스트와 패턴 1칸 이동하여 다음 문자를 계속해서 비교
		}
		else if(pp==0) // 문자끼리 일치X && pp가 0인 경우
			pt++; // 텍스트 1칸 이동
		else // 문자끼리 일치X && pp가 0이 아닌 경우
			pp=skip[pp];
	}
	
	if(pat[pp]=='\0')
		return pt-pp;
	
	return -1;
}

int main()
{
	char s1[256];
	char s2[256];
	puts("KMP법");
	printf("텍스트 : ");
	scanf("%s",s1);
	printf("패턴 : ");
	scanf("%s",s2);
	
	int idx=kmp_match(s1,s2);
	if(idx==-1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n",idx+1);
	
	return 0;
}
