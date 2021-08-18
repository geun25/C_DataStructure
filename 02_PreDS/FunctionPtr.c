#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

/*
	함수 포인터

	'함수이름'이 곧 '포인터'닷!

*/

void fnPlus(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}

typedef void fnAction(int, int); // 함수포인터 타입 정의!


int main(int argc, char** argv) 
{
	{
		fnPlus(10, 20);

		printf("fnPlus-> %p\n", fnPlus); // 함수이름-->함수포인터

		// 함수포인터 참조가 곧 '호출' 동작이다.
		(*fnPlus)(30, 40);

		// 함수 포인터 타입 변수 선언 가능
		// int *p;   <-- int 에 대한 포인터
		// void 리턴하고 (int, int) 매개변수 받는 함수에 대한 함수 포인터?
		void(*fnOp)(int, int); // <--fnOp 라는 '함수 포인터변수' 선언

		// 포인터 대입 가능!!!
		fnOp = fnPlus;

		// 함수처럼 호출 가능!
		(*fnOp)(70, 100);

		fnAction* action = fnPlus;
		(*action)(300, 400);
	}

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()