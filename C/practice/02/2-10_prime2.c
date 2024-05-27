#include <stdio.h>

int main()
{
	int prime[500];
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
	// prime 배열에 2를 넣은 후 ptr은 1이다. n=3일 때, i=1이 초기값이지만 조건식 i<ptr을 만족하지 못해 for문 진입 불가능. i가 초기값 1인 상태이므로 ptr과 같다. 따라서 prime 배열에 3이 진입.
	// 이후 숫자들은 prime 배열의 모든 요소들로 나누어지게 되는데, 모든 요소들로 나누었지만 나머지가 0이 되지 않아 break 당하지 않은 경우 그 당시 i는 ptr-1이지만 for문을 나오면서 후위식 i++로 인해 i는 ptr과 같게 된다.
	
	for(i=0;i<ptr;i++)
		printf("%d\n",prime[i]);
	
	printf("나눗셈을 실행한 횟수: %lu\n",counter);
	
	return 0;
}
