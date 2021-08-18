#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

#include "BinarySearchTree.h"

// 이진탐색트리의 생성 및 초기화
void bst_make_init(BTreeNode** ppRoot)
{
	*ppRoot = NULL;
}

// 이진탐색트리를 대상으로 데이터 저장 (노드의 생성과정 포함)
int bst_insert(BTreeNode** ppRoot, BTData data)
{
	BTreeNode* parentNode = NULL; // parent node;
	BTreeNode* curNode = *ppRoot; // current node : 일단 root부터 시작
	BTreeNode* newNode = NULL; // new node

	//새로운 노드가 추가될 위치를 찾는다
	// root부터 시작하여 위치를 찾을때까지 밑으로 내려간다
	// --> parentNode 를 결정하기 위한 while
	while (curNode != NULL) {
		if (data == btree_get_data(curNode))
			return FAIL; // 키의 중복 허용하지 않음

		parentNode = curNode;

		if (btree_get_data(curNode) > data)
			curNode = btree_get_left(curNode); // 삽입하려는 데이터가 더 작다면 curNode를 left로 이동
		else // 삽입하려는 데이터가 더 크다면 curNode를 right로 이동
			curNode = btree_get_right(curNode);
	}

	// 추가할 새 노드 생성
	newNode = btree_make_node();
	btree_set_data(newNode, data); // 새 노드에 데이터 저장

	// parentNode의 서브노드 새 노드 추가
	if (parentNode != NULL) { // 새 노드가 루트 노드가 아니라면,
		if (data < btree_get_data(parentNode)) // 부모의 데이터보다 작다면 left
			btree_make_left(parentNode, newNode); 
		else									// 부모의 데이터보다 작다면 left
			btree_make_right(parentNode, newNode);
	}
	else { // 첫번째 노드의 경우, 새 노드가 루트 위치이기에 parentNode 는 NULL인 상태
		*ppRoot = newNode;
	}
	return SUCCESS;
}

// 이진탐색트리를 대상으로 데이터 탐색, 발견한 노드 리턴
BTreeNode* bst_search(BTreeNode* pRoot, BTData data)
{
	BTreeNode* curNode = pRoot; // current node 는 root 부터 탐색 시작
	BTData curData; // current data

	while (curNode != NULL) {
		curData = btree_get_data(curNode);

		if (data == curData)
			return curNode; // 발견! 노드를 리턴하고 종료.
		else if (data < curData) // 데이터값이 curData 보다 작다면 left 서브트리로 이동하여 탐색
			curNode = btree_get_left(curNode);
		else// 데이터값이 curData 보다 크다면 right 서브트리로 이동하여 탐색
			curNode = btree_get_right(curNode);
	}

	return NULL; // 탐색 결과  없음
}