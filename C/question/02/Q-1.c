#include <stdio.h>
#include <stdlib.h>

int minof(const int a[],int n)
{
	int i;
	int min=a[0];
	
	for(i=1;i<n;i++)
		if(a[i]<min) min=a[i];
	
	return min;
}

int main()
{
	int i;
	int num;
	printf("사람 수: ");
	scanf("%d",&num);
	
	int* height=calloc(num,sizeof(int));
	
	printf("%d명의 키를 입력하세요.\n",num);
	for(i=0;i<num;i++)
	{
		printf("height[%d]: ",i);
		scanf("%d",&height[i]);
	}
	
	printf("최솟값은 %d입니다.\n",minof(height,num));
	
	return 0;
}
