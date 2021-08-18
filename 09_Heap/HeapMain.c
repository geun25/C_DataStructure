#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#include "Heap.h"

int DataPriorityComp(HData ch1, HData ch2) // ���Լ�
{
	//return ch1 - ch2; // max_heap
	return ch2 - ch1; // min-heap
}

int main(int argc, char** argv) {

	Heap heap;
	heap_init(&heap, DataPriorityComp);

	heap_insert(&heap, 9);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);
	
	// MAX-Heap
	//	(30)
	//	�� ��
	// (9) (20)


	// MIN-Heap
	//	(9)
	//	�� ��
	// (20) (30)
										// MAX-Heap	MIN-Heap
	printf("%d\n", heap_delete(&heap)); // 30			9
	printf("%d\n", heap_delete(&heap)); // 20			20
	printf("%d\n", heap_delete(&heap)); // 9			30

	printf("\n");
	heap_insert(&heap, 15);
	heap_insert(&heap, 4);
	heap_insert(&heap, 8);
	heap_insert(&heap, 12);
	heap_insert(&heap, 13);
	heap_insert(&heap, 7);
	heap_insert(&heap, 1);
	heap_insert(&heap, 9);

	while (!heap_is_empty(&heap))
		printf("%d ", heap_delete(&heap));
	printf("\n");															

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()