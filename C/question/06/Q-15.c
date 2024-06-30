#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x; x=y; y=t;} while(0)

void insertion(int a[],int n)
{
	puts("단순 삽입 정렬");
	int i,j;
	
	for(i=1;i<n;i++)
	{
		int tmp=a[i];
		for(j=i;j>0 && a[j-1]>tmp;j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}
}

int sort3elem(int x[],int a,int b,int c)
{
	if(x[b]<x[a]) swap(int,x[b],x[a]);
	if(x[c]<x[b]) swap(int,x[c],x[b]);
	if(x[b]<x[a]) swap(int,x[b],x[a]);
	return b;
}

void quick(int a[],int left,int right)
{
	puts("퀵 정렬");
	int pl=left;
	int pr=right;
	int m=sort3elem(a,pl,(pl+pr)/2,pr);
	int x=a[m];
	
	swap(int,a[m],a[right-1]);
	pl++;
	pr-=2;
	
	do
	{
		while(a[pl]<x) pl++;
		while(a[pr]>x) pr--;
		if(pl<=pr)
		{
			swap(int,a[pl],a[pr]);
			pl++;
			pr--;
		}
	} while(pl<=pr);
	
	if(left<pr) quick(a,left,pr);
	if(pl<right) quick(a,pl,right);
}

int main()
{
	int i;
	int nx;
	puts("정렬");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int *x=calloc(nx,sizeof(int));
	
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}
	
	if(nx<=9)
		insertion(&x[0],nx);
	else
		quick(x,0,nx-1);
	
	puts("오름차순으로 정렬했습니다.");
	for(i=0;i<nx;i++)
		printf("x[%d] = %d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
