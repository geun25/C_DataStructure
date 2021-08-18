#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#define DATA_SIZE 3000

#include "Sort.h"
#include "Heap.h"
#include "Quicksort.h"

int main(int argc, char** argv)
{
	/*
	int length;

	printf("BubbleSort ����\n");
	{
		int data[] = { 3, 2, 7, 5, 6 };
		length = sizeof(data) / sizeof(int);
		BubbleSort(data, length);
		printArr(data, length);  // 2 3 5 6 7
	}
	{
		int data[] = { 11, 3, 28, 43, 9, 4 };
		length = sizeof(data) / sizeof(int);
		BubbleSort(data, length);
		printArr(data, length);
	}

	printf("\nSelectionSort ����\n");
	{
		int data[] = { 3, 2, 7, 5, 6 };
		length = sizeof(data) / sizeof(int);
		SelectionSort(data, length);
		printArr(data, length);  // 2 3 5 6 7
	}
	{
		int data[] = { 11, 3, 28, 43, 9, 4 };
		length = sizeof(data) / sizeof(int);
		SelectionSort(data, length);
		printArr(data, length);
	}

	printf("\nInsertionSort ����\n");
	{
		int data[] = { 28, 3, 11, 43, 9, 4};
		length = sizeof(data) / sizeof(int);
		InsertionSort(data, length);
		printArr(data, length);  
	}
	{
		int data[] = { 11, 3, 28, 43, 9, 4 };
		length = sizeof(data) / sizeof(int);
		InsertionSort(data, length);
		printArr(data, length);
	}

	*/

	//-----------------------------------------------------
	/*
	printf("\nTIme complexity\n");
	{
		int srcArr[DATA_SIZE]; // 40000, 
		genRandom(srcArr, DATA_SIZE, DATA_SIZE); // ���� ������� ����

		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- �迭 ����
		chkTimeLap(BubbleSort, workArr, DATA _SIZE, "��������");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- �迭 ����
		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "��������");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- �迭 ����
		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "��������");
	}

	*/
	//-----------------------------------------------------
	/*
	
	printf("\nWORST vs BEST case\n");
	{
		int srcArr[DATA_SIZE]; // 40000, 
		//genRandom(srcArr, DATA_SIZE, DATA_SIZE); // #1 ���� ������� ����
		//genIncSorted(srcArr, DATA_SIZE); // #2 �������� �̹� ���ĵ� �迭
		genDecSorted(srcArr, DATA_SIZE); // #3 �������� �����ĵ� �迭

		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- �迭 ����
		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- �迭 ����
		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "��������");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- �迭 ����
		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "��������");
	}

	*/

	printf("\nHeapSort & QuickSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE, DATA_SIZE); 

		int workArr[DATA_SIZE];

		// Heap ����
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

		//printArr(workArr, DATA_SIZE); // ������

		Heap hp;
		heap_init(&hp, DATA_SIZE);

		chkTimeLap(HeapSort, workArr, DATA_SIZE, "������");

		//printArr(workArr, DATA_SIZE); // ������

		heap_destroy(&hp);

		//Quick ����
		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������-����");

		//Quick ���� Best, Worst
		genIncSorted(srcArr, DATA_SIZE);
		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������-��������");

		genDecSorted(srcArr, DATA_SIZE);
		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������-��������");
	}

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()