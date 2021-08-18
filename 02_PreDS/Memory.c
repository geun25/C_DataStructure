#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

/*
	malloc, free
	calloc, realloc

	memcpy, memset
*/

int main(int argc, char** argv) {

	
	{
		// 동적 메모리 할당
		// (void*)malloc ( 할당 받을 메모리 용량 byte )

		int* arr = (int*)malloc(100); // 100byte 메모리 영역 할당.
		arr[0] = 100;
		arr[1] = 200;

		//int n = 200;
		//arr = &n; // 메모리 누수 발생!!!

		free(arr); // 할당받은 메모리 해제
	}

	{
		int len = 100000;
		int* arr = (int*)malloc(sizeof(int) * len);

		printf("arr[0] ; %d\n", arr[0]);

		memset(arr, 0, sizeof(int) * len);

		printf("arr[0] ; %d\n", arr[0]);

		free(arr);
	}

	{
		int* arr1 = (int*)malloc(sizeof(int) * 3); // 12byte
		arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;
		arr1[3] = 40; // <--- 위험!

		// 기존에 메모리 할당 받은 공간을 '확장/축소' 해서
		// 재할당 받기,  (기존 공간을 따로 free 시켜줄 필요는 없다)
		// re-allocation
		arr1 = (int*)realloc(arr1, sizeof(int) * 5); // 20byte

		arr1[3] = 40; arr1[4] = 50;

		free(arr1);

	}

	printf("메모리 누적 할당 시작합니다...");
	_getch();
	{
		int len = 1000000;
		int* arr;

		for (int i= 0; i < 100; i++) {
			arr = (int*)malloc(sizeof(int) * len);
			_sleep(50); // 0.05초 단위 delay()
			free(arr);
		}
	}

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()