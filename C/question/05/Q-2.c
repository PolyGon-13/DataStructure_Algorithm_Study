#include <stdio.h>

int main()
{
	int x,y;
	puts("두 정수의 최대공약수를 구합니다.");
	printf("정수를 입력하세요 : ");
	scanf("%d",&x);
	printf("정수를 입력하세요 : ");
	scanf("%d",&y);
	
	int temp;
	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}
	
	int result;
	while(1)
	{
		temp=x;
		x=y;
		y=temp%y;
		if(y==0)
		{
			result=x;
			break;
		}
	}
	printf("최대공약수는 %d입니다.\n",result);
	
	return 0;
}
