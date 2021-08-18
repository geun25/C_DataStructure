#ifndef __LINKED_LIST H__
#define __LINKED_LIST H__

/*
	LinkedList의 ADT
	
	배열 리스트의 삽입/삭제가 어렵다는 점을 보완
*/

#define TRUE 1
#define FALSE 0

typedef int Data; // 데이터는 int

// 노드 타입 정의
typedef struct _node
{
	Data data; // 노드 데이터
	struct _node* pNext; // 다음노드를 구조체로 선언
} Node;

// Linked List 타입 정의
typedef struct _linkedList
{
	Node* pHead; // 시작 노드
	Node* pTail; // 마지막 노드
	
	int numData; // 노드의 개수
	Node* pCurrent; // iteration 용
} LinkedList;

typedef LinkedList List;

/* List 동작 */
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

// 탐색 : 주어진 pList에서 data가 담긴 Node 를 찾아서 리턴, 없으면 NULL 리턴
Node* list_search(List* pList, Data data);
#endif
