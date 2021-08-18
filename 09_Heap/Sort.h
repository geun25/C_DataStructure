#ifndef __SORT_H__
#define __SORT_H__


void printArr(int arr[], int n); // �迭 ���
void genRandom(int arr[], int n, int bound); // ������ �迭 ���� 0 ~ bound ���� ���� x n��
void genIncSorted(int arr[], int n); // ���� ���� �迭 ����
void genDecSorted(int arr[], int n); // ���� ���� �迭 ����

//-----------------------------------

typedef void fnSort(int arr[], int n);
void chkTimeLap(fnSort sort, int arr[], int n, char *title);

//-----------------------------------
void BubbleSort(int arr[], int n); // ��������
void SelectionSort(int arr[], int n); // ��������
void InsertionSort(int arr[], int n); // ��������
#endif
