#include <stdio.h>
#include <stdlib.h>

#include "ListQueue.h"

// 큐 초기화
void queue_init(Queue* pq)
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}

// 큐 제거
void queue_destroy(Queue* pq)
{
	while (!queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}

//큐가 비어있는지 ?
int queue_is_empty(Queue* pq)
{
	if (pq->pFront == NULL)
		return SUCCESS;
	else
		return FAIL;
}

// enqueue : 데이터를 rear에 추가
int queue_enq(Queue* pq, Data data)
{
	// 새로운 노드 생성
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->data = data;

	// 큐가 비어있을때와 그렇지 않을때 구분
	if (queue_is_empty(pq))
	{
		pq->pFront = pNewNode;
		pq->pRear = pNewNode;
	}
	else
	{
		pq->pRear->pNext = pNewNode;
		pq->pRear = pNewNode;
	}

	return SUCCESS;
}

// dequeue : 데이터를 front 에서 꺼내기
int queue_deq(Queue* pq, Data* pData)
{
	if (queue_is_empty(pq))
	{
		printf("EMPTY QUEUE!\n");
		return FAIL;
	}

	Node* delNode;// 삭제할 노드 기억

	if (pData != NULL)
		*pData = pq->pFront->data;

	delNode = pq->pFront; // 삭제할 노드는 front
	pq->pFront = pq->pFront->pNext;

	free(delNode); // 메모리 해제

	return SUCCESS;
}

// peek : front 의 데이터를 읽기
int queue_peek(Queue* pq, Data* pData)
{
	if (queue_is_empty(pq))
	{
		printf("EMPTY QUEUE!\n");
		return FAIL;
	}

	if (pData != NULL)
		*pData = pq->pFront->data;

	return SUCCESS;
}
