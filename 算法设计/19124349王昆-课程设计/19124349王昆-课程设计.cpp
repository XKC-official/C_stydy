/*************************************************************
��дʱ�䣺2021-5-30
����汾��V1.0
�����ߣ�19124349 ����

�����ܣ���������ʵ�ִӳ�ʼ���ֵ�Ŀ�겼�ֵ�ת��
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/

#include <iostream>
#include "stdio.h"
#include <cstdlib>
#include <cmath>
#include<process.h>
using namespace std;

//�ṹ�嶨��
typedef struct Node
{
	struct Node* parent;
	double f, g;
	int num[9];
	Node* next;
}QNode, * Lnode;

//OPEN CLOSED ��ṹ��
typedef struct Stack
{
	Node* npoint;
	struct Stack* next;
}Stack, * Lstack;



//�ж������������������ż�ԣ��Ӷ��ж������Ƿ�ɽ�
int cansolve(int num1[], int num2[])
{

	int i, j;
	int sum1 = 0, sum2 = 0;

	for (i = 0; i < 9; i++)
		for (j = 0; j < i; j++)
		{
			if (num1[j] > num1[i] && num1[i] != 0) ++sum1;
			if (num2[j] > num2[i] && num2[i] != 0) ++sum2;
		}

	if (sum1 % 2 == sum2 % 2) return 1;
	else return 0;
}



//�������뺯��
void input(int num[])
{
	int i = 0, j = 0, flag = 0;
	char c;
	while (i < 9)
	{
		while (((c = getchar()) != 10))
		{
			if (c == ' ')
			{
				if (flag >= 0)flag = 0;
			}
			else if (c >= '0' && c <= '8')
			{
				if (flag == 0)
				{
					num[i] = (c - '0');
					flag = 1;
					for (j = 0; j < i; j++)
						if (num[j] == num[i])flag = -2;
					i++;
				}
			}
			else if (flag >= 0)flag = -1;
		}
		if (flag < 0 || i < 9)
		{
			if (flag < 0)
			{
				if (flag == -1) cout<<"���зǷ��ַ�������!\n����������:\n";
				else if (flag == -2) cout<<"������������ظ�!\n����������:\n";
			}
			else if (i < 9) cout<<"�������Ч���ֲ���!\n����������:\n";
			i = 0;
			flag = 0;
		}
	}
}

//����
int move_up(int num[])
{
	int i;

	for (i = 0; i< 9; i++)
		if (num[i] == 0) break;

	if (i == 0 || i == 1 || i == 2)
		return 0;
	else
	{
		num[i] = num[i - 3];
		num[i - 3] = 0;
		return 1;
	}
}

//����
int move_down(int num[])
{
	int i;

	for (i = 0; i < 9; i++)
		if (num[i] == 0) break;

	if (i == 6 || i == 7 || i == 8)
		return 0;
	else
	{
		num[i] = num[i + 3];
		num[i + 3] = 0;
		return 1;
	}
}

//����
int move_left(int num[])
{
	int i;

	for (i = 0; i < 9; i++)
		if (num[i] == 0) break;

	if (i == 0 || i == 3 || i == 6)
		return 0;
	else
	{
		num[i] = num[i - 1];
		num[i - 1] = 0;
		return 1;
	}
}

//����
int move_right(int num[])
{
	int i;

	for (i = 0; i < 9; i++)
		if (num[i] == 0) break;

	if (i == 2 || i == 5 || i == 8)
		return 0;
	else
	{
		num[i] = num[i + 1];
		num[i + 1] = 0;
		return 1;
	}
}

//���ڵ��е������ȡ����
//��ȡ��temp
void get_num(QNode* node, int temp[])
{
	int i;
	for (i = 0; i < 9; i++)
	{
		temp[i] = node->num[i];
	}
}

//���ýڵ������������
//temp���ݽ���QNode
void set_num(QNode* node, int temp[])
{
	int i;
	for (i = 0; i < 9; i++)
		node->num[i] = temp[i];
}

//��ӡ
void print(QNode* node)
{
	int i;
	for (i = 0; i < 9; i++)
	{
		cout << node->num[i]<<" ";
		if ((i + 1) % 3 == 0)
			cout << endl;
	}
}

//�ж�Ŀ��ڵ�������Ŀ�����������Ƿ����
int isequal(QNode* node, int target[])
{
	int i;
	int flag = 1;
	for (i = 0; i < 9 && flag; i++)
	{
		if (node->num[i] != target[i])
			flag = 0;
	}

	return flag;
}

//�˳�
int exist(QNode* node, int temp[])
{
	QNode* p;

	for (p = node; p != NULL; p = p->parent)
		if (isequal(node, temp))
			return 1;

	return 0;
}


//ѡȡOPEN����fֵ��С�Ľڵ㣬���ظýڵ��ַ
Node* Minf(Lstack* Open)
{
	Lstack temp = (*Open)->next, min = (*Open)->next, minp = (*Open);
	Node* minx;

	while (temp->next != NULL)
	{
		if ((temp->next->npoint->f) < (min->npoint->f))
		{
			min = temp->next;
			minp = temp;
		}
		temp = temp->next;
	}
	minx = min->npoint;
	temp = minp->next;
	minp->next = minp->next->next;
	free(temp);
	return minx;
}


//�жϽڵ��Ƿ����
//���������ڵ�
//�������<1>�������<0>
int Equal(Node* suc, Node* goal)
{
	for (int i = 0; i < 9; i++)
		if (suc->num[i] != goal->num[i])return 0;
	return 1;
}

//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ
//����ڵ��ַ<Node* suc>�����ַ<Lstack* list>
Node* Belong(Node* suc, Lstack* list)
{
	Lstack temp = (*list)->next;
	if (temp == NULL)return NULL;
	while (temp != NULL)
	{
		if (Equal(suc, temp->npoint))return temp->npoint;
		temp = temp->next;
	}
	return NULL;
}

//�ѽڵ����OPEN ��CLOSED ����
//����ڵ��ַ<Node* suc>�����ַ<Lstack* list>
void Putinto(Node* suc, Lstack* list)
{
	Stack* temp;
	temp = (Stack*)malloc(sizeof(Stack));
	temp->npoint = suc;
	temp->next = (*list)->next;
	(*list)->next = temp;
}

//���㷽��Ĵ�λ����
//�����ʼ�ڵ�<Node suc>��Ŀ��ڵ� <Node goal>,i�ڵ���
double Distance(Node suc, Node goal, int i)
{
	int k, h1, h2;
	for (k = 0; k < 9; k++)
	{
		if (suc.num[k] == i)h1 = k;
		if (goal.num[k] == i)h2 = k;
	}
	return double(fabs(h1 / 3 - h2 / 3) + fabs(h1 % 3 - h2 % 3));
}

//����fֵ
//�����ʼ�ڵ�<Node suc>��Ŀ��ڵ� <Node goal>,speed�����ٶ�
double Fvalue(Node suc, Node goal, float speed)
{
	double Distance(Node, Node, int);
	double h = 0;
	for (int i = 1; i <= 8; i++)
		h = h + Distance(suc, goal, i);
	return h * speed + suc.g; //(speedֵ����ʱ�����������ҵ�Ŀ��Ϊ������˿��ܲ��᷵�����Ž�)                                       
}



//*******************��չ��̽ڵ㲿�ֵĺ���-����****************//

