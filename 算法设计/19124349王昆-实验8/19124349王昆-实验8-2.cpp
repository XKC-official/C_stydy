/*************************************************************
��дʱ�䣺2021-5-26
����汾��V1.0
�����ߣ�����

�����ܣ���ƻ���̰�ķ����㷨ʵ�ֹ�������������
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/

#include<iostream>
#include<string>
using namespace std;

#define MaxNum 1000

//���������ṹ��
typedef struct
{
	int weight;
	int flag;
	int parent;
	int lchild;
	int rchild;
}hnodetype;

//�����¼
typedef struct
{
	int bit[10];
	int start;
	char leaf;
}hcodetype;

//������������
//cha:��ǰ�����ַ���m:ÿ���ַ����ֵĴ���,n:�ַ��ܸ���
//����ַ�Ƶ�ʣ��Լ�ÿ���ַ��Ĺ���������
void huf(char cha[], int m[], int n)

{
	int c, i, j, m1, m2, x1, x2, p;
	hnodetype* huffnode = new hnodetype[2 * n - 1];
	hcodetype* huffcode = new hcodetype[n], cd;
	//��ʼ����������
	for (i = 0; i < 2 * n - 1; i++){
		huffnode[i].flag = 0;
		huffnode[i].lchild = -1;
		huffnode[i].rchild = -1;
		huffnode[i].parent = 0;
		huffnode[i].weight = 0;
	}

	for (i = 0; i < n; i++){
		huffnode[i].weight = m[i];
		huffcode[i].leaf = cha[i];
	}

	//����Ѱ����������,��x1,x2��¼
	for (i = 0; i < n - 1; i++){
		m1 = m2 = INT_MAX;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++){
			if (huffnode[j].weight <= m1 && huffnode[j].flag == 0){
				x2 = x1;
				x1 = j;
				m2 = m1;
				m1 = huffnode[j].weight;
			}
			else if (huffnode[j].weight <= m2 && huffnode[j].flag == 0){
				x2 = j;
				m2 = huffnode[j].weight;
			}
		}

		huffnode[x1].parent = n + i;
		huffnode[x2].parent = n + i;
		huffnode[x1].flag = 1;
		huffnode[x2].flag = 1;
		huffnode[n + i].weight = huffnode[x1].weight + huffnode[x2].weight;
		huffnode[n + i].lchild = x1;
		huffnode[n + i].rchild = x2;
	}
	//���ɹ��������ı���
	for (i = 0; i < n; i++){
		cd.start = n - 1;
		c = i;
		p = huffnode[c].parent;
		while (p != 0){
			if (huffnode[p].lchild == c) cd.bit[cd.start] = 0;
			else cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = huffnode[c].parent;
		}

		cout << huffcode[i].leaf << ":";
		for (j = cd.start + 1; j < n; j++){
			huffcode[i].bit[j] = cd.bit[j];
			cout << cd.bit[j];
		}
		cout << endl;
		huffcode[i].start = cd.start;
	}
	delete[] huffcode;
	delete[] huffnode;
}


int main()
{
	string str;
	int i = 0, j, n, m[MaxNum], h, k = 0;
	char cha[MaxNum];
	cout << "����һ���ַ���:" << endl;
	cin >> str;
	n = str.length();
	cout << "�ַ�������" << n << "���ַ�" << endl;

	for (i = 0; i < n; i++){
		j = 0;
		h = 0;

		while (str[j] != str[i]) j++;

		if (i == j){
			cout << "�ַ�" << str[i] << "����";
			cha[k] = str[i];
		}
		else continue;

		for (j = i; j < n; j++){
			if (str[i] == str[j])
				h++;
		}

		cout << h << "��" << endl;
		m[k] = h;
		k++;
	}

	cout << "ÿ���ַ��Ĺ�����������:" << endl;
	huf(cha, m, k);

	return 0;
}







