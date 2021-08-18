#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

/*
C, C++ ���� ���� �����ϱ�
	���1:  time() ���
	���2:  clock() ���

C ���� ���α׷� ���� ���� ��Ű��
	_sleep() ���
*/

int main(int argc, char** argv) {

	// time() �Լ�
	{
		time_t start, end;
		printf("time() ��������\n");
		start = time(NULL); // ���� �ð� ����(���۽ð�)

		int n = 10; // 30000, 60000 .. �׽�Ʈ �غ���. �󸶳� �ð��� �ɸ���?
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum += i*j;
			}
		}

		end = time(NULL); // (����ð�)
		double result = (double)(end - start); // ����ð�
		printf("%f s\n", result);
	}

	// clock() ���
	{
		clock_t start, end;

		printf("clock() ��������\n");
		start = clock(); // ����ð�, ���۽ð�

		// ������ �ڵ�..
		int n = 60000; // 30000, 60000 .. �׽�Ʈ �غ���. �󸶳� �ð��� �ɸ���?
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum += i * j;
			}
		}

		end = clock(); // ����ð�
		long result = end - start;
		printf("%ld ms\n", result);
	}

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()