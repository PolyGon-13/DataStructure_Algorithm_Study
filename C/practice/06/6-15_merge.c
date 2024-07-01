#include <stdio.h>
#include <stdlib.h>

static int *buff;

static void __mergesort(int a[],int left,int right)
{
	int center,i,k;
	int j=0;
	int p=0;
	
	if(left<right)
	{
		center=(left+right)/2;
		p=0;
		j=0;
		k=left;
		
		__mergesort(a,left,center);
		__mergesort(a,center+1,right);
		
		for(i=left;i<=center;i++)
			buff[p++]=a[i];
		while(i<=right && j<p)
			a[k++]=(buff[j]<=a[i]) ? buff[j++] : a[i++];
		while(j<p)
			a[k++]=buff[j++];
	}
}

int mergesort(int a[],int n)
{
	if((buff=calloc(n,sizeof(int)))==NULL)
		return -1;
	__mergesort(a,0,n-1);
	
	free(buff);
	
	return 0;
}

int main()
{
	int i;
	int nx;
	puts("병합 정렬");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	
	int *x=calloc(nx,sizeof(int));
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}
	
	mergesort(x,nx);
	
	puts("오름차순으로 정렬했습니다.");
	for(i=0;i<nx;i++)
		printf("x[%d] = %d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