//�ж��ӽڵ��Ƿ�����OPEN��CLOSED��������Ӧ�Ĵ���
//����ڵ��ַ<Lnode* suc>�����ַ<Lstack* Open> <Lstack* Closed> Ŀ��ڵ� <Node goal>,speed�����ٶ�
int BelongProgram(Lnode* suc, Lstack* Open, Lstack* Closed, Node goal, float speed)
{
	Node* temp = NULL;
	int flag = 0;
	if ((Belong(*suc, Open) != NULL) || (Belong(*suc, Closed) != NULL))
	{
		if (Belong(*suc, Open) != NULL) temp = Belong(*suc, Open);
		else temp = Belong(*suc, Closed);
		if (((*suc)->g) < (temp->g))
		{
			temp->parent = (*suc)->parent;
			temp->g = (*suc)->g;
			temp->f = (*suc)->f;
			flag = 1;
		}
	}
	else
	{
		Putinto(*suc, Open);
		(*suc)->f = Fvalue(**suc, goal, speed);
	}
	return flag;
}


//�жϿո�ɷ���÷����ƶ�����ʾ�ո�������������������
//����ڵ�<node suc>, i�ڵ���
int Canspread(Node suc, int n)
{
	int i, flag = 0;
	for (i = 0; i < 9; i++)
		if (suc.num[i] == 0)break;
	switch (n)
	{
	case 1:
		if (i / 3 != 0)flag = 1; break;
	case 2:
		if (i / 3 != 2)flag = 1; break;
	case 3:
		if (i % 3 != 0)flag = 1; break;
	case 4:
		if (i % 3 != 2)flag = 1; break;
	default:break;
	}
	return flag;
}


