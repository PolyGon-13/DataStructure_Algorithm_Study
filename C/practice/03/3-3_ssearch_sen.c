#include <stdio.h>
#include <stdlib.h>

int search(int a[],int n,int key)
{
	int i=0;
	a[n]=key; // 배열을 읽기뿐만 아니라 쓰기도 수행하고 있기에 search함수가 a[]를 매개변수로 받을 때 const 키워드 생략
	
	while(1)
	{
		if(a[i]==key)
			break;
		i++;
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
