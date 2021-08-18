#ifndef __BST_H__
#define __BST_H__

#include "BinaryTree.h" 
#define FAIL 0
#define SUCCESS 1

// ����Ž��Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode** ppRoot);

// ����Ž��Ʈ���� ������� ������ ���� (����� �������� ����)
int bst_insert(BTreeNode** ppRoot, BTData data);

// ����Ž��Ʈ���� ������� ������ Ž��, �߰��� ��� ����
BTreeNode* bst_search(BTreeNode* pRoot, BTData data);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� �� ��ȯ
BTreeNode* bst_remove(BTreeNode** ppRoot, BTData data);

#endif
