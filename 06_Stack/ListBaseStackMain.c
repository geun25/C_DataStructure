#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

#include "ListBaseStack.h"

int main(int argc, char** argv) 
{
	Stack stack;
	Data data;

	stack_init(&stack); // Stack 생성 및 초기화

	//데이터 push
	stack_push(&stack, 1); // 1
	stack_push(&stack, 2); // 2 -> 1
	stack_push(&stack, 3); // 3 -> 2 -> 1
	stack_push(&stack, 4); // 4 -> 3 -> 2 -> 1
	stack_push(&stack, 5); // 5 -> 4 -> 3 -> 2 -> 1

	//데이터 pop
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data); // 5
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data); // 4
	 
	while (!stack_is_empty(&stack)) // 3 2 1
	{
		stack_pop(&stack, &data);
		printf("pop --> %d\n", data);
	}

	for (int i = 100; i <= 1000; i += 100)
	{
		stack_push(&stack, i);
	}

	while (!stack_is_empty(&stack)) // 1000 900 ... 100
	{
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}

	stack_destroy(&stack); // Stack 제거

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()