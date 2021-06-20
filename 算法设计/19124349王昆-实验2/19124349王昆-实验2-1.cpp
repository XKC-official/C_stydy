/*************************************************************
��дʱ�䣺2020-4-12
����汾��V1.0
�����ߣ�����

�����ܣ�������˳����ٽ��м�ѡ������
�������ݣ�����˵�ָ������
��������������˳���
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


/*��ӡ˳���*/
void display(SqList L)
{
	int i;
	if (L.length == 0)
		cout << "˳���Ϊ�գ�\n";
	else
	{
		cout << "˳���������Ϊ��";
		for (i = 0; i < L.length; i++)
			cout << L.r[i] << " ";
		cout << endl;
	}
}



//��ѡ������
//L��˳���ĵ�ַ
//����������˳���
void SelectionSort(SqList &L)
{
	int i, j, k, t;
	for (i = 0; i < L.length-2; i++){
		k = i;
		for (j = i + 1; j <= L.length-1; j++) 
			if (L.r[j] < L.r[k])
				k = j;
		if (k != i) {
			t = L.r[i];
			L.r[i] = L.r[k];
			L.r[k] = t;
		}
	}
}


/*����������*/
int main()
{
	SqList L;
	initlist(&L);
	KeyboardInput(&L);
	SelectionSort(L); 
	display(L); 
	return 0;
}




