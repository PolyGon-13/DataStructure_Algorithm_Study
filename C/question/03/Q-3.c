#include <stdio.h>
#include <stdlib.h>

int cnt=0;

int search_idx(const int a[],int n,int key,int idx[])
{
	int i;
	
	for(i=0;i<n;i++)
		if(a[i]==key)
			idx[cnt++]=i;
	
	return cnt;
}

int main()
{
	int i;
	int n,k;
	printf("요소 개수 : ");
	scanf("%d",&n);
	int* a=calloc(n,sizeof(int));
	int* idx=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("a[%d] : ",i);
		scanf("%d",&a[i]);
	}
	
	printf("검색값 : ");
	scanf("%d",&k);
	
	search_idx(a,n,k,idx);
	for(i=0;i<cnt;i++)
		printf("%d\n",idx[i]);
	printf("%d개\n",cnt);
	
	free(a);
	free(idx);
	
	return 0;
}
