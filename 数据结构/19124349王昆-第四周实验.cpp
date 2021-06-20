/*************************************************************
��дʱ�䣺2020-12-16
����汾��V1.0
�����ߣ�����

�����ܣ�ʵ��˳��ջ�Ļ�����������ջ����ջ��ջ��ʼ������ջ��Ԫ��
�������ݣ�����˵�ָ������
�����������ָ��������ջ
****************************************************************/
#include<iostream>
using namespace std;
#define MaxLen  100  
typedef int ElemType;

/*ջ��˳��洢�ṹ*/
typedef struct
{
	ElemType data[MaxLen];/*����洢����Ԫ��*/
	int top;/*���Ա�ĵ�ǰ����*/
}STACK;


/*��ʼ��*/
void initStack(STACK* S)
{
	S->top = -1;
}


int Empty(STACK* S)
{
	return (S->top == -1 ? 1 : 0);
}



//��ջ��������������
//STACK* S ��ѹ�����ݵ�ջ
//����ֵ���������ݺ����ɵ�ջ
int Push(STACK* S)
{
	int i, k, n;
	if (S->top == MaxLen - 1)
	{
		cout << " ջ����!";
		return 0;
	}
	cout << "������n, ������n��Ԫ�أ���ջ��";
	cin >> n;
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		cin >> k;
		S->top++;
		S->data[S->top] = k;
	}
	return 1;
}

//��ջ
//STACK *S �������ջ, ElemType *x ��ȡ�������ݵ�ָ��
//����ֵ��ȡ�����ݵ�ջ������
int Pop(STACK *S, ElemType *x)
{
	if (Empty(S)) {
		cout << "ջΪ��!";
		return 0;
	}
	*x = S->data[S->top];
	S->top--;
	return 1;
}

//��ջ��Ԫ��
//STACK *S �������ջ, ElemType *x ��ȡ�������ݵ�ָ��
//����ֵ��ȡ��������
int GetTop(STACK* S, ElemType* x)
{
	if (Empty(S)) 
	{
		cout << "ջΪ��!";
		return 0;
	}
	*x = S->data[S->top];
	return 1;
}


//��ӡ
void display(STACK S)
{
	int i;
	if (Empty(&S))
		cout << "ջΪ��!\n";
	else
	{
		cout << "ջ������Ϊ��";
		for (i = 0; i <= S.top; i++)
			cout << S.data[i] << " ";
		putchar('\n');
	}
}


//�˵�
void menu()
{
	cout << "***************************************\n";
	cout << "*       1��Ԫ�ؽ�ջ                   *\n";
	cout << "*       2��Ԫ�س�ջ                   *\n";
	cout << "*       3����ջ��Ԫ��                 *\n";
	cout << "*       4����ӡջ��Ԫ��               *\n";
	cout << "*       5���˳�����                   *\n";
	cout << "***************************************\n";
}

/*����������*/
int main()
{
	//��������
	int i = 0,t,x;
	STACK S;
	initStack(&S);//��ʼ��
	while (i != 5)
	{
		
		switch (i)//��������ֵ��ִ�й���
		{
		case 0:menu(); break;//�˵�
		case 1:Push(&S); break;//��ջ
		case 2:
			Pop(&S,&x); //��ջ
			cout << x << endl;
			break;
		case 3:
			GetTop(&S,&x);//��ջ��Ԫ��
			cout << x << endl;
			break;
		case 4:display(S); break;//��ʾ
		default:cout << "�����ڸù���ѡ�\n"; break;
		}
		if (i != 0)
		{
			cout << "����������Y<1>/N<0>: ";
			cin >> t;
			if (t == 0) break;
		}
		cout << "��ѡ��1-5: ";
		cin >> i;
		cout << endl;
	}
	cout << "��л����ʹ�ã�\n";
	return 1;
}




