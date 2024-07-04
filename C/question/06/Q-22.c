#include <stdio.h>
#include <stdlib.h>

void counting(int a[],int n,int min,int max)
{
	int i;
	int *f=calloc(max-min+2,sizeof(int));
	int *b=calloc(n,sizeof(int));
	
	for(i=0;i<=max-min+1;i++) f[i]=0;
	for(i=0;i<n;i++) f[a[i]-min]++; // 최솟값이 7이라면, 7을 0번째 인덱스에 해당하게 만드는 과정
	for(i=1;i<=max-min+1;i++) f[i]+=f[i-1];
	for(i=n-1;i>=0;i--) b[--f[a[i]-min]]=a[i];
	for(i=0;i<n;i++) a[i]=b[i];
	
	free(b);
	free(f);
}

int main()
{
	int i;
	int nx;
	int min,max;
	puts("도수 정렬");
	printf("요소 개수 : ");
	
	scanf("%d",&nx);
	int *x=calloc(nx,sizeof(int));
	scanf("%d %d",&min,&max);
	
	printf("0~%d의 정수를 입력하세요\n",max);
	for(i=0;i<nx;i++)
	{
		do
		{
			printf("x[%d] : ",i);
			scanf("%d",&x[i]);
		} while(x[i]<0 || x[i]>max);
	}
	
	counting(x,nx,min,max);
	puts("오름차순으로 정렬했습니다.");
	
	for(i=0;i<nx;i++)
		printf("x[%d] = %d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
