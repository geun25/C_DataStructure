#ifndef ___BINARY_TREE_H__
#define ___BINARY_TREE_H__

/* Binary Tree ������ */
typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* pLeft; // left child node
	struct _bTreeNode* pRight; // right child node
} BTreeNode;

/* Binary Tree ���� */
BTreeNode* btree_make_node(void); // Ʈ�� ��� ����
BTData btree_get_data(BTreeNode* bt); // ��� ������ �б�
void btree_set_data(BTreeNode* bt, BTData data); // ��� ������ ����

BTreeNode* btree_get_left(BTreeNode* bt); // ����� Left sub tree
BTreeNode* btree_get_right(BTreeNode* bt); // ����� Right sub tree

void btree_make_left(BTreeNode* bt, BTreeNode* sub); // ����� left�� sub tree �����ϱ�
void btree_make_right(BTreeNode* bt, BTreeNode* sub); // ����� right�� sub tree �����ϱ�

void btree_delete(BTreeNode* bt); // �־��� ������ ����

// Traversing
typedef void fnVisitNode(BTData data); // vist �Ͽ� ������ �Լ� (�Լ�������) ����

void btree_preorder_traverse(BTreeNode* bt, fnVisitNode action);
void btree_inorder_traverse(BTreeNode* bt, fnVisitNode action);
void btree_postorder_traverse(BTreeNode* bt, fnVisitNode action);

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action);

#endif