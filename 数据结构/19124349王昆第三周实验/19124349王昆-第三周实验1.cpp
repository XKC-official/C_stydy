/*************************************************************
��дʱ�䣺2020-12-17
����汾��V1.0
�����ߣ�����

�����ܣ�ʵ�����Ա����ݵ����ɣ�����
�������ݣ�����˵�ָ������
�������������������˳���
****************************************************************/
#include<iostream>
using namespace std;
#define MaxLen  100  
typedef int ElemType;
          
/*���Ա��˳��洢�ṹ*/
typedef struct
{
	ElemType data[MaxLen];/*����洢����Ԫ��*/
	int length;/*���Ա�ĵ�ǰ����*/
}SqList;


/*��ʼ��˳���*/
void initlist(SqList* L)
{
	L->length = 0;
}


//����˳���������������
//SqList* S �����ɵ����ݱ�
//����ֵ���������ݺ����ɵ����ݱ�
void KeyboardInput(SqList* S)
{
	int i, k, n;
	cout<<"��������Ҫ�����Ԫ�صĸ�����";
	cin >> n;
	S->length = n;
	for (i = 1; i <= n; i++)
	{
		cout << "�������"<<i<<"��Ԫ�أ�";
		cin >> k;
		S->data[i - 1] = k;
	}
}


//����˳���
//SqList* S ����������ݱ�
//����ֵ�����������ݱ�
void reverse(SqList* S)
{
	for (int i = 0, j = S->length - 1; i < S->length / 2; i++, j--)
	{
		int temp = S->data[i];
		S->data[i] = S->data[j];
		S->data[j] = temp;
	}
}

/*��ӡ˳���*/
void display(SqList S)
{
	int i;
	if (S.length == 0)
		cout<<"˳���Ϊ�գ�\n";
	else
	{
		cout << "˳���������Ϊ��";
		for (i = 0; i < S.length; i++)
			cout<< S.data[i]<<" ";
		putchar('\n');
	}
}


/*����������*/
int main()
{
	//��������
	int i = 0;
	SqList S;
	initlist(&S);//��ʼ��
	KeyboardInput(&S);
	reverse(&S);
	display(S);//��ʾ
	return 0;
}




