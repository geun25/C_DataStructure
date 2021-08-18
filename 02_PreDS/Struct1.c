#include <stdio.h> // 표준입출력 header
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include <time.h> // clock... 시간 날짜 함수
#pragma warning(disable:4996) // scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477) // unsigned sigend 관련 에러메세지 무시

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

		// 구조체 변수로,  멤버 접근 : . 연산자 사용
		stu1.age = 10;
		stu1.gender = 'F';

		printf("%d, %c\n", stu1.age, stu1.gender);

		// 구조체 포인터
		struct Student* pStu;
		pStu = &stu1;

		// 구조체 포인터로 멤버 접근 : -> 연산자 사용
		pStu->age = 23;
		pStu->gender = 'M';
		printf("%d, %c\n", pStu->age, pStu->gender);
	}
	
	{
		//typedef 구조체 타입명;

		typedef struct _Student
		{
			int age;
			char gender;
		} Student;

		Student stu1; // typedef로 사용하면 개편리!!!
		Student* pStu1;
	}

	printf("\n아무키나 입력하시면 프로그램 종료\n");
	_getch();
	return 0;
} // end main()