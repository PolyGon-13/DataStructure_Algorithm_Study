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
		int menu,x,y,ctrl;
		printf("현재 데이터 수 : %d / %d\n",Size(&s),Capacity(&s));
		printf("(1)Push1, (2)Push2, (3)Pop1, (4)Pop2, (0)Exit : ");
		scanf("%d",&menu);
		
		if(menu==0) 
			break;
		switch(menu)
		{
			case 1:
				ctrl=1;
				printf("데이터 : ");
				scanf("%d",&x);
				if(Push(&s,x,ctrl)==-1)
					puts("오류: 푸시에 실패했습니다.");
				break;
			
			case 2:
				ctrl=2;
				printf("데이터 : ");
				scanf("%d",&y);
				if(Push(&s,y,ctrl)==-1)
					puts("오류: 푸시에 실패했습니다.");
				break;
				
			case 3:
				ctrl=1;
				if(Pop(&s,&x,ctrl)==-1)
					puts("오류: 팝에 실패했습니다.");
				else
					printf("팝 데이터는 %d입니다.\n",x);
				break;
				
			case 4:
				ctrl=2;
				if(Pop(&s,&y,ctrl)==-1)
					puts("오류: 팝에 실패했습니다.");
				else
					printf("팝 데이터는 %d입니다.\n",y);
				break;
		}
	}
	Terminate(&s);
	
	return 0;
}
