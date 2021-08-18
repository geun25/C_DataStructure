#ifndef __BST_H__
#define __BST_H__

#include "BinaryTree.h" 
#define FAIL 0
#define SUCCESS 1

// 이진탐색트리의 생성 및 초기화
void bst_make_init(BTreeNode** ppRoot);

// 이진탐색트리를 대상으로 데이터 저장 (노드의 생성과정 포함)
int bst_insert(BTreeNode** ppRoot, BTData data);

// 이진탐색트리를 대상으로 데이터 탐색, 발견한 노드 리턴
BTreeNode* bst_search(BTreeNode* pRoot, BTData data);

// 트리에서 노드를 제거하고 제거된 노드의 주소 값 반환
BTreeNode* bst_remove(BTreeNode** ppRoot, BTData data);

#endif
