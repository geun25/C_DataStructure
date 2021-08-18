#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

// ��Ʈ ������ ��� �Ͽ� ��뼺�� ���
// �θ��� �ε���
#define GET_PARENT_IDX(idx) ((idx) >> 1) // idx / 2

// left �ڽĳ�� �ε���
#define GET_LEFT_IDX(idx) ((idx) << 1) // idx * 2

// right �ڽĳ�� �ε���
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) // idx * 2 + 1

// ���Լ� ��� ��ũ�� (���� UP)
#define COMP_ASC(d1, d2) ((d2) - (d1)) // ��������
#define COMP_DESC(d1, d2) ((d1) - (d2)) // ��������
//--------------------------------------------------------

/*
// �� �ʱ�ȭ
void heap_init(Heap* ph, fnPriorityComp pc)
{
	ph->numData = 0; // ������(���) ����
	ph->comp = pc; // ���Լ�
}
*/

// �� �ʱ�ȭ
void heap_init(Heap* ph, int len)
{
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1)); // +1�� ��ŭ �ʿ� 1 base
	g_hp = ph; // �����Ŀ� �ʿ�
}

// �� ����
void heap_destroy(Heap* ph)
{
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
	g_hp = NULL;
}

// ���� ��� �ֳ�?
int heap_is_empty(Heap* ph)
{
	if (ph->numData == 0)
		return SUCCESS;
	return FAIL;
}

// idx �� �ڽĵ� �� �켱 ������ ���� �ڽ��� index �� ���� --> delete�� ���
int getHighPriority(Heap* ph, int idx)
{
	// �ڽĳ�尡 ���ٸ� 0 ����
	if (GET_LEFT_IDX(idx) > ph->numData)
		return 0;

	// ���� �ڽ� ��尡 ������(������) �ڽ� �����
	if (GET_LEFT_IDX(idx) == ph->numData)
		return GET_LEFT_IDX(idx);

	// �켱 ���� ���Լ� ���
	//if (ph->comp(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
		return GET_RIGHT_IDX(idx); // Right �켱���� ����.
	else
		return GET_LEFT_IDX(idx); // left �켱���� ���ų� ����.
}

// ���� ������ �߰�
void heap_insert(Heap* ph, HData data)
{
	int idx = ph->numData + 1; // �迭�ε����� '1' ���� �����Ѵ�.

	// �Ʒ� while�� �����ϸ鼭 ���� insert�� data�� ��ġ�� idx�� ����
	while (idx != 1) // root (�ֻ���)�� �����Ҷ�����
	{
		// �θ𺸴� �켱������ ���ٸ�
		//if (ph->comp(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)
		{
			// �θ� ���� ������
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];

			// �θ� index �� idx ���� �̵�
			idx = GET_PARENT_IDX(idx);
		}

		else // �θ𺸴� �켱������ ���ų� �۴ٸ� .. �ű⼭ ����
		{
			break;
		}
	}
	ph->heapArr[idx] = data; // idx�� ���� �װ��� ���� ���� data ����
	ph->numData++; // ������ ���� 1 ����
}

// ������ ����(root ����) �Ͽ�  ����
HData heap_delete(Heap* ph)
{
	// �ε��� 1���� ��Ʈ���
	// �̸� �����ϰ� �����Ѵ�.
	HData retData = ph->heapArr[1];

	// numData ��°�� ������ ���
	HData lastElem = ph->heapArr[ph->numData];

	int idx = 1;
	int childIdx;

	// �ϴ�, �ڽĳ���� �켱���� ������ ����
	// ���� �ڽ��� �ϳ��� ���ٸ� 0�� ���ϵǾ� while �� ����
	// �Ʒ� while���� idx���� �����ϱ� ����.
	while (childIdx = getHighPriority(ph, idx))
	{
		// ���õ� �ڽİ�, �Ʒ����� �ö�� ������ ���� �켱���� ��.
		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����

		//if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		// �ڽ��� �켱������ �� ũ�ٸ�, �� �ڽ��� �θ��� �ڸ��� ��ü
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// ���� �񱳸� ���� idx�� ������ �ڽ���ġ�� ������
		idx = childIdx;
	}

	// while�� �� ���� �� �ڸ��� ������ ��尡 ��ġ�� ���̴�.
	ph->heapArr[idx] = lastElem;
	ph->numData--; // ������ ���� 1 ����
	return retData; // ���� ������ ���� root ����
}

void HeapSort(int arr[], int n)
{
	int i;
	// �� ���� ������ �ʰ���
	for (i = 0; i < n; i++)
		heap_insert(g_hp, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = heap_delete(g_hp);
}