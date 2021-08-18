#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#define MAX_LENGTH 4

#define TRUE 1
#define FALSE 0

typedef struct _IterArray
{
	int arr[MAX_LENGTH];
	int curPosition;
} IterArray;

// iterator �ʱ�ȭ
void iter_init(IterArray* p)
{
	printf("Iterator �ʱ�ȭ\n");
	p->curPosition = -1;
}

// ������ ������ �����Ͱ� �ֳ�?
int iter_hasNext(IterArray* p)
{
	if (p->curPosition + 1 < MAX_LENGTH) 
		return TRUE;
	else 
	{
		printf("�� �̻� ������ �����Ͱ� �����ϴ�.\n");
		return FALSE;
	}
}

// ���� ������ �����ϱ�
int iter_next(IterArray* p)
{
	p->curPosition++; // �켱! position�� next�� +1 ����
	return p->arr[p->curPosition]; // curPostion�� ����Ű�� ���� ���� ����
}

int main(int argc, char** argv) 
{

	IterArray data = { {10, 20, 30, 40}, -1 };
	iter_init(&data);

	while (iter_hasNext(&data)) // �� ������ ������ �ֳ�?
	{                                 
		printf("%d\n", iter_next(&data));
	}
	printf("\n");

	// �ٽ� iterator ������ �ϸ�??
	while (iter_hasNext(&data)) // �� ������ ������ �ֳ�?
	{
		printf("%d\n", iter_next(&data));
	}
	printf("\n");

	// iterator �� ���� ���۽��Ѿ� �Ѵ�.
	iter_init(&data);
	while (iter_hasNext(&data)) // �� ������ ������ �ֳ�?
	{
		printf("%d\n", iter_next(&data));
	}
	printf("\n");

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()