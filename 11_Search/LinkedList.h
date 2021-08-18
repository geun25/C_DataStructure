#ifndef __LINKED_LIST H__
#define __LINKED_LIST H__

/*
	LinkedList�� ADT
	
	�迭 ����Ʈ�� ����/������ ��ƴٴ� ���� ����
*/

#define TRUE 1
#define FALSE 0

typedef int Data; // �����ʹ� int

// ��� Ÿ�� ����
typedef struct _node
{
	Data data; // ��� ������
	struct _node* pNext; // ������带 ����ü�� ����
} Node;

// Linked List Ÿ�� ����
typedef struct _linkedList
{
	Node* pHead; // ���� ���
	Node* pTail; // ������ ���
	
	int numData; // ����� ����
	Node* pCurrent; // iteration ��
} LinkedList;

typedef LinkedList List;

/* List ���� */
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

// Ž�� : �־��� pList���� data�� ��� Node �� ã�Ƽ� ����, ������ NULL ����
Node* list_search(List* pList, Data data);
#endif
