#include <stdio.h> // ǥ������� header
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // memcpy, strcpy �޸𸮺�, ���ڿ� �Լ�
#include <conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h> // clock... �ð� ��¥ �Լ�
#pragma warning(disable:4996) // scanf() �� ���� C�Լ� �����޼��� ����
#pragma warning(disable:4477) // unsigned sigend ���� �����޼��� ����

#include "Wallet.h"

int main(int argc, char** argv) {
	Wallet myWallet; // ���� ����

	wlt_init(&myWallet); // ���� �ʱ�ȭ

	wlt_put_coin(&myWallet, 2);// ���� ���� : 500�� x 2��
	wlt_put_bill(&myWallet, 1);// ���� ���� : 1000�� x 1��

	printf("�ܾ� %d\n", wlt_balance(&myWallet)); // �ܾ� : 2000��

	wlt_take_coin(&myWallet, 2); // ���� 2�� ����
	wlt_take_bill(&myWallet, 1); // ���� ����

	printf("�ܾ� %d\n", wlt_balance(&myWallet)); 

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����\n");
	_getch();
	return 0;
} // end main()