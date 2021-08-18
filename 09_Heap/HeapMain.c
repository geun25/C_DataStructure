#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

#include "Heap.h"

int DataPriorityComp(HData ch1, HData ch2) // 비교함수
{
	//return ch1 - ch2; // max_heap
	return ch2 - ch1; // min-heap
}

int main(int argc, char** argv) {

	Heap heap;
	heap_init(&heap, DataPriorityComp);

	heap_insert(&heap, 9);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);
	
	// MAX-Heap
	//	(30)
	//	↙ ↘
	// (9) (20)


	// MIN-Heap
	//	(9)
	//	↙ ↘
	// (20) (30)
										// MAX-Heap	MIN-Heap
	printf("%d\n", heap_delete(&heap)); // 30			9
	printf("%d\n", heap_delete(&heap)); // 20			20
	printf("%d\n", heap_delete(&heap)); // 9			30

	printf("\n");
	heap_insert(&heap, 15);
	heap_insert(&heap, 4);
	heap_insert(&heap, 8);
	heap_insert(&heap, 12);
	heap_insert(&heap, 13);
	heap_insert(&heap, 7);
	heap_insert(&heap, 1);
	heap_insert(&heap, 9);

	while (!heap_is_empty(&heap))
		printf("%d ", heap_delete(&heap));
	printf("\n");															

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()