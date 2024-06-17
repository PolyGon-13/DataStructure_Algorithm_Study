#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void bubble(int a[],int n)
{
	int j;
	int k=0;
	while(k<n-1)
	{
		int last=n-1;
		for(j=n-1;j>k;j--)
			if(a[j-1]>a[j])
			{
				swap(int,a[j-1],a[j]);
				last=j;
			}
	}
}

int main()
{
	int nx;
	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int* x=calloc(nx,sizeof(int));
	
	int i;
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}
	
	bubble(x,nx);
	
	puts("오름차순으로 정렬했습니다.");
	for(i=0;i<nx;i++)
		printf("x[%d]=%d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
