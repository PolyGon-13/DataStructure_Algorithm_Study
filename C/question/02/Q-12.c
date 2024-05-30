#include <stdio.h>

typedef struct
{
	int y;
	int m;
	int d;
} Date;

int isleap(int y)
{
	return y%4==0 && y%100!=0 || y%400==0;
}

Date Dateof(int y,int m,int d)
{
	printf("%d년 %d월 %d일\n",y,m,d);
}

Date After(Date x,int a)
{
	x.d+=a;
	while(x.d>27)
	{
		if(isleap(x.y))
			if(x.d>29 && x.m==2)
			{
				x.m+=1;
				x.d-=29;
			}
		else if(!isleap(x.y))
			if(x.d>28 && x.m==2)
			{
				x.m+=1;
				x.d-=28;
			}
		
		if((x.m==1||x.m==3||x.m==5||x.m==7||x.m==8||x.m==10||x.m==12) && x.d>31)
		{
			x.m+=1;
			x.d-=31;
			
			if(x.m>12)
			{
				x.y+=1;
				x.m=1;
			}
		}
		else if((x.m==4||x.m==6||x.m==9||x.m==11) && x.d>30)
		{
			x.m+=1;
			x.d-=30;
		}
	}
	printf("%d일 뒤의 날짜는 : %d년 %d월 %d일\n",a,x.y,x.m,x.d);
}

Date Before(Date x,int b)
{
	x.d-=b;
	
	while(x.d<0)
	{
		if(x.m==3 && x.d<0)
		{
			if(isleap(x.y))
			{
				x.m-=1;
				x.d+=29;
			}
			else if(!isleap(x.y))
			{
				x.m-=1;
				x.d+=28;
			}
		}

		if((x.m==1||x.m==2||x.m==4||x.m==6||x.m==8||x.m==9||x.m==11) && x.d<0)
		{
			x.m-=1;
			x.d+=31;
			
			if(x.m==0)
			{
				x.y-=1;
				x.m=12;
			}
		}
		else if((x.m==5||x.m==7||x.m==10||x.m==12) && x.d<0)
		{
			x.m-=1;
			x.d+=30;
		}
	}
	
	printf("%d일 앞의 날짜는 : %d년 %d월 %d일\n",b,x.y,x.m,x.d);
}

int main()
{
	int t,na,nb,a,b;
	int i;
	
	Date x[]=
	{
		{2021,3,26},
		{2022,11,15},
		{2023,4,2},
		{2024,11,13}
	};
	int n=sizeof(x)/sizeof(x[0]);
	
	printf("하고 싶은 작업 선택\n");
	printf("0---저장된 날짜 출력\n");
	printf("1---날짜 x의 n일 뒤의 날짜\n");
	printf("2---날짜 x의 n일 앞의 날짜\n");
	scanf("%d",&t);
	
	if(t==0)
	{
		for(i=0;i<n;i++)
			Dateof(x[i].y,x[i].m,x[i].d);
	}
	else if(t==1)
	{
		printf("몇 번째 날짜 선택? : ");
		scanf("%d",&na);
		printf("몇 일 뒤 날짜? : ");
		scanf("%d",&a);
		After(x[na-1],a);
	}
	else if(t==2)
	{
		printf("몇 번째 날짜 선택? : ");
		scanf("%d",&nb);
		printf("몇 일 앞 날짜? : ");
		scanf("%d",&b);
		Before(x[nb-1],b);
	}
	
	return 0;
}
