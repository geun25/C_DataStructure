#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

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

// 배열 섞기
void shuffleArr(int arr[], int n)
{
	int i;
	if (n > 1) // 배열길이 2개 이상인 경우만 shuffle
	{
		for (i = 0; i < n - 1; i++) 
		{
			// i와 임의의 j번째와 swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

// 배열로부터 list 생성
void getList(List* pList, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		list_add(pList, arr[i]);
}

// 배열로부터 BST 생성
void genBST(BTreeNode** ppRoot, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		bst_insert(ppRoot, arr[i]);
}

// 검색함수 타입
typedef void* fnSearch(void*, int);

// 특정 data 하나 탐색 : 시간 체크
void chkTimeLapData(fnSearch search, void* collection, int data, char* title)
{
	clock_t start, end;
	start = clock();

	search(collection, data); // 탐색 수행

	end = clock();
	printf("%s (탐색:%d) 수행결과: %ld ms\n", title, data, end - start);
}

// 여러 data 탐색 : 시간 체크
void chkTimeLapArray(fnSearch search, void* collection, int arr[], int n, char* title)
{
	int cnt = 0;   // Search 성공한 개수
	clock_t start, end;
	long duration = 0;

	// 각 개별적인 search 의 누적합산 한뒤 평균을 구한다.
	for (int i = 0; i < n; i++) {
		start = clock();
		if (search(collection, arr[i]) != NULL) cnt++;  // 탐색수행
		end = clock();
		duration += end - start;
	}

	printf("%s (%d/%d개 탐색) 수행결과: %.3f ms\n", title, cnt, n, (double)duration / n); // 평균수행시간
}

int main(int argc, char** argv) 
{
	List list;

	//중복된 값이 없는 랜덤 배열 생성
	int srcArr[LEN];
	int workArr[LEN];

	genIncSorted(srcArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	shuffleArr(workArr, LEN);
	//printArr(srcArr, LEN);
	//printArr(workArr, LEN);

	list_init(&list);
	getList(&list, workArr, LEN); // list <- workArr

	chkTimeLapArray(list_search, &list, srcArr, LEN, "리스트탐색");

	list_destroy(&list);

	// BST 탐색
	BTreeNode* pRoot; // BST의 루트
	bst_make_init(&pRoot); //BST 초기화
	genBST(&pRoot, workArr, LEN); // BST <- workArr

	chkTimeLapArray(bst_search, pRoot, srcArr, LEN, "BST탐색");

	btree_delete(pRoot); // BST 삭제

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()