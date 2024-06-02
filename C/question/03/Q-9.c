#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a,const int *b)
{
	if(*a<*b)
		return -1;
	else if(*a<*b)
		return 1;
	else
		return 0;
}

void* binsearch(const void* key,const void* base,size_t nmemb,size_t size,int(*compar)(const void*,const void*))
{
	int i;
	int store;
	int n=nmemb;
	int pl=0;
	int pr=n-1;
	
	do
	{
		int pc=(pl+pr)/2;
		
		if(((int*)base)[pc]==*(int*)key)
		{
			for(i=pc;i>=0;i--)
			{
				if(((int*)base)[pc]==*(int*)key)
					store=i;
				else
					break;
			}
			return &((int*)base)[store];
		}
		else if(((int*)base)[pc] < *(int*)key)
			pl=pc+1;
		else
			pr=pc-1;
	} while(pl<=pr);
	
	return NULL;
}

int main()
{
	int i;
	int nx,ky;
	puts("이진 검색");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int* x=calloc(nx,sizeof(int));
	
	printf("오름차순으로 입력하세요\n");
	printf("x[0]: ");
	scanf("%d",&x[0]);
	for(i=1;i<nx;i++)
	{
		do
		{
			printf("x[%d]: ",i);
			scanf("%d",&x[i]);
		} while(x[i]<x[i-1]);
	}
	
	printf("검색값: ");
	scanf("%d",&ky);
	int* p=binsearch(&ky,x,nx,sizeof(int),(int(*)(const void *,const void *))int_cmp);
	
	if(p==NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d은(는) x[%d]에 있습니다.\n",ky,(int)(p-x));
	
	free(x);
	
	return 0;
}
