#include <stdio.h>

int main()
{
	int a;
	int cnt=1;
	scanf("%d",&a);
	
	while(a>=10)
	{
		cnt++;
		a/=10;
	}
	
	printf("그 수는 %d자리입니다.\n",cnt);
	return 0;
}
