#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#include "ArrayList.h"

// ����Ʈ ��� ����� �Լ�
void printList(List *pList)
{
	list_init_iter(pList); // iteration �ʱ�ȭ
	printf("[");
	while (list_hasNext(pList)) {
		printf("%d ", list_next(pList));
	}
	printf("]\n");
}

int main(int argc, char** argv)
{
	List myList;
	list_init(&myList); // ����Ʈ ����

	printList(&myList);
	list_add(&myList, 100); // ������ �߰�
	printList(&myList);
	list_add(&myList, 50); // ������ �߰�
	printList(&myList);
	list_add(&myList, 100); // ������ �߰�
	printList(&myList);
	list_add(&myList, 20); // ������ �߰�
	printList(&myList);
	list_add(&myList, 45); // ������ �߰� ����
	printList(&myList);
	list_add(&myList, 70); // ������ �߰� ����
	printList(&myList);

	// ������ ����
	list_set(&myList, 0, 40); // 0��° �����͸� 100 -> 40���� ����
	list_set(&myList, 1, 30); // 1��° �����͸� 50 -> 30���� ����
	list_set(&myList, 4, 30); // �ش��ε��� X, ������ ���� ����!!!
	printList(&myList);		// [40  30  100  20]

	// ������ ����
	printf("������ ������ %d\n", list_length(&myList));

	// ������ ��ȸ
	Data data;
	if (list_get(&myList, 0, &data)) printf("0��° : %d\n", data);
	if (list_get(&myList, 6, &data)) printf("6��° : %d\n", data); // ��� X
	if (list_get(&myList, 2, &data)) printf("2��° : %d\n", data);

	// ������ ���� (������ [40 30 100 20])
	list_remove(&myList, 2);
	printList(&myList); // [40 30 20]
	list_remove(&myList, 2);
	printList(&myList); // [40 30]
	list_remove(&myList, 0);
	printList(&myList); // [30]

	printf("������ ������ %d\n", list_length(&myList));

	// ������ ����
	printf("\n");
	list_add(&myList, 10);
	printList(&myList); // [30 10]
	list_insert(&myList, 1, 40);
	printList(&myList); // [30 40 10]
	list_insert(&myList, 4, 5);
	printList(&myList); // [5 30 40 10]
	list_insert(&myList, 0, 5); // insert ����

	list_destroy(&myList); // ����Ʈ ����
	
	{
		printf("--------------------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("�������ϸ� ����: ������ - �ƹ�Ű�� ��������\n");
		_getch();

		printf("%d �� insert...\n", test_size);
		// �������ϸ�
		start = clock();  // �ð����� ����
		for (unsigned int i = 0; i < test_size; i++) {
			list_insert(&myList, 0, i);  // 0��°�� insert!
		}
		end = clock(); // �ð����� ����
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("insert ��� : %ld ms ���\n", end - start);

		//----------------------------------------
		printf("�ƹ�Ű�� �����ø� ���� �׽�Ʈ �����մϴ�\n");
		_getch();
		printf("%d �� get...\n", test_size);

		// �������ϸ�
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_get(&myList, i, &data);
		}
		end = clock(); //�ð� ���� ��
		printf("get ��� : %ld ms ���\n", end - start);
	}
	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()