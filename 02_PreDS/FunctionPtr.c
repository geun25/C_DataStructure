#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

/*
	�Լ� ������

	'�Լ��̸�'�� �� '������'��!

*/

void fnPlus(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}

typedef void fnAction(int, int); // �Լ������� Ÿ�� ����!


int main(int argc, char** argv) 
{
	{
		fnPlus(10, 20);

		printf("fnPlus-> %p\n", fnPlus); // �Լ��̸�-->�Լ�������

		// �Լ������� ������ �� 'ȣ��' �����̴�.
		(*fnPlus)(30, 40);

		// �Լ� ������ Ÿ�� ���� ���� ����
		// int *p;   <-- int �� ���� ������
		// void �����ϰ� (int, int) �Ű����� �޴� �Լ��� ���� �Լ� ������?
		void(*fnOp)(int, int); // <--fnOp ��� '�Լ� �����ͺ���' ����

		// ������ ���� ����!!!
		fnOp = fnPlus;

		// �Լ�ó�� ȣ�� ����!
		(*fnOp)(70, 100);

		fnAction* action = fnPlus;
		(*action)(300, 400);
	}

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()