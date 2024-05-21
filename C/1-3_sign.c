#include <stdio.h>

int main()
{	
	int n;
	
	printf("정수: ");
	scanf("%d",&n);
	
	if(n>0) printf("양수\n");
	else if(n<0) printf("음수\n");
	else printf("0\n");
	
	return 0;
}
