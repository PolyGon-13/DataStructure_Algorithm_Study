#include <stdio.h>
#include "IntQueue.h"

int main()
{
	IntQueue que;
	
	if(Initialize(&que,64)==-1)
	{
		puts("큐 생성에 실패하였습니다.");
		return 1;
	}
	while(1)
	{
		int m,x;

		printf("현재 데이터 수 : %d / %d\n",Size(&que),Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)리셋 (6)Empty (7)Full (8)Search (0)종료");
		scanf("%d",&m);
		
		if(m==0)
			break;
		switch(m)
		{
			case 1:
				printf("데이터 : "); scanf("%d",&x);
				if(Enque(&que,x)==-1)
					puts("오류 : 인큐에 실패하였습니다.");
				break;
			case 2:
				if(Deque(&que,&x)==-1)
					puts("오류 : 디큐에 실패하였습니다.");
				else
					printf("디큐한 데이터는 %d입니다.\n",x);
				break;
			case 3:
				if(Peek(&que,&x)==-1)
					puts("오류 : 피크에 실패하였습니다.");
				else
					printf("피크한 데이터는 %d입니다.\n",x);
				break;
			case 4:
				Print(&que);
				break;
			case 5:
				puts("큐에서 모든 데이터를 삭제합니다.");
				Clear(&que);
				break;
			case 6:
				if(IsEmpty(&que))
					puts("큐가 비어있습니다.");
				else
					puts("큐에 데이터가 존재합니다.");
				break;
			case 7:
				if(IsFull(&que))
					puts("큐가 가득 찼습니다.");
				else
					puts("큐에 공간이 남아있습니다.");
				break;
			case 8:
				printf("찾으시는 문자를 입력하세요: ");
				scanf("%d",&x);
				printf("찾으시는 문자는 %d번째에 위치합니다.\n",Search(&que,x)+1);
				break;
		}
	}
	Terminate(&que);
	return 0;
}
