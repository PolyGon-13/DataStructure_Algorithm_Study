#include <stdio.h>

int main()
{
	int i,j;
	printf("----------------------곱셈표----------------------\n");
	for(i=1;i<=19;i++)
	{
		for(j=1;j<=10;j++)
			printf("%5d",i*j);
		putchar('\n'); // 문자 전용 출력 함수
	}
	return 0;
}
