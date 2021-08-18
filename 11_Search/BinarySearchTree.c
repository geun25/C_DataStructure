#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#include "BinarySearchTree.h"

// ����Ž��Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode** ppRoot)
{
	*ppRoot = NULL;
}

// ����Ž��Ʈ���� ������� ������ ���� (����� �������� ����)
int bst_insert(BTreeNode** ppRoot, BTData data)
{
	BTreeNode* parentNode = NULL; // parent node;
	BTreeNode* curNode = *ppRoot; // current node : �ϴ� root���� ����
	BTreeNode* newNode = NULL; // new node

	//���ο� ��尡 �߰��� ��ġ�� ã�´�
	// root���� �����Ͽ� ��ġ�� ã�������� ������ ��������
	// --> parentNode �� �����ϱ� ���� while
	while (curNode != NULL) {
		if (data == btree_get_data(curNode))
			return FAIL; // Ű�� �ߺ� ������� ����

		parentNode = curNode;

		if (btree_get_data(curNode) > data)
			curNode = btree_get_left(curNode); // �����Ϸ��� �����Ͱ� �� �۴ٸ� curNode�� left�� �̵�
		else // �����Ϸ��� �����Ͱ� �� ũ�ٸ� curNode�� right�� �̵�
			curNode = btree_get_right(curNode);
	}

	// �߰��� �� ��� ����
	newNode = btree_make_node();
	btree_set_data(newNode, data); // �� ��忡 ������ ����

	// parentNode�� ������ �� ��� �߰�
	if (parentNode != NULL) { // �� ��尡 ��Ʈ ��尡 �ƴ϶��,
		if (data < btree_get_data(parentNode)) // �θ��� �����ͺ��� �۴ٸ� left
			btree_make_left(parentNode, newNode); 
		else									// �θ��� �����ͺ��� �۴ٸ� left
			btree_make_right(parentNode, newNode);
	}
	else { // ù��° ����� ���, �� ��尡 ��Ʈ ��ġ�̱⿡ parentNode �� NULL�� ����
		*ppRoot = newNode;
	}
	return SUCCESS;
}

// ����Ž��Ʈ���� ������� ������ Ž��, �߰��� ��� ����
BTreeNode* bst_search(BTreeNode* pRoot, BTData data)
{
	BTreeNode* curNode = pRoot; // current node �� root ���� Ž�� ����
	BTData curData; // current data

	while (curNode != NULL) {
		curData = btree_get_data(curNode);

		if (data == curData)
			return curNode; // �߰�! ��带 �����ϰ� ����.
		else if (data < curData) // �����Ͱ��� curData ���� �۴ٸ� left ����Ʈ���� �̵��Ͽ� Ž��
			curNode = btree_get_left(curNode);
		else// �����Ͱ��� curData ���� ũ�ٸ� right ����Ʈ���� �̵��Ͽ� Ž��
			curNode = btree_get_right(curNode);
	}

	return NULL; // Ž�� ���  ����
}