#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

#define MAX_LENGTH 4

#define TRUE 1
#define FALSE 0

typedef struct _IterArray
{
	int arr[MAX_LENGTH];
	int curPosition;
} IterArray;

// iterator 초기화
void iter_init(IterArray* p)
{
	printf("Iterator 초기화\n");
	p->curPosition = -1;
}

// 다음에 추출할 데이터가 있냐?
int iter_hasNext(IterArray* p)
{
	if (p->curPosition + 1 < MAX_LENGTH) 
		return TRUE;
	else 
	{
		printf("더 이상 추출할 데이터가 없습니다.\n");
		return FALSE;
	}
}

// 다음 데이터 추출하기
int iter_next(IterArray* p)
{
	p->curPosition++; // 우선! position이 next로 +1 증가
	return p->arr[p->curPosition]; // curPostion이 가리키는 곳의 값을 추출
}

int main(int argc, char** argv) 
{

	IterArray data = { {10, 20, 30, 40}, -1 };
	iter_init(&data);

	while (iter_hasNext(&data)) // 더 추출할 데이터 있나?
	{                                 
		printf("%d\n", iter_next(&data));
	}
	printf("\n");

	// 다시 iterator 돌리려 하면??
	while (iter_hasNext(&data)) // 더 추출할 데이터 있나?
	{
		printf("%d\n", iter_next(&data));
	}
	printf("\n");

	// iterator 를 새로 동작시켜야 한다.
	iter_init(&data);
	while (iter_hasNext(&data)) // 더 추출할 데이터 있나?
	{
		printf("%d\n", iter_next(&data));
	}
	printf("\n");

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()