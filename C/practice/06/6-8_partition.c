#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x; x=y; y=t;} while(0)

void partition(int a[],int n)
{
	int i;
	int pl=0;
	int pr=n-1;
	int x=a[n/2];
	
	do
	{
		while(a[pl]<x) pl++; // x가 a[pl]보다 크거나 같으면 탈출
		while(a[pr]>x) pr--; // x가 a[pr]보다 작거나 같으면 탈출
		
		if(pl<=pr)
		{
			swap(int,a[pl],a[pr]); // pl과 pr이 같아도 교체
			pl++;
			pr--;
			// pl과 pr을 증감을 통해 교차시켜 do문을 탈출시킴
		}
	} while(pl<=pr);
	
	printf("피벗의 값은 %d입니다.\n",x);
	
	puts("피벗 이하의 그룹");
	for(i=0;i<=pl-1;i++) // pl이 x보다 1만큼 큰 요소에 위치해있기 때문에 pl-1까지 반복
		printf("%d",a[i]);
	putchar('\n');
	
	if(pl>pr+1) // 같은 곳에서 pl과 pr이 만난 경우
	{
		puts("피벗과 일치하는 그룹");
		for(i=pr+1;i<=pl-1;i++)
			printf("%d",a[i]);
		putchar('\n');
	}
	
	puts("피벗 이상의 그룹");
	for(i=pr+1;i<n;i++)
		printf("%d",a[i]);
	putchar('\n');
}

int main()
{
	int i;
	int nx;
	puts("배열을 나눕니다.");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int *x=malloc(nx*sizeof(int));
	
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}
	
	partition(x,nx);
	
	free(x);
	
	return 0;
}
