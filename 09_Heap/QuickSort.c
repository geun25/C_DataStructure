#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

#include "Quicksort.h"

// 배열 두개값 바꾸기
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// 배열 영역 쪼개기 (쪼갤 index 리턴)
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽!
	int low = left + 1; // 피벗 오른쪽부터 시작
	int high = right; // 가장 오른쪽에서부터 시작

	while (low <= high) { // 교차되지 않을 때까지 반복하며 low, high 이동

		// low 우측 이동, pivot 보다 큰 것을 만날때까지!
		while (pivot >= arr[low] && low <= right)
			low++;

		// high 좌측 이동, pivot 보다 작은것을 만날때까지!
		while (pivot <= arr[high] && high >= (left + 1))
			high--;

		//low 와 high 가 멈추면!
		if (low <= high) // low, high가 교차되지 않은 상태라면 Swap 진행
			Swap(arr, low, high); // low 와 high가 가리키는 대상 교환
	}

	// pivot 과 high 가 가리키는 값 교환
	Swap(arr, left, high);

	return high; // 옮겨진 피벗의 위치 정보 반환
}

// 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right)
{
	if (left <= right) // 정렬 수행 조건
	{
		int pivot = Partition(arr, left, right); // pivot 기준으로 둘로 나누기
		QuickSort(arr, left, pivot - 1); // 왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬
	}
}

// main()에서 호출할 용도
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

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()

*/