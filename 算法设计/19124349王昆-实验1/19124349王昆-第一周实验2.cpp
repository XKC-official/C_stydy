/*************************************************************
��дʱ�䣺2020-4-1
����汾��V1.0
�����ߣ�����

�����ܣ�������˳����ֳ������Ӽ�S1��S2��ʹ�ã�ÿ���µļ����к���n/2��Ԫ�أ���S1�е�����Ԫ�صĺ���S2�е�����Ԫ�صĺ͵Ĳ����
�������ݣ�����˵�ָ������
�������������Ӽ�
****************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;
#define MaxLen  100 
typedef int ElemType;

/*���Ա��˳��洢�ṹ*/
typedef struct
{
	ElemType r[MaxLen];/*����洢����Ԫ��*/
	int length;/*���Ա�ĵ�ǰ����*/
}SqList;

//��ʼ��
void initlist(SqList* L)
{
	L->length = 0;
}

//����˳���������������
//SqList* S �����ɵ����ݱ�
//����ֵ���������ݺ����ɵ����ݱ�
void KeyboardInput(SqList* L)
{
	int i, k, n;
	cout << "��������Ҫ�����Ԫ�صĸ�����";
	cin >> n;
	L->length = n;
	for (i = 1; i <= n; i++)
	{
		cout << "�������" << i << "��Ԫ�أ�";
		cin >> k;
		L->r[i - 1] = k;
	}
}

//ð������
//L��˳���ĵ�ַ
//����������˳���
void BubbleSort(SqList& L) {
	int i, j, t, flag;
	for (i = 0; i <= L.length - 2; i++) {
		flag = 0;
		for (j = 0; j <= L.length - 2 - i; j++)
			if (L.r[j] > L.r[j + 1]) {
				t = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = t;
				flag = 1;
			}
		if (flag == 0) return;
	}
}


//�����㷨
//L��˳���ĵ�ַ
//���������Ӽ�
void  divide(SqList& L) {
	int S1[MaxLen], S2[MaxLen],i;
	BubbleSort(L);//ð������
	for (i = L.length / 2 ; i < L.length; i++) {
		S2[i - L.length / 2] = L.r[i];
	}
	for (i = 0; i < L.length / 2; i++) {
		S1[i] = L.r[i];
	}
	cout << "S1Ϊ";
	for (i = 0; i < L.length / 2; i++) {
		cout << S1[i];
	}
	cout << endl << "S2Ϊ";
	for (i = 0; i < L.length/2; i++) {
		cout << S2[i];
	}
	cout << endl;
}



/*����������*/
int main()
{
	SqList L;
	initlist(&L);
	KeyboardInput(&L);
	divide(L);
	return 0;
}




