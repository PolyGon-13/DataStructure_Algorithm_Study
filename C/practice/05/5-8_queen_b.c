#include <stdio.h>

int pos[8];

void print()
{
	int i;
	for(i=0;i<8;i++)
		printf("%2d",pos[i]);
	putchar('\n');
}

void set(int i)
{
	int j;
	for(j=0;j<8;j++)
	{
		pos[i]=j;
		if(i==7)
			print();
		else
			set(i+1);
	}
	// set(0)부터 set(7)까지 j=0일때 쭉 실행되어 set(7)에서 모든 요소에 0이 담긴채로 한 번 출력
	// set(7)이 마저 실행됨. j가 1부터 7까지.
	// 그리고 이제 set(6)으로 내려옴. j가 바뀌어 매 실행마다 다시 set(7)이 실행되어 pos[6]과 pos[7]의 값이 계속 바뀜.
}

int main()
{
	set(0);
	
	return 0;
}
