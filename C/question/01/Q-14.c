#include <stdio.h>

int main()
{
	int n;
	int i,j;
	
	printf("정사각형을 출력합니다.\n");
	printf("입력할 수: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("*");
		}
		putchar('\n');
	}
	return 0;
}
