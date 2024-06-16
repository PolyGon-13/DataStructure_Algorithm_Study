#include <stdio.h>
#include <stdlib.h>

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

void move(int no,int x,int y)
{
	int sw=0;
	IntStack xstk,ystk,sstk;
	
	Initialize(&xstk,100);
	Initialize(&ystk,100);
	Initialize(&sstk,100);
	// 각 기둥마다 스택을 할당
	
	while(1)
	{
		if(sw==0 && no>1)
		{
			Push(&xstk,x);
			Push(&ystk,y);
			Push(&sstk,sw);
			no--;
			y=6-x-y; // 기둥번호의 합(1+2+3)이 6이므로 6에서 나머지 기둥의 번호(x,y)를 빼주면 남은 하나의 기둥의 번호를 알 수 있음
			continue; // while문의 시작으로 돌아감
		}
		
		printf("원반[%d]를 %d 기둥에서 %d 기둥으로 이동\n",no,x,y);
		// 위의 if문을 만족하지 않더라도 printf는 실행되고 아래의 if문으로 들어감
		
		if(sw==1 && no>1)
		{
			Push(&xstk,x);
			Push(&ystk,y);
			Push(&sstk,sw);
			no--;
			x=6-x-y;
			if(++sw==2)
				sw=0;
			continue;
		}
		
		do
		{
			if(IsEmpty(&xstk))
				return;
			Pop(&xstk,&x);
			Pop(&ystk,&y);
			Pop(&sstk,&sw);
			// Pop하면 현재의 x,y,sw 값이 Pop한 값으로 바뀌는 점 주의
			sw++;
			no++;
		} while(sw==2);
	}
	
	Terminate(&xstk);
	Terminate(&ystk);
	Terminate(&sstk);
}

int main()
{
	int n;
	printf("하노이의 탑\n원반 개수 : ");
	scanf("%d",&n);
	move(n,1,3);
	
	return 0;
}
