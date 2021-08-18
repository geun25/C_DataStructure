#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "ListQueue.h"

// Ʈ�� ��� ����
BTreeNode* btree_make_node(void)
{
	BTreeNode* pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->data = 0;

	return pNewNode;
}

// ��� ������ �б�
BTData btree_get_data(BTreeNode* bt)
{
	return bt->data;
}

// ��� ������ ����
void btree_set_data(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

// ����� Left sub tree
BTreeNode* btree_get_left(BTreeNode* bt)
{
	return bt->pLeft;
}

// ����� Right sub tree
BTreeNode* btree_get_right(BTreeNode* bt)
{
	return bt->pRight;
}

// ����� left�� sub tree �����ϱ�
void btree_make_left(BTreeNode* bt, BTreeNode* sub)
{
	if (bt->pLeft == NULL)
		bt->pLeft = sub;
}

// ����� right�� sub tree �����ϱ�
void btree_make_right(BTreeNode* bt, BTreeNode* sub)
{
	if (bt->pRight == NULL)
		bt->pRight = sub;
}

// �־��� ������ ����
void btree_delete(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	// ������ post order(L -> R -> C) ������ ������ �Ѵ�.

	// ���ȣ��!
	btree_delete(bt->pLeft); // L
	btree_delete(bt->pRight); // R

	// �ڱ��ڽ� ����
	printf("��� ���� : %d \n", bt->data);  //C
	free(bt);
}

//Traversing
void btree_preorder_traverse(BTreeNode* bt, fnVisitNode action)
{
	if (bt == NULL)
		return; // �������

	// C -> L -> R
	action(bt->data); // C
	btree_preorder_traverse(bt->pLeft, action); // L : ���ȣ��
	btree_preorder_traverse(bt->pRight, action); // R : ���ȣ��
}

void btree_inorder_traverse(BTreeNode* bt, fnVisitNode action)
{
	if (bt == NULL)
		return; 

	btree_inorder_traverse(bt->pLeft, action); // L : ���ȣ��
	action(bt->data); // C
	btree_inorder_traverse(bt->pRight, action); // R : ���ȣ��
}

void btree_postorder_traverse(BTreeNode* bt, fnVisitNode action)
{
	if (bt == NULL)
		return;

	btree_postorder_traverse(bt->pLeft, action); // L : ���ȣ��
	btree_postorder_traverse(bt->pRight, action); // R : ���ȣ��
	action(bt->data); // C
}

// level-order traversing
void btree_levelorder_traverse(BTreeNode* bt, fnVisitNode action)
{
	//ť �غ�(BTNode* ������)
	Queue q;
	queue_init(&q);

	//�ϴ� root�� ť�� enq
	queue_enq(&q, bt);

	//while(ť�� empty �ɶ�����)
	while (!queue_is_empty(&q))
	{
		BTreeNode* btCurrent;

		//	1. dequeue�Ͽ� ���
		queue_deq(&q, &btCurrent);

		//	2. action() : visit
		action(btCurrent->data);

		//	3. ������ deq�� ����� left�� enq
		if (btCurrent->pLeft != NULL)
			queue_enq(&q, btCurrent->pLeft);

		//	4. ������ deq�� ����� right�� enq
		if (btCurrent->pRight != NULL)
			queue_enq(&q, btCurrent->pRight);
	}

	queue_destroy(&q);
}