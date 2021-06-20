/*************************************************************
��дʱ�䣺2020-1-6
����汾��V1.0
�����ߣ�����

�����ܣ��б�����һ���ԡ�@��Ϊ���������ַ������Ƿ��ǡ����ġ�
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
int STACKEmpty(LinkSTACK** top)
{
	return ((*top)->next == NULL ? 1 : 0);
}


//��ջ
//LinkSTACK** top ��ȡ�����ݵ�ջ��ElemType *x ȡ�����ݵ�ָ��
//����ֵ��ȡ��Ԫ�ص����ݣ���ջ
int Pop(LinkSTACK** top, ElemType* x)
{
	LinkSTACK* s;
	if (STACKEmpty(top))
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
	if (STACKEmpty(top))
	{
		cout << "stack is free!";
		return 0;
	}
	return (*top)->next->data;
}



//**************************************************************����



/*��ʽ���д洢�ṹ*/
typedef struct QNode      //���ӽ������� 
{
	ElemType data;   /*����洢����Ԫ��*/
	struct QNode* next;  /*ָ����һ���ڵ��ָ��*/
}QTYPE;

typedef struct QPinter      //����ָ������ 
{
	QTYPE* front, * rear;
}SQUEUE;



/*��ʼ��*/
void InitQueue(SQUEUE* LQ)
{
	QTYPE* p;
	p = (QTYPE*)malloc(sizeof(QTYPE));
	p->next = NULL;
	LQ->front = LQ->rear = p;
}


// ��ӣ�������������
//SQUEUE* LQ ���������ݵĶ��У�ElemType x �����������
//����ֵ���������ݺ����ɵĶ���
int EnQueue(SQUEUE* LQ, ElemType x)
{
	QTYPE* s;
	s = (QTYPE*)malloc(sizeof(QTYPE));
	s->data = x;
	s->next = LQ->rear->next;
	LQ->rear->next = s;
	LQ->rear = s;
	return 1;
}


//�ж�Ϊ��
int SQUEUEEmpty(SQUEUE* LQ)
{
	return(LQ->front == LQ->rear ? 1 : 0);
}

int OutQueue(SQUEUE* LQ, ElemType* x)
{
	QTYPE* p;
	if (SQUEUEEmpty(LQ)) 
	{
		cout << "Queue is free";
		return 0;
	}
	p = LQ->front->next;
	*x = p->data;
	LQ->front->next = p->next;
	if (LQ->front->next == NULL)
		LQ->rear = LQ->front;
	free(p);
	return 1;
}

// �жϻ���
//char* p�����жϵ��ַ���ַ
//����ֵ���жϽ��
int check(char* p)
{
	SQUEUE q;
	InitQueue(&q);
	LinkSTACK* s;
	InitStack(&s);
	ElemType e1, e2;
	while (*p == '@')//��@ֹͣ����
	{
		Push(&s, *p);
		EnQueue(&q, *p);
		p++;
	}
	while (!STACKEmpty(&s))
	{
		Pop(&s, &e1);
		OutQueue(&q, &e2);
		if (e1 != e2) return 0;//����ջ�Ͷ��е����Խ������ݱȽ�
	}
	return 1;
}

/*����������*/
int main()
{
	char p;
	cout << "�������ַ����У�";
	cin >> p;
	if ((check(&p))==1) cout << "�ǻ���";
	else cout << "���ǻ���";
	return 0;
}




