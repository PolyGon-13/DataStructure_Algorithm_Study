#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void bubble(int a[],int n)
{
	int i,j,m;
	int compare=0;
	int change=0;
	
	for(i=0;i<n-1;i++)
	{
		printf("패스%d:\n",i+1);
		for(j=n-1;j>i;j--)
		{
			for(m=0;m<n-1;m++)
				printf("%3d %c",a[m],(m!=j-1) ? ' ' : (a[j-1]>a[j])?'+':'-'); // 삼항 연산자 2중 중첩을 통해 간편하게 출력 가능
			printf("%3d\n",a[n-1]);
			compare++;
			if(a[j-1]>a[j])
			{
				change++;
				swap(int,a[j-1],a[j]);
			}
		}
		for(m=0;m<n;m++)
			printf("%3d ",a[m]);
		putchar('\n');
	}
	printf("비교 %d회\n",compare);
	printf("교환 %d회\n",change);
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
