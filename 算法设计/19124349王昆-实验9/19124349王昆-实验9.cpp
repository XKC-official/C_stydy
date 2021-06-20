/*************************************************************
��дʱ�䣺2021-5-27
����汾��V1.0
�����ߣ�����

�����ܣ���ƻ��ڶ�̬�滮���㷨ʵ��0-1��������
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/


#include <iostream>
#define MAX_NUM 5
#define MAX_WEIGHT 10
using namespace std;

//��̬�滮���
//���� total_weight ����������w ��Ʒ������v ��Ʒ��ֵ��flag ������飬n ��Ʒ����
//��������
int zero_one_pack(int total_weight, int w[], int v[], int flag[], int n) {
	int c[MAX_NUM + 1][MAX_WEIGHT + 1] = { 0 }; 
												
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= total_weight; j++) {
			if (w[i] > j) {
				// ˵����i����Ʒ���ڱ������������Ų���ȥ
				c[i][j] = c[i - 1][j];
			}
			else {
				//˵����i����Ʒ������С�ڱ��������������Կ���ѡ���i����Ʒ�Ż��ǲ���
				if (c[i - 1][j] > v[i] + c[i - 1][j - w[i]]) {
					c[i][j] = c[i - 1][j];
				}
				else {
					c[i][j] = v[i] + c[i - 1][j - w[i]];
				}
			}
		}
	}

	//�ĸ���ƷӦ�÷Ž�����
	int i = n, j = total_weight;
	while (c[i][j] != 0) {
		if (c[i - 1][j - w[i]] + v[i] == c[i][j]) {

			flag[i] = 1;
			j -= w[i];
		}--i;
	}
	return c[n][total_weight];
}


int main() {
	int gg;
	int total_weight = 10;
	int w[6] = { 0, 2, 2, 6, 5 ,4 };
	int v[6] = { 0, 6,3,5,4,6 };
	int flag[5]; //flag[i][j]��ʾ������Ϊj��ʱ���Ƿ񽫵�i����Ʒ���뱳��
	int total_value = zero_one_pack(total_weight, w, v, flag, 5);
	cout << "��Ҫ�������Ʒ����" << endl;
	for (int i = 1; i <= 5; i++) {
		if (flag[i] == 1)
			cout << i << "����Ϊ" << w[i] << ", ��ֵΪ" << v[i] << endl;
	}
	cout << "�ܵļ�ֵΪ: " << total_value << endl;
	cin >> gg;
	return 0;
}