//��չchild�ڵ���ӽڵ�
//n��ʾ���� , ��ʾ�ո�������������������
void Spreadchild(Node* child, int n)
{
	int i, loc, temp;
	for (i = 0; i < 9; i++)
		child->num[i] = child->parent->num[i];
	for (i = 0; i < 9; i++)
		if (child->num[i] == 0)break;
	if (n == 0)
		loc = i % 3 + (i / 3 - 1) * 3;
	else if (n == 1)
		loc = i % 3 + (i / 3 + 1) * 3;
	else if (n == 2)
		loc = i % 3 - 1 + (i / 3) * 3;
	else
		loc = i % 3 + 1 + (i / 3) * 3;
	temp = child->num[loc];
	child->num[i] = temp;
	child->num[loc] = 0;
}


//��չ��̽ڵ��ܺ���
//����ڵ��ַ<Lnode* suc>�����ַ<Lstack* Open> <Lstack* Closed> Ŀ��ڵ� <Node goal>,speed�����ٶ�
int Spread(Lnode* suc, Lstack* Open, Lstack* Closed, Node goal, float speed)
{
	int i;
	Node* child;

	for (i = 0; i < 4; i++)
	{
		if (Canspread(**suc, i + 1))                               //�ж�ĳ�������ϵ��ӽڵ�ɷ���չ
		{
			child = (Node*)malloc(sizeof(Node));          //��չ�ӽڵ�
			child->g = (*suc)->g + 1;                        //���ӽڵ��gֵ
			child->parent = (*suc);                         //�ӽڵ㸸ָ��ָ�򸸽ڵ�
			Spreadchild(child, i);                          //��÷����ƶ��ո������ӽڵ�
			if (BelongProgram(&child, Open, Closed, goal, speed)) //	�ж��ӽڵ��Ƿ�����OPEN��CLOSED��������Ӧ�Ĵ���
				free(child);
		}
	}
	return 1;
}
//**********************��չ��̽ڵ㲿�ֵĺ���-����*****************************//


//��ִ�к���
//����ڵ��ַ<Lnode* org>�����ַ<Lstack* Open> <Lstack* Closed> Ŀ��ڵ� <Lnode* goal>,speed�����ٶ�
Node* Process(Lnode* org, Lnode* goal, Lstack* Open, Lstack* Closed, float speed)
{
	while (1)
	{
		if ((*Open)->next == NULL)return NULL;                    //�ж�OPEN���Ƿ�Ϊ�գ�Ϊ����ʧ���˳�
		Node* minf = Minf(Open);                                //��OPEN����ȡ��fֵ��С�Ľڵ�
		Putinto(minf, Closed);                                   //���ڵ����CLOSED����
		if (Equal(minf, *goal))return minf;                       //�����ǰ�ڵ���Ŀ��ڵ㣬��ɹ��˳�
		Spread(&minf, Open, Closed, **goal, speed);
		//��ǰ�ڵ㲻��Ŀ��ڵ�ʱ��չ��ǰ�ڵ�ĺ�̽ڵ�
	}
}

