/*************************************************************
��дʱ�䣺2021-5-26
����汾��V1.0
�����ߣ�����

�����ܣ���ƻ���̰�ķ����㷨ʵ�ֻ��������
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/

#include <iostream>
#include<stdio.h>
using namespace std;


//�����ṹ��
void swap(int ar_a[], int a, int b)
{
	int temp = ar_a[a];
	ar_a[a] = ar_a[b];
	ar_a[b] = temp;
}


//ð������
//�������飬�Լ�����ͷβ
//�������������
void bubble_sort(int ar_f[], int ar_s[], int left, int right)
{
	for (int i = left; i < right; i++){
		for (int j = left + 1; j <= right; j++){
			if (ar_f[j] < ar_f[j - 1]){
				swap(ar_s, j, j - 1);
				swap(ar_f, j, j - 1);
			}
		}
	}
}

//̰���㷨������������
//�������飬�Լ����鳤��
//������Ž��
void  GreedySelect(int ar_s[], int ar_f[], bool ar_a[], int lenght_ar_s)
{
	int n = lenght_ar_s - 1;
	ar_a[1] = true;
	int j = 1, count = 1;
	cout << "1";
	for (int i = 2; i <= n; i++){
		if (ar_s[i] >= ar_f[j]){
			ar_a[i] = true;
			j = i;
			count++;
			cout << i << endl;
		}
		else{
			ar_a[i] = false;
		}
	}
	cout << "count=" << count << endl;
}

int main()
{	
	int ar_s[] = { 1,3,0,5,3,5,6,8,8,2,12 };
	int ar_f[] = { 4,5,6,7,8,9,10,11,12,13,14 };

	const int length_ar_f = sizeof(ar_f) / sizeof(ar_f[0]);
	const int length_ar_s = sizeof(ar_s) / sizeof(ar_s[0]);
	bool ar_a[length_ar_f] = {};
	bubble_sort(ar_f, ar_s, 1, length_ar_f - 1);
	GreedySelect(ar_s, ar_f, ar_a, length_ar_s);

	return 0;
}






