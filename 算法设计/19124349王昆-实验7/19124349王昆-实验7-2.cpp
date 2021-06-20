/*************************************************************
编写时间：2021-5-19
程序版本：V1.0
开发者：王昆

程序功能：基于变治法的算法实现AVL树创建问题
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


typedef struct node {
	int data;
	int bf;		//平衡因子
	struct node* lchild, * rchild;
}BitNode, * BiTree;


//右调整：对以p为根的二叉树右旋  左子树深度大于右子树
//根节点为p节点的左孩子，同时将p节点左孩子的右孩子接在p节点的左孩子
//然后将p节点作为新根的右孩子
void rightRotate(BiTree* p) {
	BiTree L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	*p = L;
}

//左调整：以p为根的二叉树左旋，该树的右子树深度大于左子树
//调整好：根节点为p的右孩子，同时将p节点的右孩子的左孩子加在p节点的右孩子
//然后将p节点作为新的根节点的左孩子
void leftRotate(BiTree* p) {
	BiTree R = (*p)->rchild;
	(*p)->rchild = R->lchild;
	R->lchild = (*p);
	*p = R;
}

//处理LL 和LR 两种类型的旋状  LL型旋转只需要右旋一次 LR型分三种情况
//LR型的处理方法都是先根据根节点的左孩子左旋转一次变为LL型然后再又旋转
void LL_LRBalance(BiTree* p) {
	BiTree L = (*p)->lchild;
	BiTree R;
	switch (L->bf) {
	case 1://若为1,则表示新节点插在左孩子的左子树上，为LL型
		(*p)->bf = L->bf = 0;
		rightRotate(p);
		break;
	case -1://若为-1,则表示插入到左孩子的右子树上，为LR型
		R = L->rchild;
		switch (R->bf) {
		case 0:
			(*p)->bf = L->bf = 0; break;
		case 1:
			(*p)->bf = -1; R->bf = L->bf = 0; break;
		case -1:
			(*p)->bf = R->bf = 0; L->bf = 1; break;

		}
		leftRotate(&((*p)->lchild));
		rightRotate(p);
		break;
	}
}

//处理RR 和RL 两种类型的旋状  RR型旋转只需要左旋一次 RL型分三种情况
//RL型的处理方法都是先根据根节点的右孩子右旋转一次变为RR型然后再又旋转
void RR_RLBalance(BiTree* p) {
	BiTree R = (*p)->rchild;
	BiTree L;
	switch (R->bf) {
	case -1:
		(*p)->bf = R->bf = 0;
		leftRotate(p);
		break;
	case 1:
		L = R->lchild;
		switch (L->bf) {
		case 0: (*p)->bf = R->bf = 0; break;
		case 1: (*p)->bf = L->bf = 0; R->bf = -1; break;
		case -1: (*p)->bf = 1; L->bf = R->bf = 0; break;
		}
		rightRotate(&(*p)->rchild);
		leftRotate(p);
		break;
	}
}

//输入 p为根节点指针 key为被插入的关键字 chain表示插入节点后是否引起调整
//输出插入后的树
int insertAVL(BiTree* p, int key, int* chain) {
	//表示未在树中找到key，直接生成新的节点，用于存储key
	if ((*p) == NULL) {
		(*p) = (BitNode*)malloc(sizeof(BitNode));
		(*p)->bf = 0;
		(*p)->lchild = (*p)->rchild = NULL;
		(*p)->data = key;
		*chain = 1;
	}
	else {
		//表示树中有相同的关键字，表示插入失败
		if (key == (*p)->data) {
			*chain = 0;
			return 0;
		}
		if (key < (*p)->data) {
			if (!insertAVL(&(*p)->lchild, key, chain)) return 0;
			if (*chain) {

				switch ((*p)->bf) {
				case 0:(*p)->bf = 1; *chain = 1; break;
				case 1: LL_LRBalance(p); *chain = 0; break;
				case -1:(*p)->bf = 0; chain = 0; break;
				}
			}
		}
		else
		{
			if (!insertAVL(&(*p)->rchild, key, chain)) return 0;
			if (*chain) {
				{
					switch ((*p)->bf) {
					case 0: (*p)->bf = -1; *chain = 1; break;
					case 1: (*p)->bf = 0; chain = 0; break;
					case -1:RR_RLBalance(p); chain = 0; break;
					}
				}
			}
		}
	}
	return 1;
}

//中序遍历
void InOrder(BiTree t) {
	if (t != NULL) {
		InOrder(t->lchild);
		cout << t->data<<" ";
		InOrder(t->rchild);
	}
}
int main() {
	int a[100];
	int num;
	cout << "输入数据的数目：";
	cin >> num;
	cout << "输入数据：";
	for (int i = 0; i < num; i++) {

		cin >> a[i];
	}
	BiTree T = NULL;
	int chain;
	for (int i = 0; i < num; i++) {
		insertAVL(&T, a[i], &chain);
	}
	cout<<"遍历结果为：";
	InOrder(T);
	cout << endl;
}





