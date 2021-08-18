#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned signed 관련 에러메세지 무시

int main(int argc, char** argv) {

	printf("배열\n");

	// 배열 선언 및 초기화
	int arr[5] = { 1, 2, 3, 4, 5 }; // int 타입 5개를 담는 배열 arr을 선언
	
	// 배열[n]의 index는 0 ~ n-1까지
	for (int i = 0; i < 5; i++) {
		printf("arr[%d] = %d\n", i, arr[i]); // arr[i]의 타입은 int
	}

	// 배열이름 arr .. 배열변수라고도 하나.. 본질적으로는 '포인터'닷!
	// arr의 타입은? int*
	printf("arr = %d\n", arr);
	printf("arr = %X\n", arr);
	printf("arr = %p\n", arr); // 주소값 출력은 %p

	// sizeof() 연산자, byte 단위 용량 리턴
	int n = 100;
	printf("sizeof(n) = %d\n", sizeof(n));
	printf("sizeof(n) = %d\n", sizeof(double));
	printf("sizeof(arr[0]) = %d\n", sizeof(arr[0]));
	printf("sizeof(arr) = %d\n", sizeof(arr)); // 20, 포인터와는 다른 결과

	// 배열원소의 개수
	// 배열의 길이 length
	printf("length = %d\n", sizeof(arr) / sizeof(arr[0]));


	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()