#ifndef __SORT_H__
#define __SORT_H__


void printArr(int arr[], int n); // 배열 출력
void genRandom(int arr[], int n, int bound); // 무작위 배열 생성 0 ~ bound 범위 숫자 x n개
void genIncSorted(int arr[], int n); // 오름 차순 배열 생성
void genDecSorted(int arr[], int n); // 내림 차순 배열 생성

//-----------------------------------

typedef void fnSort(int arr[], int n);
void chkTimeLap(fnSort sort, int arr[], int n, char *title);

//-----------------------------------
void BubbleSort(int arr[], int n); // 버블정렬
void SelectionSort(int arr[], int n); // 선택정렬
void InsertionSort(int arr[], int n); // 삽입정렬
#endif
