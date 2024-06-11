#include <stdio.h>

void recur(int n)
{
Top:
	if(n>0)
	{
		recur(n-1);
		printf("%d\n",n);
		n=n-2;
		goto Top;
	}
	
}

int main()
{
	int x;
	printf("정수를 입력하세요: ");
	scanf("%d",&x);
	recur(x);
	
	return 0;
}
