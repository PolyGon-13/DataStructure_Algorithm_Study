#include <stdio.h>

int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

void print()
{
	int i;
	for(i=0;i<8;i++)
		printf("%2d",pos[i]);
	putchar('\n');
}

void set(int i)
{
	int j;
	for(j=0;j<8;j++)
	{
		if(!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+7])
		// flag_b 시작 열 i에 j가 0이면 i열 0행, 그리고 j가 커져갈수록 i열 i+j행이 성립
		// flag_c는 가운데 대각선이 7번째 요소이다. 여기에 j가 0이면 i열 0행, 그리고 j가 커져갈수록 i열 i-j+7행이 성립
		{
			pos[i]=j;
			if(i==7)
				print();
			else
			{
				flag_a[j]=flag_b[i+j]=flag_c[i-j+7]=1;
				set(i+1);
				flag_a[j]=flag_b[i+j]=flag_c[i-j+7]=0;
			}
		}
	}
}

int main()
{
	int i;
	for(i=0;i<8;i++)
		flag_a[i]=0;
	for(i=0;i<15;i++)
		flag_b[i]=flag_c[i]=0;
	set(0);
	
	return 0;
}
