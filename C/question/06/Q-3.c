#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

int is_sorted(const int a[],int n)
{
	int i;
	for(i=n-1;i>0;i--)
		if(a[i-1]>a[i])
			return 0;
	return 1;
}

void bubble(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--)
			if(a[j-1]>a[j])
				swap(int,a[j-1],a[j]);
		if(is_sorted(a,n))
			break;
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
