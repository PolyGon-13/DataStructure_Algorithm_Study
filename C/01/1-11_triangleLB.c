#include <stdio.h>

int main()
{
	int n;
	int i,j;
	
	do{
		printf("몇 단 삼각형입니까?: ");
		scanf("%d",&n);
	}while(n<=0);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
	
	return 0;
}
