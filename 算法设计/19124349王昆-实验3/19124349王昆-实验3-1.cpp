/*************************************************************
��дʱ�䣺2020-4-22
����汾��V1.0
�����ߣ�����

�����ܣ�������˳����ٽ��л��ڷ��η����۰����
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
		L->r[i] = k;
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



//���ڷ��η����۰����
//a[]Ϊ��������,low highΪ�������䷶Χ��kΪ������ֵ
//���ز��ҽ��

int BinSearch(int a[],int low, int high,int k)
{
	int mid;
	if (low <= high)		
	{
		mid = (low + high) / 2;	
		if (a[mid] == k)		
			return mid;
		if (a[mid]>k)		
			return BinSearch(a,low,mid - 1,k);
		else			
			return BinSearch(a,mid + 1,high,k);
	}
	else return -1;		
}



/*����������*/
int main()
{
	SqList L;
	int low, high;
	int e;
	initlist(&L);
	KeyboardInput(&L);

	high = L.length;
	low = 1;
	while(1){
		cout << "��������ҵ�ֵ";
		cin >> e;
		if (BinSearch(L.r, low, high, e) != -1)
			cout << "λ��Ϊ" << BinSearch(L.r, low, high, e) << endl;
		else
			cout << "���������޴�ֵ" << endl;
	}
	return 0;
}




