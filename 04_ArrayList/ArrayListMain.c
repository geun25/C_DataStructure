#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

#include "ArrayList.h"

// 리스트 출력 도우미 함수
void printList(List *pList)
{
	list_init_iter(pList); // iteration 초기화
	printf("[");
	while (list_hasNext(pList)) {
		printf("%d ", list_next(pList));
	}
	printf("]\n");
}

int main(int argc, char** argv)
{
	List myList;
	list_init(&myList); // 리스트 생성

	printList(&myList);
	list_add(&myList, 100); // 데이터 추가
	printList(&myList);
	list_add(&myList, 50); // 데이터 추가
	printList(&myList);
	list_add(&myList, 100); // 데이터 추가
	printList(&myList);
	list_add(&myList, 20); // 데이터 추가
	printList(&myList);
	list_add(&myList, 45); // 데이터 추가 실패
	printList(&myList);
	list_add(&myList, 70); // 데이터 추가 실패
	printList(&myList);

	// 데이터 수정
	list_set(&myList, 0, 40); // 0번째 데이터를 100 -> 40으로 수정
	list_set(&myList, 1, 30); // 1번째 데이터를 50 -> 30으로 수정
	list_set(&myList, 4, 30); // 해당인덱스 X, 데이터 수정 실패!!!
	printList(&myList);		// [40  30  100  20]

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList));

	// 데이터 조회
	Data data;
	if (list_get(&myList, 0, &data)) printf("0번째 : %d\n", data);
	if (list_get(&myList, 6, &data)) printf("6번째 : %d\n", data); // 출력 X
	if (list_get(&myList, 2, &data)) printf("2번째 : %d\n", data);

	// 데이터 삭제 (삭제전 [40 30 100 20])
	list_remove(&myList, 2);
	printList(&myList); // [40 30 20]
	list_remove(&myList, 2);
	printList(&myList); // [40 30]
	list_remove(&myList, 0);
	printList(&myList); // [30]

	printf("데이터 개수는 %d\n", list_length(&myList));

	// 데이터 삽입
	printf("\n");
	list_add(&myList, 10);
	printList(&myList); // [30 10]
	list_insert(&myList, 1, 40);
	printList(&myList); // [30 40 10]
	list_insert(&myList, 4, 5);
	printList(&myList); // [5 30 40 10]
	list_insert(&myList, 0, 5); // insert 실패

	list_destroy(&myList); // 리스트 제거
	
	{
		printf("--------------------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("프로파일링 시작: 스냅샷 - 아무키나 누르세요\n");
		_getch();

		printf("%d 개 insert...\n", test_size);
		// 프로파일링
		start = clock();  // 시간측정 시작
		for (unsigned int i = 0; i < test_size; i++) {
			list_insert(&myList, 0, i);  // 0번째에 insert!
		}
		end = clock(); // 시간측정 종료
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("insert 결과 : %ld ms 경과\n", end - start);

		//----------------------------------------
		printf("아무키나 누르시면 다음 테스트 진행합니다\n");
		_getch();
		printf("%d 개 get...\n", test_size);

		// 프로파일링
		start = clock(); //시간 측정 시작
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_get(&myList, i, &data);
		}
		end = clock(); //시간 측정 끝
		printf("get 결과 : %ld ms 경과\n", end - start);
	}
	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()