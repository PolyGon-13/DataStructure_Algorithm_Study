#include <stdio.h>

int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

typedef struct
{
	int max;
	int ptr;
	int* stk;
} IntStack;

int Initialize(IntStack* s,int max)
{
	s->ptr=0;
	
	if((s->stk=calloc(max,sizeof(int)))==NULL)
	{
		s->max=0;
		return -1;
	}
	s->max=max;
	
	return 0;
}

int Push(IntStack* s,int x)
{
	if(s->ptr >= s->max)
		return -1;
	s->stk[s->ptr++]=x;
	
	return 0;
}

int Pop(IntStack* s,int* x)
{
	if(s->ptr<=0)
		return -1;
	*x=s->stk[--s->ptr];
	
	return 0;
}

int IsEmpty(const IntStack* s)
{
	return s->ptr<=0;
}

int IsFull(const IntStack* s)
{
	return s->ptr>=s->max;
}

void Terminate(IntStack* s)
{
	if(s->stk != NULL)
		free(s->stk);
	s->max=s->ptr=0;
}

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
	IntStack stk;
	Initialize(&stk, 8);

Start:
	while(1) 
	{
		j=0;
		while(1)
		{
			while(j<8) 
			{
				if(!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+7]) 
				{
					pos[i]=j;
					if(i==7) // 전체 열 배치 마침
						print();
					else 
					{
						flag_a[j]=flag_b[i+j]=flag_c[i-j+7]=1;
						i++;
						Push(&stk,j); // i번째 열의 행을 푸시
						goto Start;
					}
				}
				j++;
			}
			if(--i==-1)
				return;
			Pop(&stk,&j); // i번째 열의 행을 팝
			flag_a[j]=flag_b[i+j]=flag_c[i-j+7]=0;
			j++;
		}
		// 하나의 케이스를 우선 구성하고, 배치된 행의 열 번호를 저장해둔다.
		// 8열까지 모두 진행 후, if문에 의해 i가 7로 내려오고, 이전에 넣어둔 7열의 퀸을 배치한 번호 j를 pop하여 다른 경우의 수를 찾는다.
	}
	
	Terminate(&stk);
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
