#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

static BinNode *AllocBinNode(void)
{
	return calloc(1,sizeof(BinNode));
}

static void SetBinNode(BinNode *n,const Member *x,const BinNode *left,const BinNode *right)
{
	n->data=*x;
	n->left=left;
	n->right=right;
}

BinNode *Search(BinNode *p,const Member *x)
{
	int cond;
	
	if(p==NULL)
		return NULL;
	else if((cond=MemberNocmp(x,&p->data))==0)
		return p;
	else if(cond<0)
		Search(p->left,x);
	else
		Search(p->right,x);
}

BinNode *Add(BinNode *p,const Member *x)
{
	int cond;
	
	if(p==NULL)
	{
		p=AllocBinNode();
		SetBinNode(p,x,NULL,NULL);
	}
	else if((cond=MemberNocmp(x,&p->data))==0)
		printf("[오류] %d는 이미 등록되어 있습니다.\n",x->no);
	else if(cond<0)
		p->left=Add(p->left,x);
	else
		p->right=Add(p->right,x);
	
	return p;
}
