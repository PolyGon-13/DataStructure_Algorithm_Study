#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void bubble(int a[],int n)
{
	int i,j;
	for(i=n-1;i>0;i--)
		for(j=0;j<i;j++) // 끝쪽부터 정렬된 데이터가 쌓이므로 점점 반복횟수가 뒤에서부터 줄어듦
			if(a[j]>a[j+1])
				swap(int,a[j],a[j+1]);
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
