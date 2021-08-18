#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#include "ListBaseStack.h"

int main(int argc, char** argv) 
{
	Stack stack;
	Data data;

	stack_init(&stack); // Stack ���� �� �ʱ�ȭ

	//������ push
	stack_push(&stack, 1); // 1
	stack_push(&stack, 2); // 2 -> 1
	stack_push(&stack, 3); // 3 -> 2 -> 1
	stack_push(&stack, 4); // 4 -> 3 -> 2 -> 1
	stack_push(&stack, 5); // 5 -> 4 -> 3 -> 2 -> 1

	//������ pop
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

	stack_destroy(&stack); // Stack ����

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()