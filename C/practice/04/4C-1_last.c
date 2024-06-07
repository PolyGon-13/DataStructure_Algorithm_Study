#include <stdio.h>

#define N 10

int main() 
{
	int a[N];
	int cnt=0;
	int retry;
	puts("정수를 입력하세요.");
	do
	{
		printf("%d번째 정수 : ",cnt+1);
		scanf("%d",&a[cnt++%N]); // 0~9까지 10개의 수를 저장한 뒤 더 저장하는 경우 cnt++%N을 통해 0번째 인덱스부터 다시 덮어씀 (링 버퍼)
		printf("계속할까요?(Yes---1 / No---0) : ");
		scanf("%d",&retry);
	} while(retry==1);
	
	int i=cnt-N; // cnt에 N을 빼주어 가장 마지막에 입려된 N개의 수를 출력할 수 있도록 함
	if(i<0) i=0;
	for(;i<cnt;i++)
		printf("%2d번째 정수 = %d\n",i+1,a[i%N]);
	
	return 0;
}
