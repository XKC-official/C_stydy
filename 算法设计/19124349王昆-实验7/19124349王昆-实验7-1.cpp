/*************************************************************
��дʱ�䣺2021-5-19
����汾��V1.0
�����ߣ�����

�����ܣ����ڱ��η����㷨ʵ�ֶ���������
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/

#include<stdio.h>
#include <iostream>
#include<iomanip>
using namespace std;

//�������飬��������������Ŀ���������е��±���
//��������������
void SiftHeap(int r[], int k, int n) {
	int i, j, temp;
	i = k;
	j = 2 * i + 1;    
	while (j < n) {
		if (j < n - 1 && r[j] < r[j + 1])
			j++;
		if (r[i] > r[j])
			break;
		else {
			temp = r[i]; r[i] = r[j]; r[j] = temp;
			i = j; j = 2 * i + 1;
		}
	}
}
//�������飬��������������Ŀ
//��������������
void HeadSort(int r[], int n) {
	int i, temp;
	for (i = (n - 1) / 2; i >= 0; i--)
		SiftHeap(r, i, n);      //�����ѣ����һ����֧���±���(n-1)/2

	for (i = 1; i <= n - 1; i++) {      //�ؽ���
		temp = r[0]; r[0] = r[n - i]; r[n - i] = temp;
		SiftHeap(r, 0, n - i);
	}
}

int main() {
	int r[100];
	int num;
	cout << "�������ݵ���Ŀ��";
	cin >> num;
	cout << "�������ݣ�";
	for (int i = 0; i < num; i++) {

		cin >> r[i];
	}
	HeadSort(r, num);
	for (int i = 0; i < num; i++)
		cout << r[i]<<" ";
	cout << endl;
	return 0;
}





