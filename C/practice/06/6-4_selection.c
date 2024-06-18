#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void selection(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		int min=i; // 0번째 요소부터 n-2번째 요소(가장 끝 요소 빼고 전부) 돌아가면서 탐색
		for(j=i+1;j<n;j++)
			if(a[j]<a[min]) // 선택한 요소(min)보다 작은 요소(j)가 발견된 경우
				min=j; // 가장 작은 요소를 갱신
		swap(int,a[i],a[min]); // i번째 요소(가장 작은 요소)와 min번째 요소(탈락된 요소)를 교체
	}
}

int main()
{
	int nx;
	puts("단순 선택 정렬");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int* x=calloc(nx,sizeof(int));

	int i;
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}

	selection(x,nx);

	puts("오름차순으로 정렬했습니다.");
	for(i=0;i<nx;i++)
		printf("x[%d]=%d\n",i,x[i]);

	free(x);

	return 0;
}
