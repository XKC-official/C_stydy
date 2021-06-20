/*************************************************************
��дʱ�䣺2020-12-31
����汾��V1.0
�����ߣ�����

�����ܣ�ʵ��˳��ʽ���еĻ�������
�������ݣ�����˵�ָ������
���������洢��Ķ��е�ǰ�������ݳ�������Ļ��ʾ
****************************************************************/
#include<iostream>
using namespace std;
#define MaxLen  100  
typedef int ElemType;

/*���е�˳��洢�ṹ*/
typedef struct
{
	ElemType data[MaxLen];/*����洢����Ԫ��*/
	int front, rear;/*����ͷ��β*/
}SQUEUE;


/*��ʼ��*/
void initSqueue(SQUEUE* SQ)
{
	SQ->rear = SQ->front = 0;
}

//�ж�Ϊ��
int Empty(SQUEUE* SQ)
{
	return(SQ->rear == SQ->front) ? 1 : 0;
}


//��ӣ�������������
//SQUEUE* SQ ���������ݵĶ��У�ElemType x �����������
//����ֵ���������ݺ����ɵ�ջ
int EnQueue(SQUEUE* SQ, ElemType x)
{
	if ((SQ->rear + 1) % MaxLen == SQ->front)
	{
		cout << "Queue is full!";
		return 0;
	}
	SQ->rear = (SQ->rear + 1) % MaxLen;
	SQ->data[SQ->rear] = x;
	return 1;
}


//����
//SQUEUE* SQ ��ȡ�����ݵĶ��У�ElemType *x ȡ�����ݵ�ָ��
//����ֵ��ȡ��Ԫ�ص�����
int OutQueue(SQUEUE* SQ, ElemType* x)
{
	if (Empty(SQ)) {
		cout << "Queue is free";
		return 0;
	}
	SQ->front = (SQ->front + 1) % MaxLen;
	*x = SQ->data[SQ->front];
	return 1;
}



/*����������*/
int main()
{
	//��������
	int n, k;
	SQUEUE SQ;
	initSqueue(&SQ);//��ʼ��
	cout << "��������Ҫ�����Ԫ�صĸ�����";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "�������" << i << "��Ԫ�أ�";
		cin >> k;
		EnQueue(&SQ, k);//���
	}
	for (int i = 1; i <= 3; i++)
	{
		OutQueue(&SQ, &k);//����
		cout << k;
	}
	cout << endl;
	return 1;
}




