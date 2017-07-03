#include"linklist.h"

Status CheckAddresses(unsigned long long int ValueChecked)
{
	if(ValueChecked == 0)	//For 64-bits --> 8 bytes
	{
		Fatal("There is an invalid address value!");
		exit(OVERFLOW);
	}

	return OK;
}
void Fatal(char *ErrorMessage)
{
	char Message[100];
	strcpy(Message,"[!!]Fatal Error: ");
	strncat(Message,ErrorMessage,strlen(ErrorMessage));
	perror(Message);
}

void *ECMalloc(unsigned int size)
{
	void *Pointer;
	Pointer=malloc(size);
	if(Pointer == NULL)
	{
		Fatal("Failed to allocate memory!\n");
		exit(OVERFLOW);
	}

	return Pointer;
}

Status CheckLocationIndex(LinkList* pLinkList,int Index)
{
	if(Index <= 0 || (Index > pLinkList->Length))
	{
		Fatal("The location index is invalid!");
		exit(INDEX_EXCEED);
	}
	else
	{
		return OK;
	}
}

LinkList* CreateLinkList(void)
{
	LinkList *pLinkList;
	pLinkList = (LinkList*)ECMalloc(sizeof(LinkList));

	pLinkList->Length = 0;
	pLinkList->pFirstNode = NULL;

	return pLinkList;
}

Status NodeInsertBeforeFirst(LinkList* pLinkList,ElementType DataInserted)
{
	Node* pFirstNode = pLinkList->pFirstNode;
	CheckAddresses((unsigned long long int)pLinkList);
	Node* pTemporary = (Node*)ECMalloc(sizeof(Node));

	pTemporary->Data = DataInserted;
	pTemporary->pNext = pFirstNode;
	pLinkList->pFirstNode = pTemporary;
	(pLinkList->Length)++;

	return OK;
}

Status NodeInsertBefore(LinkList* pLinkList, int LocationIndex, ElementType DataInserted)
{
	CheckAddresses((unsigned long long int)pLinkList);
	Node* pCurrentNode = pLinkList->pFirstNode;
	int Counter = 1;

	CheckLocationIndex(pLinkList,LocationIndex);
	
	if(1 == LocationIndex)
	{
		NodeInsertBeforeFirst(pLinkList,DataInserted);
	}
	else
	{	
		while(CheckAddresses((unsigned long long int)pCurrentNode) && Counter < LocationIndex - 1)
		{
			pCurrentNode = pCurrentNode->pNext;
			Counter++;
		}
		Node* pTemporary = (Node*)ECMalloc(sizeof(Node));

		pTemporary->Data = DataInserted;
		pTemporary->pNext = pCurrentNode->pNext;
		pCurrentNode->pNext = pTemporary;
		pLinkList->Length++;
	}

	return OK;
}

BOOL JudgeEmpty(LinkList *pLinkList)
{
	if(pLinkList->Length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status ClearLinkList(LinkList* pLinkList)
{
	CheckAddresses((unsigned long long int)pLinkList);
	if(JudgeEmpty(pLinkList) == TRUE)
	{
		printf("The linklist is already empty.\n");
		return OK;
	}
	Node *pTemporary0=pLinkList->pFirstNode;
	Node *pTemporary1;
	int Counter;
	int LinkListLength;
	
	LinkListLength=pLinkList->Length;

	for(Counter=0;Counter<LinkListLength;Counter++)
	{
		pTemporary1=pTemporary0->pNext;
		CheckAddresses((unsigned long long int)pTemporary0);
		free(pTemporary0);
		pTemporary0=NULL;
		pTemporary0=pTemporary1;
		pLinkList->Length--;
	}

	return OK;
}

Node *GetNode(LinkList *pLinkList, int LocationIndex)
{
	CheckAddresses((unsigned long long int)pLinkList);
	CheckLocationIndex(pLinkList,LocationIndex);
	Node *pNode=pLinkList->pFirstNode;
	int Counter=1;
	while((pNode != NULL) && (Counter < LocationIndex))
	{
		pNode = pNode->pNext;
		Counter++;	
	}
	CheckAddresses((unsigned long long int)pNode);

	return pNode;
}

ElementType GetElement(LinkList* pLinkList, int LocationIndex)
{
	Node *pNode;
	pNode=GetNode(pLinkList,LocationIndex);

	return (pNode->Data);
}
/*
ElementType DeleteNode(LinkList* pLinkList, int LocationIndex)
{
	CheckAddresses((unsigned long long int)pLinkList);
	CheckLocationIndex(pLinkList,LocationIndex);
	Node* pFirstNode = pLinkList->pFirstNode;
	int Count = 1;
	if (LocationIndex == 1
	{
		*pBackCarrier = pFirstNode->Data;
		pLinkList->pFirstNode = pFirstNode->pNext;
		pLinkList->Length--;
	}
	else
	{
		while (pFirstNode&&Count < LocationIndex - 1)
		{
			pFirstNode = pFirstNode->pNext;
			Count++;
		}
		if (!pFirstNode)
			return ERROR;

		Node* pTemporary = (Node*)malloc(sizeof(Node));
		if (!pTemporary)
			exit(OVERFLOW);
		pTemporary = pFirstNode->pNext;
		*pBackCarrier = pTemporary->Data;
		pFirstNode->pNext = pTemporary->pNext;
		pLinkList->Length--;
	}

	return OK;
}

Status MergeLinkList(LinkList* pLinkList0, LinkList* pLinkList1, LinkList* pLinkList2)
{

}
*/
