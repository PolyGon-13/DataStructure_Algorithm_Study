#include <stdio.h>
#include <stdlib.h>

int search(int a[],int n,int key)
{
	int i=0;
	a[n]=key;
	
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			break;
	}
	
	return i==n ? -1 : i;
}

int main()
{
	int nx,ky;
	int i;
	
	puts("선형검색");
	printf("요소개수 : ");
	scanf("%d",&nx);
	int* x=calloc(nx+1,sizeof(int));
	for(i=0;i<nx;i++)
	{
		printf("x[%d]: ",i);
		scanf("%d",&x[i]);
	}
	
	printf("검색값: ");
	scanf("%d",&ky);
	int idx=search(x,nx,ky);
	
	if(idx==-1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n",ky,idx);
	
	free(x);
	
	return 0;
}
