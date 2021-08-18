#ifndef __HEAP_H__
#define __HEAP_H__

#define SUCCESS 1
#define FAIL	0

/* Heap의 데이터 */
// #define HEAP_LEN 100

typedef int HData; // HData는 정수타입

// d1의 우선순위가 높다면 0보다 큰 값
// d2의 우선순위가 높다면 0보다 작은 값
// d1과 d2의 우선순위가 같다면 0을 반환
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	HData* heapArr; // 동적메모리로 구현 ★
	int numData; // 담고 있는 데이터 개수
	fnPriorityComp* comp; // 우선순위 비교 함수 포인터 변수 설정
} Heap;

/* Heap의 동작*/
//void heap_init(Heap* ph, fnPriorityComp pc); // 힙 초기화
void heap_init(Heap* ph, int len); // 힙초기화
void heap_destory(Heap* ph);

int heap_is_empty(Heap* ph); // 힙이 비어 있나?

void heap_insert(Heap* ph, HData data);// 힙에 데이터 추가
HData heap_delete(Heap* ph);// 힙에서 삭제(root 삭제)하여 리턴

// 힙정렬
Heap* g_hp;
void HeapSort(int arr[], int n);

#endif