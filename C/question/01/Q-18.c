#include <stdio.h>

void nrpira(int n)
{
	int i,j;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i-1;j++)
			putchar(' ');
		for(j=1;j<=(n-i)*2+1;j++) // {(전체 열 수)-(현재 출력 중인 행)}*2+1
			printf("%d",i%10);
		putchar('\n');
	}
}

int main()
{
	int n;
	printf("숫자를 입력하세요: ");
	scanf("%d",&n);
	
	nrpira(n);
	return 0;
}
