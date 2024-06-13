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


void recur3(int n)
{
	IntStack stk;
	Initialize(&stk,100);
Top:
	if(n>0)
	{
		Push(&stk,n);
		n=n-1;
		goto Top;
	}
	if(!IsEmpty(&stk))
	{
		Pop(&stk,&n);
		n=n-2;
		printf("%d\n",n);
		goto Top;
	}
	Terminate(&stk);
}

int main()
{
	int x;
	printf("정수를 입력하세요: ");
	scanf("%d",&x);
	recur3(x);
	
	return 0;
}
