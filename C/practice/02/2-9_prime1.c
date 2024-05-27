#include <stdio.h>

int main()
{
	unsigned long counter=0;
	int n;
	
	for(n=2;n<=1000;n++)
	{
		int i;
		
		for(i=2;i<n;i++)
		{
			counter++;
			if(n%i==0) break;
		}
		
		if(n==i) printf("%d\n",n);
	}
	printf("나눗셈을 실행한 횟수: %lu\n",counter);
	
	return 0;
}
