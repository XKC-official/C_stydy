/*************************************************************
��дʱ�䣺2020-3-11
����汾��V1.0
�����ߣ�����

�����ܣ�������˳����ٽ��п��������ð������
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


//��������
//L��˳���ĵ�ַ
//����������˳���
void Quick_Sort(int R[], int left, int right)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = R[left];  //ȡ����ߵ���Ϊ��׼��
	while (i < j)
	{
		while (R[j] >= base && i < j)
			j--;
		while (R[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = R[i];
			R[i] = R[j];
			R[j] = temp;
		}
	}

	R[left] = R[i];
	R[i] = base;
	Quick_Sort(R,left, i - 1);//�ݹ����
	Quick_Sort(R,i + 1, right);//�ݹ��ұ�
}


//ð������
//L��˳���ĵ�ַ
//����������˳���
void BubbleSort(SqList& L){	
	int i, j, t, flag;
	for (i = 0; i <= L.length-2; i++){
		flag = 0;
		for (j = 0; j <= L.length-2 - i; j++)
			if (L.r[j] > L.r[j + 1]){
				t = L.r[j]; 
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = t;
				flag = 1;
			}
		if (flag == 0) return;
	}
}

//�˵�
void menu()
{
	cout << "����������:" << endl << "0:�ٴβ鿴�˵�\n1����������\n2��ð������\n3���˳�����" << endl;
}


/*����������*/
int main()
{
	int i = 0, left = 0, right;
	SqList L;
	initlist(&L);
	KeyboardInput(&L);
	right = L.length-1;
	int* R = L.r;
	while (i != 3) {
		switch (i)//��������ֵ��ִ�й���
		{
		case 0:menu(); break;
		case 1:Quick_Sort(R,left,right); display(L); break;
		case 2:BubbleSort(L); display(L); break;
		}
		cin >> i;
	}
	return 0;
}




