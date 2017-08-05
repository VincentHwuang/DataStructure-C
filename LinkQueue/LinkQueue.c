#include"linkqueue.h"

struct LinkQueue *CreateLinkQueue(void)
{
	struct LinkQueue *NewQueue;
	NewQueue=(struct LinkQueue*)ECMalloc(sizeof(struct LinkQueue));
	NewQueue->pFirst=NULL;
	NewQueue->pLast=NULL;
	NewQueue->Length=0;

	return NewQueue;
}

struct QueueNode *CreateQueueNode(ElementType Data)
{
	struct QueueNode *pNewNode=(struct QueueNode *)ECMalloc(sizeof(struct QueueNode));
	pNewNode->Data=Data;
	pNewNode->pNext=NULL;

	return pNewNode;
}

Status FreeSingleNode(struct QueueNode **pNode)
{
	free(*pNode);
	*pNode=NULL;

	return OK;
}

Status FreeNodes(struct QueueNode **pNodes,int number)
{
	CheckAddresses((unsigned long long int)pNodes);

	int i;
	for(i=0;i<number;i++)
	{
		FreeSingleNode(&pNodes[i]);
	}

	return OK;
}

Status DestoryQueue(struct LinkQueue **pQueue)
{
	CheckAddresses((unsigned long long int)*pQueue);

	if(JudgeEmpty(*pQueue) == TRUE)
	{
		free(*pQueue);
		*pQueue=NULL;

		return OK;
	}

	int i;
	int Length=GetQueueLength(*pQueue);
	struct QueueNode *pCurrentNode=(*pQueue)->pFirst;

	if(Length == 1)
	{
		FreeSingleNode(&pCurrentNode);
		free(*pQueue);
		*pQueue=NULL;

		return OK;
	}

	struct QueueNode *pNextNode=pCurrentNode->pNext;
	for(i=0;i<Length;i++)
	{
		FreeSingleNode(&pCurrentNode);
		pCurrentNode=pNextNode;
		if(pCurrentNode == NULL)
		{
			break;
		}
		pNextNode=pNextNode->pNext;
	}

	free(*pQueue);
	*pQueue=NULL;

	return OK;
}

/*
Status ClearQueue(struct QueueType& Queue)
{
	QueueNodeType* pTemporary0 = Queue.pFront->pNext;
	QueueNodeType* pTemporary1 = pTemporary0->pNext;
	while (pTemporary0 !=Queue.pRear)
	{
		free(pTemporary0);
		pTemporary0 = NULL;
		pTemporary0 = pTemporary1;
		pTemporary1 = pTemporary1->pNext;
	}
	free(pTemporary0);
	pTemporary0 = NULL;
	Queue.pFront->pNext = NULL;
	Queue.pRear = Queue.pFront;

	return OK;
}
*/
BOOL JudgeEmpty(const struct LinkQueue *pQueue)
{
	CheckAddresses((unsigned long long int)pQueue);

//	return ((pQueue->pFirst == NULL) && (pQueue->pLast == NULL));
	return (pQueue->Length == 0);
}

int GetQueueLength(const struct LinkQueue *pQueue)
{
	CheckAddresses((unsigned long long int)pQueue);

	return pQueue->Length;
}

Status PushSingleData(struct LinkQueue *pQueue, ElementType DataPushed)
{
	CheckAddresses((unsigned long long int)pQueue);
	
	struct QueueNode *pNewNode=CreateQueueNode(DataPushed);
	if(JudgeEmpty(pQueue) == TRUE)
	{
		pQueue->pFirst=pNewNode;
		pQueue->pLast=pNewNode;
		pQueue->Length++;
	}
	else
	{
		pQueue->pLast->pNext=pNewNode;
		pQueue->pLast=pNewNode;
		pQueue->Length++;
	}

	return OK;
}

Status PushDatas(struct LinkQueue *pQueue,ElementType Datas[],int number)
{
	CheckAddresses((unsigned long long int)pQueue);
	
	int i;
	for(i=0;i<number;i++)
	{
		PushSingleData(pQueue,Datas[i]);
	}

	return OK;
}

Status PushSingleNode(struct LinkQueue *pQueue,struct QueueNode *pNode)
{
	CheckAddresses((unsigned long long int)pQueue * (unsigned long long int)pNode);

	pNode->pNext=NULL;	//'pNext' of the last node must be NULL
	if(JudgeEmpty(pQueue) == TRUE)
	{
		pQueue->pFirst=pNode;
		pQueue->pLast=pNode;
		pQueue->Length++;
	}
	else
	{
		pQueue->pLast->pNext=pNode;
		pQueue->pLast=pNode;
		pQueue->Length++;
	}

	return OK;
}

Status PushNodes(struct LinkQueue *pQueue,struct QueueNode* Nodes[],int number)
{
	CheckAddresses((unsigned long long int)pQueue);
	
	int i;
	for(i=0;i<number;i++)
	{
		PushSingleNode(pQueue,Nodes[i]);
	}

	return OK;
}

struct QueueNode *PopSingleNode(struct LinkQueue *pQueue)
{
	CheckAddresses((unsigned long long int)pQueue);
	
	struct QueueNode *pFirstNode=pQueue->pFirst;
	if(JudgeEmpty(pQueue) == TRUE)
	{
		printf("Sorry,the link queue is empty!\n");
		return NULL;
	}
	else
	{
		pQueue->pFirst=pFirstNode->pNext;
		pQueue->Length--;
		if(pQueue->Length == 0)
		{
			pQueue->pFirst=NULL;
			pQueue->pLast=NULL;
		}
	}

	return pFirstNode;

}

ElementType GetSingleData(const struct LinkQueue *pQueue)
{
	CheckAddresses((unsigned long long int)pQueue);

	return (pQueue->pFirst->Data);
}

struct QueueNode **PopNodes(struct LinkQueue *pQueue,int number)
{
	CheckAddresses((unsigned long long int)pQueue);

	if(pQueue->Length < number)
	{
		printf("Sorry,there are not enough nodes to pop!\n");
		return NULL;
	}

	struct QueueNode **pNodes=(struct QueueNode**)ECMalloc(sizeof(struct QueueNode*) * number);
	int i;
	for(i=0;i<number;i++)
	{
		pNodes[i]=PopSingleNode(pQueue);	
	}

	return pNodes;
}

ElementType *GetDatas(const struct LinkQueue *pQueue,int number)
{
	CheckAddresses((unsigned long long int)pQueue);
	if(number > (pQueue->Length))
	{
		printf("Sorry,there are not enough datas!\n");
		return NULL;
	}

	ElementType *pDatas=(ElementType*)ECMalloc(sizeof(ElementType)*number);
	struct QueueNode *pCurrentNode=pQueue->pFirst;
	int i;

	for(i=0;i<number;i++)
	{
		pDatas[i]=pCurrentNode->Data;
		pCurrentNode=pCurrentNode->pNext;
	}

	return pDatas;
}
/*
Status QueueTravel(const struct QueueType& Queue, Status(*Visit)(QueueNodeType&))
{
	QueueNodeType* pTemporary = Queue.pFront->pNext;
	while (Visit(*pTemporary) > 0)
	{
		pTemporary = pTemporary->pNext;
		if (pTemporary == NULL)
			break;
	}
	if (pTemporary == NULL)
		return OK;
	else
		return ERROR;
}
*/
