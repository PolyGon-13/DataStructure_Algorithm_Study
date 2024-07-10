#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm_match(const char txt[],const char pat[])
{
	int pt,pp;
	int txt_len=strlen(txt);
	int pat_len=strlen(pat);
	int skip[UCHAR_MAX+1];
	
	for(pt=0;pt<=UCHAR_MAX;pt++)
		skip[pt]=pat_len;
	for(pt=0;pt<pat_len-1;pt++)
		skip[pat[pt]]=pat_len-pt-1;
	
	while(pt<txt_len)
	{
		pp=pat_len-1;
		while(txt[pt]==pat[pp])
		{
			if(pp==0)
				return pt;
			pp--;
			pt--;
		}
		pt+=(skip[txt[pt]]>pat_len-pp) ? skip[txt[pt]] : pat_len-pp;
		/*
		마지막 문자를 제외하고, 비교 과정에서 이미 텍스트에서 한 번 등장한 패턴 안의 문자가 또 텍스트에서 등장한 경우
		원래의 skip 배열 값은 pat_len-pt-1의 값으로 지정되어 있는데 그것보다 더 큰 값이 나오게 된다는 건, 텍스트에서 등장한 문자가 다시 등장하게 되었음을 의미
		이 코드를 사용해야 뒤로 안가고 앞으로 가게 해줌 (코드에서 위치지정은 현재인덱스+이동할 거리=이동한 패턴의 마지막 문자 위치이기 때문)
  
		패턴의 마지막 문자의 중복에 대한 경우는 처음부터 skip 배열 안에 n으로 지정하여, 현재 인덱스+n=다음 검사할 패턴의 마지막 문자위치라는 식을 도입하였는데, 
 		패턴의 자미가 문자 이외에 다른 문자들이 한 번 이상 등장하게 되면, 현재 인덱스+x 위치의 결과로 기존의 패턴위치보다 뒤로 갈 수 있는 경우가 생기기에 이를 방지하기 위함
		*/
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
