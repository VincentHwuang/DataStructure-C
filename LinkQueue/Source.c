#include"linkqueue.h"

void PrintQueueInfo(struct LinkQueue *);
void PrintQueueNodeInfo(struct QueueNode *);
void PrintStatusMessage(Status,char *);
void PrintBOOLMessage(BOOL,char *);
Status Handler(struct QueueNode *);

int main(int argc,char **argv)
{
	//Test for function 'CreateLinkQueue()'
	struct LinkQueue *pQueue0=CreateLinkQueue();
	if(pQueue0 != NULL)
	{
		printf("Succeed to create a new link queue!\n");
		PrintQueueInfo(pQueue0);
	}
	else
	{
		printf("Failed to create a new link queue!\n");
		exit(1);
	}
	//Test for function 'JudgeEmpty()'
	if(JudgeEmpty(pQueue0) == TRUE)
	{
		printf("The link queue is empty.\n");
	}
	else
	{
		printf("It's not empty.\n");
	}
//	//Test for function 'CreateQueueNode()'
//	struct QueueNode *pNode0=CreateQueueNode(10);
//	PrintQueueNodeInfo(pNode0);
	//Test for function 'PushSingleData()'
//	int i;
//	for(i=90;i<100;i++)
//	{	if(PushSingleData(pQueue0,i) == OK)
//		{
//			;
//		}
//		else
//		{
//			printf("Failed to push single data!\n");
//			break;
//		}
//	}
	//Test for function 'PushDatas()'
//	int Datas[5]={1,2,3,4,5};
//	int number=sizeof(Datas)/sizeof(Datas[0]);
//	PrintStatusMessage(PushDatas(pQueue0,Datas,number),"push several datas.");
//	PrintQueueInfo(pQueue0);
	//Test for function 'PushSingleNode()'
//	struct QueueNode *pNewNode=CreateQueueNode(15);
//	PrintStatusMessage(PushSingleNode(pQueue0,pNewNode),"push a node.");
//	PrintQueueInfo(pQueue0);
	//Test for function 'PushNodes()'
	struct QueueNode* Nodes[5];
	int i;
	int number;
	for(i=0;i<5;i++)
	{
		Nodes[i]=CreateQueueNode(i);
	}
	number=sizeof(Nodes)/sizeof(Nodes[0]);
	PrintStatusMessage(PushNodes(pQueue0,Nodes,number),"push several nodes.");
	PrintQueueInfo(pQueue0);
	//Test for function 'PopSingleNode()'
//	struct QueueNode *pNode=PopSingleNode(pQueue0);
//	if(pNode != NULL)
//	{
//		printf("Succeed to pop single node.\n");
//		PrintQueueInfo(pQueue0);
//		PrintQueueNodeInfo(pNode);
//	}
//	else
//	{
//		printf("Failed to pop single node.\n");
//	}
	//Test for function 'PopNodes()'
//	number=pQueue0->Length;
//	struct QueueNode **pNodes=PopNodes(pQueue0,number);
//	if(pNodes != NULL)
//	{
//		printf("Succeed to pop several nodes.\n");
//		for(i=0;i<number;i++)
//		{
//			PrintQueueNodeInfo(pNodes[i]);
//		}
//		PrintQueueInfo(pQueue0);
//	}
//	else
//	{
//		printf("Failed to pop several nodes.\n");
//	}
	//Test for function 'GetQueueLength()'
//	int Length;
//	Length=GetQueueLength(pQueue0);
//	printf("The length of the link queue is:%d\n",Length);
//	//Test for function 'GetSingleData()'
//	ElementType Data;
//	Data=GetSingleData(pQueue0);
//	printf("Data returned is:%d\n",Data);
//	//Test for function 'GetDatas()'
//	ElementType *pDatas;
//	Length=pQueue0->Length;
//	
//	pDatas=GetDatas(pQueue0,Length);
//	if(pDatas != NULL)
//	{
//		printf("Succeed to get several datas, they are:\n");
//		for(i=0;i<Length;i++)
//		{
//			printf("%d\n",pDatas[i]);
//		}
//	}
//	else
//	{
//		printf("Failed to get several datas.\n");
//	}
	//Test for function 'DestoryQueue()'
//	PrintBOOLMessage(DestoryQueue(&pQueue0),"destory the link queue");
	//Test for function 'ClearQueue()'
//	PrintStatusMessage(ClearQueue(pQueue0),"clear the queue");
//	PrintQueueInfo(pQueue0);
	//Test for function 'QueueTraverse()'
	Status (*pHandler)(struct QueueNode *)=Handler;
	PrintStatusMessage(QueueTraverse(pQueue0,pHandler),"traverse the link queue.");
	PrintQueueInfo(pQueue0);

	return 0;
}

void PrintQueueInfo(struct LinkQueue *pQueue)
{
	CheckAddresses((unsigned long long int)pQueue);
	printf("[DEBUG] the address of the queue is:%p\nThe length of the queue is:%d\nThe value of pFirst is:%p\nThe value of pLast is:%p\n",pQueue,pQueue->Length,pQueue->pFirst,pQueue->pLast);
	int i;
	int Length=pQueue->Length;
	struct QueueNode *pNode=pQueue->pFirst;
	printf("Datas in the queue are:\n");
	for(i=0;i<Length;i++)
	{
		printf("%d\n",pNode->Data);
		pNode=pNode->pNext;
	}
	
	return;
}

void PrintQueueNodeInfo(struct QueueNode *pNode)
{
	CheckAddresses((unsigned long long int)pNode);
	printf("[DEBUG] the address of the node is:%p\nThe data is:%d\nThe value of pNext is:%p\n",pNode,pNode->Data,pNode->pNext);

	return;
}

void PrintStatusMessage(Status Flag,char *Handler)
{
	if(Flag == OK)
	{
		printf("Succeed to %s\n",Handler);
	}
	else
	{
		printf("Failed to %s\n",Handler);
	}

	return;
}

void PrintBOOLMessage(BOOL Flag,char *Handler)
{
	if(Flag == TRUE)
	{
		printf("Succeed to %s\n",Handler);
	}
	else
	{
		printf("Failed to %s\n",Handler);
	}

	return;
}

Status Handler(struct QueueNode *pNode)
{
	pNode->Data *= 7;

	return OK;
}


