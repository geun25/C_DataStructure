#include <stdio.h>
#include <string.h>
#include "ArrayList.h"

// 리스트 초기화
void list_init(List* pList)
{
	pList->numData = 0;
	pList->curPosition = -1; // iteration
	memset(pList->arr, 0, sizeof(pList->arr));
	printf("리스트 초기화\n");
}

// 리스트 제거
void list_destroy(List* pList)
{
	pList->numData = 0;
	printf("리스트 제거\n");
}

// 데이터 추가
int list_add(List* pList, Data data) // data는 int 타입
{
	if (pList->numData >= LIST_LEN) // 4부터 안된다...
	{
		printf("데이터 추가 불가\n");
		return FAIL;
	}
	pList->arr[pList->numData] = data;
	printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);
	(pList->numData)++;
	return SUCCESS;
}

// 데이터 조회, 초기화
void list_init_iter(List * pList)
{
	pList->curPosition = -1;
}

// 데이터 조회 : 다음번 있나?
int list_hasNext(List* pList)
{
	if (pList->curPosition + 1 < pList->numData)
		return SUCCESS; // 뽑아낼 데이터가 최소 하나 존재

	return FAIL;	
}

// 데이터 조회, 다음 데이터
Data list_next(List* pList)
{
	pList->curPosition++;
	Data result = pList->arr[pList->curPosition];
	return result;
}

// n번째 데이터 수정
int list_set(List* pList, int n, Data data) 
{
	if (n >= pList->numData) { // n의 범위 판단 조건
		printf("%d번째 데이터 수정 실패\n", n);
		return FAIL;
	}

	printf("%d 번째 데이터 수정 %d --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data; // 수정
	return SUCCESS;
}

// 데이터 개수
int list_length(List* pList)
{
	return pList->numData; 
}

// 데이터 조회 : n번째 데이터 값 읽기(포인터 연산으로 빠르게 처리)
int list_get(List* pList, int n, Data* pData) 
{
	if (n >= pList->numData) // n의 범위 판단 조건
		return FAIL;

	*pData = pList->arr[n]; // 데이터 값, 포인터를 통해 전달

	return SUCCESS;
}
	
// n번째 데이터 삭제
int list_remove(List* pList, int n)
{
	if (n >= pList->numData) // n의 범위 판단 조건
	{
		printf("%d번째 데이터 삭제 실패\n", n);
		return FAIL;
	}

	// 배열이니까, 중간을 삭제하면 뒤의 것들을 당겨와야 한다.
	for (int i = n; i < pList->numData - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1]; // 바로 뒤것을 앞으로 당김
	}

	pList->numData--; // 리스트 length 감소

	return SUCCESS;
}

// 데이터 삽입 : n번째 위치에 삽입
int list_insert(List * pList, int n, Data data)
{
	// 이미 다 차있으면 불가
	if (pList->numData >= LIST_LEN) // 4부터 안된다...
	{
		printf("데이터 삽입 불가\n");
		return FAIL;
	}
		
	// n 유효범위 검증, '중간', '끝' 삽입허용
	if (n > pList->numData)
	{
		printf("%d 번째 위치에 삽입 불가\n", n);
		return FAIL;
	}

	//기본의 n번째 부터 한칸씩 뒤로 밀려나야 한다.
	//맨 뒤에서부터 n 앞의 것들을 한칸씩 우측으로 복사
	for (int i = pList->numData; i - 1 >= n; i--)
	{
		pList->arr[i] = pList->arr[i - 1];
	}
	pList->arr[n] = data; // n번째 새 데이터
	pList->numData++; // 데이터 삽입했으므로 길이 증가
}