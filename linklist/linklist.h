#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef struct Node Node;
typedef int ElementType;
typedef struct LinkList LinkList;

#include"myheader.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void   Fatal(char *);					//A function to print fatal error message
void  *ECMalloc(unsigned int);				//A error-checked version malloc function
Status CheckLocationIndex(LinkList*,int);		//A function to check the location index whether it is valid
Status CheckAddresses(unsigned long long int);		//A function to check addresses whether it is valid
LinkList* CreateLinkList(void);                    //Create a linklist
Status NodeInsertBeforeFirst(LinkList*,ElementType);	//Insert the data before the first node
Status NodeInsertBefore(LinkList*,int,ElementType);     //Insert the data appointed by the third parameter before the location appointed by th second parameter into the linklist 
Status ClearLinkList(LinkList*);			//A function to clear the linklist

Status GetElement(LinkList*, int, ElementType*);       //if the data that appointed by the second parameter are existed,

BOOL   JudgeEmpty(LinkList*);			       //A function to examine if the linklist is empty
                                                       //return it by the third parameter,and return OK,otherwise return ERROR

Status NodeDelete(LinkList*, int, ElementType*);   //Delete the data which location are appointed by the second parameter
                                                       //and return it by the third parameter
Status MergeLinkList(LinkList*, LinkList*, LinkList*); //Merge the first linklist and the second linklist to the third linklist






#endif
