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

Status CheckLocationIndex(LinkList*,int);		//A function to check the location index whether it is valid
LinkList* CreateLinkList(void);                    	//Create a linklist
Status NodeInsertBeforeFirst(LinkList*,ElementType);	//Insert the data before the first node,technically,this function is redundant because we also have the function 'NodeInsertBefore'
Status NodeInsertBefore(LinkList*,int,ElementType);     //Insert the data appointed by the third parameter before the location appointed by th second parameter into the linklist 
Status ClearLinkList(LinkList*);			//A function to clear the linklist
Node *GetNode(LinkList*,int);				//A function to return a node located at a specified location indicated by the second argument
ElementType GetElement(LinkList*, int);       		//A function to return a data located at a specified location indicated by the second argument

BOOL   JudgeEmpty(LinkList*);			        //A function to examine if the linklist is empty
                                                        //return it by the third parameter,and return OK,otherwise return ERROR

Node *DeleteNode(LinkList*, int);   		//A function to delete the data located at a specified location indicated by the second argument and return the deleted data value,and return the deleted node
                                                       //and return it by the third parameter
Status MergeLinkList(LinkList*, LinkList*, LinkList*); //Merge the first linklist and the second linklist to the third linklist







#endif
