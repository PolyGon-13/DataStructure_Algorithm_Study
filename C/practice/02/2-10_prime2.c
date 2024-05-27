#include <stdio.h>

int main()
{
	int prime[5000];
	int ptr=0;
	unsigned long counter=0;
	int n,i;
	
	prime[ptr++]=2;
	
	for(n=3;n<=1000;n+=2)
	{		
		for(i=1;i<ptr;i++)
		{
			counter++;
			if(n%prime[i]==0) break;
		}
		
		if(ptr==i)
			prime[ptr++]=n;
	}
	
	for(i=0;i<ptr;i++)
		printf("%d\n",prime[i]);
	
	printf("나눗셈을 실행한 횟수: %lu\n",counter);
	
	return 0;
}
