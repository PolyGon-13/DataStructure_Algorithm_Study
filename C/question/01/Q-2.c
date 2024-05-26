#include <stdio.h>

int min3(int a,int b,int c)
{
	if(a<b && a<c) return a;
	else if (b<a && b<c) return b;
	else return c;
}

int main()
{
	printf("세 정수의 최솟값: %d",min3(4,2,3));
	return 0;	
}
