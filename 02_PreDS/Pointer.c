#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

int main(int argc, char** argv) {

	for (int i= 0; i < 10; i++) { // for 블럭 안에서 선언된 지역변수
		printf("%d, ", i);
	}
	printf("\n");
	// for 이후 i 값은?
	//printf("i = %d\n", i); // 블럭 끝난 이후에는 i 사용못함.

	{
		int n = 10; 
		{
			int n = 20; // 엥?!
			printf("n = %d\n", n);
		}
		printf("n = %d\n", n);
	}
	//printf("n = %d\n", n);

	// 주소
	{
		int n = 10;
		printf("n = %d\n", n);

		// 주소연산자 &
		printf("n의 주소는 %p\n", &n); // 변수 n의 주소

	}
	printf("\n");

	// 주소를 담는 타입: 포인터
	{
		int n = 100;
		int *p; // p는 int 타입이 아니라 int* 타입
		
		p = &n; // 포인터 변수 p에 'n의 주소' 대입
		printf("p = %p, &n = %p\n", p, &n);
	}

	// 포인터의 포인터
	{
		int n1 = 300, n2 = 500;
		int *p = &n1; // p의 타입은 int*
		int **pp = &p;		// pp의 타입은 int**

		// 참조연산자 * 을 사용해서 주소위치를 찾아가 해당 값 접근(사용) 가능
		printf("n1 = %d, *p = %d, *pp = %d\n", n1, *p, **pp);
		printf("***pp = %d\n", *((int*)(**pp))); // 죽어요...
	}

	{
		int arr[] = { 10, 20, 30, 40 };
		//arr[n] = *(arr + n)
	}


	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()