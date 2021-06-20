/*************************************************************
��дʱ�䣺2021-5-19
����汾��V1.0
�����ߣ�����

�����ܣ����ڱ��η����㷨ʵ��AVL����������
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


typedef struct node {
	int data;
	int bf;		//ƽ������
	struct node* lchild, * rchild;
}BitNode, * BiTree;


//�ҵ���������pΪ���Ķ���������  ��������ȴ���������
//���ڵ�Ϊp�ڵ�����ӣ�ͬʱ��p�ڵ����ӵ��Һ��ӽ���p�ڵ������
//Ȼ��p�ڵ���Ϊ�¸����Һ���
void rightRotate(BiTree* p) {
	BiTree L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	*p = L;
}

//���������pΪ���Ķ�������������������������ȴ���������
//�����ã����ڵ�Ϊp���Һ��ӣ�ͬʱ��p�ڵ���Һ��ӵ����Ӽ���p�ڵ���Һ���
//Ȼ��p�ڵ���Ϊ�µĸ��ڵ������
void leftRotate(BiTree* p) {
	BiTree R = (*p)->rchild;
	(*p)->rchild = R->lchild;
	R->lchild = (*p);
	*p = R;
}

//����LL ��LR �������͵���״  LL����תֻ��Ҫ����һ�� LR�ͷ��������
//LR�͵Ĵ����������ȸ��ݸ��ڵ����������תһ�α�ΪLL��Ȼ��������ת
void LL_LRBalance(BiTree* p) {
	BiTree L = (*p)->lchild;
	BiTree R;
	switch (L->bf) {
	case 1://��Ϊ1,���ʾ�½ڵ�������ӵ��������ϣ�ΪLL��
		(*p)->bf = L->bf = 0;
		rightRotate(p);
		break;
	case -1://��Ϊ-1,���ʾ���뵽���ӵ��������ϣ�ΪLR��
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

//����RR ��RL �������͵���״  RR����תֻ��Ҫ����һ�� RL�ͷ��������
//RL�͵Ĵ����������ȸ��ݸ��ڵ���Һ�������תһ�α�ΪRR��Ȼ��������ת
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

//���� pΪ���ڵ�ָ�� keyΪ������Ĺؼ��� chain��ʾ����ڵ���Ƿ��������
//�����������
int insertAVL(BiTree* p, int key, int* chain) {
	//��ʾδ�������ҵ�key��ֱ�������µĽڵ㣬���ڴ洢key
	if ((*p) == NULL) {
		(*p) = (BitNode*)malloc(sizeof(BitNode));
		(*p)->bf = 0;
		(*p)->lchild = (*p)->rchild = NULL;
		(*p)->data = key;
		*chain = 1;
	}
	else {
		//��ʾ��������ͬ�Ĺؼ��֣���ʾ����ʧ��
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

//�������
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
	cout << "�������ݵ���Ŀ��";
	cin >> num;
	cout << "�������ݣ�";
	for (int i = 0; i < num; i++) {

		cin >> a[i];
	}
	BiTree T = NULL;
	int chain;
	for (int i = 0; i < num; i++) {
		insertAVL(&T, a[i], &chain);
	}
	cout<<"�������Ϊ��";
	InOrder(T);
	cout << endl;
}





