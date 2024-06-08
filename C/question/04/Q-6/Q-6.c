#include <stdio.h>
#include "IntDeck.h"

int main()
{
	IntDeck deck;
	
	if(Initialize(&deck,64)==-1)
	{
		puts("덱 생성에 실패하였습니다.");
		return 1;
	}
	while(1)
	{
		int m,x;

		printf("현재 데이터 수 : %d / %d\n",Size(&deck),Capacity(&deck));
		printf("(1)프런트인덱 (2)리어인덱 (3)프런트디덱 (4)리어디덱 (5)출력 (0)종료");
		scanf("%d",&m);
		
		if(m==0)
			break;
		switch(m)
		{
			case 1:
				printf("데이터 : "); scanf("%d",&x);
				if(Endeck(&deck,x)==-1)
					puts("오류 : 인덱에 실패하였습니다.");
				break;
				
			case 2:
				printf("데이터 : "); scanf("%d",&x);
				if(Endeck2(&deck,x)==-1)
					puts("오류 : 인덱에 실패하였습니다.");
				break;
				
			case 3:
				if(Dedeck(&deck,&x)==-1)
					puts("오류 : 디덱에 실패하였습니다.");
				else
					printf("디덱한 데이터는 %d입니다.\n",x);
				break;
				
			case 4:
				if(Dedeck2(&deck,&x)==-1)
					puts("오류 : 디덱에 실패하였습니다.");
				else
					printf("디덱한 데이터는 %d입니다.\n",x);
				break;
				
			case 5:
				Print(&deck);
				break;
		}
	}
	Terminate(&deck);
	return 0;
}
