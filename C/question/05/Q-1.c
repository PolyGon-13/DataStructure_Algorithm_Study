#include <stdio.h>

int main()
{
	int i;
	int x;
	printf("정수를 입력하세요 : ");
	scanf("%d",&x);
	
	int sum=1;
	for(i=1;i<=x;i++)
		sum*=i;
	printf("%d의 순차곱셈값은 %d입니다.\n",x,sum);
	
	return 0;
}
