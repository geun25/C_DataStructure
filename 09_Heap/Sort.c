#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#include "Sort.h"

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

void chkTimeLap(fnSort sort, int arr[], int n, char* title)
{
	clock_t start, end;
	start = clock();

	// ���ļ���
	sort(arr, n);

	end = clock();
	printf("%s (size: %d) ������ : %ld ms\n", title, n, end - start);
}

//-----------------------------------------
void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) { // cycle ȸ�� Ƚ�� n-1��
		for (j = 0; j < (n - i) - 1; j++) {  // �� Ƚ��
			// 1. ������ �ΰ� ��
			if (arr[j] > arr[j + 1]) {  // 2. ũ�Ⱑ �ݴ��� << �� >>
				// �� ��ȯ (swap)
				temp = arr[j];		 // << �̵� >> �� ����Ŭ�� �ִ� (n - i) - 1 �� �߻�
				arr[j] = arr[j + 1]; // << �̵� >>
				arr[j + 1] = temp;   // << �̵� >>
			}
		}
		// �߰����� ���
		//printArr(arr, n);
	} // end for
} // end BubbleSort

// ��������
void SelectionSort(int arr[], int n)
{
	int i, j;
	int min_idx;  
	int temp;

	for (i = 0; i < n - 1; i++) // (N - 1)���� ����Ŭ
	{
		// i��°�� ����(i + 1) ���� �����Ͽ� �������� i��° ���� ���� ���� ���� ���� �ּڰ��� ã�´�.
		// �ּڰ��� ��ġ(min_idx) �� '����' �ϴ� ���� ��ǥ��!
		min_idx = i;

		// [i+1 .. n-1] �������� '���� ���� ���� ��ġ min_idx' �� ã�´�
		for (j = i + 1; j < n; j++)  // �ּڰ� Ž��
		{
			if (arr[min_idx] > arr[j])  // Ȥ�� ������ min_idx ��° ������ �� ���� ���� �߰ߵǸ� << �� >>
				min_idx = j;			// min_idx �� �̹��� �߰��� �� ���� ������ �����ϱ�!
		}

		// �� for���� ������
		// min_idx �� ���� i��° ������ ���� �߿��� ���� ���� ���� ����Ű�� �������̴�.
		// �׷��� ���� i ���� min_idx ���� ��ȯ�ϸ� �ȴ�.
		if (i != min_idx) {
			temp = arr[i];		   // << �̵� >> �� ����Ŭ �� ���ƾ� 1ȸ �߻�
			arr[i] = arr[min_idx]; // << �̵� >>
			arr[min_idx] = temp;   // << �̵� >>
		}

		// �߰��ܰ� ���
		//printArr(arr, n);
	}

} // end SelectionSort

// ��������
void InsertionSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++) { // i = 1���� ����!
		insData = arr[i]; // i��° ������ ����(insData�� �ӽ�����), ���߿� INSERT �� ��ġ �������� �� �ڸ��� '����'

		for (j = i - 1; j >= 0; j--) { // j�� i ���ʺ��� �������� �˻��� ����
			if (arr[j] > insData) { // �����Ϸ��� ������ insData ���� j��° �����Ͱ� ũ�� << �� >>
				arr[j + 1] = arr[j]; // j��° �����͸� �������� ��ĭ�� �̵� << �̵� >>
			}
			else
				break; // ���� �װ��� ���Ե� ��ġ, ������ġ ã������ ����
		}

		// ������ j �� �ٷ� �������� ����(INSERT)�� ��ġ
		arr[j + 1] = insData; // ã�� ��ġ�� ���� ���(insData) ���� << �̵� >> �� ����Ŭ �� 1��

		// �߰����� ���
		//printArr(arr, n);
	}
}