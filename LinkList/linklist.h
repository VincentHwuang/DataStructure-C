#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef struct Node Node;
typedef int ElementType;
typedef struct LinkList LinkList;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"error.h"
#include"myheader.h"

struct Node
{
	ElementType Data;
	struct Node* pNext;
};

struct LinkList
{
	int Length;
	struct Node* pFirstNode;
};

Status CheckLocationIndex(const LinkList*,int);			//A function to check the location index whether it is valid
LinkList* CreateLinkList(void);							//A function to Create a linklist
Status NodeInsertBeforeFirst(LinkList*,ElementType);	//A function to insert a data before the first node,technically,this function is redundant because we also have the function 'NodeInsertBefore'
Node *CreateNode(ElementType);							//A function to create a new node.
Status InsertDatas(LinkList*,ElementType [],int);		//A function to insert multiple datas to the link list by an array.
Status NodeInsertBefore(LinkList*,int,ElementType);     //A function to insert the data appointed by the third parameter before the location appointed by th second parameter into the linklist 
Status ClearLinkList(LinkList*);						//A function to clear the linklist
Node *GetNode(const LinkList*,int);						//A function to return a node located at a specified location indicated by the second argument
ElementType GetElement(const LinkList*, int);       	//A function to return a data located at a specified location indicated by the second argument

BOOL JudgeEmpty(const LinkList*);						//A function to examine if the linklist is empty
Node *DeleteFirstNode(LinkList*);						//A function to delete the first Node.[!!!]Pay attention that it returns the deleted node so you must free its memory at some place afterwards,otherwise it will cause memory leak!!!
Node *DeleteNode(LinkList*, int);						//A function to delete the data located at a specified location indicated by the second argument and return the deleted data value,and return the deleted node.[!!!]Pay attention that we also need to free memory space of the deleted node afterwards,otherwise it will cause memory leak!!!
Status DestoryLinkList(LinkList*);						//A function to destory the linklist 
Status AppendLinkList(LinkList*, LinkList*);			//A function to append another link list(specified by the second argument) to current link list(specified by the first argument).
Status TraverseLinkList(LinkList*,Status (*)(Node*));	//A function to traverse the link list,access or modify each data in the link list with the function specified by the second argument.

#endif
