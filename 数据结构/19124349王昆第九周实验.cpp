/*************************************************************
��дʱ�䣺2020-3-4
����汾��V1.0
�����ߣ�����

�����ܣ�������˳����ٽ���ֱ�Ӳ���������ѡ������
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


//ֱ�Ӳ�������
//L��˳���ĵ�ַ
//����������˳���
void InsertSort(SqList& L)
{
	int i, j;
	for (i = 2; i <= L.length-2; ++i) {
		if (L.r[i] < L.r[i - 1])//��L.r[i]���������ӱ�
		{
			L.r[0] = L.r[i]; // ����Ϊ�ڱ�
			L.r[i] = L.r[i - 1];
			for (j = i - 2; L.r[0] < L.r[j]; --j)
				L.r[j + 1] = L.r[j]; // ��¼���� 
			L.r[j + 1] = L.r[0]; //���뵽��ȷλ��
		}
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

void menu()
{
	cout << "����������:" << endl << "0:�ٴβ鿴�˵�\n1��ֱ�Ӳ�������\n2����ѡ������\n3���˳�����" << endl;
}

/*����������*/
int main()
{
	int i = 0;
	SqList L;
	initlist(&L);//��ʼ��
	KeyboardInput(&L);
	while (i != 3) {
		switch (i)//��������ֵ��ִ�й���
		{
		case 0:menu(); break;//�˵�
		case 1:InsertSort(L); display(L); break;
		case 2:SelectionSort(L); display(L); break;
		}
		cin >> i;
	}
	return 0;
}




