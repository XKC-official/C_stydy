/*************************************************************
��дʱ�䣺2020-4-1
����汾��V1.0
�����ߣ�����

�����ܣ�������˳���ȷ���������Ƿ����������ȵ�Ԫ��
�������ݣ�����˵�ָ������
���������жϽ��
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


//�жϺ���
//L��˳���ĵ�ַ
//�жϽ��
int Sort(SqList& L) {
	int i, j;
	for (i = 0; i < L.length - 1; i++) {
		for (j = i + 1; j <= L.length - 1; j++) {
			if (L.r[i] == L.r[j])
				return 1;
		}
	}
	return 0;
}



/*����������*/
int main()
{
	SqList L;
	initlist(&L);
	KeyboardInput(&L);
	if (Sort(L)) cout << "��������ͬ���";
	else cout << "û��������ͬ���";
	return 0;
}




