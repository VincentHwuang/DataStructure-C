#include"linklist.h"

Status CheckLocationIndex(const LinkList* pLinkList,int Index)
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

Node *CreateNode(ElementType Data)
{
	Node *pNewNode;
	pNewNode=(Node*)ECMalloc(sizeof(Node));

	pNewNode->Data=Data;
	pNewNode->pNext=NULL;

	return pNewNode;
}

Status NodeInsertBeforeFirst(LinkList* pLinkList,ElementType DataInserted)
{
	Node* pFirstNode = pLinkList->pFirstNode;
	CheckAddresses((unsigned long long int)pLinkList);
	Node* pTemporary = CreateNode(DataInserted);
	pTemporary->pNext = pFirstNode;
	pLinkList->pFirstNode = pTemporary;
	(pLinkList->Length)++;

	return OK;
}

Status InsertDatas(LinkList *pLinkList,ElementType Datas[],int Number)
{
	CheckAddresses((unsigned long long int)pLinkList);

	int Counter;
	Node *pNewNode;
	Node *pLastNode;

	if(JudgeEmpty(pLinkList) == TRUE)
	{
		if(NodeInsertBeforeFirst(pLinkList,Datas[0]) != OK)
		{
			Fatal("in InsertDatas() function while inserting data before the first node!\n");
		}
	}

	pLastNode=GetNode(pLinkList,pLinkList->Length);
	for(Counter=1;Counter<Number;Counter++)
	{
		pNewNode=CreateNode(Datas[Counter]);
		pLastNode->pNext=pNewNode;
		pLastNode=pNewNode;
		pLinkList->Length++;
	}

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

BOOL JudgeEmpty(const LinkList *pLinkList)
{
	if(pLinkList->Length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	return (pLinkList->Length == 0 ? TRUE:FALSE);
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

Node *GetNode(const LinkList *pLinkList, int LocationIndex)
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

ElementType GetElement(const LinkList* pLinkList, int LocationIndex)
{
	Node *pNode;
	pNode=GetNode(pLinkList,LocationIndex);

	return (pNode->Data);
}

Node *DeleteFirstNode(LinkList *pLinkList)
{
	CheckAddresses((unsigned long long int)pLinkList);

	Node *pFirstNode;

	pFirstNode=pLinkList->pFirstNode;
	pLinkList->pFirstNode=pFirstNode->pNext;
	pLinkList->Length--;

	return pFirstNode;
}

Node *DeleteNode(LinkList* pLinkList, int LocationIndex)
{
	CheckAddresses((unsigned long long int)pLinkList);
	CheckLocationIndex(pLinkList,LocationIndex);

	Node *pBackCarrier;
	Node *pLastNode;

	if(1 == LocationIndex)
	{
		return (DeleteFirstNode(pLinkList));
	}
	else
	{
		pLastNode=GetNode(pLinkList,LocationIndex-1);
		pBackCarrier=pLastNode->pNext;
		pLastNode->pNext=pBackCarrier->pNext;
		pLinkList->Length--;

		return pBackCarrier;
	}
}

Status DestoryLinkList(LinkList *pLinkList)
{
	CheckAddresses((unsigned long long int)pLinkList);

	int Counter=0;
	int LinkListLength=pLinkList->Length;
	Node *pCurrentNode=pLinkList->pFirstNode;
	Node *pNext;

	for(;Counter<LinkListLength;Counter++)
	{
		pNext=pCurrentNode->pNext;
		free(pCurrentNode);
		pCurrentNode=pNext;
	}

	free(pLinkList);
	pLinkList=NULL;

	return OK;
}

Status AppendLinkList(LinkList* pLinkList0, LinkList* pLinkList1)
{
	CheckAddresses((unsigned long long int)pLinkList0 * (unsigned long long int)pLinkList1);
	Node *pLastNode;
	int Length=pLinkList0->Length;

	pLastNode=GetNode(pLinkList0,Length);
	pLastNode->pNext=pLinkList1->pFirstNode;
	pLinkList0->Length += pLinkList1->Length;
	free(pLinkList1);
	pLinkList1=NULL;
	
	return OK;
}

Status TraverseLinkList(LinkList *pLinkList,Status (*pHandler)(Node*))
{
	CheckAddresses((unsigned long long int)pLinkList * (unsigned long long int)pHandler);

	if(JudgeEmpty(pLinkList) == TRUE)
	{
		Fatal("in TraverseLinkList() function,the link list is empty!\n");
	}

	int Counter;
	Node *pCurrentNode=pLinkList->pFirstNode;
	int  Length=pLinkList->Length;

	for(Counter=0;Counter<Length;Counter++)
	{
		if(pHandler(pCurrentNode) != OK)
		{
			Fatal("in TraverseLinkList() function while handling the data!\n");
		}
		pCurrentNode=pCurrentNode->pNext;
	}

	return OK;
}
