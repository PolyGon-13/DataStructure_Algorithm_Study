// 가우스 덧셈
#include <stdio.h>

int main()
{
	int n;
	int sum=0;
	scanf("%d",&n);
	
	if(n/2==0) sum=(1+n)*(n/2);
	else sum=(1+n)*(n/2)+(n-(n/2));
	
	printf("1부터 %d까지의 합은 %d입니다.",n,sum);
	return 0;
}
