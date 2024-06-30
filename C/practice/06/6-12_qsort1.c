#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a,const int *b)
{
	if(*a<*b)
		return -1;
	else if(*a>*b)
		return 1;
	else
		return 0;
	
	// return (*(int *)a-*(int *)b);
}

int main()
{
	int i;
	int nx;
	puts("qsort에 의한 정렬");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int *x=calloc(nx,sizeof(int));
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}
	
	qsort(x,nx,sizeof(int),(int(*)(const void *,const void *))int_cmp);
	
	puts("오름차순으로 정렬했습니다.");
	for(i=0;i<nx;i++)
		printf("x[%d] = %d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
