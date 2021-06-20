/*************************************************************
��дʱ�䣺2021-1-5
����汾��V1.0
�����ߣ�����

�����ܣ�������ʽջ�ṹ����ϯ���ᶼ��������Ӳϯ����֮ǰ
�������ݣ�����˵�ָ������
������������ı���ջ
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
	if (Empty(top)) 
	{
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
	if (Empty(top))
	{
		cout << "stack is free!";
		return 0;
	}
	return (*top)->next->data;
}


/*����������*/
int main()
{
	LinkSTACK* s;
	char lst[80];
	int i = 0, j = 0;
	InitStack(&s);
	cout << "������Ӳϯ(H)����ϯ����(S)���У�";
	cin >> lst;
	cout << lst << endl;
	while (lst[i])
	{
		if (lst[i] == 'S') //��ϯ����
		{
			lst[j] = lst[i];
			j++;
		}
		else Push(&s, lst[i]);//Ӳϯ��ջ
		i++;
	}
	while (lst[j])//ʣ�µģ���ϯ����ջ
	{
		Pop(&s, &lst[j]);
		j++;
	}
	cout << lst << endl;
	return 0;
}




