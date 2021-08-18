#include <stdio.h>
#include <stdlib.h>

#include "ListQueue.h"

// ť �ʱ�ȭ
void queue_init(Queue* pq)
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}

// ť ����
void queue_destroy(Queue* pq)
{
	while (!queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}

//ť�� ����ִ��� ?
int queue_is_empty(Queue* pq)
{
	if (pq->pFront == NULL)
		return SUCCESS;
	else
		return FAIL;
}

// enqueue : �����͸� rear�� �߰�
int queue_enq(Queue* pq, Data data)
{
	// ���ο� ��� ����
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->data = data;

	// ť�� ����������� �׷��� ������ ����
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

// dequeue : �����͸� front ���� ������
int queue_deq(Queue* pq, Data* pData)
{
	if (queue_is_empty(pq))
	{
		printf("EMPTY QUEUE!\n");
		return FAIL;
	}

	Node* delNode;// ������ ��� ���

	if (pData != NULL)
		*pData = pq->pFront->data;

	delNode = pq->pFront; // ������ ���� front
	pq->pFront = pq->pFront->pNext;

	free(delNode); // �޸� ����

	return SUCCESS;
}

// peek : front �� �����͸� �б�
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
