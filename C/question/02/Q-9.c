#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int a[],int n)
{
	int i;
	int num1,num2,temp;
	
	srand(time(NULL));
	
	for(i=0;i<n;i++)
	{
		num1=rand()%n;
		num2=rand()%n;
		
		temp=a[num1];
		a[num1]=a[num2];
		a[num2]=temp;
	}
}

int main()
{
	int n;
	int i;
	printf("요소 개수: ");
	scanf("%d",&n);
	
	int* a=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("a[%d]: ",i);
		scanf("%d",&a[i]);
	}
	
	shuffle(a,n);
	
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	
	free(a);
	
	return 0;
}
