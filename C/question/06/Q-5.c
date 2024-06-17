#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void bubble(int a[],int n)
{
	int j,m;
	int i=0;
	int k=0;
	int compare=0;
	int change=0;
	
	while(k<n-1)
	{
		int last=n-1;
		printf("패스%d:\n",++i);
		for(j=n-1;j>k;j--)
		{
			for(m=0;m<n-1;m++)
				printf("%3d %c",a[m],(m!=j-1) ? ' ' : (a[j-1]>a[j])?'+':'-');
			printf("%3d\n",a[n-1]);
			
			compare++;
			
			if(a[j-1]>a[j])
			{
				swap(int,a[j-1],a[j]);
				last=j;
				change++;
			}
		}
		k=last;
		for(m=0;m<n;m++)
			printf("%3d  ",a[m]);
		putchar('\n');
	}
	printf("비교를 %d회 했습니다.\n",compare);
	printf("교환을 %d회 했습니다.\n",change);
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
