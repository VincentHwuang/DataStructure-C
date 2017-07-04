#include"linklist.h"

void PrintLinkListInfo(LinkList*);
void PrintNodeInfo(Node*);

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
	//Test for function 'GetElement'
	ElementType Data0;
	ElementType Data1;
	Data0=GetElement(pLinkList,1);
	Data1=GetElement(pLinkList,3);
	printf("Data0: %d\nData1: %d\n",Data0,Data1);
	//Test for function 'DeleteFirstNode'
	Node *pNodeDeleted;
	pNodeDeleted=DeleteFirstNode(pLinkList);
	PrintNodeInfo(pNodeDeleted);
	//[!!!]Pay attention that we must manully free memory of the deleted node
	//otherwise it will cause memory leak!!!
	free(pNodeDeleted);
	pNodeDeleted=NULL;
	pNodeDeleted=DeleteFirstNode(pLinkList);
	PrintNodeInfo(pNodeDeleted);
	free(pNodeDeleted);
	pNodeDeleted=NULL;
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
