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
	int days=d;
	int i;
	
	for(i=1;i<m;i++)
		days+=mdays[isleap(y)][i-1];
	
	return days;
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
