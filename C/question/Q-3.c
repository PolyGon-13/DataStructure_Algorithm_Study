#include <stdio.h>

int min4(int a,int b,int c, int d)
{
	if(a<b && a<c && a<d) return a;
	else if (b<a && b<c && b<d) return b;
	else if (c<a && c<b && c<d) return c;
	else return d; 
}

int main()
{
	printf(" 네 정수의 최솟값: %d",min4(4,2,7,3));
	return 0;	
}
