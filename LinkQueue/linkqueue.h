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

void CheckNumber(const struct LinkQueue *,int);	//A function to check if the number is valid.
struct LinkQueue *CreateLinkQueue(void);		//A function to create a link queue
struct QueueNode *CreateQueueNode(ElementType);	//A function to create a queue node.!!!Pay attention,later we must manually free the memory we allocated here,or it will cause memory leak!
Status FreeSingleNode(struct QueueNode **);		//A function to free memory of a single node.
Status FreeNodes(struct QueueNode **,int);		//A function to free memory of several nodes, the number is specified by the second argument.
Status DestoryQueue(struct LinkQueue **);		//A function to destory the link queue.
Status ClearQueue(struct LinkQueue *);			//A function to clear the link queue.
BOOL JudgeEmpty(const struct LinkQueue *);				//A function to judge if the link queue is empty
int GetQueueLength(const struct LinkQueue *);			//A function to get the length of the link queue.
Status PushSingleData(struct LinkQueue *, ElementType);	//A function to push single data into the link queue
Status PushDatas(struct LinkQueue *,ElementType [],int);//A function to push several datas into the link queue
Status PushSingleNode(struct LinkQueue *,struct QueueNode *);	//A function to push single node into the link queue.
Status PushNodes(struct LinkQueue *,struct QueueNode* [],int);	//A function to push several nodes into the link queue.
struct QueueNode *PopSingleNode(struct LinkQueue *);			//A function to pop single node from the link queue.
ElementType GetSingleData(const struct LinkQueue *);			//A function to get single data without pop the node.
struct QueueNode **PopNodes(struct LinkQueue *,int);			//A function to pop several nodes from the link queue.The number of nodes to be poped needs to be specified by the second argument.
ElementType *GetDatas(const struct LinkQueue *,int);			//A function to get several datas without pop the nodes.Pay attention!!! In order to transfer datas,i allocated memory to store them,so you must manually free the memory afterwards or it will cause memory leak!
struct QueueNode **GetNodes(const struct LinkQueue *,int);		//A function to get several nodes without pop the nodes.Pay attention!!! In order to transfer nodes,i allocated memory to store them,so you must manually free the memory afterwards or it will cause memory leak!
Status QueueTraverse(const struct LinkQueue *, Status(*)(struct QueueNode*));	//A function to traverse the link queue,access or modify each data in the queue with the function specified by the second argument.

#endif
