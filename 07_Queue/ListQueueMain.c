#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����
#include "ListQueue.h"

int main(int argc, char** argv) {

	// Queue �� ���� �� �ʱ�ȭ
	Queue q;
	Data data;
	queue_init(&q); // ť �ʱ�ȭ

	// enqueue : ������ �߰�
	queue_enq(&q, 1); 
	queue_enq(&q, 2);
	queue_enq(&q, 3);
	queue_enq(&q, 4);
	queue_enq(&q, 5);
	// front --> [1<-2<-3<-4<-5] <-- back

	// dequeue ������ ������
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

	queue_destroy(&q); // ť ����

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()