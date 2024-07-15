#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

static Node *AllocNode(void)
{
	return calloc(1,sizeof(Node));
}

static void SetNode(Node *n,const Member *x,Node *next)
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

void InsertRear(List *list,const Member *x)
{
	if(list->head==NULL)
		InsertFront(list,x);
	else
	{
		Node *ptr=list->head;
		while(ptr->next != NULL)
			ptr=ptr->next;
		ptr->next=list->crnt=AllocNode();
		SetNode(ptr->next,x,NULL);
	}
}

void RemoveFront(List *list)
{
	if(list->head != NULL)
	{
		Node *ptr=list->head->next;
		free(list->head);
		list->head=list->crnt=ptr;
	}
}

void RemoveRear(List *list)
{
	if((list->head)->next==NULL)
	{
		if((list->head)->next==NULL)
			RemoveFront(list);
		else
		{
			Node *ptr=list->head;
			Node *pre;
			while(ptr->next!=NULL)
			{
				pre=ptr;
				ptr=ptr->next;
			}
			pre->next=NULL;
			free(ptr);
			list->crnt=pre;
		}
	}
}

void RemoveCurrent(List *list)
{
	if(list->head!=NULL)
	{
		if(list->crnt==list->head)
			RemoveFront(list);
		else
		{
			Node *ptr=list->head;
			while(ptr->next!=list->crnt)
				ptr=ptr->next;
			ptr->next=list->crnt->next;
			free(list->crnt);
			list->crnt=ptr;
		}
	}
}

void Clear(List *list)
{
	while(list->head!=NULL)
		RemoveFront(list);
	list->crnt=NULL;
}

void PrintCurrent(const List *list)
{
	if(list->crnt==NULL)
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->crnt->data);
}

void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

void Print(const List *list)
{
	if(list->head==NULL)
		puts("노드가 없습니다.");
	else
	{
		Node *ptr=list->head;
		puts("[모두 보기]");
		while(ptr!=NULL)
		{
			PrintLnMember(&ptr->data);
			ptr=ptr->next;
		}
	}
}

void Purge(List *list,int compare(const Member *x,const Member *y))
{
	Node *ptr=list->head;
	Node *next_ptr;
	
	while(ptr!=NULL)
	{
		next_ptr=ptr->next;
		
		while(next_ptr!=NULL)
		{
			if(compare(&ptr->data,&next_ptr->data)==0) // ptr이 가리키는 데이터와 next_ptr이 가리키는 데이터가 같은 경우
			{
				list->crnt=next_ptr; // 현재 커서를 중복되는 데이터로 옮기기
				RemoveCurrent(list); // 해당 데이터 제거
			}
			next_ptr=next_ptr->next; // NULL이 되어버린 노드를 버리고 그 다음 노드를 가리키게 함
		}
		ptr=ptr->next; // NULL이 되어버린 노드의 앞 노드는 next_ptr이 가리키게 된 새로운 노드를 가리키게 함
	}
	list->crnt=list->head;
}

void Terminate(List *list)
{
	Clear(list);
}

/*
void Purge(List *list,int compare(const Member *x,const Member *y))
{
	Node *ptr=list->head;
	
	while(ptr!=NULL)
	{
		Node *ptr2=ptr;
		Node *pre=ptr;
		
		while(pre->next!=NULL)
		{
			ptr2=pre->next;
			if(!compare(&ptr->data,&ptr2->data))
			{
				pre->next=ptr2->next;
				free(ptr2);
			}
			else
				pre=ptr2;
		}
		ptr=ptr->next;
	}
	list->crnt=list->head;
}
*/
