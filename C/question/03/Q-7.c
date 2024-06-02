#include <stdio.h>
#include <stdlib.h>

int search(const int* a,const int* b)
{
	if(*a<*b)
		return -1;
	else if(*a>*b)
		return 1;
	else
		return 0;
}

void* seqsearch(const void* key,const void* base,size_t nmemb,size_t size,int(*compar)(const void*,const void*))
{
	int n=nmemb;
	int i;
	
	for(i=0;i<n;i++)
		if(((int*)base)[i]==*(int*)key) 
			// i번째 배열의 요소값을 int*형(정수를 가리키는 포인터)로 변환
			// 키값의 주소를 가리키는 key를 int*형으로 변환한 해당 주소의 값
			return &((int*)base)[i]; // 조건문에 해당하는 base배열의 i번째 요소를 int*형으로 변환한 값의 주소를 반환
	
	return NULL;
}

int main()
{
	int nx,ky;
	int i;
	
	puts("선형검색");
	printf("요소개수 : ");
	scanf("%d",&nx);
	int* x=calloc(nx,sizeof(int));
	for(i=0;i<nx;i++)
	{
		printf("x[%d]: ",i);
		scanf("%d",&x[i]);
	}
	
	printf("검색값: ");
	scanf("%d",&ky);
	int* p=seqsearch(&ky,x,nx,sizeof(int),(int(*)(const void*,const void*))search);
	
	if(p==NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n",ky,(int)(p-x));
	
	free(x);
	
	return 0;
}
