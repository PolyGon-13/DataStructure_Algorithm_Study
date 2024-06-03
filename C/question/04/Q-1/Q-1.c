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
		int menu,x;
		printf("현재 데이터 수 : %d / %d\n",Size(&s),Capacity(&s));
		printf("(1)Push, (2)Pop, (3)Peek, (4)Clear, (5)IsEmpty, (6)IsFull, (7)Search, (8)Print, (0)Exit : ");
		scanf("%d",&menu);
		
		if(menu==0) 
			break;
		switch(menu)
		{
			case 1:
				printf("데이터 : ");
				scanf("%d",&x);
				if(Push(&s,x)==-1)
					puts("\a오류: 푸시에 실패했습니다.");
				break;
			
			case 2:
				if(Pop(&s,&x)==-1)
					puts("\a오류: 팝에 실패했습니다.");
				else
					printf("팝 데이터는 %d입니다.\n",x);
				break;
				
			case 3:
				if(Peek(&s,&x)==-1)
					puts("\a오류: 피크에 실패했습니다.");
				else
					printf("피크 데이터는 %d입니다.\n",x);
				break;
				
			case 4:
				printf("스택을 청소합니다.\n");
				Clear(&s);
				break;
				
			case 5:
				if(IsEmpty(&s))
					printf("스택이 비어있습니다.\n");
				else
					printf("스택에 데이터가 들어있습니다.\n");
				break;
				
			case 6:
				if(IsFull(&s))
					printf("스택이 가득 찼습니다.\n");
				else
					printf("스택에 남은 공간이 있습니다.\n");
				break;
				
			case 7:
				printf("검색할 데이터를 입력하세요: ");
				scanf("%d",&x);
				int find=Search(&s,x);
				if(find==-1)
					printf("해당 데이터는 존재하지 않습니다.\n");
				else
					printf("해당 데이터는 %d번째 공간에 있습니다.\n",find);
				break;
				
			case 8:
				Print(&s);
				break;
		}
	}
	Terminate(&s);
	
	return 0;
}
