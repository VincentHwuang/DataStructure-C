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

	return 0;	

}

void PrintLinkList(LinkList* pLinkList)
{
	CheckAddresses((unsigned long long int)pLinkList);
	Node* pFirstNode = pLinkList->pFirstNode;
	printf("[DEBUG INFO]: The address of the linklist is 0x%016x\nThe length of the linklist is:%d\n",pLinkList,pLinkList->Length);
	while (pFirstNode)
	{
		printf("%d\n", pFirstNode->Data);
		pFirstNode = pFirstNode->pNext;
	}
	printf("\n");
	return;
}
