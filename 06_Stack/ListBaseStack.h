#ifndef __STACK_H__
#define __STACK_H__

#define SUCCESS 1
#define FAIL 0

/* ������ ADT */

/* ������ ������ */
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* pNext;
} Node;

typedef struct _listStack
{
	Node* pTop; // �� �̹� ���������� numData ���� ����.
} ListStack;

typedef ListStack Stack;

/* ������ ����*/
void stack_init(Stack* pStack); // ���� �ʱ�ȭ
void stack_destroy(Stack* pStack); // ���� ����

int stack_is_empty(Stack* pStack);// ������ ������� Ȯ��

int stack_push(Stack* pStack, Data data);// push : top�� ������ �߰�
int stack_pop(Stack* pStack, Data *pData);// pop : top�� ������ ������
int stack_peek(Stack* pStack, Data *pData);// peek : top�� ������ �̸�����

#endif