//����ʽ����
//��ʼ������<init[9]>,Ŀ�������<target[9]>
void qf(int init[9], int target[9])
{
	Lstack Open = (Stack*)malloc(sizeof(Stack));
	Open->next = NULL;
	Lstack Closed = (Stack*)malloc(sizeof(Stack));
	Closed->next = NULL;
	Node* org = (Node*)malloc(sizeof(Node));
	Node* p;
	org->parent = NULL;                                        //��ʼ״̬�ڵ�

	org->f = 1;
	org->g = 1;
	int count = 0;
	Node* goal = (Node*)malloc(sizeof(Node));               //Ŀ��״̬�ڵ�

	Node* result;
	set_num(org, init);
	set_num(goal, target);
	float speed = 1000;//speed�����ٶ�

	Putinto(org, &Open);
	result = Process(&org, &goal, &Open, &Closed, speed);  //����ʣ��Ĳ���print(result)
	for (p = result; p != NULL; p = p->parent)
	{
		print(p);
		cout<<"------\n";
		count++;
	}
	cout << "�ó����Ž⹲��" << count << "���ڵ�\n";
	cout<<endl;
	cout<<"Press Enter key to exit!";

}



//�����������
//��ʼ������<init[]>,Ŀ�������<target[]>
int bfs(int init[], int target[])
{

	int  temp[9];
	int find = 0;
	int step = 1, count = 1;

	QNode* front, * rear, * new_node, * p;

	if (!cansolve(init, target))
	{
		cout<<"����ʵ��\n";
		return 0;
	}

	front = (QNode*)malloc(sizeof(QNode));
	set_num(front, init);
	front->parent = NULL;
	front->next = NULL;
	rear = front;


	while (front != NULL && !find)
	{
		if (isequal(front, target))
		{
			find = 1;
			break;
		}

		get_num(front, temp);
		if (move_up(temp) && !exist(front, temp))
		{
			new_node = (QNode*)malloc(sizeof(QNode));
			set_num(new_node, temp);
			new_node->parent = front;
			new_node->next = NULL;
			rear->next = new_node;
			rear = new_node;
			step++;

		}
		get_num(front, temp);
		if (move_left(temp) && !exist(front, temp))
		{
			new_node = (QNode*)malloc(sizeof(QNode));
			set_num(new_node, temp);
			new_node->parent = front;
			new_node->next = NULL;
			rear->next = new_node;
			rear = new_node;
			step++;

		}
		get_num(front, temp);
		if (move_down(temp) && !exist(front, temp))
		{
			new_node = (QNode*)malloc(sizeof(QNode));
			set_num(new_node, temp);
			new_node->parent = front;
			new_node->next = NULL;
			rear->next = new_node;
			rear = new_node;
			step++;
		}
		get_num(front, temp);
		if (move_right(temp) && !exist(front, temp))
		{
			new_node = (QNode*)malloc(sizeof(QNode));
			set_num(new_node, temp);
			new_node->parent = front;
			new_node->next = NULL;
			rear->next = new_node;
			rear = new_node;
			step++;

		}   front = front->next;
		count++;

	}

	if (find)
	{
		count = 0;
		for (p = front; p != NULL; p = p->parent)
		{
			print(p);
			cout<<"------\n";
			count++;
		}
		cout<<"�ó����Ž⹲��"<<count<<"���ڵ�\n";
	}
}


int main()
{
	int init[9], target[9];
	cout << "�����ʼ״̬:" << endl;
	input(init);
	cout << "����Ŀ��״̬:" << endl;
	input(target);

	if (cansolve(init, target))
	{
		cout << "ʹ�ù�����Ƚ�������:" << endl;
		bfs(init, target);

		cout << endl;

		cout << "ʹ������ʽ��������:" << endl;
		qf(init, target);
	}
	else {
		cout << "�޽�" << endl;
	}

	return 0;
}
