#include <stdio.h>
#include <string.h>
#include "ArrayList.h"

// ����Ʈ �ʱ�ȭ
void list_init(List* pList)
{
	pList->numData = 0;
	pList->curPosition = -1; // iteration
	memset(pList->arr, 0, sizeof(pList->arr));
	printf("����Ʈ �ʱ�ȭ\n");
}

// ����Ʈ ����
void list_destroy(List* pList)
{
	pList->numData = 0;
	printf("����Ʈ ����\n");
}

// ������ �߰�
int list_add(List* pList, Data data) // data�� int Ÿ��
{
	if (pList->numData >= LIST_LEN) // 4���� �ȵȴ�...
	{
		printf("������ �߰� �Ұ�\n");
		return FAIL;
	}
	pList->arr[pList->numData] = data;
	printf("[%d] ��° ������ %d �߰�\n", pList->numData, data);
	(pList->numData)++;
	return SUCCESS;
}

// ������ ��ȸ, �ʱ�ȭ
void list_init_iter(List * pList)
{
	pList->curPosition = -1;
}

// ������ ��ȸ : ������ �ֳ�?
int list_hasNext(List* pList)
{
	if (pList->curPosition + 1 < pList->numData)
		return SUCCESS; // �̾Ƴ� �����Ͱ� �ּ� �ϳ� ����

	return FAIL;	
}

// ������ ��ȸ, ���� ������
Data list_next(List* pList)
{
	pList->curPosition++;
	Data result = pList->arr[pList->curPosition];
	return result;
}

// n��° ������ ����
int list_set(List* pList, int n, Data data) 
{
	if (n >= pList->numData) { // n�� ���� �Ǵ� ����
		printf("%d��° ������ ���� ����\n", n);
		return FAIL;
	}

	printf("%d ��° ������ ���� %d --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data; // ����
	return SUCCESS;
}

// ������ ����
int list_length(List* pList)
{
	return pList->numData; 
}

// ������ ��ȸ : n��° ������ �� �б�(������ �������� ������ ó��)
int list_get(List* pList, int n, Data* pData) 
{
	if (n >= pList->numData) // n�� ���� �Ǵ� ����
		return FAIL;

	*pData = pList->arr[n]; // ������ ��, �����͸� ���� ����

	return SUCCESS;
}
	
// n��° ������ ����
int list_remove(List* pList, int n)
{
	if (n >= pList->numData) // n�� ���� �Ǵ� ����
	{
		printf("%d��° ������ ���� ����\n", n);
		return FAIL;
	}

	// �迭�̴ϱ�, �߰��� �����ϸ� ���� �͵��� ��ܿ;� �Ѵ�.
	for (int i = n; i < pList->numData - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1]; // �ٷ� �ڰ��� ������ ���
	}

	pList->numData--; // ����Ʈ length ����

	return SUCCESS;
}

// ������ ���� : n��° ��ġ�� ����
int list_insert(List * pList, int n, Data data)
{
	// �̹� �� �������� �Ұ�
	if (pList->numData >= LIST_LEN) // 4���� �ȵȴ�...
	{
		printf("������ ���� �Ұ�\n");
		return FAIL;
	}
		
	// n ��ȿ���� ����, '�߰�', '��' �������
	if (n > pList->numData)
	{
		printf("%d ��° ��ġ�� ���� �Ұ�\n", n);
		return FAIL;
	}

	//�⺻�� n��° ���� ��ĭ�� �ڷ� �з����� �Ѵ�.
	//�� �ڿ������� n ���� �͵��� ��ĭ�� �������� ����
	for (int i = pList->numData; i - 1 >= n; i--)
	{
		pList->arr[i] = pList->arr[i - 1];
	}
	pList->arr[n] = data; // n��° �� ������
	pList->numData++; // ������ ���������Ƿ� ���� ����
}