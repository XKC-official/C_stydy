/*************************************************************
��дʱ�䣺2020-4-22
����汾��V1.0
�����ߣ�����

�����ܣ�����һ�ö�������ͳ�Ƹö�����Ҷ��������ͽ������
�������ݣ�����˵�ָ������
��������Ҷ��������ͽ������
****************************************************************/

/*ͷ�ļ�*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
int n = 0, m = 0;

/*�������洢�ṹ*/
typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
} BTree, * tree;


//�����������
//T��ָ���ָ���ָ��
//����������ݵĶ�����
int CreateBinTree(BTree* root, int f1 = 0, int f2 = 0)         //ǰ�����
{
	root = (tree)malloc(sizeof(BTree));
	int a;
	cin >> a;
	if (a == -1) { root->data = NULL; return 1; }
	root->data = a; //�뵱ǰ���ֵ
	f1 = CreateBinTree(root->lchild);    //�ݹ�ǰ��������ӽ��
	f2 = CreateBinTree(root->rchild);    //�ݹ�ǰ��������ӽ��
	if (f1 == 1 && f2 == 1) n++; 
	else
		m++;
	return 0;                      //����
}

/*����������*/
int main()
{
	BTree T;
	cout << "�������ַ����У�";
	CreateBinTree(&T);
	cout << "Ҷ�ڵ���Ϊ" << n << ",�ڵ���Ϊ" << m+n << endl;
	return 0;
}




