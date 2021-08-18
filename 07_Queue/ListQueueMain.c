#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시
#include "ListQueue.h"

int main(int argc, char** argv) {

	// Queue 의 생성 및 초기화
	Queue q;
	Data data;
	queue_init(&q); // 큐 초기화

	// enqueue : 데이터 추가
	queue_enq(&q, 1); 
	queue_enq(&q, 2);
	queue_enq(&q, 3);
	queue_enq(&q, 4);
	queue_enq(&q, 5);
	// front --> [1<-2<-3<-4<-5] <-- back

	// dequeue 데이터 꺼내기
	while (!queue_is_empty(&q))
	{
		queue_deq(&q, &data);
		printf("deq --> %d\n", data); // 1 2 3 4 5
	}

	for (int i = 100; i <= 1000; i += 100)
	{
		queue_enq(&q, i);
	}

	while (!queue_is_empty(&q))
	{
		queue_deq(&q, &data);
		printf("deq --> %d\n", data); // 100 ~ 1000
	}

	queue_destroy(&q); // 큐 제거

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()