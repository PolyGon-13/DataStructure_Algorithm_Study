#include <stdio.h>

void recur2(int n)
{
	if(n>0)
	{
		recur(n-2);
		printf("%d\n",n);
		recur(n-1);
	}
}

int main()
{
	int x;
	printf("정수를 입력하세요: ");
	scanf("%d",&x);
	recur2(x);
	
	return 0;
}

// 하향식 분석
/*
n=4이면,
recur2(2) 4 recur2(3)으로 쪼개짐
recur2(2)는 recur2(0) 2 recur2(1)로 쪼개지고
recur2(1)은 recur2(-1) 1 recur2(0)으로 쪼개진다.
따라서 recur2(2)는 2 1 4를 출력한다.
recur2(3)도 동일한 방식으로 1 3 2 1을 출력한다.
*/

// 상향식 분석
/*
recur2(1)부터 하나씩 구해나가면 된다.
recur2(1) : 1
recur2(2) : 2 1
recur2(3) : 1 3 2 1
recur2(4) : 2 1 4 1 3 2 1
recur2(5) : 1 3 2 1 5 2 1 4 1 3 2 1
*/
