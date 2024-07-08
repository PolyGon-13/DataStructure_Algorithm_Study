#include <stdio.h>
#include <string.h>

int bf_match(const char txt[], const  char pat[]) 
{
     int pt = 0;
     int pp = 0;
     int pp_last = 0;
     
     while(txt[pt] != '\0') // 텍스트의 끝을 찾아서 pt에 저장
         pt++;
     while(pat[pp] != '\0') // 패턴의 끝을 찾아서 pp에 저장
         pp++;
     pp_last = pp - 1; // 패턴의 마지막 인덱스 저장
     
	 while(pt >= 0 && pp >= 0)
	 {
		 if(txt[pt] == pat[pp]) // 현재 인덱스의 텍스트와 패턴의 문자가 일치하는 경우
		 {
			 pt--;
			 pp--;
			 // 왼쪽으로 한 칸씩 이동
		 }
		 else
		 {
			 pt = pt + pp_last - 1; // 현재 인덱스 + 패턴의 길이 -1
			 pp = pp_last; // 패턴의 문자열 인덱스는 다시 마지막으로 돌아감
		 }
	 }
	
     if(pp == -1) // 패턴 문자열이 -1이라면 패턴이 텍스트 안에서 발견된 것
         return pt + 1; // 패턴이 시작된 인덱스 반환
	
     return -1; // 패턴을 찾지 못한 경우
}

int main() 
{
     int idx;
     char s1[256];
     char s2[256];
     puts("브루트 포스법");
     printf("텍스트 : ");
     scanf("%s", s1);
     printf("패턴 : ");
     scanf("%s", s2);
     
     idx = bf_match(s1, s2);
     if(idx == -1)
         puts("텍스트에 패턴이 없습니다.");
     else
         printf("%d번째 문자부터 match합니다.\n", idx + 1);
     
     return 0;
}

/*
int bf_matchr(const char txt[], const char pat[])
{
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int pt = txt_len - pat_len;
	int pp;


	while (pt >= 0) 
	{
		pp = 0;
		while (txt[pt] == pat[pp]) 
		{
 		if (pp == pat_len - 1)
				return pt - pp;
			pp++;
			pt++;
		}
		pt = pt - pp - 1;
	}

	return -1;
}
*/
