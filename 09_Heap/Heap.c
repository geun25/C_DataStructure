#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

// 비트 연산자 사용 하여 사용성능 향상
// 부모노드 인덱스
#define GET_PARENT_IDX(idx) ((idx) >> 1) // idx / 2

// left 자식노드 인덱스
#define GET_LEFT_IDX(idx) ((idx) << 1) // idx * 2

// right 자식노드 인덱스
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) // idx * 2 + 1

// 비교함수 대신 매크로 (성능 UP)
#define COMP_ASC(d1, d2) ((d2) - (d1)) // 오름차순
#define COMP_DESC(d1, d2) ((d1) - (d2)) // 오름차순
//--------------------------------------------------------

/*
// 힙 초기화
void heap_init(Heap* ph, fnPriorityComp pc)
{
	ph->numData = 0; // 데이터(노드) 개수
	ph->comp = pc; // 비교함수
}
*/

// 힙 초기화
void heap_init(Heap* ph, int len)
{
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1)); // +1개 만큼 필요 1 base
	g_hp = ph; // 힙정렬에 필요
}

// 힙 제거
void heap_destroy(Heap* ph)
{
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
	g_hp = NULL;
}

// 힙이 비어 있나?
int heap_is_empty(Heap* ph)
{
	if (ph->numData == 0)
		return SUCCESS;
	return FAIL;
}

// idx 의 자식들 중 우선 순위가 높은 자식의 index 값 리턴 --> delete에 사용
int getHighPriority(Heap* ph, int idx)
{
	// 자식노드가 없다면 0 리턴
	if (GET_LEFT_IDX(idx) > ph->numData)
		return 0;

	// 왼쪽 자식 노드가 유일한(마지막) 자식 노드라면
	if (GET_LEFT_IDX(idx) == ph->numData)
		return GET_LEFT_IDX(idx);

	// 우선 순위 비교함수 사용
	//if (ph->comp(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
		return GET_RIGHT_IDX(idx); // Right 우선순위 높다.
	else
		return GET_LEFT_IDX(idx); // left 우선순위 높거나 같다.
}

// 힙에 데이터 추가
void heap_insert(Heap* ph, HData data)
{
	int idx = ph->numData + 1; // 배열인덱스는 '1' 부터 시작한다.

	// 아래 while문 수행하면서 새로 insert된 data가 위치할 idx를 결정
	while (idx != 1) // root (최상위)에 도달할때까지
	{
		// 부모보다 우선순위가 높다면
		//if (ph->comp(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)
		{
			// 부모를 끌어 내리고
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];

			// 부모 index 로 idx 값을 이동
			idx = GET_PARENT_IDX(idx);
		}

		else // 부모보다 우선순위가 같거나 작다면 .. 거기서 멈춤
		{
			break;
		}
	}
	ph->heapArr[idx] = data; // idx가 멈춘 그곳에 새로 들어온 data 쓰기
	ph->numData++; // 데이터 개수 1 증가
}

// 힙에서 삭제(root 삭제) 하여  리턴
HData heap_delete(Heap* ph)
{
	// 인덱스 1번이 루트노드
	// 이를 리턴하고 제거한다.
	HData retData = ph->heapArr[1];

	// numData 번째가 마지막 노드
	HData lastElem = ph->heapArr[ph->numData];

	int idx = 1;
	int childIdx;

	// 일단, 자식노드중 우선순위 높은거 선택
	// 만약 자식이 하나도 없다면 0이 리턴되어 while 문 종료
	// 아래 while문은 idx값을 결정하기 위함.
	while (childIdx = getHighPriority(ph, idx))
	{
		// 선택된 자식과, 아래에서 올라온 마지막 노드와 우선순위 비교.
		// 만약 자식의 우선순위가 같거나 낮다면 while 종료

		//if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		// 자식의 우선순위가 더 크다면, 그 자식이 부모의 자리로 교체
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// 다음 비교를 위헤 idx를 좀전의 자식위치로 내리기
		idx = childIdx;
	}

	// while이 다 끝난 그 자리가 마지막 노드가 위치할 곳이다.
	ph->heapArr[idx] = lastElem;
	ph->numData--; // 데이터 개수 1 감소
	return retData; // 최초 저장해 놓은 root 리턴
}

void HeapSort(int arr[], int n)
{
	int i;
	// 힙 정렬 구현은 초간단
	for (i = 0; i < n; i++)
		heap_insert(g_hp, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = heap_delete(g_hp);
}