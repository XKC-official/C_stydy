/*************************************************************
编写时间：2020-1-14
程序版本：V1.0
开发者：王昆

程序功能：先序遍历序列，构造一棵二叉树，统计该二叉树叶结点总数和结点总数
输入数据：跟随菜单指引输入
输出结果：叶结点总数和结点总数
****************************************************************/

/*头文件*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;

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

//输出叶子节点总数
//T是指向根指针的指针
//返回二叉树叶子节点总数
int Leaf(tree T)//叶子节点总数
{
	int static leaves = 0;
	if (T)
	{	//中序遍历
		Leaf(T->lchild);	//遍历左子树
		if (!(T->lchild || T->rchild))//左右孩子均为空
			leaves++;	//叶子数加1
		Leaf(T->rchild);	//遍历右子树
	}
	return leaves;
}

//输出节点总数
//T是指向根指针的指针
//返回二叉树节点总数
int Node(tree T)//节点总数
{
	int static nodes = 0;
	if (T)
	{	//中序遍历
		Node(T->lchild);	//遍历左子树
		nodes++;		//结点数加1
		Node(T->rchild);	//遍历右子树
	}
	return nodes;

}



/*主函数定义*/
int main()
{
	tree T;
	int m, n;
	cout << "请输入字符序列：";
	CreateBinTree(&T);
	m = Leaf(T);
	n = Node(T);
	cout << "叶节点数为" << m << ",节点数为" << n << endl;
	return 0;
}




