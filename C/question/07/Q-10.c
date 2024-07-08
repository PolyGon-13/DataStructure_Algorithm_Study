#include <stdio.h>
#include <string.h>

int bf_match(const char txt[], const  char pat[]) 
{
     int pt = 0;
     int pp = 0;
     int pp_last = 0;
     
     while(txt[pt] != '\0')
         pt++;
     while(pat[pp] != '\0')
         pp++;
     
     pp_last = pp - 1; // pat의 끝자리
     
     //시작은 각 문자열의 널문자부터인데 딱히 상관없을듯.
     while(pt >= 0 && pp >= 0) 
	 {
         if(txt[pt] == pat[pp]) 
		 {
             pt--;
             pp--;
         } 
		 else 
		 {
             pt = pt + pp_last - 1;
             pp = pp_last;
         }
     }
	
     if(pp == -1)
         return pt + 1;
	
     return -1;
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
