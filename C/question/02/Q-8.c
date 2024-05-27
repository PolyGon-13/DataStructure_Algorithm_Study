#include <stdio.h>
#include <stdlib.h>

void ary_copy(int a[],const int b[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
		a[i]=b[n-i-1];
}

int main()
{
	int n;
	int i;
	printf("요소 개수: ");
	scanf("%d",&n);
	
	int* a=calloc(n,sizeof(int));
	int* b=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("b[%d]: ",i);
		scanf("%d",&b[i]);
	}
	
	ary_copy(a,b,n);
	
	for(i=0;i<n;i++)
		printf("a[%d]: %d\n",i,a[i]);
	
	free(a);
	free(b);
	
	return 0;
}
