#include <stdio.h>

void move(int no,int x,int y)
{
	char* name[]={"A 기둥","B 기둥","C 기둥"};
	// char로 배열을 선언하면 각 요소는 단일 문자만을 저장
	// char*로 배열을 선언하면 문자 포인터 타입의 데이터를 저장하므로 각 요소는 문자열을 가리키는 포인터
	if(no>1)
		move(no-1,x,6-x-y);
	
	printf("원반[%d]를(을) %s에서 %s으로 옮김\n",no,name[x-1],name[y-1]);
	
	if(no>1)
		move(no-1,6-x-y,y);
}

int main()
{
	int n;
	printf("하노이의 탑\n원반 개수 : ");
	scanf("%d",&n);
	move(n,1,3);
	
	return 0;
}
