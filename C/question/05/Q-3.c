#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int gcd_array(const int a[],int n)
{
	if(n==1)
		return a[0];
	else if(n==2)
		return gcd(a[0],a[1]);
	else
		return gcd(a[0],gcd_array(&a[1],n-1));
	// a[1]의 주소를 보낸다. 따라서 첫 시작 배열이 {2,4,6,8}이었으면, a[1]인 {4}의 주소를 보내므로 {4,6,8}배열로 함수에 인자로 들어가게 된다.
}

int main(void)
{
	int i;
	int nx;
	printf("정수 개수: ");
	scanf("%d",&nx);
	int* x=calloc(nx,sizeof(int));

	for(i=0;i<nx;i++) 
	{
		printf("x[%d]: ",i);
		scanf("%d",&x[i]);
	}

	printf("최대 공약수는 %d입니다.\n",gcd_array(x,nx));

	free(x);

	return 0;
}
