#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "ListQueue.h"

// 트리 노드 생성
BTreeNode* btree_make_node(void)
{
	BTreeNode* pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->data = 0;

	return pNewNode;
}

// 노드 데이터 읽기
BTData btree_get_data(BTreeNode* bt)
{
	return bt->data;
}

// 노드 데이터 쓰기
void btree_set_data(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

// 노드의 Left sub tree
BTreeNode* btree_get_left(BTreeNode* bt)
{
	return bt->pLeft;
}

// 노드의 Right sub tree
BTreeNode* btree_get_right(BTreeNode* bt)
{
	return bt->pRight;
}

// 노드의 left에 sub tree 연결하기
void btree_make_left(BTreeNode* bt, BTreeNode* sub)
{
	if (bt->pLeft == NULL)
		bt->pLeft = sub;
}

// 노드의 right에 sub tree 연결하기
void btree_make_right(BTreeNode* bt, BTreeNode* sub)
{
	if (bt->pRight == NULL)
		bt->pRight = sub;
}

// 주어진 노드부터 삭제
void btree_delete(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	// 삭제는 post order(L -> R -> C) 순서로 지워야 한다.

	// 재귀호출!
	btree_delete(bt->pLeft); // L
	btree_delete(bt->pRight); // R

	// 자기자신 삭제
	printf("노드 삭제 : %d \n", bt->data);  //C
	free(bt);
}

//Traversing
void btree_preorder_traverse(BTreeNode* bt, fnVisitNode action)
{
	if (bt == NULL)
		return; // 재귀종료

	// C -> L -> R
	action(bt->data); // C
	btree_preorder_traverse(bt->pLeft, action); // L : 재귀호출
	btree_preorder_traverse(bt->pRight, action); // R : 재귀호출
}

void btree_inorder_traverse(BTreeNode* bt, fnVisitNode action)
{
	if (bt == NULL)
		return; 

	btree_inorder_traverse(bt->pLeft, action); // L : 재귀호출
	action(bt->data); // C
	btree_inorder_traverse(bt->pRight, action); // R : 재귀호출
}

void btree_postorder_traverse(BTreeNode* bt, fnVisitNode action)
{
	if (bt == NULL)
		return;

	btree_postorder_traverse(bt->pLeft, action); // L : 재귀호출
	btree_postorder_traverse(bt->pRight, action); // R : 재귀호출
	action(bt->data); // C
}

// level-order traversing
void btree_levelorder_traverse(BTreeNode* bt, fnVisitNode action)
{
	//큐 준비(BTNode* 데이터)
	Queue q;
	queue_init(&q);

	//일단 root를 큐에 enq
	queue_enq(&q, bt);

	//while(큐가 empty 될때까지)
	while (!queue_is_empty(&q))
	{
		BTreeNode* btCurrent;

		//	1. dequeue하여 출력
		queue_deq(&q, &btCurrent);

		//	2. action() : visit
		action(btCurrent->data);

		//	3. 좀전에 deq한 노드의 left를 enq
		if (btCurrent->pLeft != NULL)
			queue_enq(&q, btCurrent->pLeft);

		//	4. 좀전에 deq한 노드의 right를 enq
		if (btCurrent->pRight != NULL)
			queue_enq(&q, btCurrent->pRight);
	}

	queue_destroy(&q);
}