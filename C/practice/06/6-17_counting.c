#include <stdio.h>
#include <stdlib.h>

void counting(int a[],int n,int max)
{
	int i;
	int *f=calloc(max+1,sizeof(int));
	int *b=calloc(n,sizeof(int));
	
	for(i=0;i<=max;i++) f[i]=0;
	for(i=0;i<n;i++) f[a[i]]++;
	for(i=1;i<=max;i++) f[i]+=f[i-1];
	for(i=n-1;i>=0;i--) b[--f[a[i]]]=a[i];
	for(i=0;i<n;i++) a[i]=b[i];
	
	free(b);
	free(f);
}

int main()
{
	int i;
	int nx;
	const int max=100;
	puts("도수 정렬");
	printf("요소 개수 : ");
	
	scanf("%d",&nx);
	int *x=calloc(nx,sizeof(int));
	printf("0~%d의 정수를 입력하세요\n",max);
	for(i=0;i<nx;i++)
	{
		do
		{
			printf("x[%d] : ",i);
			scanf("%d",&x[i]);
		} while(x[i]<0 || x[i]>max);
	}
	
	counting(x,nx,max);
	puts("오름차순으로 정렬했습니다.");
	
	for(i=0;i<nx;i++)
		printf("x[%d] = %d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
