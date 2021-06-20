/*************************************************************
��дʱ�䣺2020-1-14
����汾��V1.0
�����ߣ�����

�����ܣ�����������У�����һ�ö�������ͳ�Ƹö�����Ҷ��������ͽ������
�������ݣ�����˵�ָ������
��������Ҷ��������ͽ������
****************************************************************/

/*ͷ�ļ�*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;

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
void CreateBinTree(tree* T)
{ 
	char ch;
	if ((ch = getchar()) == ' ')
	{
		*T = NULL;
	}
	else       
	{
        *T = (BTree*)malloc(sizeof(BTree));  
		(*T)->data = ch;
		CreateBinTree(&(*T)->lchild);
		CreateBinTree(&(*T)->rchild);
	}
}

//���Ҷ�ӽڵ�����
//T��ָ���ָ���ָ��
//���ض�����Ҷ�ӽڵ�����
int Leaf(tree T)//Ҷ�ӽڵ�����
{
	int static leaves = 0;
	if (T)
	{	//�������
		Leaf(T->lchild);	//����������
		if (!(T->lchild || T->rchild))//���Һ��Ӿ�Ϊ��
			leaves++;	//Ҷ������1
		Leaf(T->rchild);	//����������
	}
	return leaves;
}

//����ڵ�����
//T��ָ���ָ���ָ��
//���ض������ڵ�����
int Node(tree T)//�ڵ�����
{
	int static nodes = 0;
	if (T)
	{	//�������
		Node(T->lchild);	//����������
		nodes++;		//�������1
		Node(T->rchild);	//����������
	}
	return nodes;

}



/*����������*/
int main()
{
	tree T;
	int m, n;
	cout << "�������ַ����У�";
	CreateBinTree(&T);
	m = Leaf(T);
	n = Node(T);
	cout << "Ҷ�ڵ���Ϊ" << m << ",�ڵ���Ϊ" << n << endl;
	return 0;
}




