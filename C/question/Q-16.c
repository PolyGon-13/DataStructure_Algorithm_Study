#include <stdio.h>

int i,j;

void triangleLB(int n) //왼쪽 아래가 직각인 이등변 삼각형 
{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
}

void triangleLU(int n) // 왼쪽 위가 직각인 이등변 삼각형 
{
	for(i=n;i>0;i--)
	{
		for(j=1;j<=i;j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
}

void triangleRU(int n) // 오른쪽 위가 직각인 이등변 삼각형 
{
	return 0;
}

void triangleRB(int n) // 오른쪽 아래가 직각인 이등변 삼각형 
{
	return 0;
}

int main()
{
	int n;
	
	do{
		printf("몇 단 삼각형입니까?: ");
		scanf("%d",&n);
	}while(n<=0);
	
	triangleLU(n);
	return 0;
}
