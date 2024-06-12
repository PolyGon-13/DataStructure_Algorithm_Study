#include <stdio.h>
#include <string.h>

static char memo[128][1024]; // static변수 => 자동으로 0으로 초기화시켜줌

void recur(int n)
{
	if(memo[n+1][0]!='\0') // '\0'은 문자열의 끝을 나타냄
		printf("%s",memo[n+1]);
	else
	{
		if(n>0)
		{
			recur(n-1);
			printf("%d\n",n);
			recur(n-2);
			sprintf(memo[n+1],"%s%d\n%s",memo[n],n,memo[n-1]); // sprintf(str,format) => 문자열 생성 함수. format에 맞는 문자열을 str에 생성
		}
		else
			strcpy(memo[n+1],""); // strcpy(str1,str2) => str2에 있는 문자열을 str1으로 복사
	}
}
// 머리로 이해하기 어려우면 직접 그려보면서 이해 => 재귀 알고리즘을 무작정 이용한 것보다 메모제이션을 사용하면 recur함수 호출 횟수가 상당히 줄어듦

int main()
{
	int x;
	printf("정수를 입력하세요: ");
	scanf("%d",&x);
	
	recur(x);
	
	return 0;
}
