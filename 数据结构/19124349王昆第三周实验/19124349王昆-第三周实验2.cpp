/*************************************************************
��дʱ�䣺2020-12-17
����汾��V1.0
�����ߣ�����

�����ܣ�ʵ�����������
�������ݣ�����˵�ָ������
���������������
****************************************************************/

/*ͷ�ļ�*/
#include<iostream>
#include<cstdlib>
using namespace std;

/*�����˳��洢�ṹ*/
typedef struct LinkList
{
	char data;   /*����洢����Ԫ��*/
	struct LinkList* next;  /*ָ����һ���ڵ��ָ��*/
}LNode, LinkList;

/*��ʼ������*/
void initlist(LinkList* L)
{
	L = (LinkList*)malloc(sizeof(LNode));
	L->next = NULL;
}


// ����������
//LinkList* L �����ɵ����ݱ�
//int n �������ݵĸ���
//����ֵ���������ݺ����ɵ����ݱ�
void CreateList(LinkList* L, int n)
{
	LNode* p;

	for (int i = n; i > 0; --i) {
		p = (LinkList*)malloc(sizeof(LNode));
		cin >> (&p->data);    // ����Ԫ��ֵ
		p->next = L->next;
		L->next = p;//����
	}
} // CreateList_L

//��ӡ����
void print(LinkList* L)
{
	if (L == NULL)
	{
		return;
	}

	LNode* p = L->next;
	cout << "�����ӡ��";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;  //����
}


/*����������*/
int main()
{
	//��������
	int n;
	cout << "��������Ҫ�����Ԫ�صĸ�����";
	cin >> n;
	LinkList L;
	initlist(&L);//��ʼ��
	CreateList(&L, n);
	print(&L);
	return 0;
}




