#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

/*

*/

int main(int argc, char** argv)
{
	{
		struct Student
		{
			int age;
			char gender;
		} stu1;

		// ����ü ������,  ��� ���� : . ������ ���
		stu1.age = 10;
		stu1.gender = 'F';

		printf("%d, %c\n", stu1.age, stu1.gender);

		// ����ü ������
		struct Student* pStu;
		pStu = &stu1;

		// ����ü �����ͷ� ��� ���� : -> ������ ���
		pStu->age = 23;
		pStu->gender = 'M';
		printf("%d, %c\n", pStu->age, pStu->gender);
	}
	
	{
		//typedef ����ü Ÿ�Ը�;

		typedef struct _Student
		{
			int age;
			char gender;
		} Student;

		Student stu1; // typedef�� ����ϸ� ����!!!
		Student* pStu1;
	}

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()