#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

/*
	malloc, free
	calloc, realloc

	memcpy, memset
*/

int main(int argc, char** argv) {

	
	{
		// ���� �޸� �Ҵ�
		// (void*)malloc ( �Ҵ� ���� �޸� �뷮 byte )

		int* arr = (int*)malloc(100); // 100byte �޸� ���� �Ҵ�.
		arr[0] = 100;
		arr[1] = 200;

		//int n = 200;
		//arr = &n; // �޸� ���� �߻�!!!

		free(arr); // �Ҵ���� �޸� ����
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
		arr1[3] = 40; // <--- ����!

		// ������ �޸� �Ҵ� ���� ������ 'Ȯ��/���' �ؼ�
		// ���Ҵ� �ޱ�,  (���� ������ ���� free ������ �ʿ�� ����)
		// re-allocation
		arr1 = (int*)realloc(arr1, sizeof(int) * 5); // 20byte

		arr1[3] = 40; arr1[4] = 50;

		free(arr1);

	}

	printf("�޸� ���� �Ҵ� �����մϴ�...");
	_getch();
	{
		int len = 1000000;
		int* arr;

		for (int i= 0; i < 100; i++) {
			arr = (int*)malloc(sizeof(int) * len);
			_sleep(50); // 0.05�� ���� delay()
			free(arr);
		}
	}

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()