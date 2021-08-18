#ifndef __HEAP_H__
#define __HEAP_H__

#define SUCCESS 1
#define FAIL	0

/* Heap�� ������ */
// #define HEAP_LEN 100

typedef int HData; // HData�� ����Ÿ��

// d1�� �켱������ ���ٸ� 0���� ū ��
// d2�� �켱������ ���ٸ� 0���� ���� ��
// d1�� d2�� �켱������ ���ٸ� 0�� ��ȯ
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	HData* heapArr; // �����޸𸮷� ���� ��
	int numData; // ��� �ִ� ������ ����
	fnPriorityComp* comp; // �켱���� �� �Լ� ������ ���� ����
} Heap;

/* Heap�� ����*/
//void heap_init(Heap* ph, fnPriorityComp pc); // �� �ʱ�ȭ
void heap_init(Heap* ph, int len); // ���ʱ�ȭ
void heap_destory(Heap* ph);

int heap_is_empty(Heap* ph); // ���� ��� �ֳ�?

void heap_insert(Heap* ph, HData data);// ���� ������ �߰�
HData heap_delete(Heap* ph);// ������ ����(root ����)�Ͽ� ����

// ������
Heap* g_hp;
void HeapSort(int arr[], int n);

#endif