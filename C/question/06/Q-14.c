// Ver.1 (6-9)
#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x; x=y; y=t;} while(0)

void quick(int a[],int left,int right)
{
	int pl=left;
	int pr=right;
	int x=a[(pl+pr)/2];
	
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
	
	if(pr-left<right-pl)
	{
		swap(int,pl,left);
		swap(int,pr,right);
	}
	
	if(left<pr) quick(a,left,pr);
	if(pl<right) quick(a,pl,right);
}

int main()
{
	int i;
	int nx;
	puts("퀵 정렬");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int *x=malloc(nx*sizeof(int));
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}
	
	quick(x,0,nx-1);
	
	puts("오름차순으로 정렬했습니다.");
	for(i=0;i<nx;i++)
		printf("x[%d] = %d\n",i,x[i]);
	
	free(x);
	
	return 0;
}


// Ver.2 (6-10)
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type,x,y) do{type t=x; x=y; y=t;} while(0)

void quick(int a[],int left,int right)
{
	IntStack lstack;
	IntStack rstack;
	
	Initialize(&lstack,right-left+1);
	Initialize(&rstack,right-left+1);
	
	Push(&lstack,left);
	Push(&rstack,right);
	
	while(!IsEmpty(&lstack))
	{
		int pl=(Pop(&lstack,&left),left);
		int pr=(Pop(&rstack,&right),right);
		int x=a[(left+right)/2];
		
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
		
		if(pr-left<right-pl)
		{
			swap(int,pl,left);
			swap(int,pr,right);
		}
		
		if(left<pr)
		{
			Push(&lstack,left);
			Push(&rstack,pr);
		}
		
		if(pl<right)
		{
			Push(&lstack,pl);
			Push(&rstack,right);
		}
	}
	
	Terminate(&lstack);
	Terminate(&rstack);
}

int main()
{
	int i;
	int nx;
	puts("퀵 정렬");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int *x=calloc(nx,sizeof(int));
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}
	
	quick(x,0,nx-1);
	
	puts("오름차순으로 정렬했습니다.");
	for(i=0;i<nx;i++)
		printf("x[%d] = %d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
