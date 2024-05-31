#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[],int n,int key)
{
	int pl=0; // 검색 범위 맨 앞의 인덱스
	int pr=n-1; // 검색 범위 맨 끝의 인덱스
	
	do
	{
		int pc=(pl+pr)/2;
		
		if(a[pc]==key) // 검색 범위 가운데의 인덱스
			return pc; // 검색 성공
		else if(a[pc]<key)
			pl=pc+1; // 검색 범위를 뒤쪽 절반으로 좁힘
		else
			pr=pc-1; // 검색 범위를 앞쪽 절반으로 좁힘
	} while(pl<=pr); // pl과 pr이 하나의 수로 좁혀질 때까지 찾는 값이 없는 경우 do문 탈출
	
	return -1; // 검색 실패
}

int main()
{
	int i;
	int nx,ky;
	
	puts("이진 검색");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int* x=calloc(nx,sizeof(int));
	printf("오름차순으로 입력하세요.\n");
	printf("x[0]: ");
	scanf("%d",&x[0]);
	for(i=1;i<nx;i++)
	{
		do
		{
			printf("x[%d]: ",i);
			scanf("%d",&x[i]);
		} while(x[i]<x[i-1]); // 이진 검색은 배열이 정렬되어 있음을 가정하므로 바로 앞의 값보다 작으면 다시 입력해야 함.
	}
	
	printf("검색값 : ");
	scanf("%d",&ky);
	int idx=bin_search(x,nx,ky);
	if(idx==-1)
		puts("검색에 실패했습니다.");
	else
		printf("%d는(은) x[%d]에 있습니다.\n",ky,idx);
	
	free(x);
	
	return 0;
}
