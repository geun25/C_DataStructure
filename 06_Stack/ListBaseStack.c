#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListBaseStack.h"

// ���� �ʱ�ȭ
void stack_init(Stack* pStack)
{
	pStack->pTop = NULL;
}

// ���� ����
void stack_destroy(Stack* pStack)
{
	while (!stack_is_empty(pStack)) // ������ �� �����������
	{
		stack_pop(pStack, NULL); // pop
	}
}

// ������ ������� Ȯ��
int stack_is_empty(Stack* pStack)
{
	if (pStack->pTop == NULL)
		return SUCCESS;
	return FAIL;
}

// push : top�� ������ �߰�
int stack_push(Stack* pStack, Data data)
{
	// ���ο� ��� ����
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;

	// ��带 ���ÿ� �߰� (����Ʈ �� �տ� insert)
	pNewNode->pNext = pStack->pTop;
	pStack->pTop = pNewNode;

	return SUCCESS;
}

// pop : top�� ������ ������
int stack_pop(Stack* pStack, Data* pData)
{
	if (stack_is_empty(pStack)) // ������ ����ִٸ�,
	{
		printf("Empty Stack\n");
		return FAIL;
	}

	Node* pCurrent = pStack->pTop; // ������ ��� ���

	if (pData != NULL) 
		*pData = pStack->pTop->data; // ������ �б�(������)

	pStack->pTop = pStack->pTop->pNext; // TOP �̵�

	free(pCurrent); // pop �� ��� ����

	return SUCCESS;
}

// peek : top�� ������ �̸�����
int stack_peek(Stack* pStack, Data* pData)
{
	if (stack_is_empty(pStack))
	{
		printf("Empty Stack\n");
		return FAIL;
	}

	if (pData != NULL)
		*pData = pStack->pTop->data; // ������ �б�(������)

	return SUCCESS;
}
