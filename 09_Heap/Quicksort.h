#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

void Swap(int arr[], int idx1, int idx2); // �迭 �ΰ��� �ٲٱ�
int Partition(int arr[], int left, int right); // �迭 ���� �ɰ��� (�ɰ� index ����)
void QuickSort(int arr[], int left, int right); // ��������� ������ ����

void QuickSortMain(int arr[], int n); // main()���� ȣ���� �뵵
#endif