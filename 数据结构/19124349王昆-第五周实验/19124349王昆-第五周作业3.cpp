/*************************************************************
��дʱ�䣺2020-12-31
����汾��V1.0
�����ߣ�����

�����ܣ����������������ʽ���з�ʽ�洢�������洢��Ķ�����������Ļ��ӡ���
�������ݣ�����˵�ָ������
���������������
****************************************************************/

/*ͷ�ļ�*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;

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
int Empty(SQUEUE* LQ)
{
	return(LQ->front == LQ->rear ? 1 : 0);
}



//��ӡ����
void Display(SQUEUE* LQ)
{
	if (Empty(LQ)) {
		cout << "Queue is free";
	}

	else 
	{
		QTYPE *temp = NULL;
		while (temp != LQ->rear) {
			temp = LQ->front->next;
			cout << temp->data;
			LQ->front = temp;
		}
	}
}



/*����������*/
int main()
{
	int n;
	ElemType k;
	SQUEUE LQ;
	InitQueue(&LQ);
	cout << "��������Ҫ�����Ԫ�صĸ�����";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "�������" << i << "��Ԫ�أ�";
		cin >> k;
		EnQueue(&LQ, k);//���
	}
	Display(&LQ);//��ӡ
	return 0;
}




