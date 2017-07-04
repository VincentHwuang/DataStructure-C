#include"linklist.h"

void PrintLinkList(LinkList*);

int main(void)
{
	LinkList *pLinkList;
	//Test for function 'CreateLinkList'
	pLinkList=CreateLinkList();
	PrintLinkList(pLinkList);
	//Test for function 'NodeInsertBeforeFirst'
	NodeInsertBeforeFirst(pLinkList,10);
	PrintLinkList(pLinkList);
	//Test for function 'NodeInsertBefore'
	int ListLength=pLinkList->Length;
	NodeInsertBefore(pLinkList,ListLength,11);
	NodeInsertBefore(pLinkList,1,5);
	NodeInsertBefore(pLinkList,2,6);
	PrintLinkList(pLinkList);
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
//	printf("Node0: 0x%016x ---> Data: %d pNext: 0x%016x\nNode1: 0x%016x ---> Data: %d pNext: 0x%016x\n",(unsigned long long int)Node0,Node0->Data,(unsigned long long int)Node0->pNext,(unsigned long long int)Node1,Node1->Data,(unsigned long long int)Node1->pNext);
	//Test for function 'GetElement'
	ElementType Data0;
	ElementType Data1;
	Data0=GetElement(pLinkList,1);
	Data1=GetElement(pLinkList,3);
	printf("Data0: %d\nData1: %d\n",Data0,Data1);
	

	return 0;	

}

void PrintLinkList(LinkList* pLinkList)
{
	CheckAddresses((unsigned long long int)pLinkList);
	Node* pFirstNode = pLinkList->pFirstNode;
	printf("[DEBUG INFO]: The address of the linklist is 0x%016x\nThe length of the linklist is:%d\n",(unsigned long long int)pLinkList,pLinkList->Length);
	while (pFirstNode)
	{
		printf("%d\n", pFirstNode->Data);
		pFirstNode = pFirstNode->pNext;
	}
	printf("\n");
	return;
}
