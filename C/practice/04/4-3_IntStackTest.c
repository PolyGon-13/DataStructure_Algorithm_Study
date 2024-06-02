#include <stdio.h>
#include "IntStack.h"

int main()
{
	IntStack s;
	if(Initialize(&s,64)==-1)
	{
		puts("스택 생성에 실패했습니다.");
		return 1;
	}
	
	while(1)
	{
		int memu,x;
		printf("현재 데이터 수 : %d / %d\n",Size(&s),Capacity(&s));
	}
}
