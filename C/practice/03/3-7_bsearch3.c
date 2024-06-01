#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[10];
	int height;
	int weight;
} Person; // struct형 Person을 생성

int npcmp(const Person *x,const Person *y)
{
	return strcmp(x->name,y->name); // 문자열 비교
}

int main()
{
	Person x[]=
	{
		{"김영준",179,79},
		{"박현규",172,63},
		{"이수진",176,52},
		{"최윤미",165,51},
		{"함진아",181,73},
		{"홍연의",172,84},
	};
	
	int nx=sizeof(x)/sizeof(x[0]);
	int retry;
	puts("이름으로 검색합니다.");
	do
	{
		Person temp; // Person 구조체 변수 temp 생성
		printf("이름 : ");
		scanf("%s",temp.name);
		Person *p=bsearch(&temp,x,nx,sizeof(Person),(int(*)(const void *,const void *)) npcmp);
		if(p==NULL)
			puts("검색에 실패했습니다.");
		else
		{
			puts("검색 성공! 아래 요소를 찾았습니다.");
			printf("x[%d]: %s %dcm %dkg\n",(int)(p-x),p->name,p->height,p->weight);
			// p가 구조체형 객체에 대한 포인터이므로 p가 가리키는 객체의 맴버에 접근하는 형식은 -> 이다.
		}
		printf("다시 검색할까요? (1)예 / (0)아니오 : ");
		scanf("%d",&retry);
	} while(retry==1);
	
	return 0;
}
