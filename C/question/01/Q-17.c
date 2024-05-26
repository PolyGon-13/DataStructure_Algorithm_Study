#include <stdio.h>

void spira(int n)
{
	int i,j;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
			putchar(' ');
		for(j=1;j<=(i-1)*2+1;j++) // i행에 *문자가 몇 개 오는지 판단
			putchar('*');
		putchar('\n');
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	spira(n);
	return 0;
}
