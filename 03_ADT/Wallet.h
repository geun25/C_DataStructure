#ifndef __WALLET_H__
#define __WALLET_H__

/*
	Wallet 의 추상자료형(ADT)
*/

#define SUCCESS 1
#define FAIL 0

/** 지갑의 데이터 **/
typedef struct _wallet
{
	int coin500; // 500원짜리 동전개수
	int bill1000; // 1000원짜리 지폐개수
} Wallet;

/** 지갑의 동작**/
void wlt_init(Wallet* p);// 지갑 초기화

void wlt_put_coin(Wallet* p, int coinNum);// 동전 삽입
int wlt_take_coin(Wallet* p, int coinNum); // 동전 추출(반환값 정수)

void wlt_put_bill(Wallet* p, int billNum);// 지폐 삽입
int wlt_take_bill(Wallet* p, int billNum);// 지폐 추출(반환값 정수)

int wlt_balance(Wallet* p);// 지갑 내 잔액 확인

#endif