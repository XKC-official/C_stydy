/*************************************************************
编写时间：2020-4-22
程序版本：V1.0
开发者：王昆

程序功能：构造一棵二叉树，统计该二叉树叶结点总数和结点总数
输入数据：跟随菜单指引输入
输出结果：叶结点总数和结点总数
****************************************************************/

/*头文件*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
int n = 0, m = 0;

/*二叉树存储结构*/
typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
} BTree, * tree;


//构造二叉链表
//T是指向根指针的指针
//输出输入数据的二叉树
int CreateBinTree(BTree* root, int f1 = 0, int f2 = 0)         //前序遍历
{
	root = (tree)malloc(sizeof(BTree));
	int a;
	cin >> a;
	if (a == -1) { root->data = NULL; return 1; }
	root->data = a; //入当前结点值
	f1 = CreateBinTree(root->lchild);    //递归前序遍历左子结点
	f2 = CreateBinTree(root->rchild);    //递归前序遍历右子结点
	if (f1 == 1 && f2 == 1) n++; 
	else
		m++;
	return 0;                      //结束
}

/*主函数定义*/
int main()
{
	BTree T;
	cout << "请输入字符序列：";
	CreateBinTree(&T);
	cout << "叶节点数为" << n << ",节点数为" << m+n << endl;
	return 0;
}




