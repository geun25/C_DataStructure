#ifndef __ARRAY _LIST H__
#define __ARRAY _LIST H__

/*
	ArrayList�� ADT 
	
	����: n��° �����Ϳ� ���� �˻�/��ȸ �ӵ��� ������.
	�迭�� ����ũ�� ���ӵ� �޸� ������ �ֱ� ������ 
	�迭÷�� ����(->) ������ �������� �ſ� ������ n��° ������ ��ȸ

	����: ������� �ʴ� �����Ϳ� ���ؼ��� �޸� ����.
	������ ����/������ ��ư�, �ð��� ���� �ɸ���.
*/

#define SUCCESS 1
#define FAIL 0

/* ArrayList �� ������ ���� */
//#define LIST_LEN 4 // �ִ�� ������ �ִ� ������
#define LIST_LEN	30000 // �������ϸ���

typedef int Data; // �����ʹ� intŸ��

typedef struct _ArrayList {
	Data arr[LIST_LEN]; // ���� ������(��) , �迭�� ����
	int numData;		// ����Ʈ���� ������ ����
	int curPosition;	// iteration
} ArrayList;

typedef ArrayList List;

/* ArrayList ���� */
void list_init(List* pList); // ����Ʈ �ʱ�ȭ
void list_destroy(List* pList); // ����Ʈ ����

int list_add(List* pList, Data data); // ������ �߰�
int list_remove(List* pList, int n); // n��° ������ ����
int list_set(List* pList, int n, Data data); // n��° ������ ����
int list_length(List* pList);// ������ ����

//iteration ����
void list_init_iter(List* pList); // ������ ��ȸ, �ʱ�ȭ
Data list_next(List* pList); // ������ ��ȸ, ���� ������
int list_hasNext(List* pList); // ������ ��ȸ : ������ �ֳ�?

int list_get(List* pList, int n, Data* pData);// ������ ��ȸ : n��° ������ �� �б�

int list_insert(List* pList, int n, Data data); // ������ ���� : n��° ��ġ�� ������ ����
#endif