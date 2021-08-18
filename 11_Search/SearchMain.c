#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#include "LinkedList.h"
#include "BinarySearchTree.h"

#define LEN 40000

void printArr(int arr[], int n)
{
	printf("[");
	for (int i = 0; i < n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n");  // backspace
}

// ������ �迭 ���� 0 ~ bound ���� ���� x n��
void genRandom(int arr[], int n, int bound)
{
	// ������ ����
	int i;
	srand(time(NULL)); // �ð��� �޶��������� ������ ����
	for (i = 0; i < n; i++) {
		arr[i] = rand() % bound + 1; // bound�� ���� 100�̶��
									 // 1~100���� ���� ����
	}
}

// ���� ���� �迭 ����
void genIncSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = i;
	}
}

// ���� ���� �迭 ����
void genDecSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = n - i;
	}
}

// �迭 ����
void shuffleArr(int arr[], int n)
{
	int i;
	if (n > 1) // �迭���� 2�� �̻��� ��츸 shuffle
	{
		for (i = 0; i < n - 1; i++) 
		{
			// i�� ������ j��°�� swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

// �迭�κ��� list ����
void getList(List* pList, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		list_add(pList, arr[i]);
}

// �迭�κ��� BST ����
void genBST(BTreeNode** ppRoot, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		bst_insert(ppRoot, arr[i]);
}

// �˻��Լ� Ÿ��
typedef void* fnSearch(void*, int);

// Ư�� data �ϳ� Ž�� : �ð� üũ
void chkTimeLapData(fnSearch search, void* collection, int data, char* title)
{
	clock_t start, end;
	start = clock();

	search(collection, data); // Ž�� ����

	end = clock();
	printf("%s (Ž��:%d) ������: %ld ms\n", title, data, end - start);
}

// ���� data Ž�� : �ð� üũ
void chkTimeLapArray(fnSearch search, void* collection, int arr[], int n, char* title)
{
	int cnt = 0;   // Search ������ ����
	clock_t start, end;
	long duration = 0;

	// �� �������� search �� �����ջ� �ѵ� ����� ���Ѵ�.
	for (int i = 0; i < n; i++) {
		start = clock();
		if (search(collection, arr[i]) != NULL) cnt++;  // Ž������
		end = clock();
		duration += end - start;
	}

	printf("%s (%d/%d�� Ž��) ������: %.3f ms\n", title, cnt, n, (double)duration / n); // ��ռ���ð�
}

int main(int argc, char** argv) 
{
	List list;

	//�ߺ��� ���� ���� ���� �迭 ����
	int srcArr[LEN];
	int workArr[LEN];

	genIncSorted(srcArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	shuffleArr(workArr, LEN);
	//printArr(srcArr, LEN);
	//printArr(workArr, LEN);

	list_init(&list);
	getList(&list, workArr, LEN); // list <- workArr

	chkTimeLapArray(list_search, &list, srcArr, LEN, "����ƮŽ��");

	list_destroy(&list);

	// BST Ž��
	BTreeNode* pRoot; // BST�� ��Ʈ
	bst_make_init(&pRoot); //BST �ʱ�ȭ
	genBST(&pRoot, workArr, LEN); // BST <- workArr

	chkTimeLapArray(bst_search, pRoot, srcArr, LEN, "BSTŽ��");

	btree_delete(pRoot); // BST ����

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()