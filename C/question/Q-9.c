#include <stdio.h>

int sumof(int a, int b)
{
	int i;
	int sum=0;
	
	for(i=a;i<=b;i++)
	{
		sum+=i;
	}
	return sum;
}

int main()
{
	int a,b;
	
	printf("a값: ");
	scanf("%d",&a);
	printf("b값: ");
	scanf("%d",&b);
	
	if(a>b) printf("a와 b 사이 모든 정수의 합: %d",sumof(b,a));
	else printf("a와 b 사이 모든 정수의 합: %d",sumof(a,b));
	
	return 0;
}
