#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

int main(int argc, char** argv) {

	for (int i= 0; i < 10; i++) { // for �� �ȿ��� ����� ��������
		printf("%d, ", i);
	}
	printf("\n");
	// for ���� i ����?
	//printf("i = %d\n", i); // �� ���� ���Ŀ��� i ������.

	{
		int n = 10; 
		{
			int n = 20; // ��?!
			printf("n = %d\n", n);
		}
		printf("n = %d\n", n);
	}
	//printf("n = %d\n", n);

	// �ּ�
	{
		int n = 10;
		printf("n = %d\n", n);

		// �ּҿ����� &
		printf("n�� �ּҴ� %p\n", &n); // ���� n�� �ּ�

	}
	printf("\n");

	// �ּҸ� ��� Ÿ��: ������
	{
		int n = 100;
		int *p; // p�� int Ÿ���� �ƴ϶� int* Ÿ��
		
		p = &n; // ������ ���� p�� 'n�� �ּ�' ����
		printf("p = %p, &n = %p\n", p, &n);
	}

	// �������� ������
	{
		int n1 = 300, n2 = 500;
		int *p = &n1; // p�� Ÿ���� int*
		int **pp = &p;		// pp�� Ÿ���� int**

		// ���������� * �� ����ؼ� �ּ���ġ�� ã�ư� �ش� �� ����(���) ����
		printf("n1 = %d, *p = %d, *pp = %d\n", n1, *p, **pp);
		printf("***pp = %d\n", *((int*)(**pp))); // �׾��...
	}

	{
		int arr[] = { 10, 20, 30, 40 };
		//arr[n] = *(arr + n)
	}


	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()