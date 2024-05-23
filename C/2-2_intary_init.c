#include <stdio.h>

int main()
{
	int a[5]={1,2,3,4,5};
	int na=sizeof(a)/sizeof(a[0]); // 전체 배열의 크기에서 하나의 요소의 크기를 나누었으므로 20/4=5로 배열의 요소의 개수는 5임을 알 수 있다.
	printf("배열 a의 요소 개수는 %d입니다.\n",na);
	
	for(i=0;i<na;i++)
		printf("a[%d]=%d\n",i,a[i]);
	
	return 0;
}
