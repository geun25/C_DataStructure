#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

/*
	�Լ��� ���༺�� (�ð����⵵: Time Complexity) üũ
*/

typedef void fnAction(int);	// ������ �Լ� Ÿ��

// �Լ� ���� �ð� ����
void chkTime(char* szTitle, fnAction action, int size)
{
	clock_t start, end;

	printf("%s : size[%d] ��������\n", szTitle, size);
	start = clock(); // ����ð�, ���۽ð�

	action(size);

	end = clock(); // ����ð�
	long result = end - start;
	printf("%s : size[%d] ����ð� %ld ms\n", szTitle, size, result);
}

void func1(int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum++;
	}
}

void func2(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum++;
		}
	}
}

void func3(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				sum++;
			}
		}
	}
}

int main(int argc, char** argv) {
	int size;
	{
		size = 100000000;
		chkTime("O(n)", func1, size);
		chkTime("O(n)", func1, size * 2);
		chkTime("O(n)", func1, size * 4);
	}

	{
		size = 10000;
		chkTime("O(n^2)", func2, size);
		chkTime("O(n^2)", func2, size * 2);
		chkTime("O(n^2)", func2, size * 4);
	}

	{
		size = 500;
		chkTime("O(n^3)", func3, size);
		chkTime("O(n^3)", func3, size * 2);
		chkTime("O(n^3)", func3, size * 4);
	}

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()