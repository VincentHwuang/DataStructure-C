#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include"error.h"
#include"myheader.h"

typedef int ElementType;

struct QueueNode
{
	ElementType  Data;
	struct QueueNode* pNext;
};

struct LinkQueue
{
	struct QueueNode* pFirst;
	struct QueueNode* pLast;
	int				  Length;
};

struct LinkQueue *CreateLinkQueue(void);		//A function to create a link queue
struct QueueNode *CreateQueueNode(ElementType);	//A function to create a queue node.!!!Pay attention,later we must manually free the memory we allocated here,or it will cause memory leak!
//Status DestoryQueue(struct QueueType&);
//Status ClearQueue(struct QueueType&);
BOOL JudgeEmpty(const struct LinkQueue *);	//A function to judge if the link queue is empty
//int GetQueueLength(const struct QueueType&);
//Status GetFirstData(const struct QueueType&, ElementType&);
Status PushSingleData(struct LinkQueue *, ElementType);	//A function to push single data into the link queue
Status PushDatas(struct LinkQueue *,ElementType [],int);//A function to push several datas into the link queue
Status PushSingleNode(struct LinkQueue *,struct QueueNode *);	//A function to push single node into the link queue.
Status PushNodes(struct LinkQueue *,struct QueueNode* [],int);	//A function to push several nodes into the link queue.
struct QueueNode *PopSingleNode(struct LinkQueue *);			//A function to pop single node from the link queue.
struct QueueNode **PopNodes(struct LinkQueue *,int);			//A function to pop several nodes from the link queue.The number of nodes to be poped needs to be specified by the second argument.
//Status QueueTravel(const struct QueueType&, Status(*)(QueueNodeType&));



#endif
