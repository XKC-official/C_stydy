/*************************************************************
��дʱ�䣺2020-4-12
����汾��V1.0
�����ߣ�����

�����ܣ��ֶ�����㼯�����㲢���������Ժ;���
�������ݣ�����˵�ָ������
�������������Ժ;���
****************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#define MaxNumber 100 //����������
using namespace std;

//������̾����ƽ��
//x[],  y[]�Ǵ�ŵ㼯��x��y��������飬nΪ��ĸ���
//����(���)�����������꣬�Լ������ƽ��
void closestPoints(double x[], double y[], int n) {  
	double x1, x2, y1, y2;                     
	double distance, min = 999999;   //�ֶ������������ƽ��
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j<n; j++) {
			distance = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);     //�������
			if (distance<min) {
				min = distance;      //�Ƚ�
				x1 = x[i]; y1 = y[i];
				x2 = x[j]; y2 = y[j];
			}
		}
	cout << "������Ϊ��(" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")"<<endl;    //�������
	cout << "�����Ϊ��" << sqrt(min);    //����̾���
}



//�����㼯��������������
// x[],  y[], ������ŵ㼯��x��y���������
//����ֵ�����ɵ�����͵�ĸ���
int creat(double x[], double y[]) {   
	int n;
	cout << "�����ĸ�����\n";
	cin >> n;
	cout << "���������꣺\n";
	for (int i = 1; i <= n; i++) {
		cout << "��" << i << "����Ϊ";
		cin >> x[i] >> y[i];
	}
	return n;
}

int main() {
	double x[MaxNumber], y[MaxNumber];
	int n;
	n=creat(x, y);
	closestPoints(x, y, n);
	return 0;
}
