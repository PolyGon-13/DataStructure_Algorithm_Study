#include <stdio.h>
#include <stdlib.h>
#include "IntDeck.h"

int Initialize(IntDeck* d,int max)
{
	d->num=d->front=d->rear=0;
	if((d->deck=calloc(max,sizeof(int)))==NULL)
	{
		d->max=0;
		return -1;
	}
	d->max=max;
	return 0;
}

int Endeck(IntDeck* d,int x)
{
	if(d->num>=d->max)
		return -1;
	if(d->front<=0)
	{
		d->front=d->max-1;
		d->deck[d->front]=x;
		d->num++;
		return 0;
	}
	else
	{
		d->deck[d->front-1]=x;
		d->front--;
		d->num++;
		return 0;
	}
}

int Endeck2(IntDeck* d,int x)
{
	if(d->num>=d->max)
		return -1;
	if(d->rear<d->max)
	{
		d->deck[d->rear++]=x;
		d->num++;
		return 0;
	}
	else
	{
		d->rear=0;
		d->deck[d->rear++]=x;
		d->num++;
		return 0;
	}
}

int Dedeck(IntDeck* d,int* x)
{
	if(d->num<=0)
		return -1;
	if(d->front<d->max)
	{
		*x=d->deck[d->front++];
		d->num--;
		return 0;
	}
	else
	{
		d->front=0;
		*x=d->deck[d->front];
		d->num--;
		return 0;
	}
}

int Dedeck2(IntDeck* d,int* x)
{
	if(d->num<=0)
		return -1;
	if(d->rear>0)
	{
		*x=d->deck[d->rear-1];
		d->rear--;
		d->num--;
		return 0;
	}
	else
	{
		d->rear=d->max-1;
		*x=d->deck[d->rear];
		d->num--;
		return 0;
	}
}

int Peek(const IntDeck* d,int* x)
{
	if(d->num<=0)
		return -1;
	*x=d->deck[d->front];
	return 0;
}

void Clear(IntDeck* d)
{
	d->num=d->front=d->rear=0;
}

int Capacity(const IntDeck* d)
{
	return d->max;
}

int Size(const IntDeck* d)
{
	return d->num;
}

int IsEmpty(const IntDeck* d)
{
	return d->front==d->rear;
}

int IsFull(const IntDeck* d)
{
	return d->front==(d->rear+1)%d->max;
}

int Search(const IntDeck* d,int x)
{
	int i;
	
	for(i=0;i<d->num;i++)
	{
		int idx;
		if(d->deck[idx=(i+d->front)%d->max]==x)
			return idx;
	}
	return -1;
}

void Print(const IntDeck* d)
{
	int i;
	
	for(i=0;i<d->num;i++)
		printf("%d",d->deck[(i+d->front)%d->max]);
	putchar('\n');
}

void Terminate(IntDeck* d)
{
	if(d->deck!=NULL)
		free(d->deck);
	d->max=d->num=d->front=d->rear=0;
}
