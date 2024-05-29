#include <stdio.h>

int mdays[][12]=
{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

int isleap(int year)
{
	return year%4==0 && year%100 !=0 || year%400==0;
}

int dayof_year(int y,int m,int d)
{
	int *p=mdays[isleap(y)]; // 포인터를 이용하여 윤년여부에 따른 mdays의 배열을 가리킴
	
	while(--m) // m이 어떤 값인지에 관계없이 0이 되면 while문을 탈출
		d+=*p++; // 주어진 일수 d에 포인터p가 가리키고 있는 값을 더하고 그 다음 요소로 넘어간다.
	// 예를 들어 m이 4라면, m이 3으로 줄어들어 while문으로 진입한다. *p가 가리키는 값은 4월의 일수가 아닌 1월의 일수이다.
	// 따라서, m은 입력값에서부터 줄어들고, *p는 1에서부터 올라가므로 결국에는 원하는 일수를 모두 더할 수 있다.
	
	return d;
}

int main()
{
	int retry;
	
	do
	{
		int year,month,day;
		
		printf("년: "); scanf("%d",&year);
		printf("월: "); scanf("%d",&month);
		printf("일: "); scanf("%d",&day);
		printf("%d년의 %d일째입니다.\n",year,dayof_year(year,month,day));
		printf("다시 할까요?(1---예 / 0---아니오): ");
		scanf("%d",&retry);
	} while(retry==1);
	
	return 0;
}
