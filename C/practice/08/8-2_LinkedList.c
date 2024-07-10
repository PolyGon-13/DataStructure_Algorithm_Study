#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

static Node *AllocNode(void)
{
	return calloc(1,sizeof(Node));
}

static void SetNode(Node *n,const Member *x,const Node *next)
{
	n->data=*x;
	n->next=next;
}

void Initialize(List *list)
{
	list->head=NULL;
	list->crnt=NULL;
}

Node *Search(List *list,const Member *x,int compare(const Member *x,const Member *y))
{
	Node *ptr=list->head;
	while(ptr!=NULL)
	{
		if(compare(&ptr->data,x)==0)
		// 함수 포인터
		// 이전에 선언된 함수가 int형을 반환하고 char형 변수를 매개변수로 받는 int (char) 함수라면, int (*p)(char)로 함수 포인터를 선언할 수 있음
		// Member.h에 선언된 MemberNoCmp, MemberNameCmp 함수를 compare함수는 사용하고 있는 것
		// 데이터 포인터는 &를 붙여주는게 좋음 (안 붙여도 동작은 한다고 함)
		{
			list->crnt=ptr;
			return ptr;
		}
		ptr=ptr->next;
	}
	return NULL;
}

void InsertFront(List *list,const Member *x)
{
	Node *ptr=list->head;
	list->head=list->crnt=AllocNode();
	SetNode(list->head,x,ptr);
}

void InsetRear(List *list,const Member *x)
{
	if(list->head==NULL)
		InsetFront(list,x);
	else
	{
		Node *ptr=list->head;
		while(ptr->next != NULL)
			ptr=ptr->next;
		ptr->next=list->crnt=AllocNode();
		SetNode(ptr->next,x,NULL);
	}
}
