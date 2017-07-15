#include"linklist.h"

void PrintLinkListInfo(LinkList*);
void PrintNodeInfo(Node*);
Status HandlerFunc(Node*);

int main(void)
{
	LinkList *pLinkList;
	//Test for function 'CreateLinkList'
	pLinkList=CreateLinkList();
	PrintLinkListInfo(pLinkList);
	//Test for function 'NodeInsertBeforeFirst'
	NodeInsertBeforeFirst(pLinkList,10);
	PrintLinkListInfo(pLinkList);
	//Test for function 'NodeInsertBefore'
	int ListLength=pLinkList->Length;
	NodeInsertBefore(pLinkList,ListLength,11);
	NodeInsertBefore(pLinkList,1,5);
	NodeInsertBefore(pLinkList,2,6);
	PrintLinkListInfo(pLinkList);
	//Test for function 'JudgeEmpty'
	//BOOL flag;
	//flag=JudgeEmpty(pLinkList);
	//if(flag == TRUE)
	//{
	//	printf("The linklist is empty.\n");
	//}
	//else
	//{
	//	printf("The linklist is not empty.\n");
	//}
	//Test for function 'ClearLinkList'
	//if(ClearLinkList(pLinkList) == OK)
	//{
	//	;
	//}
	//if(JudgeEmpty(pLinkList) == TRUE)
	//{
	//	printf("The linklist is empty.\nThe Length is:%d\n",pLinkList->Length);
	//}
	//else
	//{
	//	printf("Something error happened!\n");
	//}
	//Test for function 'GetElement'
	//ElementType DataReturned;
	//DataReturned=GetElement(pLinkList,5);
	//printf("The returned data is:%d\n",DataReturned);
	//Test for function 'GetNode'
//	Node *Node0;
//	Node *Node1;
////	int  TheLast=pLinkList->Length;
//	Node0=GetNode(pLinkList,1);
////	Node1=GetNode(pLinkList,TheLast);	
//	Node1=GetNode(pLinkList,2);
//	PrintNodeInfo(Node0);
//	PrintNodeInfo(Node1);
//	//Test for function 'GetElement'
//	ElementType Data0;
//	ElementType Data1;
//	Data0=GetElement(pLinkList,1);
//	Data1=GetElement(pLinkList,3);
//	printf("Data0: %d\nData1: %d\n",Data0,Data1);
	//Test for function 'DeleteFirstNode'
//	Node *pNodeDeleted;
//	pNodeDeleted=DeleteFirstNode(pLinkList);
//	PrintNodeInfo(pNodeDeleted);
//	//[!!!]Pay attention that we must manully free memory of the deleted node
//	//otherwise it will cause memory leak!!!
//	free(pNodeDeleted);
//	pNodeDeleted=NULL;
//	pNodeDeleted=DeleteFirstNode(pLinkList);
//	PrintNodeInfo(pNodeDeleted);
//	free(pNodeDeleted);
//	pNodeDeleted=NULL;
	//Test for function 'DeleteNode'
//	Node *pNodeDeleted;
//	pNodeDeleted=DeleteNode(pLinkList,2);
//	PrintNodeInfo(pNodeDeleted);
//	PrintLinkListInfo(pLinkList);
//
//	//We must manully free memory of the deleted node otherwise it will cause memory leak!!!
//	free(pNodeDeleted);
//	pNodeDeleted=NULL;

	//Test for function 'DestoryLinkList'
//	if(DestoryLinkList(pLinkList) == OK)
//	{
//		printf("Succeed to destory link list!\n");
//	}
//	else
//	{
//		printf("Failed to destory link list!\n");
//	}
	//Test for function 'InsertDatas'
	LinkList *pNewLinkList=CreateLinkList();
	ElementType Datas[8]={12,234,21,53,34,45,23,54};
	int Number=sizeof(Datas)/sizeof(Datas[0]);
	if(InsertDatas(pNewLinkList,Datas,Number) == OK)
	{
		printf("Succeed insert datas!New link list info:\n");
		PrintLinkListInfo(pNewLinkList);
	}
	else
	{
		printf("Failed to insert datas!\n");
	}

	//Test for function 'AppendLinkList'
	if((AppendLinkList(pLinkList,pNewLinkList)) == OK)
	{
		;
	}
	else
	{
		printf("Failed to append link list!\n");
	}
	PrintLinkListInfo(pLinkList);

	//Test for function 'TraverseLinkList()'
	Status (*Handler)(Node*)=HandlerFunc;
	if(TraverseLinkList(pLinkList,Handler) != OK)
	{
		printf("Failed to traverse the link list,some errors happen!\n");
		exit(1);
	}
	PrintLinkListInfo(pLinkList);
	
	return 0;	
}

void PrintLinkListInfo(LinkList* pLinkList)
{
	CheckAddresses((unsigned long long int)pLinkList);
	Node* pFirstNode = pLinkList->pFirstNode;
	printf("[DEBUG LINKLIST INFO]: The address of the linklist is 0x%016x\nThe length of the linklist is:%d\n",pLinkList,pLinkList->Length);
	while (pFirstNode)
	{
		printf("%d\n", pFirstNode->Data);
		pFirstNode = pFirstNode->pNext;
	}
	printf("\n");
	return;
}

void PrintNodeInfo(Node *pNode)
{
	printf("[DEBUG NODE INFO]: address: 0x%016x\nThe data of it: %d\npNext address: 0x%016x\n",pNode,pNode->Data,pNode->pNext);

	return;
}

Status HandlerFunc(Node *pNode)
{
	pNode->Data += 1;

	return OK;
}
