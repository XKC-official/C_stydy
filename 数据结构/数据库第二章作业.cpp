/*************************************************************
编写时间：2020-12-22
程序版本：V1.0
开发者：王昆

程序功能：删除表中所有值大于mink且小于maxk的元素
输入数据：跟随菜单指引输入
输出结果：输出链表
****************************************************************/

/*头文件*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;

/*链表的顺序存储结构*/
typedef struct LNode
{
	ElemType data;   /*链表存储数据元素*/
	struct LNode* next;  /*指向下一个节点的指针*/
}LNode, * LinkList;

/*初始化链表*/
void initlist(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
}


// 建立单链表
//LinkList* L 待生成的数据表
//int n 输入数据的个数
//返回值，输入数据后生成的数据表
void CreateList(LinkList L, int n)
{
	LinkList p, end;
	end = L;
	for (int i = n; i > 0; --i)
	{
		p = (LNode*)malloc(sizeof(LNode));
		cin >> (p->data);    // 输入元素值
		end->next = p;
		end = p;
	}
	end->next = NULL;
}


//打印链表
void print(LinkList L)
{
	if (L == NULL)
	{
		return;
	}

	LNode* p = L->next;
	cout << "链表打印：";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;  //换行
}

// 删除指定数据之间的的节点
//LinkList L 待处理的数据表
//ElemType mink, ElemType maxk 删除区间的最大值和最小值
//返回值，输入数据后生成的数据表
void ListDelete(LinkList L, ElemType mink, ElemType maxk)
{
	LinkList p, q, t;
	if (mink > maxk) cout << "ERROR" << endl;
	p = L;
	t = p;
	p = p->next;
	while (p && p->data < maxk)
	{
		if (p->data <= mink)
		{
			t = p;
			p = p->next;
		}
		else
		{
			t->next = p->next;
			q = p;
			p = p->next;
			free(q);
		}
	}
}

/*主函数定义*/
int main()
{
	//变量定义
	int n;
	ElemType mink, maxk;
	cout << "请输入需要键入的元素的个数：";
	cin >> n;
	LinkList L;
	initlist(L);//初始化
	CreateList(L, n);
	cout << "输入一小一大两个数字" << endl;
	cin >> mink >> maxk;
	ListDelete(L, mink, maxk);
	print(L);
	return 0;
}




