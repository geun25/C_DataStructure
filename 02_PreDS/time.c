#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

/*
C, C++ 에서 시작 측정하기
	방법1:  time() 사용
	방법2:  clock() 사용

C 에서 프로그램 실행 지연 시키기
	_sleep() 사용
*/

int main(int argc, char** argv) {

	// time() 함수
	{
		time_t start, end;
		printf("time() 측정시작\n");
		start = time(NULL); // 현재 시간 측정(시작시간)

		int n = 10; // 30000, 60000 .. 테스트 해보자. 얼마나 시간이 걸리나?
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum += i*j;
			}
		}

		end = time(NULL); // (종료시간)
		double result = (double)(end - start); // 경과시간
		printf("%f s\n", result);
	}

	// clock() 사용
	{
		clock_t start, end;

		printf("clock() 측정시작\n");
		start = clock(); // 현재시간, 시작시간

		// 측정할 코드..
		int n = 60000; // 30000, 60000 .. 테스트 해보자. 얼마나 시간이 걸리나?
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum += i * j;
			}
		}

		end = clock(); // 종료시간
		long result = end - start;
		printf("%ld ms\n", result);
	}

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()