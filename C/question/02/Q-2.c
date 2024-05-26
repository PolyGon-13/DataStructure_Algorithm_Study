#include <stdio.h>
#include <stdlib.h>

int sumof(const int a[],int n)
{
	int i;
	int sum=0;
	
	for(i=0;i<n;i++)
		sum+=a[i];
	
	return sum;
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
	
	printf("키의 합계는 %d입니다.\n",sumof(height,num));
	
	return 0;
}
