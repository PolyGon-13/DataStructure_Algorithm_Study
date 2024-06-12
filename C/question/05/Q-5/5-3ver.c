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
