// 5-3ver
#include <stdio.h>

static int cnt;

void recur(int n)
{
	if(n>0)
	{
		recur(n-1);
		cnt++;
		printf("%d\n",n);
		recur(n-2);
		cnt++;
	}
}

int main()
{
	int x;
	printf("정수를 입력하세요: ");
	scanf("%d",&x);
	
	cnt++;
	recur(x);
	printf("\n%d\n",cnt);
	
	return 0;
}


// 5-6ver
#include <stdio.h>
#include <string.h>

static char memo[128][1024];
int cnt=0;

void recur(int n)
{
	if(memo[n+1][0]!='\0')
		printf("%s",memo[n+1]);
	else
	{
		if(n>0)
		{
			recur(n-1);
			cnt++;
			printf("%d\n",n);
			recur(n-2);
			cnt++;
			sprintf(memo[n+1],"%s%d\n%s",memo[n],n,memo[n-1]);
		}
		else
			strcpy(memo[n+1],"");
	}
}

int main()
{
	int x;
	printf("정수를 입력하세요: ");
	scanf("%d",&x);
	
	cnt++;
	recur(x);
	printf("\n%d\n",cnt);
	
	return 0;
}
