#include <stdio.h>
#include <string.h>

int main()
{
	char s1[256],s2[256];
	puts("strstr 함수");
	printf("텍스트 : ");
	scanf("%s",s1);
	printf("패턴 : ");
	scanf("%s",s2);
	
	char *p=strstr(s1,s2);
	if(p==NULL)
		printf("텍스트에 패턴이 없습니다.\n");
	else
	{
		int ofs=p-s1; // 찾은 문자에 대한 포인터에서 s1배열의 시작점을 가리키는 포인터를 빼면, 두 포인터 간의 거리를 계산할 수 있음
		printf("\n%s\n",s1);
		printf("%*s|\n",ofs,"");
		printf("%*s%s\n",ofs,"",s2);
	}
	
	return 0;
}
