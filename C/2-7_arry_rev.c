#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x; x=y; y=t;} while(0) // do문에서 제어식이 0이므로 {}안의 코드는 1회만 실행

void ary_reverse(int a[],int n)
{
	int i;
	
	for(i=0;i<n/2;i++)
		swap(int,a[i],a[n-i-1]);
}

int main()
{
	int nx;
	int i;
	
	printf("요소 개수: ");
	scanf("%d",&nx);
	
	int* x=calloc(nx,sizeof(int));
	for(i=0;i<nx;i++)
	{
		printf("x[%d]: ",i);
		scanf("%d",&x[i]);
	}
	
	ary_reverse(x,nx);
	printf("배열의 요소를 역순으로 정렬했습니다.\n");
	
	for(i=0;i<nx;i++)
		printf("x[%d]=%d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
