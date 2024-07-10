#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

typedef struct __node
{
	Member data;
	struct __node *next; // 뒤쪽 포인터 (다음 노드에 대한 포인터)
} Node;

typedef struct
{
	Node *head; // 머리 노드에 대한 포인터
	Node *crnt; // 선택한 노드에 대한 포인터
} List;

void Initialize(List *list);
Node *Search(List *list,const Member *x,int compare(const Member *x,const Member *y));
void InsertFront(List *list,const Member *x);
void InsertRear(List *list,const Member *x);
void RemoveFront(List *list);
void RemoveRear(List *list);
void RemoveCurrent(List *list);
void Clear(List *list);
void PrintCurrent(const List *list);
void PrintLnCurrent(const List *list);
void Print(const List *list);
void Terminate(List *list);

#endif
