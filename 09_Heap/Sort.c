#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

#include "Sort.h"

void printArr(int arr[], int n)
{
	printf("[");
	for (int i = 0; i < n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n");  // backspace
}

// 무작위 배열 생성 0 ~ bound 범위 숫자 x n개
void genRandom(int arr[], int n, int bound)
{
	// 무작위 점수
	int i;
	srand(time(NULL)); // 시간이 달라질때마다 랜덤수 생성
	for (i = 0; i < n; i++) {
		arr[i] = rand() % bound + 1; // bound가 만약 100이라면
									 // 1~100까지 난수 생성
	}
}

// 오름 차순 배열 생성
void genIncSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = i;
	}
}

// 내림 차순 배열 생성
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

	// 정렬수행
	sort(arr, n);

	end = clock();
	printf("%s (size: %d) 수행결과 : %ld ms\n", title, n, end - start);
}

//-----------------------------------------
void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) { // cycle 회전 횟수 n-1번
		for (j = 0; j < (n - i) - 1; j++) {  // 비교 횟수
			// 1. 인접한 두개 비교
			if (arr[j] > arr[j + 1]) {  // 2. 크기가 반대라면 << 비교 >>
				// 값 교환 (swap)
				temp = arr[j];		 // << 이동 >> 한 사이클당 최대 (n - i) - 1 번 발생
				arr[j] = arr[j + 1]; // << 이동 >>
				arr[j + 1] = temp;   // << 이동 >>
			}
		}
		// 중간과정 출력
		//printArr(arr, n);
	} // end for
} // end BubbleSort

// 선택정렬
void SelectionSort(int arr[], int n)
{
	int i, j;
	int min_idx;  
	int temp;

	for (i = 0; i < n - 1; i++) // (N - 1)번의 사이클
	{
		// i번째의 우측(i + 1) 부터 시작하여 우측에서 i번째 보다 작은 것중 가장 작은 최솟값을 찾는다.
		// 최솟값의 위치(min_idx) 를 '선택' 하는 것이 목표다!
		min_idx = i;

		// [i+1 .. n-1] 범위에서 '가장 작은 값의 위치 min_idx' 를 찾는다
		for (j = i + 1; j < n; j++)  // 최솟값 탐색
		{
			if (arr[min_idx] > arr[j])  // 혹시 기존의 min_idx 번째 값보다 더 작은 것이 발견되면 << 비교 >>
				min_idx = j;			// min_idx 는 이번에 발견한 더 작은 값으로 선택하기!
		}

		// 위 for문이 끝나면
		// min_idx 의 값은 i번째 이후의 원소 중에서 가장 작은 값을 가리키고 있을터이다.
		// 그러면 이제 i 값과 min_idx 값을 교환하면 된다.
		if (i != min_idx) {
			temp = arr[i];		   // << 이동 >> 한 사이클 당 많아야 1회 발생
			arr[i] = arr[min_idx]; // << 이동 >>
			arr[min_idx] = temp;   // << 이동 >>
		}

		// 중간단계 출력
		//printArr(arr, n);
	}

} // end SelectionSort

// 삽입정렬
void InsertionSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++) { // i = 1부터 시작!
		insData = arr[i]; // i번째 데이터 선택(insData에 임시저장), 나중에 INSERT 될 위치 정해지면 그 자리에 '삽입'

		for (j = i - 1; j >= 0; j--) { // j를 i 왼쪽부터 왼쪽으로 검색해 나감
			if (arr[j] > insData) { // 삽입하려는 데이터 insData 보다 j번째 데이터가 크면 << 비교 >>
				arr[j + 1] = arr[j]; // j번째 데이터를 우측으로 한칸씩 이동 << 이동 >>
			}
			else
				break; // 멈춘 그곳이 삽입될 위치, 삽입위치 찾았으니 멈춤
		}

		// 결정된 j 의 바로 오른쪽이 삽입(INSERT)될 위치
		arr[j + 1] = insData; // 찾은 위치에 정렬 대상(insData) 삽입 << 이동 >> 한 사이클 당 1번

		// 중간과정 출력
		//printArr(arr, n);
	}
}