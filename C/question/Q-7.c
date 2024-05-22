#include <stdio.h>

int main()
{
	int a,i;
	int sum=0;
	scanf("%d",&a);
	
	for(i=1;i<=a;i++)
	{
		sum+=i;
		if(i<a) printf("%d + ",i);
		else printf("%d = %d",i,sum);
	}
	
	return 0;
}
