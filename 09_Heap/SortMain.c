#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

#define DATA_SIZE 3000

#include "Sort.h"
#include "Heap.h"
#include "Quicksort.h"

int main(int argc, char** argv)
{
	/*
	int length;

	printf("BubbleSort 동작\n");
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

	printf("\nSelectionSort 동작\n");
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

	printf("\nInsertionSort 동작\n");
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
		genRandom(srcArr, DATA_SIZE, DATA_SIZE); // 랜덤 정수들로 생성

		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- 배열 복사
		chkTimeLap(BubbleSort, workArr, DATA _SIZE, "버블정렬");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- 배열 복사
		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택정렬");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- 배열 복사
		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입정렬");
	}

	*/
	//-----------------------------------------------------
	/*
	
	printf("\nWORST vs BEST case\n");
	{
		int srcArr[DATA_SIZE]; // 40000, 
		//genRandom(srcArr, DATA_SIZE, DATA_SIZE); // #1 랜덤 정수들로 생성
		//genIncSorted(srcArr, DATA_SIZE); // #2 오름차순 이미 정렬된 배열
		genDecSorted(srcArr, DATA_SIZE); // #3 내림차순 역정렬된 배열

		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- 배열 복사
		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블정렬");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- 배열 복사
		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택정렬");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE); // workArr <- 배열 복사
		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입정렬");
	}

	*/

	printf("\nHeapSort & QuickSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE, DATA_SIZE); 

		int workArr[DATA_SIZE];

		// Heap 정렬
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

		//printArr(workArr, DATA_SIZE); // 정렬전

		Heap hp;
		heap_init(&hp, DATA_SIZE);

		chkTimeLap(HeapSort, workArr, DATA_SIZE, "힙정렬");

		//printArr(workArr, DATA_SIZE); // 정렬후

		heap_destroy(&hp);

		//Quick 정렬
		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬-랜덤");

		//Quick 정렬 Best, Worst
		genIncSorted(srcArr, DATA_SIZE);
		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬-오름차순");

		genDecSorted(srcArr, DATA_SIZE);
		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬-내림차순");
	}

	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()