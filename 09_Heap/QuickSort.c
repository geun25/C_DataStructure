#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#include "Quicksort.h"

// �迭 �ΰ��� �ٲٱ�
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// �迭 ���� �ɰ��� (�ɰ� index ����)
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; // �ǹ��� ��ġ�� ���� ����!
	int low = left + 1; // �ǹ� �����ʺ��� ����
	int high = right; // ���� �����ʿ������� ����

	while (low <= high) { // �������� ���� ������ �ݺ��ϸ� low, high �̵�

		// low ���� �̵�, pivot ���� ū ���� ����������!
		while (pivot >= arr[low] && low <= right)
			low++;

		// high ���� �̵�, pivot ���� �������� ����������!
		while (pivot <= arr[high] && high >= (left + 1))
			high--;

		//low �� high �� ���߸�!
		if (low <= high) // low, high�� �������� ���� ���¶�� Swap ����
			Swap(arr, low, high); // low �� high�� ����Ű�� ��� ��ȯ
	}

	// pivot �� high �� ����Ű�� �� ��ȯ
	Swap(arr, left, high);

	return high; // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

// ��������� ������ ����
void QuickSort(int arr[], int left, int right)
{
	if (left <= right) // ���� ���� ����
	{
		int pivot = Partition(arr, left, right); // pivot �������� �ѷ� ������
		QuickSort(arr, left, pivot - 1); // ���� ������ ����
		QuickSort(arr, pivot + 1, right); // ������ ������ ����
	}
}

// main()���� ȣ���� �뵵
void QuickSortMain(int arr[], int n)
{
	QuickSort(arr, 0, n - 1);
}

/*
int main(int argc, char** argv) {

	int arr[] = { 3, 2, 4, 1, 7, 6, 5 };
	int len = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, len - 1);

	for (int i = 0; i < len; i++)
		printf("%d", arr[i]);
	printf("\n");

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()

*/