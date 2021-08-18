#ifndef __ARRAY _LIST H__
#define __ARRAY _LIST H__

/*
	ArrayList의 ADT 
	
	장점: n번째 데이터에 대한 검색/조회 속도가 빠르다.
	배열은 고정크기 연속된 메모리 공간에 있기 때문에 
	배열첨자 연산(->) 포인터 연산으로 매우 빠르게 n번째 데이터 조회

	단점: 사용하지 않는 데이터에 대해서도 메모리 차지.
	데이터 삭제/삽입이 어렵고, 시간이 많이 걸린다.
*/

#define SUCCESS 1
#define FAIL 0

/* ArrayList 의 데이터 정의 */
//#define LIST_LEN 4 // 최대로 담을수 있는 데이터
#define LIST_LEN	30000 // 프로파일링용

typedef int Data; // 데이터는 int타입

typedef struct _ArrayList {
	Data arr[LIST_LEN]; // 정수 데이터(들) , 배열로 구현
	int numData;		// 리스트안의 데이터 개수
	int curPosition;	// iteration
} ArrayList;

typedef ArrayList List;

/* ArrayList 동작 */
void list_init(List* pList); // 리스트 초기화
void list_destroy(List* pList); // 리스트 제거

int list_add(List* pList, Data data); // 데이터 추가
int list_remove(List* pList, int n); // n번째 데이터 삭제
int list_set(List* pList, int n, Data data); // n번째 데이터 수정
int list_length(List* pList);// 데이터 개수

//iteration 관련
void list_init_iter(List* pList); // 데이터 조회, 초기화
Data list_next(List* pList); // 데이터 조회, 다음 데이터
int list_hasNext(List* pList); // 데이터 조회 : 다음번 있나?

int list_get(List* pList, int n, Data* pData);// 데이터 조회 : n번째 데이터 값 읽기

int list_insert(List* pList, int n, Data data); // 데이터 삽입 : n번째 위치에 데이터 삽입
#endif