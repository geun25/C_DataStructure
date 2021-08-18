#ifndef ___BINARY_TREE_H__
#define ___BINARY_TREE_H__

/* Binary Tree 데이터 */
typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* pLeft; // left child node
	struct _bTreeNode* pRight; // right child node
} BTreeNode;

/* Binary Tree 동작 */
BTreeNode* btree_make_node(void); // 트리 노드 생성
BTData btree_get_data(BTreeNode* bt); // 노드 데이터 읽기
void btree_set_data(BTreeNode* bt, BTData data); // 노드 데이터 쓰기

BTreeNode* btree_get_left(BTreeNode* bt); // 노드의 Left sub tree
BTreeNode* btree_get_right(BTreeNode* bt); // 노드의 Right sub tree

void btree_make_left(BTreeNode* bt, BTreeNode* sub); // 노드의 left에 sub tree 연결하기
void btree_make_right(BTreeNode* bt, BTreeNode* sub); // 노드의 right에 sub tree 연결하기

void btree_delete(BTreeNode* bt); // 주어진 노드부터 삭제

// Traversing
typedef void fnVisitNode(BTData data); // vist 하여 수행할 함수 (함수포인터) 선언

void btree_preorder_traverse(BTreeNode* bt, fnVisitNode action);
void btree_inorder_traverse(BTreeNode* bt, fnVisitNode action);
void btree_postorder_traverse(BTreeNode* bt, fnVisitNode action);

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action);

#endif