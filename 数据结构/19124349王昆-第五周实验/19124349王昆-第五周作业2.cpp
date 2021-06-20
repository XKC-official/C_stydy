/*************************************************************
��дʱ�䣺2020-12-31
����汾��V1.0
�����ߣ�����

�����ܣ�������ʽջ�ṹ��ʵ���ж����ַ����Ƿ�Ϊ����
�������ݣ�����˵�ָ������
������������жϽ��
****************************************************************/

/*ͷ�ļ�*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;

/*��ʽջ�洢�ṹ*/
typedef struct SNode
{
	ElemType data;   /*����洢����Ԫ��*/
	struct SNode* next;  /*ָ����һ���ڵ��ָ��*/
}LinkSTACK;

/*��ʼ��*/
void InitStack(LinkSTACK** top)
{
	*top = (LinkSTACK*)malloc(sizeof(LinkSTACK));
	(*top)->next = NULL;
}

// ��ջ��������������
//LinkSTACK** top ���������ݵ�ջ��ElemType x �����������
//����ֵ���������ݺ����ɵ�ջ
int Push(LinkSTACK** top, ElemType x)
{
	LinkSTACK* s;
	s = (LinkSTACK*)malloc(sizeof(LinkSTACK));
	s->data = x;
	s->next = (*top)->next;
	(*top)->next = s;
	return 1;
}

//�ж�Ϊ��
int Empty(LinkSTACK** top)
{
	return ((*top)->next == NULL ? 1 : 0);
}


//��ջ
//LinkSTACK** top ��ȡ�����ݵ�ջ��ElemType *x ȡ�����ݵ�ָ��
//����ֵ��ȡ��Ԫ�ص����ݣ���ջ
int Pop(LinkSTACK** top, ElemType* x)
{
	LinkSTACK* s;
	if (Empty(top)) {
		cout << "stack is free!";
		return 0;
	}
	s = (*top)->next;
	*x = s->data;
	(*top)->next = s->next;
	free(s);
	return 1;
}


//ȡջ��Ԫ��
//LinkSTACK** top ��ȡ�����ݵ�ջ
//����ֵ��ȡ��Ԫ�ص�����
int GetTop(LinkSTACK** top)
{
	if (Empty(top)) {
		cout << "stack is free!";
		return 0;
	}
	return (*top)->next->data;
}


/*����������*/
int main()
{
	//��������
	int i, flag = 1;
	ElemType k;
	LinkSTACK *top;
	ElemType str[100];
	InitStack(&top);//��ʼ��
	cout << "�����ж��Ƿ�Ϊ���ĵ��ַ�����";
	cin >> str;
	int len = strlen(str);
	int mid = len / 2; //���ַ������е�
	for (i = 0; i < mid; i++)
	{
		Push(&top,str[i]);//��ջ
	}

	if (len % 2 == 1)//�ж���ż
	{
		i += 1;
	}

	while (!Empty(&top))//�жϻ���
	{
		int temp = GetTop(&top);
		if (temp != str[i])//���м俪ʼ����Ƚ�
		{
			flag = 0;
			break;
		}
		else
		{
			i += 1;
			Pop(&top,&k);
		}
	}
	if (!flag)
	{
		cout << "�ַ������ǻ���";
	}
	else
		cout << "�ַ���Ϊ����";
	return 0;
}




